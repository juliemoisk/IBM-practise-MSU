#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
int k; //пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ-пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅ
int m = 0; //пїЅпїЅпїЅ-пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅ
int counter = 0;//пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅ, пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ
int count = 0; //пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ 
int i;

FILE *in;
char *str = malloc(256);
    
if ( str == NULL ) {
  printf ( "MEMORY ERROR 1" );
  return 0;
}
    
in = fopen ( "data.txt", "r" );
if (in == NULL) {
  printf( "FILE ERROR" );
  return 0;
}


while ( fgets (str, 256, in) != NULL ){
  k = strlen(str);}
  if (k == 0) {
     printf("The file is empty");
     return 0;
  }

for (i = 0; i < k; ++i){
 if (str[i] == ' '){ m++; }
}
printf("%d", m);   
str = (char*)realloc(str, k + m);
if (str == NULL){
  printf("MEMORY ERROR 2");
  return 0;
}


for (i = 0; i <= k; i++) {
   if ((str[i] != ' ') && (str[i] !='\0')) {
    count++;
   }
   if ((str[i] == ' ') || (str[i] == '\0')||((str[i] >= '0') && (str[i] <= '9')) ) { //пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ
       if ((str[i-1] != ' ') && (str[i-1] != 0) && (str[i-1] != 1) && (str[i-1] != 2) && (str[i-1] != 3) && (str[i-1] != 4) && (str[i-1] != 5) && (str[i-1] != 6) && (str[i-1] != 7) && (str[i-1] != 8) && (str[i-1] != 9)){      
          if (str[i-1] == str[i-count]) {
            counter ++;
          }
      }

     count = 0;
}}

//пїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅ пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ, пїЅпїЅ пїЅпїЅпїЅпїЅ L пїЅ l - пїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅ

printf ("Given data:\n");  
printf ("%s \n", str); printf ("\n");
printf ("The amount of words required: ");   
printf ("%d", counter);

free(str);
fclose(in);
return 0;
}


