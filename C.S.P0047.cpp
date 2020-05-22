#include <stdio.h>
#include <string.h>

struct listStudent{
	char name[50];
}student[100];

void function2(int &i){
	printf("Enter new student name: ");
	fflush(stdin);
	gets(student[i++].name);
	printf("Student has been added to list successfully!\n");
}
void swap(listStudent &a, listStudent &b){
	listStudent temp;
	temp=a; a=b; b=temp;
}

void function3(int &i){
	char dele[50];
	int check=0,j;
	printf("Enter new student name: ");
	fflush(stdin);
	gets(dele);
	for(j=1; j<i; j++){
		if(strcmp(student[j].name, dele)==0){
			check=1; break; 
		}
	}
	if(check==1){
		for(int k=j; k<i; k++){
			swap(student[k],student[k+1]);
		}
		printf("Student has been removed successfully!\n");
		i--;
	}
	else printf("Not exist.\n");
}

void function4(int i){
	char search[50];
	int check=0,j;
	printf("Enter new student name: ");
	fflush(stdin);
	gets(search);
	for(j=1; j<i; j++){
		if(strcmp(student[j].name, search)==0){
			check=1; break; 
		}
	}
	if(check==1){
		printf("The position of student name in list is %d\n",j--);
	}
	else printf("Not exist.\n");
}

void function5(int i){
	printf("Total students: %d\n",i-1);
	for(int j=1; j<i-1; j++){
		if(strcmp(student[j].name,student[j+1].name)>0){
			swap(student[j],student[j+1]);
		}
	}
	for(int j=1; j<i; j++){
		printf("%s\n",student[j].name);
	}
}

void function1(){
	int check, i=1;
	do{
		printf("*************************************************\n");
		printf("1 - Add a student name into the array.\n");
		printf("2 - Remove a student name.\n");
		printf("3 - Search a student name.\n");
		printf("4 - Output student names in ascending orders alphabetically.\n");
		printf("5 - Exit the program.\n");
		printf("*************************************************\n");
		printf("Enter your choice: ");
		scanf("%d", &check);
		switch(check){
			case 1: function2(i); break;
			case 2: function3(i); break;
			case 3: function4(i); break;
			case 4: function5(i); break;
			case 5: return; 
		}
	}while(1);
}

int main(){
	printf("========Student Management=======");
	function1();
}
