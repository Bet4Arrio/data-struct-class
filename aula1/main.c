#include<stdio.h>
#include<stdlib.h>


struct minha_estrutura{
    int dado1;
    int dado2;
};

typedef struct {
    int dado1;
    double dado2;
} Minha_estrutura2;


int main(){
    printf("int: %d \n",sizeof(int));
    printf("short int: %d \n",sizeof(short int));
    printf("long long int: %d \n",sizeof(long long int));
    printf("unsigned int: %d \n",sizeof(unsigned int));
    printf("unsigned short int: %d \n",sizeof(unsigned short int));
    printf("unsigned long long int: %d \n",sizeof(unsigned long long int));
    printf("float: %d \n",sizeof(float));
    printf("double: %d \n",sizeof(double));
    printf("char: %d \n",sizeof(char));
    printf("void*: %d \n",sizeof(void*));
    printf("struct minha_estrutura: %d \n",sizeof(struct minha_estrutura));
    printf("Minha_estrutura2: %d \n",sizeof(Minha_estrutura2));



    return 0;
}