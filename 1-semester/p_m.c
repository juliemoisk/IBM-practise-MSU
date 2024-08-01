#include <stdio.h>
#include <stdlib.h>

int plus(int * X, int b);
int minus(int * X, int b);

int main(void)
{
 FILE * t;
 int *X, *Y;
 int a = 2, b = 1;

 t = fopen("data.txt", "r");
 if (t == NULL)
 {
  printf("Error");
  return 1;
 }
 X = (int*) malloc (a * sizeof(int));
 if (X == NULL)
 {
  printf("Error");
  return 1;
 }
 X[0] = 0;
 while (fscanf(t, "%d", &X[b]) == 1)
 {
  if (X[b] > 9)
  {
   printf("Error");
   return 1;
  }
  b += 1;
  if (b >= a)
  {
   a = a * 2;
   Y = (int *) realloc (X, a * sizeof(int));
   X = Y;
  }
 } 
 plus(X, b);
 minus(X, b);  
 free(X);
 free(Y);
 fclose(t);
 return 0;
}


int plus(int * X, int b)
{
 const int H = b;
 int A [H];
 int j, p, res_plus = 0;

 for (j = 0; j < b; ++j )
 {
  A[j] = X[j];
 }
 
 for (j = 0; j < b/2; ++j )
 {
  p = A[j];
  A[j] = A[b - 1 -j];
  A[b - 1 - j] = p;
 }
 
  if (A[0] < 9)
  {
   A[0] += 1;
  }
  else
  {
   A[0] = 0;
   for (j = 0; j < b; ++j )
   {
    if (A[j]==0)
    {
     if (A[j + 1] < 9)
     {
      A[j + 1] += 1;
     }
     else
     {
      A[j + 1] = 0;
     }
    }
   }
  }

 for (j = 0; j < b/2; ++j )
 {
  p = A[j];
  A[j] = A[b - 1 -j];
  A[b - 1 - j] = p;
 }
 
 for (j = 0; j < b; ++j )
 {
  res_plus = res_plus * 10 + A[j];
 }
 printf("NUmber which is bigger: %d \n", res_plus);
 return 0;
}

int minus(int * X, int b)
{
 const int H = b;
 int B [H];
 int j, p, res_minus = 0;
 for (j = 0; j < b; ++j )
 {
  B[j] = X[j];
 }
 for (j = 0; j < b/2; ++j )
 {
  p = B[j];
  B[j] = B[b - 1 - j];
  B[b - 1 - j] = p;
 }

 if (B[0] > 0)
  {
   B[0] -= 1;
  }
  else
  {
   B[0] = 9;
   for (j = 0; j < b; ++j )
   {
    if (B[j]==9)
    {
     if (B[j + 1] > 0)
     {
      B[j + 1] -= 1;
     }
     else
     {
      B[j + 1] = 9;
     }
    }
   }
  }


 for (j = 0; j < b/2; ++j )
 {
  p = B[j];
  B[j] = B[b - 1 -j];
  B[b - 1 - j] = p;
 }

 
 for (j = 0; j < b; ++j )
 {
  res_minus = res_minus*10 + B[j];
 }
 printf("Number which is smaller: %d \n", res_minus);
 return 0;
}
