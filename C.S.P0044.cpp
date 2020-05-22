#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//csp 0044

int getInt(char msg[], char err[], int min, int max) {
    int num;
    int check;
    char c;
    do {
        printf("%s", msg);
        check = scanf("%d%c", &num, &c); //Returns the value of an integer
        if (check != 2 || c != '\n' || num < min || num > max) {
            printf("%s", err);
            fflush(stdin); //Delete buffer
            check = 0; //input is a character
        } else {
            check = 1; //input is a number
        }
    } while (check == 0);
    return num;
}

int *addElement(int *arr, int *size) {
    //increase the size
    arr = (int*) realloc(arr, (++*size) * sizeof (int));
    int num = getInt("Enter add element: ", "Try again!!!\n", INT_MIN, INT_MAX);
    arr[*size - 1] = num; //add value to the last
    return arr;

}

//Check if the number is in the array or not

int isExist(int arr[], int size, int num) {
    //run the loop from the first element to the last
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

void findIndex(int arr[], int size) {
    int num = getInt("Enter the value to find: ", "try again!!!\n", INT_MIN, INT_MAX);
    //The num is in the array
    if (isExist(arr, size, num) == 1) {
        printf("Number %d has index:", num);
        //run the loop from the first element to the last
        for (int i = 0; i < size; i++) {
            if (arr[i] == num) {
                printf("%d  ", i); //i is index of the num
            }
        }
    } else {
        printf("In array don't have number you were entered\n");
    }
    printf("\n");
}

void display(int arr[], int size) {
    //run the loop from the first element to the last
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void printOutInRange(int arr[], int size, int min, int max) {
    //run the loop from the first element to the last
    for (int i = 0; i < size; i++) {
        //The element is between min and max
        if (arr[i] >= min && arr[i] <= max) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void sortAcending(int arr[], int n) {
    //run loop position elements of array from the first element position is 0 to last position is size -1
    for (int i = 0; i < n - 1; i++) {
        //Run loop position elements of array from the first elements position after i to last element
        for (int j = i + 1; j < n; j++) {
            //Swap if the previous element is greater than the following to sort ascending     
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void menu() {
    printf("--------Menu--------\n");
    printf("1- Add a value\n");
    printf("2- Search a value\n");
    printf("3- Print out the array\n");
    printf("4- Print out values in a range of inputted min and max values, inclusively\n");
    printf("5- Sort the array in ascending order\n");
    printf("Others- Quit\n");
}

int main(int argc, char** argv) {
    int size = 0;
    int *arr = (int *) calloc(size, sizeof (int));  
    menu();
    //menu of the option
    int choice;
    do {
        choice = getInt("Enter the choice: ", "try again!!!\n", INT_MIN, INT_MAX);

        switch (choice) {
                //add a value   
            case 1:
                // size of array smaller than 100
                if (size == 100) {
                    printf("Can not add more\n");
                    break;
                } else {
                    arr = addElement(arr, &size);
                    break;
                }
            case 2: //Search a value
                findIndex(arr, size);
                break;
                //Print out the array
            case 3:
                display(arr, size);
                break;
                //Print out values in a range of inputted min and max values,
            case 4:{
                int min = getInt("Enter min: ", "Try again!!!\n", INT_MIN, INT_MAX);
                int max = getInt("Enter max: ", "Max must be greater than Min\n", min, INT_MAX);
                printOutInRange(arr, size, min, max);
                break;
            }
            case 5: //Sort the array in ascending order
                sortAcending(arr, size);
                display(arr, size);
                break;
            default: //Others- Quit
                return 0;

        }
    } while (1);
    free(arr);

}
