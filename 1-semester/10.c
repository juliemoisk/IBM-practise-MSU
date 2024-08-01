
#include <stdio.h>

int main(void)
{
    int count, k, a1, a2, max, min, el;

    FILE * n = fopen ("data.txt", "r");
    count = 0;
    if (n == NULL){
        printf ("Что-то пошло не так");
        return 0;
    }

    k = fscanf(n, "%d%d", &a1, &a2);

    if (k == 2){
      if (a1 > a2) {
        max = a1;
        min = a2;
      }
      else {
        max = a2;
        min = a1;
      }
    } else {
        printf ("Недостаточно данных\n");
        return 0;
    }

    while (fscanf (n, "%d", &el) == 1) {
      if (el < max && el > min) {count++;}
   }
   
   fclose(n);

   printf ("Количество элементов последовательности, удовлетворяющих условию = %d\n", count);
   

    return 0;
}
                                   
