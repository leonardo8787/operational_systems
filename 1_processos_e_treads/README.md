# Processos

Neste trabalho vamos construir um sistema de classificação cujas características nos permitirão observar conceitos importantes como: escalonamento e gestão de memória primária. Neste sistema, vamos considerar duas bases de dados D e T. A base D será utilizada para simular a inicialização, fornecendo assim o conceito de bootstrapping, tal como no sistema operacional.

Já a base T representará os processos a serem executados, cada um produzindo uma série de computações pesadas e necessárias, as quais vamos coordenar utilizando um sistema de escalonamento em dois níveis: mecanismo e política. Além disso, abordaremos o conceito de memória tratando de chavear os processos entre memória primária e processador, claro, tudo de forma simulada para que possamos extrair resultados mensuráveis para avaliação.

<strong>Etapa I:</strong> Elaboração das tabelas hash para itens e classes. Dado uma linha do arquivo, considerar item as colunas de 0 a n - 1. Considere a coluna n de cada linha como classe. Nessas tabelas é preciso armazenar cada item como chave e seus índices no arquivo como valor. Considere como índice a linha que aquele valor específico aparece. Considere também item específico aquele item pertencente a coluna x. Logo, para itens de mesmo valor, a indexação deve ser feita de forma separada, ou seja, se um item aparece na coluna 1 e 3 com valor 23.4, considere como chave da hash (1, 23.4) e (3,23.4). Repita esse processo para as classes, armazenando como chave sua descrição e como valor suas indexações.

<strong>Etapa II:</strong> Agora vamos considerar o conteúdo de T. Leia o conteúdo de T em uma Fila em que cada posição detenha uma linha inteira já tokenizada. O tipo Vector do C++ consegue auxiliar vocês nessa tarefa. Depois de carregar todo o conteúdo de T, processar linha a linha. Considere como processar a ação de comparar os itens de T com a tabela hash de itens, selecionando apenas os itens em comum. Feito isso, realize a permutação dos itens comuns de 1 a N, com N definido estaticamente com define diretamente no código. Armazene todas as permutações de uma entrada em T em um segundo Vector.

<strong>Etapa III:</strong> Para cada permutação encontrada vocês precisam buscar individualmente os valores dos itens em hash, executando em seguida uma interseção desses valores. Se a interseção for não nula, aplique essa na hash de todas as classes. A classe que apresentar um valor de sobreposição maior após processar todas as permutações será apresentada como classe da tarefa em T.

<strong>Etapa IV:</strong> Elaborar um cache utilizando uma hash para armazenar o resultado das interseções já realizadas. Adote como chave as permutações e como valor o resultado das interseções. Feito isso, modifique o algoritmo para trabalhar da seguinte forma: Para cada nova permutação, buscar em cache se há resultado já processado. Em caso afirmativo, apenas teste as classes para o resultado. Caso contrário, faça toda a computação envolvida.

<strong>Etapa V:</strong> Como as tarefas em T estão espalhadas não tem como sabermos o quão importante é a cache, uma vez que estamos utilizando apenas uma política do tipo Round Robin para escalonar. Então, sua função é criar uma política que organize melhor as tarefas para a sequência de execução aproveite melhor as computações já realizadas. Para isso, pense em organizar melhor os parâmetros de entrada de forma a encontrar grandes sobreposições de itens similares.

<strong>Etapa VI:</strong> Vamos implementar uma memória primária para chavear processos. Nesse modelo, uma tarefa não será concluída por completo porque se seu tempo de CPU acabar você a colocará em um espaço de memória para aguardar nova submissão. Vamos analisar nessa etapa os impactos do chaveamento, da organização de memória e suas diferentes hierarquias.


<h2>Resuloções Etapa 1</h2>

Para resolução da etapa 1 usei um "unoder_map" para ser a hash dos itens D, no qual seria alocados os números como chave e suas aparições como valores.
![image](https://user-images.githubusercontent.com/78708394/197238271-dc03a069-d6c3-4ec0-a2f0-ab71ef59f918.png)

<strong>Menu</strong><p>
Através do menu é possível acessar cada processo individualmente, foi melhor fazer dessa forma para que fosse obtido o resultado visual das iterações entre processos, assim é necessário que o usuário clique em todas as opções em ordem crescente, para que tenha o resultado de cada processo individualmente e seja carregado para os processos subsequêntes, assim se o usuário pular uma opção os processos não estarão carregados para exucição desta. Isso vale para todas as etapas.
![menu etapa 1](https://user-images.githubusercontent.com/78708394/197241245-1623224e-8711-44db-941a-58dbb70e3634.png)


<h2>Resolução Etapa 2</h2>

![etapa 2](https://user-images.githubusercontent.com/78708394/197240421-2064cae4-452f-4952-90e4-0c1c3ac61665.png)

<strong>Menu</strong><p>
![menu etapa 2](https://user-images.githubusercontent.com/78708394/197241288-577cec32-de0a-4f89-a259-23d82bed7302.png)


<h2>Resolução Etapa 3</h2>

![etapa 3](https://user-images.githubusercontent.com/78708394/197240533-71488f10-6607-4af8-9257-9c2b4a9dd133.png)

<strong>Menu</strong><p>
![menu etapa 3](https://user-images.githubusercontent.com/78708394/197241332-dfa3a214-2308-474e-ac20-f8135f97caf6.png)

<h2>Resolução Etapa 4</h2>

![etapa 4](https://user-images.githubusercontent.com/78708394/197239728-617f40e4-7960-46ec-87a1-bbe6236eb0f9.png)

<strong>Menu</strong><p>
![menu etapa 4](https://user-images.githubusercontent.com/78708394/197241358-54ce980a-da46-4f06-808a-0beaf65d6048.png)


<h1>Referências</h1>

 *  SistemasOperacionaisModernosTanenbaum4Edio [1]
