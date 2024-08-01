#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void delete(int** matr, int m, int* n, int s, int column);
int delete_string(int**matr, int m, int *n, int s);
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
void delete(int** matr, int m, int* n, int s, int column) {
	int i;
	for (i = s; i < m; i++) {
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
	int s;
	int count;
	int count_string;
	int k;
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

for (j = 0; j < maximum; j++) {//заполняем массив нулями, чтобы не было мусора
	h[j] = 0;
}

for (i = 0; i < m; i++) {  //находим кол-во элементов в каждом столбце
	for (j = 0; j < n[i]; j++) {
		h[j]+=1;
	}
}
d:
for (i  = 0; i < m; i++ ){
	count_string = 0;
	for (j = 0; j < n[i]; j++) {
		count = 0;
		for (k = 0; k < h[j]; k++ ){
			if (k != i) {
				if (matr[i][j] > matr[k][j]) {
					count++;
				}
			}
		} 
		if (count == h[j] - 1) {
			count_string++;
		}
	}
	if (count_string == n[i]) {
		s = i;
		m = delete_string(matr,m,n,s); 
		goto d;//если я хочу удалить все такие строки вне зависимости от порядка (то есть я начинаю отсчет с начала матрицы)	
	}
}
				
if (rand == 0) 
	return m;
else 
	return 0;

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
