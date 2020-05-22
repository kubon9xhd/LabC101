#include <stdio.h>
#include <math.h>

bool checkPrime(int n){
	if(n==0||n==1) return false;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)	return false;
	}
	return true;
}

void function2(){
	int num,i=2,count=0;
	do{
		printf("Number of primes:");
		scanf("%d",&num);
		if(num<0||num>50){
			printf("Re-input:");
			scanf("%d",&num);
		} 
	}while(num<=0||num>50);
	while(1){
		if(checkPrime(i)) {
			printf("%d ",i);
			printf("\n"); count++;
			if(count==num) return;
		}
		i++;
	}
}

bool isPerfectSquare(int x){
	int s=sqrt(x);
	return (s*s==x);
}

void function3(){
	int n;
	bool check=false;
	do{
		printf("Number tested:");
		scanf("%d",&n);
		if(n<=0||n>1000) printf("Re-input");
	}while(n<=0||n>1000);
	if(isPerfectSquare(5*n*n+4)||isPerfectSquare(5*n*n-4)) check=true;
	if(check==true) printf("true\n");
	else printf("false\n");
}

void function4(){
	int sum=0,n,i;
	printf("Enter an integer:");
	scanf("%d",&n);
	while(n!=0){
		i=n%10; n=n/10;
		sum+=i;
	}
	printf("Sum of it's digits:%d\n",sum);
}

void function1(){
	int check;
	do{
		printf("1 - The first primes\n");
		printf("2 - Fibonacci element\n");
		printf("3 - Sum of digits\n");
		printf("Choosen an option:");
		scanf("%d",&check);
		switch(check){
			case 1: function2(); break;
			case 2: function3(); break;
			case 3: function4(); break;
		}
	}while(1);	
}

int main(){
	function1();	
}
