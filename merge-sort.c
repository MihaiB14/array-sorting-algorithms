#include <stdio.h>
#include <stdlib.h>

void merge(int **v, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = (*v)[l + i];
    for (j = 0; j < n2; j++)
        R[j] = (*v)[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (*v)[k] = L[i];
            i++;
        }
        else {
            (*v)[k] = R[j];
            j++;
        }
        k++;
    }
   while (i < n1) {
        (*v)[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        (*v)[k] = R[j];
        j++;
        k++;
    }
}

static void mergeSort(int **v, int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and  h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
 
        merge(v, l, m, r);
    }
}

void show(int *v, int n){
        printf("The vector is: ");
        int i;          
        for(i = 0; i < n; i++) {
                printf("%d ", v[i]);
        }
        printf("\n");
}

int main()
{
        int *v, n, i;
        printf("Number of elements: ");
        scanf("%d", &n);
        v = (int*)malloc(n*sizeof(int));
        for(i = 0; i < n; i++) {
                printf("v[%d] = ", i);
                scanf("%d", &v[i]);
        }    

        show(v, n);
        mergeSort(&v, 0, n - 1);
        printf("Vector sorted\n");
        show(v, n);

        return 0;
}
