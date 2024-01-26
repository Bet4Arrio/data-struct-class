# Programas, Processos e Threads, Processadores, Sistemas Operacionais.

Um breve resumo sobre como os programas rodam

[Este markdown contém explicações básicas da linguagem C.](./BASICOC.md)

[Este pdf contém a apresentação da primeira aula](./Programas.pdf)

## Processador

O processador é o centro de operações de um computador; ele se encarrega de ler, interpretar e executar as instruções que recebe.

A execução das instruções ocorre em um núcleo, que é responsável por executar as instruções recebidas, buscar dados da memória e trabalhar com eles (mudar de lugar, alterar valores, comparar, etc.).

## O que é um programa?

Um programa nada mais é do que um conjunto de instruções em código de máquina para uma arquitetura de processadores. Este está armazenado em uma memória não volátil, como HDs ou SSDs.

- As instruções do programa são projetadas para um Sistema Operacional e uma arquitetura de processadores específicos.

  - Processadores diferentes possuem instruções diferentes.

## Processos

Um processo seria a execução de um programa, de modo semelhante a um objeto ser uma instância de uma classe. Quem se encarrega de executar um processo de forma minimamente segura é o Sistema Operacional (SO).

Ao iniciar um processo, o Sistema Operacional cria um **PCB (Process Control Block)** que fica na memória RAM (assim como o programa). Esse bloco é responsável por conter informações necessárias para que o sistema operacional execute o programa, tais como:

- Área de memória que o processo está usando.
- Arquivos que ele abriu.
- PID (Process ID).
- Limites de memória (onde começa e onde termina).
- Entre outras informações.
- Cada sistema operacional tem campos próprios para seus PCBs.

### Processo na memória.

Uma vez que tenha criado o PCB, o processo na memória apresenta uma organização de "áreas", que seriam

| Syntax    | Description                                                           |
| --------- | --------------------------------------------------------------------- |
| **Stack** | Aqui é uma pilha onde estão as próximas instruções a serem executadas |
| **Heap**  | Aqui ficam os dados alocados dinamicamente enquanto o processo roda   |
| **Data**  | Aqui estão os dados estáticos do programa                             |
| **Code**  | Aqui ficam as instruções do programa                                  |

- Conforme o programa executa, ele vai acumulando passos na stack, que cresce em direção à Heap, a qual, por sua vez, cresce em direção à Stack conforme aloca memória.
- Conforme a stack/heap vai crescendo, o sistema operacional cuida de mudar os limites de memória no PCB (e o local do programa na memória, se necessário).

### Threads

Todo processo tem, no mínimo, uma thread, mas pode ter várias threads. Cada thread possui sua própria stack e heap. Na prática, o que é enviado para o processador são as threads em si, as quais rodam nos núcleos dos processadores.

**Não confundir threads dos processadores com threads do sistema operacional.**

## System Calls

Muitas operações de um processo, como alocar mais memória (mudar o tamanho da heap), abrir arquivos, exibir informações, comunicar-se com outros processos ou com a rede, não são realizadas diretamente pelo processo.

Os processos utilizam System Calls, transferindo para o sistema a responsabilidade de receber os dados de forma correta e, em seguida, repassam os resultados para o programa. Isso ocorre por questões de segurança, uma vez que lidar diretamente com o hardware pode ser prejudicial para o próprio sistema operacional, caso algum programador não siga os padrões estabelecidos pelo próprio sistema operacional para manipular essas operações.
