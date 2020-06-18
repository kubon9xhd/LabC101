#include<stdio.h>
#include<stdlib.h>

void input ( long long int &decimal_number){
 	printf("Convert Decimal to Binary program\n");
	do{
	printf("	Enter a positive number: ");
	scanf("%lld",&decimal_number); 
	}while(decimal_number<=0);
}
 void display(int *a ,int n){
 printf("Binary number: ");
	for(int i = 0; i<n ; i++){
		printf("%d",a[i]);
	}
 }
int* decToBinary(int *a, int &n, int decimal_number)
{
	int i=0;
	a=(int*)calloc(n,sizeof(int*));
	while(decimal_number>0){
            	a=(int *)realloc(a,(n+1)*sizeof(int*));		
		a[i]=decimal_number%2;
		decimal_number=decimal_number/2;
		i++;
		n++;
	}
        return a;
        
//	free(a);
}




int main(){
	while(1){
	int key, n =1;
	int *a;
	long long int decimal_number;
	input(decimal_number);
	a = decToBinary(a,n,decimal_number);
	display(a,n);
	printf("\nDo you want to do another convert (Y/N): ");
	fflush(stdin);
	//fpurge(stdin);
	key = getchar();
        if(key=='N'||key=='n')
        {
            break;
        }
    free(a);
	}	
}
