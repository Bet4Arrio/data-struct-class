# Algoritmos e Complexidade
Nesta aula, iremos falar um pouco sobre algoritmos, técnicas comuns de projeto de algoritimos e o que deve ser analisado para determinar se um algoritmo é bom ou ruim.

## Oque é um algoritimo? 
Um algoritmo é uma sequência ordenada de passos ou instruções projetados para resolver um problema específico ou executar uma tarefa, tendo como entrada um cenário ou conjunto de dados e produzindo um resultado ou saída desejada após o processamento.

## Complexidade 
Supondo que um algoritmo realize a tarefa proposta para ele, podemos então fazer duas análises sobre ele para determinar a sua qualidade computacional.

1. Complexidade temporal:
    - Aqui medimos o consumo de  tempo  para a tarefa ser executada, contando a quantidade de instruções que serão executadas.
2. Complexidade de espaço:
    - Aqui medimos o consumo  de memória (RAM) será necessária para que o algoritmo seja executado.


### Notação Big O 

Para realizar essas análises, usamos uma notação chamada notação Big O. Ela é uma notação assintótica, ou seja, analisa o comportamento das coisas quando os valores são muito altos, ou seja, tendendo ao infinito. Existem algumas "classes" comuns  normalmente usadas para descrever os comportamentos, usadas tanto para medir tempo quanto espaço

| Notação| analise | Complexiadade |
| -------| -- | --------- |
| O(1)   | melhor impossivel |  constante independe do input sempre terá o mesmo consumo |
| O(ln N) |  bom | O consumo cresce aproximadamente seguindo a função da notação, sendo N o tamanho da entrada. |
| O(N)|  ok |  " "  |
| O(N ln N)| mais ou menos |  " "|
| O(N²)| ruim |   " " |
| O(2 ^ N)| muito ruim| " " |
| O(N!)| melhor troca de carreira | ""  |


* N é a notação que varia conforme o algoritmo, podendo ser o valor de um número, o tamanho de uma array, ou algo como o produto das dimensões de uma matriz, etc. Varia de caso a caso.



Essa notação consiste em analisar os algoritmos e extrair aproximadamente uma função que descreve o número de instruções ou memória usada. Uma dica é não se apegar aos pequenos números, focando apenas no panorama geral das coisas.

### Exemplos de analises
Vamos a alguns exemplos de códigos para que possamos visualizar melhor essa análise.




### Caso O(1)

Casos com complexidade de tempo O(1) costumam ser raros, como somas ou acesso a índices de alguma array.

```go
func soma(nums []int, index int) int{
    return nums[index] + index
}
```
``Tempo:`` O(1) considerando que, independentemente dos valores, ele acessará e somará.

``Espaço:`` O(1) Já que vai ser necessário uma variável inteira para "guardar a soma".

#### Busca simples

Supondo uma função que retorne o índice de um valor em um array.

```go
func busca(nums []int, valor int) int{
    for( i := 0; i < len(nums); i++){
        if(nums[i] == valor){
            return i
        }
    }
    return -1
}
```

``Tempo:`` O(N) Analisando o pior caso (quando o valor não existe ou é o último item da array), onde N é o tamanho da array.

``Espaço:`` O(1) Só é necessário espaço para retornar o índice.

#### Ordenação simples
Nesse caso, vamos fazer uma cópia do array e retornar de forma ordenada usando um algoritmo bem simples:

```go
func InsertionSort(nums []int) []int{
    var pivot int
    var ordenado []int
    ordenado  = make([]int, len(nums))
    for( i := 0; i < len(nums); i++){
        ordenado[i] = nums[i]
        for(j := i, j > 0 && (nums[j] > nums[i]); j--){
            pivot  = ordenado[j]
            ordenado[j] = ordenado[i]
            ordenado[i] = pivot
        }
    }
    return ordenado
}
```

``Tempo:`` O(N^2) Analisando o pior caso (quando a array está inversamente ordenada), para cada número adicionado na **ordenado**, precisamos percorrer toda ela para reorganizá-la. 

``Espaço:``: O(N), N é o tamanho do array que vou ter que criar a cópia.

#### Ordenação simple menor consumo de Espaço

No algoritmo acima, podemos diminuir o espaço dele ordenando na própria array, como segue o exemplo:


```go
func InsertionSort(nums []int){
    var pivot int
    for( i := 0; i < len(nums); i++){
        for(j := i, j > 0 && (nums[j] > nums[i]); j--){
            pivot  = nums[j]
            nums[j] = nums[i]
            nums[i] = pivot
        }
    }
}
```

``Tempo:`` O(N^2) Analisando o pior caso (quando a array está inversamente ordenada), para cada número adicionado na **ordenado**, precisamos percorrer toda ela para reorganizá-la. 

``Espaço:``: O(1) Só é necessário a variável pivot para fazer a troca de variável (às vezes a linguagem não mostra, mas ela é usada).


### Conclusão

As notações Big O fornecem uma base para entender como o seu algoritmo se comportará em termos de tempo de execução (número de instruções) ou uso de RAM. Essas notações não estão vinculadas a um hardware específico, então o mesmo algoritmo pode ter tempos de execução diferentes em milissegundos (ms) em computadores diferentes. Além disso, o consumo de recursos pode variar dependendo do tipo de dados sendo processados. No entanto, as notações Big O servem como um guia para avaliar se o desempenho do algoritmo está dentro de limites aceitáveis ou se precisa ser otimizado.

Portanto, é necessário avaliar o que cada máquina oferece para executar o algoritmo mais rapidamente. Podemos pensar em um algoritmo como o caminho para um lugar, e a máquina como a velocidade que podemos andar. Se quisermos chegar rapidamente a um lugar, podemos escolher um caminho mais curto e/ou andar mais rápido. Cada cenário deve ser avaliado separadamente para que se faça a melhor escolha.


Caso tenha interesse em ver como alguns algoritmos podem ser pensados:


[Este markdown contém explicações básicas de algumas estrategias de criar algoritimos](./Estrategias.md)
[Este markdown contém Exercicios para aplicação de algumas tecnicas](./Exercicios.md)