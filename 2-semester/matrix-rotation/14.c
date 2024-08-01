#include <stdlib.h>
#include <stdio.h>

int main(void)
{
int c;
int n, m, i, j;
int ** matr;

FILE * in;
in = fopen("data.txt", "r");
if (in == NULL) {
 printf("FILE ERROR\n");
 return 0;
}

if ( fscanf (in, "%d", &m) != 1) {
 printf ("Value mistake \n");
 fclose (in);
 return 0;
}

if ( fscanf (in, "%d", &n) != 1) {
 printf ("Value mistake \n");
 fclose (in);
 return 0;
}

matr = (int **)malloc(m * sizeof(int*));
if ( matr == NULL) {
 printf("Creating failed \n");
 fclose (in);
 return 0;
}

for (i = 0; i < m; ++i) {
 matr[i] = (int * )malloc(n * sizeof(int));
 if ( matr[i] == NULL) {
  printf ("Creating failed \n");
  fclose ( in );
  free (matr);
  return 0;
 }}

for (i = 0; i < m; ++i) {
 for (j = 0; j < n; ++j) {
  if ( fscanf (in, "%d", &matr[i][j]) != 1) {
   printf ("Not enough data \n");
   fclose ( in );
   for (i = 0; i < m; ++i) {
    free (matr[i]);
   }
   free (matr);
   return 0;
  }}}

printf ("Given matrix \n"); // Печатаем исходную матрицу 
for (i = 0; i < m; ++i) {
 for (j = 0; j < n; ++j) {
  printf ("%d ", matr[i][j]);
 }
printf ("\n");
}
printf ("\n");

                            // Переворачиваем матрицу
for (i = 0; i < m/2; i++) {
 for (j = 0; j < n; j++) {
  c = matr[i][j];
  matr [i][j] = matr[m-1-i][j];
  matr[m-1-i][j] = c;
}
}

printf("Transformed matrix \n"); // Печатаем преобразованную матрицу
for (i = 0; i < m; ++i) {
 for (j = 0; j < n; ++j) {
  printf("%d ", matr[i][j]);
}
printf("\n");
}
printf("\n");

return 0;
}
