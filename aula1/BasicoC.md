## Basico de C
O curso de Estrutura de Dados Iremos usar C pois ele não tem varias facilidades de outras linguagens  oq nos obriga a entender como Memoria funcina e como de fato algoritimos mais basicos são feitos.

## GCC
Para criar programas em C, usaremos o compilador GCC. Então vamos a um pequena introdução de como compilar e usar algumas flags

- Para comprilar um programa .c
```bash
gcc <arquivo.c>
```
isso gera um arquivo a.out (linux e mac)  ou a.exe (windows)
- para definir o nome do programa de saida,  usa-se a flag **-o**

```bash
gcc <arquivo.c> -o programa
```

-  é possivel compilar varios arquivos em um programa para organizar seu codigo

```bash
gcc <arquivo.c> <arquivo1.c> <arquivo2.c> -o programa
```

- Caso use libs nativas do sistema (como a math.h) inclua a flag  para libs geral **-lm**

```bash
gcc <arquivo.c> -o programa -lm
```

- por fim pode querer saber como é o asm gerado do seu codigo, usar a taga **-S**

```bash
gcc <arquivo.c> -S
```

## Estrutura de codigo

```C
int main(){
    return 0; 
}
```
quando se compila uma codigo C para um executavel, ele irar sempre começar da função main.
ela sera de um tipo int, pois o retorno dela (de 0 a 255) ira indicar para o OS se o programa executou com exito ou não, 0 sigifina que não teve erros. 

:  para saber codigo de retorno de um program executado no terminal
no windows/Powershell usa-se ```echo $LASTEXITCODE``` e no linux/mac ```echop $?```.

### libs 
Para que um codig C possa importa funções/variveis de outro codigo C precisa-se um um aquivo **.h** do mesmo nome. (isso sera abordado mais a frente nas aulas)
por padrão importar libs externas (do os) usa-se #include<lib.h> por exemplo:
```C
#include <stdio.h>

int main(){
    return 0; 
}
```
nesse caso imporamos a lib stdio (standard input outpout) que nos permite usar funções como printf e scanf para entrada e saida de dados do usuario no terminal.


## Palavras chaves

- ```#include```: inclui libs
- ```#define```: define constantes ou treços de codigo (ele executado na compilação, subistituindo tudo pelo que foi definido)
    - em geral palavras que etm **#** na frente são processadas em tempo de compilação 

- ```typdef``` define ou redefine um tipo de dado para outro parecido com define, mas não subistitui na compilção, muito util para trabalhar com **structs**


- existem varis outras palavras chaves, serão apresentadas conforme forem necessarias.

## Variaveis
A linguagem C oferece uma quantidade pouco ampla de tipos de variaveis, oque emplica que na maioria dos casos temos que codificar nosso proprios tipos quando necessario.

o tamanho em Bytes das variaveis primitivas podem mudar de acordo com a arquitetura do seu processador, mas supondo que estamos em um computador 64bits, vamos aos tipo e seus tamanhos esperados.

### começando com tipos inteiros

```C
int a; //  4Bytes
short int a; // 2Bytes
long long int a; // 8 Bytes
```
para inteiros tambem pode usar  o a palavra ```unsigned``` no começo, essa não muda o tamnho da variavel, mas deixa de usar sinais (positivo ou negativo) o que aumenta 1bit para valor maximo da variavel.

#### Bits e Bytes numericos
- 1 Byte é igual a 8bits

os valores numericos que abrangem positivo e negativo, então precisa de um 1bit para falar se é positivos ou negativos o valor. então supondo que tenho um ```short int``` declarado, dos 16bits que tem na pratica so 15 são usado numericamente, ou seja o valor maximo é 2^15 e minimo -2^15, caso use  ```unsigned short int``` ganho esse bit extra e meu valor maximo vai para 2^16 e minimo para 0.

### Valores decimais

```C
float a; // 4 Bytes
double a;  // 8 Bytes
```
Ambos servem para dados decimais (ponto flutuantes como 3.9), entretantando o computador representa esses tipode numeros em uma forma de notação cientifica, oq pode gerar erros em numero muito extensos, é fortemente recomendado opitar por double sempre pois esse tem menos erros.

### Char

```C
char a; // 1 Byte
```
Esse serve para grava um byte que é tratado como letra, usa como base a tabela ASCII cada valor entre 0 e 255 equivale a um caracter 

###  Alem do basico

```C
void * a; // 4 ou 8Bytes
```
Esse tipo é para trabalahr com ponteiros de forma mais complexa, no momento não sera abordado

## Struct
Apenas os tipos de dados classicos, não são tão faceis de trabalhar e organizar as coisas, por isso podemos fazer conjuntos de tipos basicos que chamamos de ```struct```.
Para criar  uma struct

```C
struct minha_estrutura{
    int dado1;
    int dado2;
};
```
Para usa-la

```C
int main(){
    struct minha_strutura a;
    // codigos aqui
    return 0;
}
```
O tamanho de uma struct é a soma de todos os tamnhos que a compoem, ou seja a nossa ```struct minha_strutura``` tem o tamanho de 8 Bytes 4 + 4 (int +  int).

Bom por conveniencia podemos criar um typedef da struc para facilitiar sua declaração

```C
typedef struct {
    int dado1;
    double dado2;
} Minha_estrutura2;

int main(){
   Minha_estrutura2 a;
    // codigos aqui
    return 0;
}
```
o tydef apenas facilita a escrita, mas não muda em nada a struct

Essencialmente a struct apenas é uma sequencia de tamnhos de bytes enfileirados, nao possui metodos, apenas atributos.


## Extra
Caso tenha duvida no tamanho da sua variavel, a ```stdlib.h``` tem a função ```sizeof()``` que mostra o tamanho do tipo/variavel

exemplo de uso

```C
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    double dado1;
    double dado2;
} Minha_estrutura2;

int main(){
    printf("Minha_estrutura2 tamanho: %d \n",sizeof(Minha_estrutura2));
    return 0;
}
```

isso pode ser feito com qualquer dado.



