# Programs, Processos e Threads, Processedores, Sistemas Operacionais
Um breve resumo sobre como os programas rodam


## Processador 
O processador é  centro de operações de um computador, ele se encarrega de ler, interpreta e executar instruções que recebe.

A execução  instruções ocorrem em um nucleo, que é responsevel por de acordo com as instruções que recebe, buscar dados da memoria, e trabalhar em cima deles (mudar de lugar, mudar valores, comparar, etc)

## Oque um Programa?
Um programa nada mais é que um conjunto de instruções em codigo de maquina para uma arquitetura de processados, este esta salvo em uma memoria não volatil como HDs ou SSDs.
- As Intruções do programas, são feitas pra um Sistema Operacional e uma arquitetura de processados especifica
    - processadores diferentes tem instruçãoes diferentes

## Processos
Um Processos seria a execução de um Programa, de modo similar a uma objetor ser a instancia de uma classe. Quem se encarrega de executar um processo de forma minimamente segura é o Sistema Operacional (OS).

Ao iniciar um Processo o Sistema Operacional Criar um **PCB (Process Control Block)** que fica na memoria RAM (assim como o programa) esse bloco é o responsavel por ter informações necessarias pra OS executar programa, como:
- area de memoria que processo está usando 
- arquivos ele abriu
- pID (Process ID)
- limites de memoria (onde começa e onde termina),
- entre outras informaçõe,
- cada OS tem campos seus proprios para seus PCBs.


### Processo na memoria 
Uma vez que tenha criado o PCB o processo na memoria apresenta uma organização de "areas", que seriam


| Syntax | Description |
| ----------- | ----------- |
| **Stack** |  Aqui é um pilha onde tem a proxima instruçãos a ser feita
| **Heap** |  Aqui fica os dados alocados dinamicamente enquanto o processo roda
| **Data** |  Aqui os dados estaticos do programa 
| **Code** |  aqui fica as instruções do programa

* Conforme o programa executa, ela vai acumulando passos na stack, que cresce para o lado da Heap que por sua vez cresce para o lado da Stack conforme vai alocando memoria. 
* conforme vai crescendo a stack/heap o OS cuida de mudas os limites de memoria no PCB (e o local do programa na memoria se necessario)

### Threads 

Todo Processo tem no minimo uma Thread entre tantanto pode ter varias Threads, cada thread tem Stack e Heap.
Na pratica oque é enviado para o processador são as threads em si, elas rodas nos nucloes dos processados



**Não condufundir threads dos processadores com Threads do Sistema operacional**

## System Calls
Muitas operções de um processos, como alocar mais memoria (mudar tamanho da heap), abrir aquivos, mostrar coisas, se comunicar com outro processo, ou com a rede, Não são 100% feitas pelo processos.

Os Processus usam de System Calls, passam para o sistema a responsabilidade de receber os Dados de forma correta e passam para o programa. Isso ocorre por questões de segurança ja que trabalhar diratamente com o hardware pode ser danoso pro proprio OS caso tenha algum  programador não siga padrões do proprio OS para trabalhar com isso. 