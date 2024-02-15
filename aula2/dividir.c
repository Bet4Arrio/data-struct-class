#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define TOTAL_CLIENTE 0xFF


// Abordagem mais simples, porem com coplexidade  de tempo O(N)

int buscaNormal(int *clientes, size_t tamanho, int valor ){
    for(size_t i = 0; i < tamanho; i++){
        if(clientes[i] == valor){
            return i;
        }
    }
    return -1;
}


// Abordagem de dividir pra comquistar  com tempo O(ln N)
int buscaBinaria(int *clientes, size_t inicio, size_t fim, int valor){
    size_t middle = (fim+inicio)/2;
    if(clientes[middle] == valor){
        return middle;
    }
    if(inicio == fim){
        return -1;
    }
    if(clientes[middle] < valor){
        return buscaBinaria(clientes, middle+1, fim, valor);
    }
    return buscaBinaria(clientes, inicio, middle-1, valor);

}



int* criar_array(size_t tam){
// Criando array usando alocação dinamica (heap)
    int *clientes = (int*)malloc(sizeof(int)*tam);
    srand(time(NULL));
    int counter = 0;

    for(size_t i = 0; i < tam; i++){
        int r = rand() % 10;
        if ( r > 50){
            counter += r;
        }

        clientes[i] = counter;
    }
    return clientes;
}

int main(){
    int id;
    clock_t start, end;
    
    printf("Criando Lista de  %d clientes \n",TOTAL_CLIENTE );
    start = clock();
    int* clientes = criar_array(TOTAL_CLIENTE);
    end = clock();
    double elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    int valor_busca = clientes[rand()%TOTAL_CLIENTE];

    printf("Lista Criada, com intervalo de  0 a %d, buscar %d\n", TOTAL_CLIENTE, clientes[TOTAL_CLIENTE-1], valor_busca);
    printf("Tempo para cricao da lista foi de : %.9f segundos.\n", elapsed);
    

    start = clock();
    id = buscaNormal(clientes, TOTAL_CLIENTE, valor_busca);
    end = clock();
    elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("busca normal O(N) %.9f para buscar %d, id retornado %d.\n", elapsed, valor_busca, id);


    start = clock();
    id = buscaNormal(clientes, TOTAL_CLIENTE, -1);
    end = clock();
    elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("busca normal O(N)  %.9f para buscar %d, id retornado %d.\n", elapsed, -1, id);


    start = clock();
    id = buscaBinaria(clientes, 0, TOTAL_CLIENTE, valor_busca);
    end = clock();
    elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time measured BuscaBinaria O(log N): %.9f para buscar %d, id retornado %d.\n", elapsed, valor_busca, id);


    start = clock();
    id = buscaBinaria(clientes, 0, TOTAL_CLIENTE, -1);
    end = clock();
    elapsed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Time measured BuscaBinaria O(log N): %.9f para buscar %d, id retornado %d.\n", elapsed, -1, id);

    free(clientes);

    return 0;
}