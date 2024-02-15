# Algoritimos e Complexidade
Nesta aula, iremos falar um pouco sobre algoritmos, técnicas comuns e o que deve ser analisado para determinar se um algoritmo é bom ou ruim.

## Oque eh um algoritimo? 
Um algoritmo é uma sequência ordenada de passos ou instruções projetados para resolver um problema específico ou executar uma tarefa, tendo como entrada um cenário ou conjunto de dados e produzindo um resultado ou saída desejada após o processamento.

## Complexidade 
Supondo que um algoritmo realize a tarefa proposta para ele, podemos então fazer duas análises sobre ele para determinar a sua qualidade computacional.

1. Complexidade temporal:
    - Aqui medimos o consumo de  tempo demoraria para a tarefa ser executada, contando a quantidade de instruções que serão executadas.
2. Complexidade de espaço:
    - Aqui medimos o consumo  de memória (RAM) será necessário para que o algoritmo seja executado.



### Notação Big O 

Para realizar essas análises, usamos uma notação chamada notação Big O. Ela é uma notação assintótica, ou seja, analisa o comportamento das coisas quando os valores são muito altos, ou seja, tendendo ao infinito. Existe algumas "classes" comuns normalmente usadas para descrever os comporamentos, é usada tanto para medir tempo quando espaço 

| Notação| analise | Complexiadade |
| -------| -- | --------- |
| O(1)   | melhor impossivel |  constante idependete do input sempre tera o mesmo consumo |
| O(ln N) |  bom | o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do input) |
| O(N)|  ok |  o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do input ) |
| O(N ln N)| mais o menos |  o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do) input|
| O(N²)| ruim ate |  o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do input )|
| O(2 ^ N)| muito ruim| o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do input) |
| O(N!)| melhor troca de carreira |o consumo cresce aproximadamente  seguindo a função da da notação ( sendo N o tamanho do input)  |


* N eh a notação que varia do algoritimo, pode ser o valor de um numero, tamanho de um array, ou algo como produto da dimensão de uma matriz, etc, varia de caso a caso.


Essa notação consiste em analisar os algoritmos e extrair aproximadamente uma função que descreve o número de instruções ou memória usada. Uma dica é não se apegar aos pequenos números, focando apenas no quadro geral das coisas.

### Exemplos de analises
vamos a alguns exemplo de codigos para que possamos visuzalizar melhor essa analise



### Caso O(1)
Casos com complexidade de tempo O(1) costumam ser poucos, como somas ou acessar index de alguma array
r
```go
func soma(nums []int, index int) int{
    return nums[index] + index
}
```
``Tempo:`` O(1) para tempo, sendo que independente dos valores, ele vai acessar e somar.

``Espaço:`` O(1) ja que vai precisar de 1 varivavel interia pra "guardar a soma"

#### Busca simples
supondo uma função que retorne o Index de uma valor em um array
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

``Tempo:`` O(N) Analisando o pior caso (o valor não existe ou é o último item da array), onde N é o tamanho da array.

``Espaço:``: O(1), So precisa de espaço para retorna o index

#### Ordenação simples
Nesse caso, vamo fazer uma copia  do array e retornar de forma ordenada usando um algoritimo bem simples:

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

``Tempo:`` O(N^2) Analisando o pior caso (a array ta inversamente ordenada) para cada numero adicionado na **ordenado** temos que passar por toda ela pra reoganizar 

``Espaço:``: O(N), N o tamanho do Array qua vou ter que criar a copia

#### Ordenação simple menor consumo de Espaço

No a algoritimo a cima podemos diminuir o espaço dele ordenando na propria array  como segue o exemplo:


```go
func InsertionSort(nums []int){
    var pivot int
    for( i := 0; i < len(nums); i++){
        ordenado[i] = nums[i]
        for(j := i, j > 0 && (nums[j] > nums[i]); j--){
            pivot  = nums[j]
            nums[j] = nums[i]
            nums[i] = pivot
        }
    }
}
```
``Tempo:`` O(N^2) Analisando o pior caso (a array ta inversamente ordenada) para cada numero adicionado na **ordenado** temos que passar por toda ela pra reoganizar 

``Espaço:``: O(1), sempre precisa da variavel pivot para fazer a troca de variavel ( as vezes a linguagem não mostra mas ela usa)


### conclusão

As notações Big O fornecem uma base para entender como o seu algoritmo se comportará em termos de tempo de execução (número de instruções) ou uso de RAM. Essas notações não estão vinculadas a um hardware específico, então o mesmo algoritmo pode ter tempos de execução diferentes em milissegundos (ms) em computadores diferentes. Além disso, o consumo de recursos pode variar dependendo do tipo de dados sendo processados. No entanto, as notações Big O servem como um guia para avaliar se o desempenho do algoritmo está dentro de limites aceitáveis ou se precisa ser otimizado.

Então, temos que avaliar o que cada máquina oferece para executar o algoritmo mais rapidamente. Podemos pensar em um algoritmo como o caminho para um lugar, e a máquina como a velocidade que podemos andar. Se quisermos chegar rapidamente a um lugar, podemos escolher um caminho mais curto e/ou andar mais rápido. Cada cenário deve ser avaliado separadamente para que se faça a melhor escolha.


Caso tenha interesse em ver como algums algoritimos podem ser pensados:

[Este markdown contém explicações básicas de algumas estrategias de criar algoritimos](./Estrategias.md)