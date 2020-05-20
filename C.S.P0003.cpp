#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void input(int &n, int a[]){
	do{
		printf("Please enter size of array:");
		scanf("%d",&n);	
	}while(n <= 0 || n > 100);
	for(int i = 0; i < n; i++){
		printf("Enter element[%d]:",i);
		scanf("%d",&a[i]);
	}	
}
void swap(int &a, int &b){
	int c;
	c=a; 
	a=b; 
	b=c;
}

void sort(int n, int a[]){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(a[j]<a[i])	
			swap(a[i],a[j]);
		}
	}
}
void add(int &n, int a[]){
	printf("\nPlease enter new value:");
	scanf("%d",&a[n++]);
}
void display(int n, int a[]){
	for(int i = 0; i < n; i++){
		printf("%-3d",a[i]);
	}
}
int main(int argc, char *argv[]) {
	int n,a[100];
	input(n,a);
	
	sort(n,a);
	printf("The array after sorting:\n");
	display(n,a);
	
	add(n,a);
	sort(n,a);
	printf("New array:\n");
	display(n,a);
	
	return 0;
}
