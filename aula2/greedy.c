//  dado uma valor X para sacar 
// tendo umas lista de cedulas (em centavos)
// quantas cedulas de cada nota sáo necessarias para o Valor X ?
// 

#include<stdio.h>


int main(){
    int saque;
    int cedulas[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 250, 10, 5,1};


    printf("insira o valor de saque: ");
    scanf("%d", &saque);
    saque = saque *100;



    return 0;
}




