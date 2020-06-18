#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main(int argc, char *argv[]) {
    char a[1000];
    int check = 1;
    int sum = 0;
    printf("Moi ban nhap so");
    fflush(stdin);
    scanf("%[^\n]",&a);
    for(int i = 0; i < strlen(a); i++){
        // 48-57
        if(int(a[i]) < 48 || int(a[i]) > 57 ){
            check = 0;
            break;
        }
    }
    if(check == 0){
        printf("Day so ban nhap vao co ky tu khong phu hop");
    }else if(check == 1){
        for(int i = 0; i < strlen(a); i++){
            sum += (int)a[i]-48;
        }
        printf("Total :%d",sum);
    }
    return 0;
}
