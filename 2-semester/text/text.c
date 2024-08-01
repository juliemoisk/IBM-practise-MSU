#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

#define isupper(c) ( (c) >= 'А' && (c) <= 'Z' )

int search (const char *SInputFile, char *word);

int search (const char *SInputFile, char *word) { 
	int length;//длина строки 
	int number = 0; //номер строки
	int length_minimum = 0;//минимальная длина финального слова
	int min;//бегунок минимальной длины
	int l;// длина слова

FILE *in;
char *str = malloc(512);
char between [] = " \t \n"; //символы, которые являются разделителями между словами
char *res;//финальный результат
char *praca;//строка в работе
char ok[] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm"; //символы, которые могут быть в словах
      
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
	if (str[length - 1] == '\n') { //разделяем строки и выводим на экран 
		str[length - 1] = '\0';
	}
	printf ("\n %d string: %s", number, str);
	praca = str;//присваиваем рабочую строку

	if(strcspn(praca,between) == 0) {
		praca += strspn(praca, between);
	}
	
	l = 0;
	min = 0;

	while ((l = strcspn(praca,between))) {
		if(isupper(praca[0])) {
			min = strspn (praca, ok);
			if (l == min) {
				res = praca;
			}
		}
		praca+=strcspn(praca,between);
		praca+=strspn(praca,between); 
	}

	if ((length_minimum == 0) && (min != 0)) {
		length_minimum = min;
		strncpy(word,res,length_minimum);
		word[length_minimum] = '\0';
	}

	if ((length_minimum != 0) && (min < length_minimum)) {
                length_minimum = min;
		strncpy(word,res,length_minimum);
		word[length_minimum] = '\0';
	}
}

if (length_minimum == 0) word[length_minimum] ='\0'; 
					
free(str);
fclose(in);
return 0;
}

int main (void) {
	char *word = malloc (512);
	*word = '\0';
	search ("data.txt", word);
	printf ("\n The shortest word in the text that fits the required conditions is %s\n", word);
return 0;
}
