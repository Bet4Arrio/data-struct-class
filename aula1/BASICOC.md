## Basico de C

O curso de Estrutura de Dados usará a linguagem C, pois ela não possui várias facilidades de outras linguagens, o que nos obriga a entender como a memória funciona e como, de fato, algoritmos mais básicos são feitos.

## GCC

Para criar programas em C, usaremos o compilador GCC. Então, vamos a uma pequena introdução de como compilar e usar algumas flags.

- Para compilar um programa .c

```bash
$ gcc <arquivo.c>
```

Isso gera um arquivo a.out (Linux e Mac) ou a.exe (Windows).

- Para definir o nome do programa de saída, usa-se a flag **-o**.

```bash
$ gcc <arquivo.c> -o programa
```

- É possível compilar vários arquivos em um programa para organizar seu código.

```bash
$ gcc <arquivo.c> <arquivo1.c> <arquivo2.c> -o programa
```

- Caso use bibliotecas nativas do sistema (como a math.h), inclua a flag geral para bibliotecas **-lm**.

```bash
$ gcc <arquivo.c> -o programa -lm
```

- Por fim, pode querer saber como é o código assembly gerado do seu código, usando a tag **-S**.

```bash
$ gcc <arquivo.c> -S
```

## Estrutura do código.

```C
int main(){
    return 0;
}
```

Quando se compila um código em C para um executável, ele sempre começará pela função main. Essa função será do tipo int, pois o valor de retorno dela (de 0 a 255) indicará ao sistema operacional se o programa executou com sucesso ou não, sendo 0 indicativo de que não houve erros.

Para verificar o código de retorno de um programa executado no terminal, no Windows/Powershell, usa-se `echo $LASTEXITCODE`, e no Linux/Mac, usa-se `echo $?`.

### Libs

Para que um código em C possa importar funções/variáveis de outro código C, é necessário ter um arquivo **.h** (header) do mesmo nome. (Isso será abordado mais a frente nas aulas).

Por padrão, para importar bibliotecas externas do sistema operacional, utiliza-se `#include <lib.h>`, por exemplo:

```C
#include <stdio.h>

int main(){
    return 0;
}
```

Nesse caso, importamos a biblioteca stdio (standard input output), que nos permite utilizar funções como printf e scanf para entrada e saída de dados do usuário no terminal.

## Palavras chaves

- `#include`: inclui bibliotecas.
- `#define`: define constantes ou trechos de código (é executado na compilação, substituindo tudo pelo que foi definido).

  - Em geral, palavras que têm **#** na frente são processadas em tempo de compilação.

- `typedef`: define ou redefine um tipo de dado para outro parecido com `#define`, mas não substitui na compilação, muito útil para trabalhar com **structs**.

- Existem várias outras palavras-chave; serão apresentadas conforme forem necessárias.

## Variáveis

A linguagem C oferece uma quantidade limitada de tipos de variáveis, o que implica que, na maioria dos casos, temos que codificar nossos próprios tipos quando necessário.

O tamanho em bytes das variáveis primitivas pode mudar de acordo com a arquitetura do seu processador, mas supondo que estamos em um computador de 64 bits, vamos aos tipos e seus tamanhos esperados.

### Começando com tipos inteiros

```C
int a; //  4Bytes
short int a; // 2Bytes
long long int a; // 8 Bytes
```

Para inteiros, também pode-se usar a palavra `unsigned` no começo. Isso não muda o tamanho da variável, mas faz com que ela não utilize sinais (positivo ou negativo), aumentando 1 bit para o valor máximo da variável.

#### Bits e Bytes numéricos

- 1 Byte é igual a 8 bits.

Os valores numéricos que abrangem positivo e negativo necessitam de 1 bit para indicar se são positivos ou negativos. Supondo que tenha um `short int` declarado, dos 16 bits que possui, na prática, apenas 15 são usados numericamente. Isso significa que o valor máximo é 2^15 e o mínimo é -2^15. Caso utilize `unsigned short int`, ganha-se esse bit extra, fazendo com que o valor máximo seja 2^16 e o mínimo seja 0.

### Valores decimais

```C
float a; // 4 Bytes
double a;  // 8 Bytes
```

Ambos servem para dados decimais (ponto flutuante, como 3.9); entretanto, o computador representa esses tipos de números em uma forma de notação científica, o que pode gerar erros em números muito extensos. É fortemente recomendado optar por `double` sempre, pois este tem menos erros.

### Char

```C
char a; // 1 Byte
```

Esse tipo de variável é utilizado para armazenar um byte que é tratado como uma letra. Ele utiliza como base a tabela ASCII, onde cada valor entre 0 e 255 equivale a um caractere.

### Além do básico

```C
void * a; // 4 ou 8Bytes
```

Esse tipo é para trabalhar com ponteiros de forma mais complexa. No momento, não será abordado.

## Struct

Apenas os tipos de dados clássicos não são tão fáceis de trabalhar e organizar as coisas, por isso podemos criar conjuntos de tipos básicos que chamamos de `struct`.

Para criar uma `struct`,

```C
struct minha_estrutura{
    int dado1;
    int dado2;
};
```

Para utilizá-la,

```C
int main(){
    struct minha_strutura a;
    // codigos aqui
    return 0;
}
```

O tamanho de uma struct é a soma de todos os tamanhos que a compõem, ou seja, a nossa `struct minha_estrutura` tem o tamanho de 8 bytes (4 + 4, onde cada 4 é o tamanho de um `int`).

Por conveniência, podemos criar um typedef da struct para facilitar sua declaração.

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

O typedef apenas facilita a escrita, mas não altera a estrutura da struct.

Essencialmente, a struct é apenas uma sequência de tamanhos de bytes enfileirados; não possui métodos, apenas atributos.

## Extra

Caso tenha dúvida sobre o tamanho da sua variável, a `stdlib.h` possui a função `sizeof()` que mostra o tamanho do tipo/variável.

Exemplo de uso:

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

Isso pode ser feito com qualquer dado.
