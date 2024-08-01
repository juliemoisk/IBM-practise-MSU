#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int input(const char* sf, int*** matrix, int* m, int** n);
char* wfgets(char** str, int* l, FILE* in);
void Decision(int** matrix, int m, int* n);
void del(int** matrix, int m, int* n, int l, int h);
int output(int** matrix, int m, int* n);
int outputf(int** matrix, int m, int* n);



char* wfgets(char** str, int* l, FILE* in) {
	char s[3];
	if (fgets(*str, *l, in) == NULL)												
		return NULL;

	while ((strlen(*str) == (size_t)(*l) - 1) && (*str)[(*l) - 2] != '\n') {		
		if (fgets(s, sizeof(s), in) != NULL) {									
			*str = (char*)realloc(*str, (*l) + sizeof(s) - 1);						
			strcat(*str, s);														
			(*l) = (*l) + sizeof(s) - 1;										
		}
		else
			break;
	}
	return *str;
}


int input(const char* sf, int*** matrix, int* m, int** n) {
	int sz, tmp, i, ogr;																										
	char* str, * s;
	int l = 5;
	FILE* in;

	if (sf == NULL) {
		free(*n);
		*n = NULL;
		for (i = 0; i < (*m); i++)
			free((*matrix)[i]);

		free(*matrix);
		*matrix = NULL;
	}

	str = (char*)malloc(l);
	in = fopen(sf, "r");
	if (in) {
		for (*m = 0; wfgets(&str, &l, in) != NULL; (*m)++);																			

		fclose(in);
		if ((*m) == 0) {																												
			return -2;
		}
	}
	else
		return -1;

	(*matrix) = (int**)malloc((*m) * sizeof(int*));																						
	(*n) = (int*)malloc((*m) * sizeof(int));																							

	in = fopen(sf, "r");
	if (in) {
	i = 0;
	d:;

	while ((wfgets(&str, &l, in) != NULL) && (*m > 0)) {
		if (*str == '\n') {																												
			(*m)--;
			goto d;
		}

		for (ogr = 0; ogr < 2; ogr++) {																									
			for ((*n)[i] = 0, s = str; sscanf(s, "%d%n", (ogr == 0 ? &tmp : ((*matrix)[i] + (*n)[i])), &sz) == 1; s += sz, (*n)[i]++);	

			if ((*n)[i] == 0) {
				(*m)--;
				goto d;
			}

			if (ogr == 0) {
				(*matrix)[i] = NULL;
				(*matrix)[i] = ((*n)[i] == 0 ? NULL : (int*)malloc((int)((*n)[i]) * sizeof(int)));										
			}
		}
		i++;
	}
	fclose(in);

	printf("\n");
	while ((*m) > 0 && (*n)[(*m) - 1] == 0)																								
		(*m)--;

	if (*m == 0)
		return -3;
	}
	else
		return -1;
	free(str);
	return 0;
}

void del(int** matrix, int m, int* n, int l, int h) {
	int i;
	for (i = l; i < m; i++) {
		if (h < n[i]) {
			if (h == n[i] - 1)
				n[i] = n[i] - 1;
			else {
				memmove(matrix[i] + h, matrix[i] + h + 1, (n[i] - h - 1) * sizeof(int));
				n[i] = n[i] - 1;
			}
		}
	}
}

void Decision(int** matrix, int m, int* n) {
	int* sum;
	int s = 0, p = 1;
	int* h = NULL;
	int l, i, j, x;

	h = (int*)malloc(m * sizeof(int));										
	sum = (int*)malloc(m * sizeof(int));									
	memcpy(h, n, (m * sizeof(int)));

	for (i = 0; i < m; i++) {												
		s = 0;
		for (j = 0; j < n[i]; j++)
			s = s + matrix[i][j];
		sum[i] = s;
	}

	for (i = 0; i < m; i++) {
		if (i == 0) {
			for (j = 0; j < n[i]; j++) {
				s = 0;
				if ((sum[i]) == (matrix[i][j] * h[i])) {
					s = 1;
					p = 1;
					l = i;

					for (x = i + 1; x < m; x++) {
						if (j < n[x]) {
							p++;
							if (sum[x] == (matrix[x][j] * h[x]))
								s++;
						}
					}
					if (s == p) {
						del(matrix, m, n, l, j);
						j = j - 1;
					}
				}
			}
		}
		else {
			for (j = (n[i - 1]); j < n[i]; j++) {
				s = 0;
				if ((sum[i]) == (matrix[i][j] * h[i])) {
					s = 1;
					p = 1;
					l = i;
					for (x = i + 1; x < m; x++) {
						if (j < n[x]) {
							p++;
							if (sum[x] == (matrix[x][j] * h[x]))
								s++;
						}
					}
					if (s == p) {
						del(matrix, m, n, l, j);
						j = j - 1;
					}
				}
			}
		}
	}
	free(sum);
	free(h);
}

int output(int** matrix, int m, int* n) {
	int i, j;
	for (i = 0; i < m; i++, printf("\n"))
		for (j = 0; j < n[i]; j++)
			printf("%d ", matrix[i][j]);
	return 0;
}

int outputf(int** matrix, int m, int* n) {
	int i, j;
	FILE* in;
	in = fopen("data.res.txt", "w");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n[i]; j++)
			fprintf(in, "%d ", matrix[i][j]);
		fprintf(in, "\n");
	}
	fclose(in);
	return 0;
}

int main(void) {
	int** matrix = NULL, err = 0;
	int m, *n = NULL;
	err = input("data.dat.txt", &matrix, &m, &n);

	if (err == -1) {
		printf("I cannot open this File!!! \n");
		return 0;
	}

	else if (err == -2) {
		printf("I cannot find first number!!! \n");
		return 0;
	}

	else if (err == -3) {
		printf ("There is no data. Just an empty string!!! \n");
		return 0;
	}

	else if (err == 0) {
		printf("\n Original Matrix: \n");
		output(matrix, m, n);

		Decision(matrix, m, n);
		printf("\n Result Matrix: \n");
		output(matrix, m, n);
		outputf(matrix, m, n);
	}
	input(NULL, &matrix, &m, &n);
	return 0;
}
