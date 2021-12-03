#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 80

typedef struct
{
  int nPalavras, nCaracteres, nConsoantes, nVogais, nOutros;
} count;

count contagem = {0};

char *Verificar(char *str)
{
	char *pt;
	while (strlen(str) > 0 && (str[strlen(str) - 1] == '\n' ||
		   str[strlen(str) - 1] == ' ' ||
		   str[strlen(str) - 1] == '\t'))
		str[strlen(str) - 1] = '\0';
	pt = (char *)malloc(strlen(str) + 1);
	strcpy(pt, str);
	return pt;
}

void ContagemCVO(char *palavra)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'A' || palavra[i] == 'a' || palavra[i] == 'E' ||
        palavra[i] == 'e' || palavra[i] == 'I' || palavra[i] == 'i' ||
        palavra[i] == 'O' || palavra[i] == 'o' || palavra[i] == 'U' ||
        palavra[i] == 'u')
			contagem.nVogais++;
		else if (palavra[i] == 'B' || palavra[i] == 'b' || palavra[i] == 'C' ||
             palavra[i] == 'c' || palavra[i] == 'D' || palavra[i] == 'd' ||
             palavra[i] == 'F' || palavra[i] == 'f' || palavra[i] == 'G' ||
             palavra[i] == 'g' || palavra[i] == 'H' || palavra[i] == 'h' ||
             palavra[i] == 'J' || palavra[i] == 'j' || palavra[i] == 'K' ||
             palavra[i] == 'k' || palavra[i] == 'L' || palavra[i] == 'l' ||
             palavra[i] == 'M' || palavra[i] == 'm' || palavra[i] == 'N' ||
             palavra[i] == 'n' || palavra[i] == 'P' || palavra[i] == 'p' ||
             palavra[i] == 'Q' || palavra[i] == 'q' || palavra[i] == 'R' ||
             palavra[i] == 'r' || palavra[i] == 'S' || palavra[i] == 's' ||
             palavra[i] == 'T' || palavra[i] == 't' || palavra[i] == 'V' ||
             palavra[i] == 'v' || palavra[i] == 'W' || palavra[i] == 'w' ||
             palavra[i] == 'X' || palavra[i] == 'x' || palavra[i] == 'Y' ||
             palavra[i] == 'y' || palavra[i] == 'Z' || palavra[i] == 'z')
				contagem.nConsoantes++;
		else
			contagem.nOutros++;
	}
}

int main()
{
	char str[MAXSTR], *palavra;
		
	while (fgets(str, MAXSTR, stdin) != NULL) {
		palavra = Verificar(str);
		if (strlen(palavra) == 0)
			break;
		contagem.nPalavras++;
		contagem.nCaracteres += strlen(palavra);
		ContagemCVO(palavra);
		free(palavra);
	}
	
	printf("%d %d %d %d\n",
		   contagem.nPalavras,
		   contagem.nCaracteres,
		   contagem.nConsoantes,
		   contagem.nVogais);
}