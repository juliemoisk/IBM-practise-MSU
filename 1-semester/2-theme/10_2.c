#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void func (int n, int *arr); // Фуекция, которая выводит коэффициенты для степени N

void func (int n, int *arr) {
 
 arr[0] = 1; // Задаем значение первого элемента массива 

 for (int i = 1; i <= n ; i++) {   // Говорим, что все остальные пока нули
   arr[i] = 0;
}

 for (int j = 1 ; j <= n; j++) {   // Вычисляем последовательно строки треугольника Паскаля
    for (int i = j; i >= 1 ; i--) {
        arr[i] = arr[i-1] + arr[i];
}
}
    for (int i = 0; i <= n ; i++)  // Выводим на экран
       printf ("%d ", arr[i]);
}

int main (void) {

 int n;
 int *arr;

// Запрашиваем степень N и задаем размер массива

printf ("Please, enter your number\n");

if (scanf ("%d", &n) == 1) { // Проверяем корректность scanf
 if (malloc(n * sizeof(int)) != NULL){  // Проверяем корректность выделения памяти 
  arr = (int*)malloc((n+1) * sizeof(int)); // Выделяем память для (n+1) коэффициентов массива 
}
 else {printf ("Memory error\n"); return 0;}
}
else {printf ("Your number is incorrect\n"); return 0;}
  
func (n,arr);  

  return 0;
}
