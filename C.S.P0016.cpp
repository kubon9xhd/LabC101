#include <stdio.h>

void caculate(float year, float mortgage, float payment){
	int month=1;
	printf("Month	Payment		Amount Owed\n");
	do{
		mortgage=(mortgage+mortgage*year/1200)-payment ;
		printf("%2d%12.2f %16.2f\n",month++,payment,mortgage);
	}while(mortgage>payment);
	printf("%2d%12.2f\t\t0",month,mortgage=(mortgage+mortgage*year/1200));
}
	
int main(){
	float year, mortgage, payment;
	printf("What is the value left on the mortgage?\n");
	scanf("%f",&mortgage);
	printf("What is the annual interest rate of the loan, in percent?\n");
	scanf("%f",&year);
	printf("What is the monthly payment?\n");
	scanf("%f",&payment);
	caculate(year, mortgage, payment);
}
