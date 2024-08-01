#include <stdio.h>

int main(void)
{
    int count, el, a1, k, min;

    FILE * n = fopen ("data.txt", "r");
    count = 0;
    if (n == NULL){
        printf ("Что-то пошло не так");
        return 0;
    }

    k = fscanf (n, "%d", &a1);
    if (k == 1) { min = a1; count = 1;}
    else {printf ("Недостаточно данных\n");return 0;}


    while (fscanf (n, "%d", &el) == 1) {
          if ( el == min) {count++;}
          if ( el < min) {min = el; count = 1;}

    }
   
   fclose(n);

   printf ("Количество элементов последовательности, удовлетворяющих условию = %d\n", count);

    return 0;
}
