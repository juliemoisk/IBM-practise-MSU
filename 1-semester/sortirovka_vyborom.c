#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) 
{
  int m=4, k=0, a, i, min, j, b;
  int *X, *tmp;
  FILE *n;
  n = fopen("data.txt", "r");
  if (n == NULL)
  {
    printf("Ошибка.\n");
    return 0;
  }
  X = (int *)malloc(m*sizeof(int));
  if (X == NULL)
  {
    printf("Ошибка.\n");
    fclose(n);
    return 0;
  }
  if (fscanf(n, "%d", &a) != 1)
  {
    printf("Ошибка.\n");
    fclose(n);
    free(X);
    return 0;
  }
  else
  {
    X[k]=a;
    while (fscanf(n, "%d", &a) == 1)
    {
      if (k+1 == m)
      {
        m = m+4;
        tmp = (int*)realloc(X, m*sizeof(int));
        if (tmp == NULL)
        {
          printf("Ошибка.");
          free(X);
          fclose(n);
          return 0;
        }
        else
        {
          X = tmp;
        }
      }
      ++k;
      X[k]=a;
    }
  }
  

  for (i=0; i<k; i++)
  {
    a=0;
    min = X[i];
    for (j=i+1; j<=k; j++)
    {
      if (X[j]<min)
      {
        min = X[j];
        a = j;
      }
    }
    if (a!=0)
    {
      b = X[i];
      X[i] = X[a];
      X[a] = b;
    }
  }


  for (i=0; i<=k; i++)
  {
    printf("%d ", X[i]);
  }


  fclose(n);
  free(X);
  return 0;
}
