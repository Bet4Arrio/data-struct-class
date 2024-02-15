#include<stdio.h>
#include<stdlib.h>
#include <time.h>
// Solucao Gulosa complexidade de tempo O(1)

#define maximo 0xFFF

size_t Fatorial(size_t X){

}

size_t fibo(size_t X){
    if(X == 0)
        return 0;
    if(X <= 2){
        return 1;
    }

    return fibo(X-1) + fibo(X-2);
}

size_t fiboDinamico(size_t X, size_t* decorator){
    if(X == 0)
        return 0;
    if(X <= 2){
        return 1;
    }
    if(decorator[X] == -1){
        decorator[X] =  fiboDinamico(X-1, decorator) + fiboDinamico(X-2, decorator);
    }
    return decorator[X];

}


size_t* MontaDecorator(size_t tam){
    size_t *decorator = (size_t*)calloc(tam, sizeof(size_t));
    for (size_t i = 0; i < tam; i++){
        decorator[i] = -1;
    }
    return decorator;
}
int main(){
    // funciona como o malloc mas inicia tudo como Zero
    
    size_t *decorator;
    clock_t start, end;
    size_t resultado;
    size_t testes[] = {40, 43, 47, 50, 100};
    for(size_t i = 0; i < 4; i++){
        start = clock();
        resultado = fibo(testes[i]);
        end = clock();
        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        printf("fib(%d) = %d Tempo: %.9f segundos.\n",  testes[i],resultado ,elapsed);
    }

    printf("===================== \n");
    printf("====== Dinamico =====\n");
    printf("=====================\n");
    decorator = MontaDecorator(maximo+1);
    for(size_t i = 0; i < 5; i++){
        start = clock();
        resultado = fiboDinamico(testes[i], decorator);
        end = clock();
        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        printf("fibDinamico(%d) = %d Tempo: %.9f segundos.\n",  testes[i],resultado ,elapsed);
    }
    free(decorator);

    printf("================================\n");
    printf("====== Dinamico Mais justo =====\n");
    printf("====== refazendo decorator =====\n");
    printf("================================\n");

    for(size_t i = 0; i < 5; i++){
        start = clock();
        decorator = MontaDecorator(maximo+1);
        resultado = fiboDinamico(testes[i], decorator);
        free(decorator);
        end = clock();
        double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
        printf("fibDinamico(%d) = %d Tempo: %.9f segundos.\n",  testes[i],resultado ,elapsed);
    }

    return 0;
}




