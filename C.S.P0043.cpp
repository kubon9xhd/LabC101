#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// 140 loc
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void press() {
	char key;
	system("pause");
	while(1){
	        key = getchar(); // get char they click/enter
	        if(key != NULL){
	            system("cls"); // delete display
	            break;
            }
	}
}

void display(int a[],int n){
	printf("The elements of array :\n");
	for(int i = 0; i < n; i++){
		printf("%-3d",a[i]);
	}
	printf("\n");
}
void input(int a[], int &i){
	printf("Enter elements [%d]: ",i);
	scanf("%d",&a[i++]);
	display(a,i);
}
void search(int a[], int n){
	int numSearch,check = 0;
	printf("Enter an integer to search :");
	scanf("%d",&numSearch);
	// check the occurrence of numSearch
	for(int i = 0; i < n; i++){
		if(a[i] == numSearch){
			check = 1;
			break;
		}
	}
	if(check == 1){ // if the occurrence  then printf the index of them
		printf("The number at :");
		for(int i = 0; i<n; i++){
			if(a[i] == numSearch){
				printf("%d\n",i+1); // index we will index+1 
			}
		}
	}else if(check == 0){ // the numSearch does not in array
		printf("The number does not in array");
	}
	printf("\n");
}
void swap(int &a, int &b){
	int c;
	c=a; 
	a=b; 
	b=c;
}
void deleteFTime(int a[], int &n){
	int numSearch,check = 0;
	printf("Enter an integer to delete:");
	scanf("%d",&numSearch);
	// check the occurrence of numSearch
	for(int i = 0; i < n; i++){
		if(numSearch == a[i]){
			check = 1;
			break;
		}
	}
	if(check == 1){  // if the occurrence then find the firts appearing position
		for(int i = 0; i < n; i++){
			if(numSearch == a[i]){
				for(int j = i; j<n;j++){ // run j from i = numSearch to n when we delete element numSearch in array
					swap(a[j],a[j+1]); // change element numSearch from j to n after we reduce the value n
				}
				n--;	// reduce the value of n
				break; //  stop the loop when it run one time
			}
		}
		printf("Done !!\n");
		display(a,n);		// display result
	}else if(check == 0){ // the numSearch does not in array
		printf("The number does not in array\n");
	}
}
void deleteAllTime(int a[],int &n){
	int numSearch, check = 0;
	printf("Enter an integer to delete:");
	scanf("%d",&numSearch);
	// check the occurrence of numSearch
	for(int i = 0; i < n; i++){
		if(numSearch == a[i]){
			check = 1;
			break;
		}
	}
	if(check == 1){ // if the occurrence then find the firts appearing position
		for(int i = 0; i < n; i++){
			if(numSearch == a[i]){ // run j from i = numSearch to n when we delete element numSearch in array
				for(int j = i; j<n;j++){
					swap(a[j],a[j+1]); // change element numSearch from index j to n after we reduce the value n
				}
				n--; // reduce the value of n
				// we run when can not found the elements numSearch in array
			}
		}
		printf("Done !!\n");
		display(a,n);		// // display result
	}else if(check == 0){ // the numSearch does not in array
		printf("The number does not in array");
	}
}
void sortIncrease(int a[],int n) {
	int b[100];
	// creat new array to contains components of array a[]
	for(int i = 0; i < n;	i++){
		b[i] = a[i]; // coppy the element of a[] to b[]
	}
	// bubble sort 
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(b[i] > b[j]){ // if the elment of index i higher than element of index j
				swap(b[i],b[j]); //  swap index of them
			}
		}
	}
	display(b,n);
}
void sortDecrease(int a[],int n) {
	int b[100];
	// creat new array to contains components of array a[]
	for(int i = 0; i < n;	i++){
		b[i] = a[i]; 	// creat new array to contains components of array a[]
	}
	// bubble sort 
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(b[i] < b[j]){ // if the elment of index i lower than element of index j
				swap(b[i],b[j]); //  swap index of them
			}
		}
	}
	display(b,n);
}	
void function2(int a[],int &i,int option){
	// select case for option
	switch(option){
		case 1:
			// add element to array
			if(i <= 100){
				input(a,i);
			}else{
				printf("Can not add more\n");
			}
			break;
		case 2:
			// find index of element 
			search(a,i);
			break;
		case 3:
			// delete first appearing position 
			deleteFTime(a,i);
			break;
		case 4:
			// delete all appearing position 
			deleteAllTime(a,i);
			break;
		case 5:
			// display the element 
			display(a,i);
			break;
		case 6:
			// Sort Ascending
			sortIncrease(a,i);
			break;
		case 7:
			// Sort Descending 
			sortDecrease(a,i);
			break;			
				
	}
}
// select option to run
void funtion1(int a[]){
	int option,i = 0;
	// TEST is lable we can change name 
	TEST: do{
		printf("1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Remove the first existence of a value\n");
		printf("4- Remove all existences of a value\n");
		printf("5- Print out the array\n");
		printf("6- Sort the array in ascending order (positions of elements are preserved)\n");
		printf("7- Sort the array in descending order (positions of elements are preserved)\n");
		printf("Others- Quit\n");
		display(a,i);
		printf("Your choice :");
		scanf("%d",&option);
		// when option outside (1-7) then stop program
		if(option < 1 || option > 7) return;
		if(i == 0 && option != 1){
			printf("The array does not elements to manipulate other functions\n");
			press();
			goto TEST; //unconditional jump about lable TEST
		}
		// else then run function2
		function2(a,i,option);
		press();
		goto TEST; // unconditional jump about lable TEST
	}while(1);
	


}
int main(int argc, char *argv[]) {
	int a[100];
	funtion1(a);
	return 0;
}
