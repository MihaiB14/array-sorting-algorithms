#include <stdio.h>
#include <stdlib.h>

int getMax(int *v, int n) {
        int mx = v[0], i;
        for(i = 1; i < n; i++) {
                if(v[i] > mx) {
                        mx = v[i];
                }
        }
        return mx;
}	 

void countSort(int **v, int n, int exp) {
	int output[n];
	int i, count[10] = { 0 };
	
	for(i = 0; i < n; i++) {
		count[((*v)[i] / exp) % 10]++;
	}

	for(i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	for(i = n - 1; i >= 0; i--) {
		output[count[((*v)[i] / exp) % 10] - 1] = (*v)[i];
		count[((*v)[i] / exp) % 10]--;
	}

	for(i = 0; i < n; i++) {
		(*v)[i] = output[i];
	}
}

static void sort(int **v, int n)
{
 	int m = getMax(*v, n);
	int exp;	
	for(exp = 1; m / exp > 0; exp *= 10) {
		countSort(v, n, exp);
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
        sort(&v, n);
        printf("Vector sorted\n");
        show(v, n);

	return 0;
}
