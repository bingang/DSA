#include<stdio.h>
#include"Arvin.h"

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* A,int* B,int p,int q){
	// (rand() % (q - p + 1)) + p;
	int pivot_idx =  (p + q)/2;
	int pivot = A[pivot_idx];
	// printf("pivot_idx : %d\n",pivot_idx);
	// printf("pivot : %d\n", pivot);
	int i = p;
	int j = q;
	while(1){
		while( query(pivot,B[i]) == 1 ) i++;
		while( query(pivot,B[j]) == -1  ) j--;
		// printf("--%d %d\n",i,j );
		if(i == j) break;
		swap(&B[i],&B[j]);
	}

	int middle = i;
	// printf("middle : %d\n", middle);
	pivot = B[middle];
	i = p;
	j = q;

	while(1){
		while( query(A[i],pivot) == -1 ) i++;
		while( query(A[j],pivot) == 1  ) j--;
		if(i == j) break;
		swap(&A[i],&A[j]);
	}
	// printf("finish the second part \n");
	return middle;
}
void printArr(int* A,int n){
	for (int i = 0 ; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void quicksort(int* A,int* B,int p,int q){
	if (p < q){
		int m = partition(A,B,p,q);
		quicksort(A,B,p,m-1);
		quicksort(A,B,m+1,q);
		// printf("in quicksort\n");
	}
}
int main(int argc, char const *argv[])
{
	// int pan[] = {5,4,3,6,9,2,7,1,8};
	// int tea[] = {4,7,5,9,1,3,8,2,6};
	// int n = sizeof(pan)/sizeof(pan[0]);
	int N;
	int pan[510000];
	int tea[510000];
	
	scanf("%d",&N);				
	for ( int i = 0 ; i < N ; i++)
		scanf("%d",&pan[i]);
	for ( int i = 0 ; i < N ; i++)
		scanf("%d",&tea[i]);
	// printf("dd\n");
	pan[N] = '\0';
	tea[N] = '\0';
		
	quicksort(pan,tea,0,N-1);	
	for(int i = 0 ; i < N ; i++){
		printf("%d %d\n",pan[i],tea[i]);
	}
	// printf("finished\n");
	// printf("tea :");
	// printArr(tea,N);
	// printf("pan :");
	// printArr(pan,N);
	return 0;
}