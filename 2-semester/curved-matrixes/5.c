#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delete(int** matr, int m, int* n,int column);
void delete_string(int**matr, int m,int*n, int s);
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
	char *str, *s;
	FILE *f; 
	int l = 10;
	int i, I, sz, tmp;

if ( sf == NULL ) {
	free(*n);
	*n = NULL;
	for (i = 0; i < (*m); i++)
		free((*matr)[i]);

	free(*matr);
	*matr = NULL;
}

	str = (char*)malloc(l);
	f = fopen(sf, "r");
	if ( f ) {
		for (*m = 0; wfgets (&str,&l,f) != NULL; (*m)++);
		fclose(f);
		if ((*m) == 0) {
			return -2;
		}
	}
	else return -1;

(*matr)=(int**)malloc((*m)*sizeof(int*));
*n=(int*)malloc((*m)*sizeof(int));

f=fopen(sf, "r");
if(f) {
	for(i = 0; wfgets (&str,&l,f) != NULL;i++) {
		for(I = 0; I < 2; I++) {
			for((*n)[i] = 0, s = str; sscanf(s, "%d%n",(I==0?&tmp:(*matr)[i]+(*n)[i]),&sz) == 1; s+=sz,(*n)[i]++);
			if(I == 0){
				(*matr)[i]=((*n)[i]==0?NULL:(int*)malloc((*n)[i]*sizeof(int))); }
			}
	}

fclose(f);
while((*m) > 0 && n[(*m)-1] == 0) (*m)--;
if(*m == 0) 
	return -3;
}

else 
	return -1;
free(str);
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
void delete_string (int ** matr, int m, int *n, int s)     // функция удаляет только одну строку, поэтому для удаления нужно создать
{                                                          // цикл, который каждый раз удаляет строку под найденным номером, тогда 
	int i, j;                                          // удалятся все строки, которые находятся ниже + она
	for ( i = s; i < m; i++) {
		n[i] = n[i+1];
		for (j = 0; j < n[i]; j++) {
			matr[i][j] = matr[i+1][j];
		}
	}
	m = m - 1;
}		
//-----------------------------------------------------------------------------------------------------------------------------------
int matrix_transform (int** matr, int m, int* n) {
	int* sum;
	int p;
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

for (i = 0; i < m; i++) {
	if (i == 0) {	
		for (j = 0; j < n[i]; j++) {
			if (sum[j] == h[j] * matr[i][j]) { 
				delete(matr, m, n, j);
				j = j - 1;
				for (p = j + 1; p < n[i]; p++) {
					sum[p-1] = sum[p];
					h[p-1] = h[p];
				}
			} 		                                                    			
		}
	}
	else {
		for (j = (n[i - 1]); j < n[i]; j++) {
			if ((sum[j]) == (matr[i][j] * h[j])) {
				delete(matr, m, n, j);
				j = j - 1;
				for (p = j + 1; p < n[i]; p++) {
					sum[p-1] = sum[p];
					h[p-1] = h[p];
				}			
			}
		}	
	}
}
			
if (rand == 0) 
	return -1;
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
	int res;

error = matrix_input ("data.dat.txt", &matr, &m, &n);

	if (error == -1) {
		printf("FILE ERROR\n");
		return 0;
	}

	else if (error == -2) {
		printf("Something went wrong\n");
		return 0;
	}

	else if (error == -3) {
		printf ("Empty file\n");
		return 0;
	}

	else if (error == 0) {
		printf("\n Given matrix: \n");
		matrix_output(matr, m, n);

		res = matrix_transform (matr, m, n);

		if ( res == -1 ){
			printf ("\n");
			printf ("\n Transformed matrix: \n");
			matrix_output(matr, m, n);
			matrix_file_output(matr, m, n);
		}
		else printf("fuuu\n");
		
		res = matrix_transform(matr, m, n);
		if (res == -1) {
			printf ("\n");
			printf ("\n Second transformed matrix: \n"); 
			matrix_output (matr, m, n);
			matrix_file_output (matr, m, n);
		}
		else printf ("fuuuu\n");

	}
	matrix_input(NULL, &matr, &m, &n);
	return 0;
}
