#include<stdio.h>
#include<string.h>

void swap(char a[], char b[]){
	char c[50];
	strcpy(c,a);
	strcpy(a,b);
	strcpy(b,c);
}

int main(){
	char a[50][50];
	int n;
	printf("Enter the value of n\n");
	scanf("%d",&n);
	printf("Enter %d names\n",n);
	fflush(stdin);
	for(int i=0; i<n; i++){
		gets(a[i]);
	}
	printf("List input name:\n");
	for(int i=0; i<n; i++){
		printf("%d. ",i+1);
		puts(a[i]);
	}
	swap(a[0],a[1]);
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(a[i],a[j])>0) swap(a[i],a[j]);
		}
	}
	printf("List sort name:\n");
	for(int i=0; i<n; i++){
		printf("%d. ",i+1);
		puts(a[i]);
	}
	
}
