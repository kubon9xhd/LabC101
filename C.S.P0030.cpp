#include <stdio.h>
#include <stdlib.h>
// 44 loc
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void function1(int &n){
	do{
		printf("Enter a number of element n=");
		scanf("%d",&n);
	}while(n <0 || n >10);
	
}
void function2(int n,int a[]){
	printf("Input elements:\n");
	for(int i = 0; i<n;i++){
		printf("\tElements %d=",i+1);
		scanf("%d",&a[i]);
	}
}
int function3(int n, int a[]){
	int sumEven;
	for(int i = 0; i < n; i++){
		if(a[i]%2 == 0 && a[i] > 0){
			sumEven += a[i];
		}
	}
	return sumEven;
}
int function4(int n,int a[]){
	int sumOdd;
	for(int i = 0; i < n; i++){
		if(a[i]%2 != 0 && a[i] > 0){
			sumOdd += a[i];
		}
	}
	return sumOdd;
}
void function5(int n,int a[]){
	printf("Sum of Even=%d\n",function3(n,a));
	printf("Sum of Odd=%d",function4(n,a));
}
int main(int argc, char *argv[]) {
	int n;
	int a[10];
	printf("Sum Even Odd program\n");
	function1(n);
	function2(n,a);
	function5(n,a);
	return 0;
}
