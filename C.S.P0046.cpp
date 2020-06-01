#include <stdio.h>
#include <math.h>

int checkPrime(int n){
	if(n==0||n==1) return 0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0)	return 0;
	}
	return 1;
}

void outputPrimes(){
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
			count++;
			if(count==num) return;
		}
		i++;
	}
}

int isFibonacciTerm(int x){
	int f0 = 1;
    int f1 = 1;
    int fN = 0;
 
    if( x < 1 )
        return 0;
 
    if( x == 1 )
        return 1;
 
    while(fN <= x)
    {
        fN = f0 + f1;
        f0 = f1;
        f1 = fN;
        if(fN == x)
            return 1;
    }
    return 0;

}

void checkFibonacci(){
	int n;
	int check = 0;
	do{
		printf("Number tested:");
		scanf("%d",&n);
		if(n<=0||n>1000) printf("Re-input");
	}while(n<=0||n>1000);
	if(isFibonacciTerm(n)) check = 1;
	if(check==1) printf("true\n");
	else printf("false\n");
}

void sumDigits(){
	int sum=0,n,i;
	printf("Enter an integer:");
	scanf("%d",&n);
	while(n!=0){
		i=n%10; n=n/10;
		sum+=i;
	}
	printf("Sum of it's digits:%d\n",sum);
}

void choiceMenu(){
	int check;
	do{
		printf("1 - The first primes\n");
		printf("2 - Fibonacci element\n");
		printf("3 - Sum of digits\n");
		printf("Choosen an option:");
		scanf("%d",&check);
		switch(check){
			case 1: outputPrimes(); break;
			case 2: checkFibonacci(); break;
			case 3: sumDigits(); break;
		}
	}while(1);	
}

int main(){
	choiceMenu();	
}
