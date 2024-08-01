#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int search (const char *SInputFile, char *word);

int search(const char* SInputFile, char* word) {

	int length;//длина строки 
	int number = 0; //номер строки
	int length_minimum = 0;//минимальная длина финального слова lmin
	int value;
	int min;//бегунок минимальной длины dp
	int l;// длина слова dl
	int min_value = 0;

FILE *in;
char *str = malloc(512);
char between [] = ". ,"; //символы, которые являются разделителями между словами
char *res;//финальный результат
char *praca;//строка в работе
char ok[] = "0123456789"; //символы, которые могут быть в словах
      
if ( str == NULL ) {
	printf ( "Memory allocation error " );
	return 0;
}
       
in = fopen ( SInputFile, "r" );
if (in == NULL) {
	exit (-1);
}


while (fgets(str, 512, in) != NULL) {

	number++;
	length = strlen(str);
	if (str[length - 1] == '\n') {
		str[length - 1] = '\0';
	}
	printf("%d string: %s \n", number, str);

	praca = str;
	if (strcspn(praca, between) == 0) {
			praca += strspn(praca, between);
	}

	l = 0;
	min = 0;
	value = 0;
	while ((l = strcspn(praca, between))) {
		if (praca[0] == '0') {

			min = strspn(praca, ok);
			if ((min == l) && (value == 0)) {
				value = atoi(praca);
				res = praca;
				length_minimum = min;
			}

			if ((min == l) && (value > atoi(praca))) {
				value = atoi(praca);
				res = praca;
				length_minimum = min;
			}
		}

		praca += strcspn(praca, between);
		praca += strspn(praca, between);

	}

	if ((min_value == 0) && (value != 0)) {
		min_value = value;
		strncpy(word, res, length_minimum);
			word[length_minimum] = '\0';
	}

	if ((min_value > value) && (value != 0)) {
		min_value = value;
		strncpy(word, res, length_minimum);
			word[length_minimum] = '\0';
	}
}
if (length_minimum == 0) {
	word[length_minimum] = '\0';
}
				
free(str);
fclose(in);
return 0;

}

int main(void) {
	char *word = malloc (512);
	*word = '\0';
	search ("data.txt", word);
	printf ("\n The minimum value in the given text is ");
	printf ("%s\n", word);
return 0;
}
