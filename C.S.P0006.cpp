#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void input(int *ptr, int n){
	for(int i = 0; i< n; i++){
		printf("Enter element[%d]",i);
		scanf("%d", ptr+i);
	}
}
void sortAsc(int *ptr, int n){
	int temp;
	for(int i =0; i<n; i++){
		for(int j = i+1; j < n; j++){
			if(*(ptr+i) > *(ptr+j)){
				temp = *(ptr+i);
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
	printf("The array sorted in ascending:\n");
}
void sortDesc(int *ptr, int n){
	int temp;
	for(int i =0; i<n; i++){
		for(int j = i+1; j < n; j++){
			if(*(ptr+i) < *(ptr+j)){
				temp = *(ptr+i);
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = temp;
			}
		}
	}
	printf("The array sorted in descending:\n");
}
void display(int *ptr, int n){
	for(int i = 0; i<n; i++){
		printf("%-3d",*(ptr+i));
	}
}
int main(int argc, char *argv[]) {
	int n;
	int *ptr;
	do{
		printf("Please enter size of array:");
		scanf("%d",&n);
	}while(n <= 0);
	ptr = (int *)malloc(n*sizeof(int));
	input(ptr,n);
	sortAsc(ptr,n);
	display(ptr,n);
	printf("\n");
	sortDesc(ptr,n);
	display(ptr,n);
	return 0;
}
