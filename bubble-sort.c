#include <stdio.h>
#include <stdlib.h>
 
static void sort(int **v, int n)
{
    	int nr = 1, ok, i, aux;
	do {
		ok = 0;
		for(i = 0; i < n - nr; i++) {
			if((*v)[i] > (*v)[i + 1]) {
				aux = (*v)[i];
				(*v)[i] = (*v)[i + 1];
				(*v)[i + 1] = aux;
				ok = 1;
			}
		}
		nr++;
	}while(ok);
}
 
void show(int *v, int n) {
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
	free(v);	
return 0;
}
