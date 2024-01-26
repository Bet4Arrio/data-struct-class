#include<stdio.h>
#include<stdlib.h>


typedef struct pessoa{
    int idade; // 4 bytes
    unsigned long long id; // 12 bytes
    int* prox;
} Pessoa;


int main(){
    Pessoa joao;
    short int short_inteiro;
    long long int interio_muito_grande;
    float decimal;
    double muito_decimal;
    char letra;

    printf("%d - pessoa\n", sizeof(joao));
    printf("%d - short_inteiro\n", sizeof(short_inteiro));
    printf("%d - interio_muito_grande\n", sizeof(interio_muito_grande));
    printf("%d - decimal\n", sizeof(decimal));
    printf("%d - muito_decimal\n", sizeof(muito_decimal));
    printf("%d - letra\n", sizeof(letra));



    return 0;
}