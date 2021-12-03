#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 80

char *Verificar(char *str)
{
	char *pt;
	str = strtok(str," \t\n\r");
	pt = (char*)malloc(strlen(str) + 1);
	strcpy(pt, str);
	return pt;
}

int main()
{
	char *palavra, str[MAXSTR];
	fgets(str, MAXSTR, stdin);
	palavra = Verificar(str);
	printf("%d\n", (int)strlen(palavra));
	free(palavra);
}