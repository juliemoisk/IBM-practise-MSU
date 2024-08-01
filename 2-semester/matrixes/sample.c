#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//функцию вызываю дважды

//распечатка идет в том же файле, откуда и беретсЯ исходнаЯ матрица

/*закомментил фрагмент в промежуточном варианте между вызовами функции_2,
чтобы можно было посмотреть, как поменЯлась матрица*/

void fu_1 (int ***a, int *m, int *n){
    FILE *in;
    in = fopen("data.txt", "r");
    if(fscanf(in, "%d", n) != 1){
        printf("NO_scale_1");
        exit(-200);
    }
    if(fscanf(in, "%d", m) != 1){
        printf("NO_scale_2");
        exit(-201);
    }
    if(*m <= 0){
        printf("Wrong size_1");
        exit(-202);
    }
    if(*n <= 0){
        printf("Wrong size_1");
        exit(-203);
    }
    *a = (int**)malloc((*m) * sizeof(int*));
    for (int i = 0; i < *m; ++i)
        (*a)[i] = (int*)malloc((*n) * sizeof(int));
    for (int i = 0; i < *n; ++i) {
        for (int j = 0; j < *m; ++j) {
            if (fscanf(in, "%d", &((*a)[j][i])) != 1){
                printf("Not enough numbers");
                exit(-1);
            }
        }
    }
    fclose(in);
}

void fu_2(int ***a, int *m, int *n){
    int k = 0;
    for (int i = 0; i < *m; ++i){
        for(int j = 0; j < *n; ++j){
            k += (*a)[i][j];
        }
    }
    k /= (*m) * (*n);
    for (int i = 0; i < *m; ++i){
        for(int j = 0; j < *n; ++j){
            if((*a)[i][j] == k) {
                free((*a)[i]);
                for (int q = i; q < *m - 1; ++q) {
                        (*a)[q] = (*a)[q + 1];
                }
                --(*m);
                realloc(*a, (*m) * sizeof(int*));
                return;
           }
        }
    }
}


void fu_3 (int **a, const int m, const int n){
    FILE *out;
    out = fopen("data.txt", "w");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            fprintf(out, "%d ", a[j][i]);
        }
        fprintf(out, "\n");
    }
    for(int i = 0; i < m; ++i){
        free(a[i]);
    }
    free(a);
    fclose(out);
}




int main(void)
{
    int n = 0, m = 0;
    int **a = NULL;
    fu_1(&a, &m, &n);
    fu_2(&a, &m, &n);
    /*for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    */
    fu_2(&a, &m, &n);
    fu_3(a, m, n);
    return 0;
}
