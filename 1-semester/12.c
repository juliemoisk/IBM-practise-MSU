#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int count=0, find = 0, a1, a2;
    int *arr;
    FILE *n = fopen("data.txt", "r");
 if (n == NULL){
        printf ("File error");
        return 0;
    }

        fscanf(n, "%d", &count);
        arr = (int*)malloc(count * sizeof(int));

        for(int i=0; i<count; i++)
            fscanf(n, "%d", &arr[i]);
        fclose(n);
a1 = arr[0];
a2 = arr[1];

// Проверяем, какие равны 1 или 2 элементу массива 

for (int i = 0; i < count; i++){
if (arr[i] == a1 || arr[i] ==a2) find = i + 1;//Отсчет элементов последовательности идет с первого
} 

if (find == 0) printf ("Not enough data\n");
else printf ("Number  = %d\n", find);

return 0;
}
