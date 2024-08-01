#include <stdio.h>
#include <stdlib.h>

int main (void) {
int a, b, na = 0, nb = 0, nc = 0, el;

/* а - первый элемент последовательности, na - кол-во элементов, равных ему 
   b - значение первого неравного a элемента поледовательности, nb -//-
   nc - кол-во элементов, которые не равны ни a, ни b
 */

FILE * n = fopen ("data.txt", "r");
    if (n == NULL){
        printf ("Error");
        return 0;
    }
fscanf (n, "%d", &a);
na++;


while (fscanf (n, "%d", &el) == 1) {
  if (el == a) na++;
  if (el != a){
    if (nb == 0){b = el; nb++;}
    else{
      if (el == b) nb++;
      else nc++;
}
}
}
   
if (nc > 0) printf ("no, u can't\n");
if (nc == 0) {
  if (nb <= 1 || na <= 1) printf ("yes, u can\n");
  else printf("no, u can't\n");
}
return 0;

}
