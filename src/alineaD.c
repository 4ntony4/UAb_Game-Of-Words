#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 80
#define DEBUG 0

typedef struct SCount
{
  int nPalavras,
      nCaracteres,
      nConsoantes,
      nVogais,
      nOutros,
      nCDistintas,
      nVDistintas;
} Count;

typedef struct SLista
{
	char *palavra;
	int importancia;
	struct SLista *seg;
} Lista;

typedef struct SVogais
{
	int A,E,I,O,U;
} Vogais;

typedef struct SConsoantes
{
	int B,C,D,F,G,H,J,K,L,M,N,P,Q,R,S,T,V,W,X,Y,Z;
} Consoantes;

typedef struct SLetras
{
	char letra;
	int fInicio, fFim;
	struct SLetras *seg;
} Letras;

/* Protótipos */
Letras *AdicionaLetra(Letras *letras, char letra);
Letras *InicializarLetras(Letras *letras);
Letras *RemoveLetra(Letras *letras);
char *Verificar(char *str);
char *ParaMaiusculas(char *palavra);
Lista *AdicionaPalavra(Lista *lista, char *palavra);
Lista *AdicionaPalavraComImp(Lista *lista, char *palavra, int importancia);
Lista *RemovePalavra(Lista *lista);
Lista *RemovePalavraEspecifica(Lista *lista, char *palavra);
void ImprimeLista(Lista *lista);
void ImprimeUmElementoLista(Lista *lista);
void ImprimeNElementosLista(Lista *lista, int n);
void ImprimeCount(Count count);
void Frequencia(Lista *lista, Letras *letras);
void ApagarFrequenciaLetras(Letras *letras);
void Importancia(Lista *lista, Letras *letras);
int ImportanciaMaxima(Lista *lista);
Lista *OrdenarListaDecresc(Lista *lista, Letras *letras);
int Correspondencia(Lista *lista, char *palavra);
Lista *Jogar(Lista *lista, Letras *letras);
Count Estatisticas(Lista *lista, Letras *letras, Count count);
Count ContagemCVO(char *palavra, Count count);
Vogais VogaisDistintas(char *palavra, Vogais v);
int VogaisDistintasCount(Vogais v);
Consoantes ConsoantesDistintas(char *palavra, Consoantes c);
int ConsoantesDistintasCount(Consoantes c);


Letras *AdicionaLetra(Letras *letras, char letra)
{
	Letras *elemento = (Letras*)malloc(sizeof(Letras));
	if(elemento != NULL)
	{
		elemento->letra = letra;
		elemento->fInicio = 0;
		elemento->fFim = 0;
		elemento->seg = letras;
	}
	return elemento;
}

Letras *InicializarLetras(Letras *letras)
{
	letras = AdicionaLetra(letras,'A');
	letras = AdicionaLetra(letras,'B');
	letras = AdicionaLetra(letras,'C');
	letras = AdicionaLetra(letras,'D');
	letras = AdicionaLetra(letras,'E');
	letras = AdicionaLetra(letras,'F');
	letras = AdicionaLetra(letras,'G');
	letras = AdicionaLetra(letras,'H');
	letras = AdicionaLetra(letras,'I');
	letras = AdicionaLetra(letras,'J');
	letras = AdicionaLetra(letras,'K');
	letras = AdicionaLetra(letras,'L');
	letras = AdicionaLetra(letras,'M');
	letras = AdicionaLetra(letras,'N');
	letras = AdicionaLetra(letras,'O');
	letras = AdicionaLetra(letras,'P');
	letras = AdicionaLetra(letras,'Q');
	letras = AdicionaLetra(letras,'R');
	letras = AdicionaLetra(letras,'S');
	letras = AdicionaLetra(letras,'T');
	letras = AdicionaLetra(letras,'U');
	letras = AdicionaLetra(letras,'V');
	letras = AdicionaLetra(letras,'W');
	letras = AdicionaLetra(letras,'X');
	letras = AdicionaLetra(letras,'Y');
	letras = AdicionaLetra(letras,'Z');
	
	return letras;
}

Letras *RemoveLetra(Letras *letras)
{
	Letras *aux;
	if(letras != NULL)
	{
		aux = letras->seg;
		free(letras);
		return aux;
	}
	return NULL;
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

char *ParaMaiusculas(char *palavra)
{
	int i;
	for(i = 0;i < strlen(palavra); i++)
		palavra[i] = toupper(palavra[i]);
	return palavra;
}

Lista *AdicionaPalavra(Lista *lista, char *palavra)
{
	Lista *elemento=(Lista*)malloc(sizeof(Lista));
	if (elemento != NULL)
	{
		elemento->palavra = palavra;
		elemento->importancia = 0;
		elemento->seg = lista;
	}
	return elemento;
}

Lista *AdicionaPalavraComImp(Lista *lista, char *palavra, int importancia)
{
	Lista *elemento=(Lista*)malloc(sizeof(Lista));
	if (elemento != NULL)
	{
		elemento->palavra = palavra;
		elemento->importancia = importancia;
		elemento->seg = lista;
	}
	return elemento;
}

Lista *RemovePalavra(Lista *lista)
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

Lista *RemovePalavraEspecifica(Lista *lista, char *palavra)
{
	Lista *aux = NULL;
	Lista *auxOrdenada = NULL;
	int n;

	while(lista != NULL){
		n = strcmp(lista->palavra, palavra);
		if(n){
			aux = AdicionaPalavraComImp(aux, lista->palavra, lista->importancia);
		}
		lista = RemovePalavra(lista);
	}

	while(aux != NULL){
		auxOrdenada = AdicionaPalavraComImp(auxOrdenada, aux->palavra, aux->importancia);
		aux = RemovePalavra(aux);
	}
	return auxOrdenada;
}

void ImprimeLista(Lista *lista)
{
	while(lista != NULL){
		printf("%s [%d]\n", lista->palavra, lista->importancia);
		lista = lista->seg;
	}
}

void ImprimeUmElementoLista(Lista *lista)
{
    if(lista != NULL)
        printf("%s\n", lista->palavra);
}

void ImprimeNElementosLista(Lista *lista, int n)
{
	for (int i = 0; i < n; i++){
		if(lista != NULL){
			printf("%s [%d]\n", lista->palavra, lista->importancia);
			lista = lista->seg;
		}
	}
}

void ImprimeCount(Count count)
{
	printf("Estatisticas: %d %d %d %d %d %d\n",
		   count.nPalavras,
		   count.nCaracteres,
		   count.nConsoantes,
		   count.nVogais,
		   count.nCDistintas,
		   count.nVDistintas);
}

void Frequencia(Lista *lista, Letras *letras)
{
	Lista *auxLista = lista;
	Letras *auxLetras = letras;

	while(auxLista != NULL){
		while(auxLetras != NULL){
			if(auxLista->palavra[0] == auxLetras->letra)
				auxLetras->fInicio++;
			if(auxLista->palavra[strlen(auxLista->palavra) - 1] == auxLetras->letra)
				auxLetras->fFim++;
			auxLetras = auxLetras->seg;
		}
		auxLista = auxLista->seg;
		auxLetras = letras;
	}
}

void ApagarFrequenciaLetras(Letras *letras)
{
	Letras *aux = letras;

	while(aux != NULL){
		aux->fInicio = 0;
		aux->fFim = 0;
		aux = aux->seg;
	}
}

/* calcular importancia de cada palavra numa lista */
void Importancia(Lista *lista, Letras *letras)
{
	Letras *letrasAux = letras;
	int fini_fim, ff_ini;

	while(lista != NULL){
		while(letrasAux != NULL){
			if(lista->palavra[strlen(lista->palavra) - 1] == letrasAux->letra)
				fini_fim = letrasAux->fInicio;
			if(lista->palavra[0] == letrasAux->letra)
				ff_ini = letrasAux->fFim;
			letrasAux = letrasAux->seg;
		}
		lista->importancia = fini_fim * ff_ini + strlen(lista->palavra);
		
        lista = lista->seg;
		letrasAux = letras;
	}
}

int ImportanciaMaxima(Lista *lista)
{
	int importanciaMax = 0;

	while(lista != NULL){
		if (lista->importancia > importanciaMax)
			importanciaMax = lista->importancia;
		
		lista = lista->seg;
	}

	return importanciaMax;
}

Lista *OrdenarListaDecresc(Lista *lista, Letras *letras)
{
	Lista *listaOrdenadaDecresc = NULL;
	Lista *aux = lista;
	int importanciaMax = 0;

	importanciaMax = ImportanciaMaxima(lista);

	for (int i = 0; i <= importanciaMax; i++){
		while(aux != NULL){
			if (aux->importancia == i){
				listaOrdenadaDecresc = 
					AdicionaPalavraComImp(listaOrdenadaDecresc,
                    aux->palavra,
                    aux->importancia);
			}
			
			aux = aux->seg;
		}
		aux = lista;
	}

	return listaOrdenadaDecresc;
}

/* verificar se a primeira letra da palavra de uma lista eh igual a ultima letra de uma dada palavra */
int Correspondencia(Lista *lista, char *palavra)
{
	char c;
	if(lista != NULL){
		c = palavra[strlen(palavra) - 1];
		if(islower(lista->palavra[0]))
			c = tolower(c);
		if(isupper(lista->palavra[0]))
			c = toupper(c);
		if(lista->palavra[0] != c)
			return 0;
	}
	return 1;
}

Lista *Jogar(Lista *lista, Letras *letras)
{
    Lista *listaFinal = NULL, *auxiliar;
    int correspondencia;

    /* ordenar a lista por ordem decrescente de importancia */
    lista = OrdenarListaDecresc(lista, letras);

	if (DEBUG) {
        printf("DEBUG: Lista por Ordem Decrescente de Importancia\n");
        ImprimeLista(lista);
        printf("\n");
    }

    /* imprimir primeiras três palavras */
	printf("Primeiras palavras:\n");
    ImprimeNElementosLista(lista, 3);

    printf("Jogo:\n");

    listaFinal = AdicionaPalavraComImp(listaFinal, lista->palavra, lista->importancia);

    /* imprimir primeiro elemento da lista final */
	ImprimeUmElementoLista(listaFinal);

	/* retirar primeiro elemento da lista */
	lista = RemovePalavra(lista);

    /* jogar */
    while(lista != NULL){
		auxiliar = lista;
		while (auxiliar != NULL){
			correspondencia = Correspondencia(auxiliar, listaFinal->palavra);

			if (correspondencia){
				listaFinal = AdicionaPalavraComImp(listaFinal, auxiliar->palavra, auxiliar->importancia);
				ImprimeUmElementoLista(listaFinal);
				lista = RemovePalavraEspecifica(lista, listaFinal->palavra);
				if (DEBUG) {
					printf("\n");
					ImprimeLista(lista);
					printf("\n");
				}
				break;
			}
			auxiliar = auxiliar->seg;
		}

		if (!correspondencia)
			break;
	}
	
    return listaFinal;
}

Count Estatisticas(Lista *lista, Letras *letras, Count count)
{
    ApagarFrequenciaLetras(letras);
    Frequencia(lista, letras);

    while(lista != NULL){
        count.nPalavras++;
        count.nCaracteres += strlen(lista->palavra);
        count = ContagemCVO(lista->palavra, count);
        lista = lista->seg;
    }

    return count;
}

/*contagem consoantes, vogais e outros*/
Count ContagemCVO(char *palavra, Count count)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'A' ||
		palavra[i] == 'a' ||
		palavra[i] == 'E' ||
		palavra[i] == 'e' ||
		palavra[i] == 'I' ||
		palavra[i] == 'i' ||
		palavra[i] == 'O' ||
		palavra[i] == 'o' ||
		palavra[i] == 'U' ||
		palavra[i] == 'u')
			count.nVogais++;

		else if (palavra[i] == 'B' ||
		palavra[i] == 'b' ||
		palavra[i] == 'C' ||
		palavra[i] == 'c' ||
		palavra[i] == 'D' ||
		palavra[i] == 'd' ||
		palavra[i] == 'F' ||
		palavra[i] == 'f' ||
		palavra[i] == 'G' ||
		palavra[i] == 'g' ||
		palavra[i] == 'H' ||
		palavra[i] == 'h' ||
		palavra[i] == 'J' ||
		palavra[i] == 'j' ||
		palavra[i] == 'K' ||
		palavra[i] == 'k' ||
		palavra[i] == 'L' ||
		palavra[i] == 'l' ||
		palavra[i] == 'M' ||
		palavra[i] == 'm' ||
		palavra[i] == 'N' ||
		palavra[i] == 'n' ||
		palavra[i] == 'P' ||
		palavra[i] == 'p' ||
		palavra[i] == 'Q' ||
		palavra[i] == 'q' ||
		palavra[i] == 'R' ||
		palavra[i] == 'r' ||
		palavra[i] == 'S' ||
		palavra[i] == 's' ||
		palavra[i] == 'T' ||
		palavra[i] == 't' ||
		palavra[i] == 'V' ||
		palavra[i] == 'v' ||
		palavra[i] == 'W' ||
		palavra[i] == 'w' ||
		palavra[i] == 'X' ||
		palavra[i] == 'x' ||
		palavra[i] == 'Y' ||
		palavra[i] == 'y' ||
		palavra[i] == 'Z' ||
		palavra[i] == 'z')
			count.nConsoantes++;

		else
			count.nOutros++;
	}
	return count;
}

Vogais VogaisDistintas(char *palavra, Vogais v)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'A' || palavra[i] == 'a')
			v.A=1;
		if (palavra[i] == 'E' || palavra[i] == 'e')
			v.E=1;
		if (palavra[i] == 'I' || palavra[i] == 'i')
			v.I=1;
		if (palavra[i] == 'O' || palavra[i] == 'o')
			v.O=1;
		if (palavra[i] == 'U' || palavra[i] == 'u')
			v.U=1;
	}
	return v;
}

int VogaisDistintasCount(Vogais v)
{
	return v.A + v.E + v.I + v.O + v.U;
}

Consoantes ConsoantesDistintas(char *palavra, Consoantes c)
{
	int i;
	for (i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == 'B' || palavra[i] == 'b')
			c.B=1;
		if (palavra[i] == 'C' || palavra[i] == 'c')
			c.C=1;
		if (palavra[i] == 'D' || palavra[i] == 'd')
			c.D=1;
		if (palavra[i] == 'F' || palavra[i] == 'f')
			c.F=1;
		if (palavra[i] == 'G' || palavra[i] == 'g')
			c.G=1;
		if (palavra[i] == 'H' || palavra[i] == 'h')
			c.H=1;
		if (palavra[i] == 'J' || palavra[i] == 'j')
			c.J=1;
		if (palavra[i] == 'K' || palavra[i] == 'k')
			c.K=1;
		if (palavra[i] == 'L' || palavra[i] == 'l')
			c.L=1;
		if (palavra[i] == 'M' || palavra[i] == 'm')
			c.M=1;
		if (palavra[i] == 'N' || palavra[i] == 'n')
			c.N=1;
		if (palavra[i] == 'P' || palavra[i] == 'p')
			c.P=1;
		if (palavra[i] == 'Q' || palavra[i] == 'q')
			c.Q=1;
		if (palavra[i] == 'R' || palavra[i] == 'r')
			c.R=1;
		if (palavra[i] == 'S' || palavra[i] == 's')
			c.S=1;
		if (palavra[i] == 'T' || palavra[i] == 't')
			c.T=1;
		if (palavra[i] == 'V' || palavra[i] == 'v')
			c.V=1;
		if (palavra[i] == 'W' || palavra[i] == 'w')
			c.W=1;
		if (palavra[i] == 'X' || palavra[i] == 'x')
			c.X=1;
		if (palavra[i] == 'Y' || palavra[i] == 'y')
			c.Y=1;
		if (palavra[i] == 'Z' || palavra[i] == 'z')
			c.Z=1;
	}
	return c;
}

int ConsoantesDistintasCount(Consoantes c)
{
	return
		c.B +
		c.C +
		c.D +
		c.F +
		c.G +
		c.H +
		c.J +
		c.K +
		c.L +
		c.M +
		c.N +
		c.P +
		c.Q +
		c.R +
		c.S +
		c.T +
		c.V +
		c.W +
		c.X +
		c.Y +
		c.Z;
}

int main()
{
    char str[MAXSTR], *palavra;
    Letras *letras = NULL;
    Lista *lista = NULL, *listaFinal = NULL, *aux;
    Count contagem = {0};
	Vogais vogaisFinais = {0};
	Consoantes consoantesFinais = {0};

    letras = InicializarLetras(letras);

    while (fgets(str, MAXSTR, stdin) != NULL) {
		palavra = Verificar(str);
		if (palavra == NULL || palavra[0] == '\0')
			break;
		palavra = ParaMaiusculas(palavra);
		lista = AdicionaPalavra(lista, palavra);
	}

    if (DEBUG) {
        printf("DEBUG: Lista Inicial\n");
        ImprimeLista(lista);
        printf("\n");
    }

	Frequencia(lista, letras);
    Importancia(lista, letras);

	if (DEBUG) {
        printf("DEBUG: Lista Inicial com Importancia\n");
        ImprimeLista(lista);
        printf("\n");
    }
    
    if(lista != NULL){
        listaFinal = Jogar(lista, letras);
    }

    contagem = Estatisticas(listaFinal, letras, contagem);

	aux = listaFinal;
	while(aux != NULL){
		vogaisFinais = VogaisDistintas(aux->palavra, vogaisFinais);
		consoantesFinais = ConsoantesDistintas(aux->palavra, consoantesFinais);
		aux = aux->seg;
	}

	contagem.nVDistintas = VogaisDistintasCount(vogaisFinais);
	contagem.nCDistintas = ConsoantesDistintasCount(consoantesFinais);

    ImprimeCount(contagem);


    while(lista != NULL)
        lista = RemovePalavra(lista);
    while(listaFinal != NULL)
        listaFinal = RemovePalavra(listaFinal);
    while(letras != NULL)
        letras = RemoveLetra(letras);

    return 0;
}