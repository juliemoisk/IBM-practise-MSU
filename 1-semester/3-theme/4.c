#include <stdio.h>
#include <stdlib.h>

void bit (int n);//Функция, которая выписывает биты числа и считает четность количества единиц в машинном представлении числа
void reverse (int*arr, int size);//Функция, которая переставляет элементы массива в обратном порядке

void reverse (int*arr, int size) {
 int i , c;
 for (i = 0; i < size/2; i++) {
  c = arr[i]; 
  arr[i] = arr[size - 1 - i];
  arr[size-1-i] = c;
}}

void bit (int n) {
 int size = sizeof(n)*8;
 int count = 0;//Для подсчета кол-ва единиц
 int *arr;

 arr = (int*)malloc(size*sizeof(int)); // Создаем массив, в который будем записывать биты нашего числа 
 for (int i = 0; i < size; i++){ // В цикле одновременно записываем биты в массив и считаем количество единиц
   if ((n & 1) == 1){arr[i] = 1; count++;}
   else arr[i] = 0;
   n >>= 1;
}
 reverse (arr, size); //Записываем массив в обратном порядке 

 if (count % 2 == 0) printf ("Even\n"); // Проверяем четность количества единиц и выводит ответ
 else printf ("Odd\n");
 
 for (int i = 0; i < size; i++) // Выводим число в машинном представлении на экран
  printf ("%d ", arr[i]);
}

int main (void) {
 int n;

 printf ("Plese enter your number\n"); // Запрашиваем число, для которого должна быть выполнена программа 
 scanf ("%d", &n);

 bit (n); // Выводим его биты
 return 0;
}
