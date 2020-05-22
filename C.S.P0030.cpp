#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void inputN(int &n){
	do{
		printf("Enter a number of element n=");
		scanf("%d",&n);
	}while(n <0 || n >10);
	
}
void inputE(int n,int a[]){
	printf("Input elements:\n");
	for(int i = 0; i<n;i++){
		printf("\tElements %d=",i+1);
		scanf("%d",&a[i]);
	}
}
int sumEven(int n, int a[]){
	int sumEven;
	for(int i = 0; i < n; i++){
		if(a[i]%2 == 0 && a[i] > 0){
			sumEven += a[i];
		}
	}
	return sumEven;
}
int sumOdd(int n,int a[]){
	int sumOdd;
	for(int i = 0; i < n; i++){
		if(a[i]%2 != 0 && a[i] > 0){
			sumOdd += a[i];
		}
	}
	return sumOdd;
}
void display(int n,int a[]){
	printf("Sum of Even=%d\n",sumEven(n,a));
	printf("Sum of Odd=%d",sumOdd(n,a));
}
int main(int argc, char *argv[]) {
	int n;
	int a[10];
	printf("Sum Even Odd program\n");
	inputN(n);
	inputE(n,a);
	display(n,a);
	return 0;
}
