#include <stdio.h>
#include <stdlib.h> 

struct Dinosaur{
    const char* name;
    int age;
    const char* gender;
    int dmg;
    
    void (*first_skill)();
    int (*attack)(struct Dinosaur* dyno);
};

double get_interpolated_value(double x, double x0, double x1, double y0, double y1){
    double result = y0 + ((y1 - y0)/(x1 - x0)) * (x - x0);
    return result;
}

int attack(struct Dinosaur* dyno){
    double total_damage;
    if(dyno->age >= 0 && dyno->age <= 70){
        total_damage = get_interpolated_value(dyno->age, 0, 70, 0, dyno->dmg);
    }
    else if(dyno->age >= 70 && dyno->age <= 120){
        total_damage = get_interpolated_value(dyno->age, 70, 120, dyno->dmg, dyno->dmg);
    }
    else if(dyno->age >= 120 && dyno->age <= 150){
        total_damage = get_interpolated_value(dyno->age, 120, 150, dyno->dmg, 0);
    }
    printf("%s in %d y.o caused %f damage\n",dyno->name,dyno->age, total_damage);
}

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

void process_operation(int* arr, int* arr2, int size, char op){
    if(op == '+'){
        for(int i = 0; i < size; i++){
            printf("| %d + %d = %d |\n", arr[i], arr2[i], arr[i] + arr2[i]);
        }
    }
    else if(op == '-'){
        for(int i = 0; i < size; i++){
            printf("| %d - %d = %d |\n", arr[i], arr2[i], arr[i] - arr2[i]);
        }
    }
    else if(op == '*'){
        for(int i = 0; i < size; i++){
            printf("| %d * %d = %d |\n", arr[i], arr2[i], arr[i] * arr2[i]);
        }
    }
    else if(op == '/'){
        for(int i = 0; i < size; i++){
            if(arr2[i] != 0){
                printf("| %d / %d = %d |\n", arr[i], arr2[i], arr[i] / arr2[i]);
            }
            else{
                printf("na 0 delit nelzya))\n");
            }
        }
    }
    else {
        printf("wrong operation >:(\n");
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

    int max_size, min_size;
    if(size > size2){
        max_size = size;
        min_size = size2;
        arr2 = (int*)realloc(arr2, sizeof(int) * max_size);
        for(int i = min_size; i < max_size; i++){
            arr2[i] = 1;
            printf("%d\n", arr2[i]);
        }
    }
    else{
        max_size = size2;
        min_size = size;
        arr = (int*)realloc(arr, sizeof(int) * max_size);
        for(int i = min_size; i < max_size; i++){
            arr[i] = 1;
            printf("%d\n", arr[i]);
        }
    }
    process_operation(arr, arr2, max_size, op2);

}

void swap(int* a, int* b){
    int c = *a;
    *a = *b;
    *b = c;
}

void task6(){
    int arr [] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    int countdown = size - 1;

    for(int i = 0; i < size / 2; i++, countdown--){
        swap(&arr[i], &arr[countdown]);
    }

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void task7(){
    int a = 5, b = 3;
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);
}

void print_array(int* arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int* arr, int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
    }
    return sum;
}

int get_max(int* arr, int size){
    int max = 0;
    for (int i = 0; i < size; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

int get_min(int* arr, int size){
    int min = INT_MAX;
    for (int i = 0; i < size; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}

int is_array_ascending(int* arr, int size){
    int result = 0;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] < arr[i + 1]){
            result = 1;
        }
        else {
            result = 3;
            return result;
        }
    }
    return result;
}

int is_array_descending(int* arr, int size){
    int result = 0;
    for(int i = 0; i < size - 1; i++){
        if(arr[i] > arr[i + 1]){
            result = 2;
        }
        else {
            result = 3;
            return result;
        }
    }
    return result;
}

void show_arr_info(int* arr, int size){
    print_array(arr, size);
    printf("size = %d, bytes = %d.\n", size, sizeof(arr[0]) * size);
    printf("sum = %d.\n", sum_array(arr, size));
    printf("avg = %d.\n", sum_array(arr, size) / size);
    printf("max = %d, min = %d.\n", get_max(arr, size), get_min(arr, size));
    if(is_array_ascending(arr, size) == 1){
        printf("this array is ascending");
    }
    else if (is_array_descending(arr, size) == 2){
        printf("this array is descending");
    }
    else{
        printf("this array is non-monotonic");
    }
}

void task8(){
    int arr [] = {5, 4, 3, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    show_arr_info(arr, size);
}

void task9(){
    struct Dinosaur rex;
    rex.age = 0;
    rex.dmg = 100;
    rex.gender = "male";
    rex.name = "rex";
    rex.attack = attack;
    struct Dinosaur phila;
    phila.age = 0;
    phila.dmg = 70;
    phila.gender = "female";
    phila.name = "phila";
    phila.attack = attack;
    for(int i = 0; i < 151; i++){
        rex.attack(&rex);
        rex.age++;
        phila.attack(&phila);
        phila.age++;
    }
}

void print_2d_array(int matrix[][4], int rows, int columns){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void get_sum_of_all_rows_and_columns(int matrix[][4], const int rows, const int columns){
    int* sum_array = (int*)malloc((rows + columns) * sizeof(int));
    int sum_index = 0;
    int sum = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            sum += matrix[i][j];
        }
        sum_array[sum_index++] = sum;
        sum = 0;
    }
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            sum += matrix[j][i];
        }
        sum_array[sum_index++] = sum;
        sum = 0;
    }
    for(int i = 0, j = 1; i < rows + columns; i++){
        if (i < rows){
            printf("sum of #%d row : %d\n", i+1, sum_array[i]);
        }
        else{
            printf("sum of #%d column : %d\n", j, sum_array[i]);
            j++;
        }
    }
}

void task10(){
    int matrix[3][4] = { 
        {1, 4, 2, 5}, 
        {3, 6, 8, 2},
        {9, 7, 3, 1} 
    };
    int sum = 0;

    print_2d_array(matrix, 3, 4);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            sum += matrix[i][j];
        }
    }
    printf("sum = %d\n", sum);

    get_sum_of_all_rows_and_columns(matrix, 3, 4);
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
    else if(input == 6){
        task6();
    }
    else if(input == 7){
        task7();
    }
    else if(input == 8){
        task8();
    }
    else if(input == 9){
        task9();
    }
    else if(input == 10){
        task10();
    }
    else {
        printf("wrong number of task");
    }
    return 0;

}