//  dado uma valor X para sacar 
// tendo umas lista de cedulas (em centavos)
// quantas cedulas de cada nota sáo necessarias para o Valor X ?
// 

#include<stdio.h>

// Solucao Gulosa complexidade de tempo O(1)
void saque(int X){
    int cedulas[] = {20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 250, 10, 5,1};
    int resto, contagem;
    for(int i = 0; i <13; i++){
        resto = X % cedulas[i];
        contagem = X/cedulas[i];
        X = resto;
        printf(" %d de R$ %.2f\n", contagem, cedulas[i]/100.0);
    }
}
int main(){
    int valor;

    printf("insira o valor em centavos: ");
    scanf("%d", &valor);
    saque(valor);



    return 0;
}




