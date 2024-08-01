#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delete(int** matr, int m, int* n,int column);
int delete_string(int**matr, int m,int*n, int s);
int matrix_output (int** matr, int m, int* n);
int matrix_file_output (int** matr, int m, int* n);
char *wfgets (char **str, int *l, FILE *f);
int matrix_input (const char *sf, int ***matr, int *m, int **n);
int matrix_transform (int** matr, int m, int* n);

char *wfgets (char **str, int *l, FILE *f){
	char s[256];
	if ( fgets (*str, *l, f) == NULL) return NULL;
	while (( strlen(*str) == (size_t)(*l)-1) && (*str)[(*l)-2]!='\n'){ 
		if( fgets(s, sizeof(s), f) != NULL) {
			*str=(char*)realloc(*str,(*l)+sizeof(s)-1);
			strcat (*str,s);
			(*l) = (*l)+sizeof(s)-1;}
	else break;
}
return *str;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int matrix_input (const char *sf, int ***matr, int *m, int **n) {
	int i, j, elem, tmp;//i - строки, j - столбцы
FILE * in;
in = fopen (sf, "r");

if (in != NULL) {
  if (fscanf (in, "%d", &*m) != 1) {  //m - строки
    fclose(in);
    return -2; 
  }
  for (i = 0; i < *m; i++) {
  	if (fscanf (in, "%d", &tmp) != 1) {  //n - столбцы
    	fclose(in);
    	return -2;
  	}
	*n[i] = tmp; printf ("%d ", *n[i]);
  }

/*  if ((*n)==0 || (*m)==0) {
    fclose(in);
    return -3;
  }
*/
  *matr = (int**)malloc((*m) * sizeof(int*));
     if (*matr == NULL) {
       fclose(in);
       return -3;
     }

  for (i = 0; i < *m; ++i) {
    (*matr)[i] = (int*)malloc((*n[i]) * sizeof(int));
      if ((*matr)[i] == NULL) {
        fclose(in);
        free(*matr);
        return -3;
      }
  }

  for (i = 0; i < *m; ++i)
    for (j = 0; j < *n[i]; ++j) {
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
//-----------------------------------------------------------------------------------------------------------------------------------
void delete(int** matr, int m, int* n, int column) {
	int i;
	for (i = 0; i < m; i++) {
		if (column < n[i]) {
			if (column == n[i] - 1)
				n[i] = n[i] - 1;
			else {
				memmove(matr[i] + column, matr[i] + column + 1, (n[i] - column - 1) * sizeof(int));
				n[i] = n[i] - 1;
			}
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------------------
int delete_string (int ** matr, int m, int *n, int s)
{
	int i, j;
	for ( i = s; i < m ; i++) {
		if ( i == m - 1) {
			m = m - 1;
		}
		else {  
			n[i] = n[i+1];
			for ( j = 0; j < n[i]; j++){
				matr[i][j] = matr[i+1][j];
			}
		}
	}
return m;
}		
//-----------------------------------------------------------------------------------------------------------------------------------
int matrix_transform (int** matr, int m, int* n) {
	int* sum;
	int count;
	int rand = 0; // чтобы не было функции void
	int maximum = 0;
	int i, j;
	int* h = NULL; 
															
maximum = n[0];

for (int i = 0; i < m ; i++) { //находим максимальную длину строки
    if (n[i] > maximum) {
       maximum  = n[i];
    }
}

h = (int*)malloc(m*sizeof(int)); //массив из кол-ва элементов в столбцах
sum = (int*)malloc(maximum*sizeof(int)); //массив на сумму элементов по столбцам

for (j = 0; j < maximum; j++) {//заполняем массив нулями, чтобы не было мусора
	h[j] = 0;
}

for(j = 0; j < maximum; j++) {
	sum[j] = 0;
}

for (i = 0; i < m; i++) {  //находим кол-во элементов в каждом столбце
	for (j = 0; j < n[i]; j++) {
		h[j]+=1;
	}
}

for ( i = 0; i < m; i++) { //находим сумму по каждому столбцу
	for (j = 0; j <n[i]; j++){
		sum[j]+=matr[i][j];
	}
}
d:
for (i = 0; i < m; i++) {		                                                    
	count = 0;
	for (j = 0; j < n[i]; j++) {
		if (sum[j] == h[j]*matr[i][j]) {
			count++;
		}
	}
	if (count == n[i] ) {
		m = delete_string(matr,m,n,i);
		goto d;
	}
}
			
if (rand == 0) 
	return m;
else 
	return 0;

free(sum);
free(h);
}			
//-----------------------------------------------------------------------------------------------------------------------------------
int matrix_output (int** matr, int m, int* n) {
	int i, j;
 	for (i = 0; i < m; i++) {
  		printf("\n");
  		for (j = 0; j < n[i]; j++) {
    			printf("%d ", matr[i][j]);
		}
	}
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int matrix_file_output (int** matr, int m, int* n) {
	int i, j;
	FILE* in;
	in = fopen ("data.res.txt", "w");
	for (i = 0; i < m; i++) {
  		for (j = 0; j < n[i]; j++){
    			fprintf(in, "%d ", matr[i][j]);
  		}
    	fprintf (in, "\n");
 	}
fclose(in);
return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------
int main (void) {

	int **matr = NULL;
	int m, *n = NULL;
	int error = 0;
//	int res;

error = matrix_input ("data.dat.txt", &matr, &m, &n);

	if (error == -1) {
		printf("FILE ERROR\n");
		return 0;
	}

	else if (error == -2) {
		printf("Not enough data\n");
		return 0;
	}

	else if (error == -3) {
		printf ("The given value is wrong\n");
		return 0;
	}
	
	else if (error == -4) {
		printf ("Memory error\n");
		return 0;
	}

	else if (error == 0) {
		printf("\n Given matrix: \n");
		matrix_output(matr, m, n);

		m = matrix_transform (matr, m, n);

			printf ("\n");
			printf ("\n Transformed matrix: \n");
			matrix_output(matr, m, n);
			matrix_file_output(matr, m, n);
		
		m = matrix_transform(matr, m, n);
			printf ("\n");
			printf ("\n Second transformed matrix: \n"); 
			matrix_output (matr, m, n);
			matrix_file_output (matr, m, n);

	}
	matrix_input(NULL, &matr, &m, &n);
	return 0;
}
