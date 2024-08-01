#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int matrix_input_create (const char* sf, int*** matr, int* m, int* n);//функция, которая считывает данные из файла и создает матрицу
int matrix_transform (int*** matr, int* m, int* n);//функция, которая преобразует матрицу
void matrix_output (int**matr, int m, int n);//вывод матрицы


int matrix_input_create (const char* sf, int*** matr, int* m, int* n) {
int i, j, elem;//i - строки, j - столбцы
FILE * in;
in = fopen (sf, "r");

if (in != NULL) {
  if (fscanf (in, "%d", &*m) != 1) {  //m - строки
    fclose(in);
    return -2; 
  }
  if (fscanf (in, "%d", &*n) != 1) {  //n - столбцы
    fclose(in);
    return -2;
  }

  if ((*n)==0 || (*m)==0) {
    fclose(in);
    return -3;
  }

  *matr = (int**)malloc((*m) * sizeof(int*));
     if (*matr == NULL) {
       fclose(in);
       return -3;
     }

  for (i = 0; i < *m; ++i) {
    (*matr)[i] = (int*)malloc((*n) * sizeof(int));
      if ((*matr)[i] == NULL) {
        fclose(in);
        free(*matr);
        return -3;
      }
  }

  for (i = 0; i < *m; ++i)
    for (j = 0; j < *n; ++j) {
      if ( fscanf (in, "%d", &elem) != 1) {
        fclose (in);
        for (i = 0; i < *m; ++i) { 
          free (*matr[i]);
        }
        free (*matr);
        return -4;
      }
      (*matr)[i][j] = elem;
   }}

else {
  return -1;
}

return 0;
}

int matrix_transform (int*** matr, int* m, int* n) {
 
int i, j, column, max, count, elem;
count = 0;
elem = 0;
column = 0;
max = (*matr)[0][0];

//Ищем максимальный элемент в первой (нулевой) строке
for (j = 0; j < *n; ++j) { 
  if ((*matr)[0][j] > max) {
    max = (*matr)[0][j];
    column = j;
  }
}
//Считаем сколько элементов в данной строке равны максимальному
for (j = 0; j < *n; ++j) {
 if ((*matr)[0][j] == max) {
   count++;
}}

//Если таких несколько, то говорим, что требуемого столбца нет
if (count > 1) {
 return -1;
}
//Далее проверяем на макисмальность только элемент того столбца, элемент которого был макисмален для 1 строки
for (i = 1; i < *m; i++){
  max = (*matr)[i][column];
  for (j = 0; j < *n; j++) {
    if ((*matr)[i][j] > max) {
      return -1;
    }
    if (j != column && (*matr)[i][j] == max) {
      return -1;
    }
   }
 }

//Если такой столбец найден, удаляем его

for (i = 0; i < *m; ++i)
  for (j = column+1; j < *n; ++j) { 
    elem = (*matr)[i][j-1];
    (*matr)[i][j-1] = (*matr)[i][j];
    (*matr)[i][j] = elem;
}
*n-=1;
return 0;     
}

void matrix_output (int** matr, int m, int n) { // вывод происходит и на экран, и в файл 

int i, j;
FILE* in = fopen ("data.res.txt","a");

fprintf (in, "matrix: \n");

for (i = 0; i < m; ++i) {
 for (j = 0; j < n; ++j) {
   printf(" %d", matr[i][j]);
   fprintf (in, " %d", matr[i][j]);
 } 
 printf("\n");
 fprintf(in,"\n"); 
}
} 

int main (void) {

int i, m, n, error, res1, res2;
int** matr = NULL;

error = matrix_input_create ("data.txt",  &matr, &m, &n);

//в зависимости от данных в файле выводим тип ошибки
switch (error) {
  case -1:
    printf ("File does not exist\n");
    return 0;
  case -2:
    printf ("FILE ERROR\n");
    return 0;
  case -3:
    printf ("Creating failed\n");
    return 0;
  case -4:
    printf ("Not enough data\n");
    return 0;
  default:   // Если все хорошо, то продолжаем работу
    printf("Given matrix: \n");
    matrix_output (matr, m, n); //выводим исходную матрицу
    printf("\n");

    res1 = matrix_transform (&matr, &m, &n); //преобразуем матрицу и выводим один из случаев, описанных ниже
   
    switch (res1) {
      case -1:
        printf ("No such column has been found, so matrix hasn't changed\n");
        break;
      default:
        printf ("Transformed matrix:\n");
        break; 
    }
    matrix_output (matr, m, n); //выводим преобразованную или неизмененную матрицу
    printf ("\n");

    printf ("Matrix check:\n");
    res2 = matrix_transform (&matr, &m, &n);// проделываем то же самое второй раз 
   
    switch (res2) {
      case -1:
        printf ("No such column has been found, so matrix hasn't changed\n");
        break;
      default:
        printf ("Second transformed matrix:\n");
        break;
    }
    matrix_output (matr, m, n);
}


for (i = 0; i < m; ++i) {
  free(matr[i]);
}
free(matr);
return 0;
}
