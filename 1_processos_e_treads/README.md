# Processos e Treads

Neste trabalho vamos construir um sistema de classificação cujas características nos permitirão observar conceitos importantes como: escalonamento e gestão de memória primária. Neste sistema, vamos considerar duas bases de dados D e T. A base D será utilizada para simular a inicialização, fornecendo assim o conceito de bootstrapping, tal como no sistema operacional.

Já a base T representará os processos a serem executados, cada um produzindo uma série de computações pesadas e necessárias, as quais vamos coordenar utilizando um sistema de escalonamento em dois níveis: mecanismo e política. Além disso, abordaremos o conceito de memória tratando de chavear os processos entre memória primária e processador, claro, tudo de forma simulada para que possamos extrair resultados mensuráveis para avaliação.

<strong>Etapa I:</strong> Elaboração das tabelas hash para itens e classes. Dado uma linha do arquivo, considerar item as colunas de 0 a n - 1. Considere a coluna n de cada linha como classe. Nessas tabelas é preciso armazenar cada item como chave e seus índices no arquivo como valor. Considere como índice a linha que aquele valor específico aparece. Considere também item específico aquele item pertencente a coluna x. Logo, para itens de mesmo valor, a indexação deve ser feita de forma separada, ou seja, se um item aparece na coluna 1 e 3 com valor 23.4, considere como chave da hash (1, 23.4) e (3,23.4). Repita esse processo para as classes, armazenando como chave sua descrição e como valor suas indexações.

<strong>Etapa II:</strong> Agora vamos considerar o conteúdo de T. Leia o conteúdo de T em uma Fila em que cada posição detenha uma linha inteira já tokenizada. O tipo Vector do C++ consegue auxiliar vocês nessa tarefa. Depois de carregar todo o conteúdo de T, processar linha a linha. Considere como processar a ação de comparar os itens de T com a tabela hash de itens, selecionando apenas os itens em comum. Feito isso, realize a permutação dos itens comuns de 1 a N, com N definido estaticamente com define diretamente no código. Armazene todas as permutações de uma entrada em T em um segundo Vector.

<strong>Etapa III:</strong> Para cada permutação encontrada vocês precisam buscar individualmente os valores dos itens em hash, executando em seguida uma interseção desses valores. Se a interseção for não nula, aplique essa na hash de todas as classes. A classe que apresentar um valor de sobreposição maior após processar todas as permutações será apresentada como classe da tarefa em T.

<strong>Etapa IV:</strong> Elaborar um cache utilizando uma hash para armazenar o resultado das interseções já realizadas. Adote como chave as permutações e como valor o resultado das interseções. Feito isso, modifique o algoritmo para trabalhar da seguinte forma: Para cada nova permutação, buscar em cache se há resultado já processado. Em caso afirmativo, apenas teste as classes para o resultado. Caso contrário, faça toda a computação envolvida.

<strong>Etapa V:</strong> Como as tarefas em T estão espalhadas não tem como sabermos o quão importante é a cache, uma vez que estamos utilizando apenas uma política do tipo Round Robin para escalonar. Então, sua função é criar uma política que organize melhor as tarefas para a sequência de execução aproveite melhor as computações já realizadas. Para isso, pense em organizar melhor os parâmetros de entrada de forma a encontrar grandes sobreposições de itens similares.

<strong>Etapa VI:</strong> Vamos implementar uma memória primária para chavear processos. Nesse modelo, uma tarefa não será concluída por completo porque se seu tempo de CPU acabar você a colocará em um espaço de memória para aguardar nova submissão. Vamos analisar nessa etapa os impactos do chaveamento, da organização de memória e suas diferentes hierarquias.


<h2>Resuloções Etapa 1</h2>

<p align = "center">
    <strong>Menu</strong>

<p align = "center">
    <img src="https://github.com/leonardo8787/operational_systems/blob/main/imagens/menu%20.png" width="350"></img>
    
No Menu é possível ver todas as opções do software, até o presente momento. Para a primeira atividade foi proposto a procura de numerais dentro de uma pequena base de dados, informando a quantidade de aparições e suas respectivas posições. Para uma melhor compreensão segue as imagens dos resultados:


<p align = "center">
    <img src="https://github.com/leonardo8787/operational_systems/blob/main/imagens/leituraD.png" width="350"></img>

Esta primeira leitura dos dados é essencial para que as informações sejam inseridas na Tabela Hash. A tabela Hash foi usada para manutenção dos dados visto que a sua procura tem custo associado a O(1). Em seguida é mostrado a busca pelos números das flores e suas posições.

<p align = "center">
    <img src="https://github.com/leonardo8787/operational_systems/blob/main/imagens/procuraD.png" width="350"></img>
    
Na imagem acima o primeiro colchete indica quantas vezes a flor aparece, sendo ligada a seguinte equação matemática: n-1; na frente dos dois pontos é possível ver a incidência de cada numeral. A próxima imagem mostra os nomes das flores por index:

<p align = "center">
    <img src="https://github.com/leonardo8787/operational_systems/blob/main/imagens/leituraFlor.png" width="350"></img>


<h2>Resoluções Etapa 2</h2>

O menu da etapa 2 será o mesmo da etapa 1; Sendo assim a primeira opção escolhida para resolução será a opção 7, para tokenizar a linha e guardala por completo, para que seja feita a busca.

// em andamento ...

<h1>Referências</h1>

 *  SistemasOperacionaisModernosTanenbaum4Edio [1]
