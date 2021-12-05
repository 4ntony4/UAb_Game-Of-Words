# UAb_gameOfWords

[![Replit Ready to Run](https://img.shields.io/badge/Replit-Ready_to_Run-informational?logo=replit&labelColor=white)](https://replit.com/@DiogoAntao/UAbgameOfWords)

[EN] This project was made under the Curricular Unit of **Introduction to Programming** in the Computer Science and Engineering Bachelor Program of Universidade Aberta, academic year of 2018-19.

[PT] Este projeto foi realizado no âmbito da Unidade Curricular de **Introdução à Programação** da Licenciatura em Engenharia Informática da Universidade Aberta no ano letivo de 2018-19.


## Introdução

Este projeto tem por base um jogo de palavras - existe um conjunto de palavras selecionadas e tem de se escrever uma palavra que se inicie com a última letra da palavra anterior (não se podendo repetir palavras).
Consideram-se palavras com um limite de 79 caracteres. Se for introduzida uma palavra maior, leem-se os primeiros 79 caracteres.


## Alínea A

O objetivo é ler uma palavra e retornar o respetivo número de caracteres.

Exemplo de Entrada:

    jogo

Exemplo de Saída:

    4


## Alínea B

O objetivo é ler um conjunto de palavras, uma palavra por linha, terminando quando a linha for vazia.

Deve retornar:
* número de palavras lidas;
* número total de caracteres;
* número total de consoantes;
* número total de vogais.

Considera-se que a lista de consoantes é "BCDFGHJKLMNPQRSTVWXYZ" e a lista das vogais é "AEIOU". Consideram-se maiúsculas e minúsculas como sendo iguais. Contabilizam-se todos os restantes caracteres, no caso de ocorrerem, como não sendo nem consoantes nem vogais (letras acentuadas, traços, ou
mesmo espaços).

Exemplo de Entrada:

```
Código
Linguagem
Programa
Instrução
Atribuição
Execução
Output
Input

```

Exemplo de Saída:

    8 68 28 26


## Alínea C

Pretende-se na alínea C que após a leitura das palavras de acordo com a alínea B, em que pára ao encontrar uma palavra em branco, inicie de seguida a validação das palavras seguintes, de acordo com os seguintes pontos:
* Em cada linha tem de existir uma palavra do conjunto anterior, podendo cada palavra ocorrer apenas uma vez;
* Entre duas palavras seguidas A e B, a letra com que termina a palavra A tem de ser a letra com que se inicia a palavra B, caso contrário a palavra B é considerada inválida;
* O jogo termina após a inserção da primeira palavra inválida (sendo portanto contabilizadas apenas as palavras válidas), ou após se encontrar uma linha vazia;
* No final do jogo, tem de se dar as seguintes estatísticas relativas às palavras válidas:
    * número de palavras;
    * número de caracteres;
    * número de consoantes;
    * número de vogais;
    * número de consoantes distintas;
    * número de vogais distintas.

As estatísticas são iguais à alínea B, excepto o número de consoantes/vogais distintas. Pretende-se que sejam contadas de entre o conjunto das consoantes/vogais, quantas é que foram utilizadas em uma ou mais palavras. Por exemplo, se as vogais que ocorrem nas palavras forem as letras A, E e I, não existindo ocorrências das letras O e U, o número de vogais distintas é 3, independente do número total de vogais que pode ser um valor muito superior.

Exemplo de Entrada:

```
Código
Linguagem
Programa
Instrução
Atribuição
Execução
Output
Input

Código
Output
Input
Código

```

Exemplo de Saída:

    2 13 6 5 5 3


## Alínea D

Na alínea D coloca-se o computador a fazer as jogadas, após a entrada das palavras, sendo implementado o seguinte algoritmo:
* Passar todas as letras não acentuadas para maiúsculas;
* Contar quantas palavras iniciam em cada letra - FreqInicio(letra);
* Contar quantas palavras finalizam em cada letra - FreqFim(letra);
* Ordenar as palavras com base na seguinte fórmula (ordem decrescente): FreqInicio(letra-fim) * FreqFim(letra-inicio) + número de letras;
* Mostrar as três primeiras palavras, indicando a importância;
* Escolher as palavras por ordem da lista, escolhendo sempre a primeira palavra válida e removendo-a da lista;
* Ao esgotar-se a lista ou ao não existir uma palavra válida, retornar as palavras selecionadas até ao momento;
* Contabilizar as estatísticas dessas palavras, de acordo com a alínea C.

No caso de uma palavra se iniciar ou terminar com uma letra acentuada, contabilizar a frequência como zero, pelo que a importância dessa palavra será apenas o número de letras.

Exemplo de Entrada:

```
Código
Linguagem
Programa
Instrução
Atribuição
Execução
Output
Input

```

Exemplo de Saída:

    Primeiras palavras:
    ATRIBUIçãO [13]
    INSTRUçãO [11]
    EXECUçãO [10]
    Jogo:
    ATRIBUIçãO
    OUTPUT
    Estatisticas: 2 18 6 8 4 4


## Compilação
    gcc -Wall -o alineaX src/alineaX.c

## Execução
#### Linux ou Windows `PowerShell`
    ./alineaX
#### Windows `cmd.exe`
    alineaX


## Execução com ficheiro de entrada
#### Linux
    ./alineaX < input.txt
#### Windows `PowerShell`
    Get-Content input.txt | ./alineaX
#### Windows `cmd.exe`
    alineaX < input.txt


## <a href="https://replit.com/"><img src="https://raw.githubusercontent.com/4ntony4/UAb/bd3ceaf8d913be6d447fa2705434bc1b7de3261d/img/logos/replit/replit_logo.svg" alt="Replit" width="35"></a> Replit
Run it on Replit [here](https://replit.com/@DiogoAntao/UAbgameOfWords).
