#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 80

typedef struct
{
  int nPalavras, nCaracteres, nConsoantes, nVogais, nOutros, nCDistintas, nVDistintas;
} count;
count contagem={0};

typedef struct SLista
{
	char *palavra;
	struct SLista *seg;
}Lista;

typedef struct
{
	int A,E,I,O,U;
}Vogais;
Vogais vogais={0};

typedef struct
{
	int B,C,D,F,G,H,J,K,L,M,N,P,Q,R,S,T,V,W,X,Y,Z;
}Consoantes;
Consoantes consoantes={0};

Lista *Adiciona(Lista *lista, char *palavra)
{
	Lista *elemento = (Lista*)malloc(sizeof(Lista));
	if(elemento != NULL)
	{
		elemento->palavra = palavra;
		elemento->seg = lista;
	}
	return elemento;
}

Lista *Remove(Lista *lista)
{
	Lista *aux;
	if(lista != NULL)
	{
		aux = lista->seg;
		free(lista);
		return aux;
	}
	return NULL;
}

int Comparar(Lista *lista, char *palavra)
{
	Lista *aux = lista;

	while(aux != NULL){
		if(strcmp(aux->palavra, palavra) == 0)
			return 1;
		aux = aux->seg;
	}
	return 0;
}

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

void VogaisDistintas(char *palavra)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'A' || palavra[i] == 'a')
			vogais.A=1;
		if (palavra[i] == 'E' || palavra[i] == 'e')
			vogais.E=1;
		if (palavra[i] == 'I' || palavra[i] == 'i')
			vogais.I=1;
		if (palavra[i] == 'O' || palavra[i] == 'o')
			vogais.O=1;
		if (palavra[i] == 'U' || palavra[i] == 'u')
			vogais.U=1;
	}
}

void ConsoantesDistintas(char *palavra)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'B' || palavra[i] == 'b')
			consoantes.B=1;
		if (palavra[i] == 'C' || palavra[i] == 'c')
			consoantes.C=1;
		if (palavra[i] == 'D' || palavra[i] == 'd')
			consoantes.D=1;
		if (palavra[i] == 'F' || palavra[i] == 'f')
			consoantes.F=1;
		if (palavra[i] == 'G' || palavra[i] == 'g')
			consoantes.G=1;
		if (palavra[i] == 'H' || palavra[i] == 'h')
			consoantes.H=1;
		if (palavra[i] == 'J' || palavra[i] == 'j')
			consoantes.J=1;
		if (palavra[i] == 'K' || palavra[i] == 'k')
			consoantes.K=1;
		if (palavra[i] == 'L' || palavra[i] == 'l')
			consoantes.L=1;
		if (palavra[i] == 'M' || palavra[i] == 'm')
			consoantes.M=1;
		if (palavra[i] == 'N' || palavra[i] == 'n')
			consoantes.N=1;
		if (palavra[i] == 'P' || palavra[i] == 'p')
			consoantes.P=1;
		if (palavra[i] == 'Q' || palavra[i] == 'q')
			consoantes.Q=1;
		if (palavra[i] == 'R' || palavra[i] == 'r')
			consoantes.R=1;
		if (palavra[i] == 'S' || palavra[i] == 's')
			consoantes.S=1;
		if (palavra[i] == 'T' || palavra[i] == 't')
			consoantes.T=1;
		if (palavra[i] == 'V' || palavra[i] == 'v')
			consoantes.V=1;
		if (palavra[i] == 'W' || palavra[i] == 'w')
			consoantes.W=1;
		if (palavra[i] == 'X' || palavra[i] == 'x')
			consoantes.X=1;
		if (palavra[i] == 'Y' || palavra[i] == 'y')
			consoantes.Y=1;
		if (palavra[i] == 'Z' || palavra[i] == 'z')
			consoantes.Z=1;
	}
}

/*contagem consoantes, vogais e outros*/
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

/*verificar se a primeira letra da palavra eh igual a ultima letra da palavra anterior*/
int Correspondencia(Lista *lista, char *palavra)
{
	char c;
	if(lista != NULL){
		c = lista->palavra[strlen(lista->palavra) - 1];
		if(islower(palavra[0]))
			c = tolower(c);
		if(isupper(palavra[0]))
			c = toupper(c);
		if(palavra[0] != c)
			return 0;
	}
	return 1;
}

void Jogar(char *str, Lista *lista)
{
	char *palavra;
	Lista *jogo = NULL;
	int v;/*auxiliar da funcao Comparar*/
	
	/*caso nao haja lista de comparacao, nao vale apena jogar*/
	if(lista != NULL){
		while(fgets(str, MAXSTR, stdin) != NULL) {
			palavra = Verificar(str);
			if (palavra == NULL || palavra[0] == '\0')
				break;
			
			/*verificar se a palavra existe na lista anterior*/
			v = Comparar(lista, palavra);
			if(v == 0)
				break;
			
			if(jogo != NULL){
				v = Comparar(jogo, palavra);
				if(v == 1)
					break;
				if(!Correspondencia(jogo, palavra))
					break;
			}
			
			jogo = Adiciona(jogo, palavra);
			
			contagem.nPalavras++;
			contagem.nCaracteres += strlen(palavra);
			ContagemCVO(palavra);
			ConsoantesDistintas(palavra);
			VogaisDistintas(palavra);
		}
	}
	while(jogo != NULL)
		jogo = Remove(jogo);
}
	
int main()
{
	char str[MAXSTR], *palavra;
	Lista *lista = NULL;
		
	while (fgets(str, MAXSTR, stdin) != NULL) {
		palavra = Verificar(str);
		if (palavra == NULL || palavra[0] == '\0')
			break;
		lista = Adiciona(lista, palavra);
	}
	
	Jogar(str, lista);
	
	contagem.nCDistintas = 
		consoantes.B + consoantes.C + consoantes.D
		+ consoantes.F + consoantes.G + consoantes.H
		+ consoantes.J + consoantes.K + consoantes.L
		+ consoantes.M + consoantes.N + consoantes.P
		+ consoantes.Q + consoantes.R + consoantes.S
		+ consoantes.T + consoantes.V + consoantes.W
		+ consoantes.X + consoantes.Y + consoantes.Z;
	
	contagem.nVDistintas = vogais.A +
						   vogais.E +
						   vogais.I +
						   vogais.O +
						   vogais.U;
	
	printf("%d %d %d %d %d %d\n",
		   contagem.nPalavras,
		   contagem.nCaracteres,
		   contagem.nConsoantes,
		   contagem.nVogais,
		   contagem.nCDistintas,
		   contagem.nVDistintas);
	
	while(lista != NULL)
		lista = Remove(lista);
}