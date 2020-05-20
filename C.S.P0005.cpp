#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int clean_stdin(){
	// reading all char that scanf can not read with format when it read char enter then stop;
	while (getchar() != '\n') {
    }
    return 1;
}
void input(int &n){
	char c;
	do{
		printf("Please enter a number (1 - 9):");
		// check n is digits, if we enter abc then return 0 
		// if we enter 123abc the return 2 for %d is 123 and %c is abc
		// if we enter 123 then return 2 for %d is 123
	}while((scanf("%d%c",&n,&c) != 2 || c != '\n') && clean_stdin());
	
}
void mulTable(int n){
	printf("Multiplication table for %d number:",n);
	for(int i = 0; i<9; i++){
		printf("%d x %d = %d\n",n,i,n*i);
	}
	printf("-------------------------------------------\n");
}
int main(int argc, char *argv[]) {
	int n;
	char c;
	do{
		do{
			input(n);
		}while(n < 1|| n >9);
		mulTable(n);
		printf("Press enter to continue, Esc to exit.");
		c = getch();
	}while(c != 27);
	return 0;
}
