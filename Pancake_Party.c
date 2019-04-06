#include<stdio.h>
#include <time.h>


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* A,int* B,int p,int q){
	srand ( time(NULL) );
	int pivot_idx = (rand() % (q - p + 1)) + p; 
	int pivot = A[pivot_idx];
	printf("pivot_idx : %d\n",pivot_idx);
	printf("pivot : %d\n", pivot);
	int i = p;
	int j = q;
	while( i < j ){
		if(pivot < B[i]){
			swap(&B[i],&B[j]);
			j--;
		}
		else if(pivot > B[i]){
			i++;
		}
		else{
			if(i+1 == j && B[i] < B[i+1])
				break;
			swap(&B[i],&B[i+1]);
		}		
		// printf("in loop\n");
	}
	int middle = i;
	printf("middle : %d\n", middle);
	return middle;
}
void printArr(int* A,int n){
	for (int i = 0 ; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int pan[] = {5,4,3,6,9,2,7,1,8};
	int tea[] = {4,7,5,9,1,3,8,2,6};
	int n = sizeof(pan)/sizeof(pan[0]);
	int p = 0;
	int q = n - 1; 
	int k = partition(pan,tea,p,q);
	printArr(tea,n);
	return 0;
}