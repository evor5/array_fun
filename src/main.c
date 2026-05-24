#include <stdio.h>
#include <stdlib.h> 

void task1(){
    int arr[] = {1, 8, 2, 4, 27, 18, 2};
    int arr2[] = {2, 9, 8, 1};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int size;
    if(n2 < n1){
        size = n2;
    }
    else {
        size = n1;
    }

    for (int i = 0; i < size; i++) {
        printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
    }
    
    printf("\n");
}

void task2(){
    int* ptr;
    int size;
    printf("enter size of elements:");
    scanf("%d", &size);

    ptr = (int*)malloc(size * sizeof(int));

    if (ptr == NULL) {
        printf("memory not allocated.\n");
    }
    else {
        printf("memory successfully allocated using "
        "malloc.\n");

        for (int j = 0; j < size; ++j){
            ptr[j] = j + 1;
        }
        printf("the elements of the array are: ");
        for (int k = 0; k < size; ++k) {
            printf("%d, ", ptr[k]);
        }
    }
}

void task3(){
    int* arr;
    int size;
    printf("enter size of array: ");
    scanf("%d", size);

    arr = (int*)malloc(size * sizeof(int));

    

}

void task4(){
    int* trial;
    int size = 4;
    trial = malloc (size * sizeof(int));
    trial[0] = 1; trial[1] = 4; trial[2] = 7; trial[3] = 11;
    trial = (int*)realloc(trial, sizeof(int) * ++size);
    trial[size - 1] = 23;

    int a;
    for(a = 0; a < size; a++){
        printf("TRIAL %d \n", trial[a]);
    }
}

// void arr_plus(int* arr, int* arr2, int size, int size2){
//     for(int i = 0; i < size; i++){
//         if(i >= size2){
//             printf("| %d + %d = %d |\n", arr[i], 1, arr[i] + 1);
//         }
//         else {
//             printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
//         }
//     }
// }


void arr_plus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
    }
}

void arr_minus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d - %d = %d |\n", arr[i], arr2[i], arr[i] - arr2[i]);
    }
}

void arr_multiply(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d * %d = %d |\n", arr[i], arr2[i], arr[i] * arr2[i]);
    }
}

void arr_division(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        if(arr2[i] != 0){
            printf("| %d / %d = %d |\n", arr[i], arr2[i], arr[i] / arr2[i]);
        }
        else{
            printf("na 0 delit nelzya))\n");
        }
    }
}

void arr2_plus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size2; i++){
        printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
    }
}

void arr2_minus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size2; i++){
        printf("| %d - %d = %d |\n", arr[i], arr2[i], arr[i] - arr2[i]);
    }
}

void arr2_multiply(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size2; i++){
        printf("| %d * %d = %d |\n", arr[i], arr2[i], arr[i] * arr2[i]);
    }
}

void arr2_division(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size2; i++){
        if(arr2[i] != 0){
            printf("| %d / %d = %d |\n", arr[i], arr2[i], arr[i] / arr2[i]);
        }
        else{
            printf("na 0 delit nelzya))\n");
        }
    }
}

void arr3_plus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
    }
}
void arr3_minus(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d - %d = %d |\n", arr[i], arr2[i], arr[i] - arr2[i]);
    }
}
void arr3_multiply(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        printf("| %d * %d = %d |\n", arr[i], arr2[i], arr[i] * arr2[i]);
    }
}
void arr3_division(int* arr, int* arr2, int size, int size2){
    for(int i = 0; i < size; i++){
        if(arr2[i] != 0){
            printf("| %d / %d = %d |\n", arr[i], arr2[i], arr[i] / arr2[i]);
        }
        else{
            printf("na 0 delit nelzya))\n");
        }
    }
}

void task5(){
    int* arr;
    int* arr2;
    int size;
    int size2;
    char op;
    int op2;

    printf("enter size of element (1-st array): ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    printf("enter array: ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("enter size of element (2-nd array): ");
    scanf("%d", &size2);
    arr2 = (int*)malloc(size2 * sizeof(int));
    printf("enter array: ");
    for(int i = 0; i < size2; i++){
        scanf("%d", &arr2[i]);
    }

    printf("choose operation ( +, -, *, / ): ");
    while(getchar() != '\n');
    scanf("%c", &op);
    op2 = (int)op;

    if(size > size2){
        arr2 = (int*)realloc(arr2, sizeof(int) * size);
        for(int i = size2; i < size; i++){
            arr2[i] = 1;
            printf("%d\n", arr2[i]);
        }
        if(op2 == 43){
            arr_plus(arr, arr2, size, size2);
        }
        else if(op2 == 45){
            arr_minus(arr, arr2, size, size2);
        }
        else if(op2 == 42){
            arr_multiply(arr, arr2, size, size2);
        }
        else if(op2 == 47){
            arr_division(arr, arr2, size, size2);
        }
        else {
            printf("wrong operation >:(\n");
        }
    }
    else if(size2 > size){
        arr = (int*)realloc(arr, sizeof(int) * size2);
        for(int i = size; i < size2; i++){
            arr[i] = 1;
            printf("%d\n", arr[i]);
        }
        if(op2 == 43){
            arr2_plus(arr, arr2, size, size2);
        }
        else if(op2 == 45){
            arr2_minus(arr, arr2, size, size2);
        }
        else if(op2 == 42){
            arr2_multiply(arr, arr2, size, size2);
        }
        else if(op2 == 47){
            arr2_division(arr, arr2, size, size2);
        }
        else {
            printf("wrong operation >:(\n");
        }
    }
    else{
        if(op2 == 43){
            arr3_plus(arr, arr2, size, size2);
        }
        else if(op2 == 45){
            arr3_minus(arr, arr2, size, size2);
        }
        else if(op2 == 42){
            arr3_multiply(arr, arr2, size, size2);
        }
        else if(op2 == 47){
            arr3_division(arr, arr2, size, size2);
        }
        else {
            printf("wrong operation >:(\n");
        }
    }
}

int main() {
    int input;

    // char test;
    // scanf("%c", &test);
    // int test2 = (int)test;
    // printf("%d\n", test);

    printf ("input: ");
    scanf ("%d", &input);
    printf ("\n");
    if (input == 1) {
        task1();
    }
    else if(input == 2){
        task2();
    }
        else if(input == 4){
        task4();
    }
        else if(input == 5){
        task5();
    }
    else {
        printf("wrong number of task");
    }
    return 0;

}