#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* В условии задачи поставлены скобки [] над частным, которое не требовало доп скобок, поэтому я пришла к выводу, что это означает целую
часть и массив состоит из целых элементов. Если же мое предположение неверно, то все то же самое выполняется для массива с элементами
типа double, а в функции cel не надо делать приведение типов и просто вернуть результат деления 
*/

int cel (int a_i, int min, int max); // Функция нахождения целой части от искомого частного
int max_number (int *arr, int number); //Функция нахождения максимального элемента в массиве
int min_number(int *arr, int number); // Функция нахождени минимального элемента в массиве

int max_number(int *arr, int number){
  int max = arr[0];
  for (int i=0; i<number; i++){
    if (arr[i]> max) max=arr[i];
    }
return max;
}

int min_number (int *arr, int number) {
 int min = arr[0];
  for (int i = 0; i < number; i++){
   if (arr[i] < min) min = arr[i];
}
return min;
}

int cel (int a_i,int min, int max){
int k = a_i - min;
int f = abs (max - min);
double a = k/f;
int celum = (int) a;
return celum;
}

int main (void) {
int number, el, count = 0, min, max;
int *arr;
    FILE * n = fopen ("data.txt", "r");
    if (n == NULL){
        printf ("File error");
        return 0;
    }

// Узнаем размер массива (считываем первый элемент из файла)
if (fscanf (n, "%d", &number) == 1) {
 if (malloc(number *sizeof(int)) != NULL) {
  arr = (int*)malloc(number *sizeof(int));
}
 else {printf ("Memory error\n"); return 0;}
}
 else {printf("First element is wrong\n");return 0;}

// Считываем сами элементы
for (int i = 0; i < number; i++) {
  if (fscanf (n, "%d", &el) == 1){
   arr[i] = el;
}
  else {printf ("Elements of array are incorrect\n"); return 0;}
}

// Проверяем, состоит ли массив из равных элементов
for (int i = 1; i < number; i++){
  if (arr[i] == arr[0]) count++;
}
// Если да, то выводим массив без изменений 
if (count == number-1) {
  printf ("Elements are equal\n");
  for (int i = 0; i < number; i++) {
     printf ("%d ", arr[i]);
}}

// В противном случае преобразуем каждый элемент массива
else {
 min = min_number(arr, number);
 max = max_number(arr, number);
 for (int i = 0; i < number; i++){
   arr[i] = min +  cel(arr[i], min, max);
   printf ("%d ", arr[i]);
}}

return 0;
}
