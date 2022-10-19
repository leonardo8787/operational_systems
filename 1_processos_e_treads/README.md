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

Ao entrar no software haverá algumas mudanças no software em relação a versão anterior entregue ao professor. Vale ressaltar que alguns partes do desenvolvimento mudei alguns parâmetros da primeira etapa, sem alterar os resultados finais, mas para melhor desenvolvimento do código. Voltando a portabilidade do software, há um menu que leva o usuário direto as etapas a serem seguidas, na primeira etapa é necessário clicar na primeira e na segunda opção, para que a tabela HASH seja carregada. Seguindo o usuário terá que voltar digitando no terminal a opção 111, voltando ao menu principal, onde há as escolhas das etapas, agora será escolhida a segunda opção. Na segunda opção o usuário clicará na primeira opção, onde o arquivo T será carregado no vector, em seguida a opção 2, onde as informações serão processadas, por fim na opção três para que os dados sejam arquivados em um arquivo.txt. 

Em relação ao funcionamento do software, o núcleo central da aplicação é a leitura de arquivos inserindo-os em uma tabela hash e depois checando as suas aparições nos arquivos D e T. Para isso foi usado uma estrutura simples de leitura de arquivo que joga todas as informações tokenizadas para dentro da tabela hash, depois é chegada a hora de comparar os resultados da tabela T com os resultados da tabela D, utilizando um vetor para os dados tokenizados do arquivo T em comparação com os arquivos da tabela hash, que é dividida em chave e valores, sendo que as comparações são feitas utilizando a chave de cada hash. Assim sendo feitas tais comparações é hora de achar os dados que estão iguais no mesmo index de ambos arquivos. Depois desses passos o software faz uma combinação entre os valores escrevendoos em um arquivo txt. Assim foi elaborado o software até o presente momento. 


<h2>Etapa 3</h2>

Para esta terceira etapa reorganizei a etapa 2 para que pudesse estar no padrão para as intersecções e combinações que a terceira iria exigir, assim foi melhorado a parte das combinações, utilizando um algoritmo pre moldado de combinações, além de separar em classes os itens pegos na primeira etapa, para que pudesse ser realizada a última demanda da Etapa 3. Assim para o cumprimento da atual etapa guardei as combinações num arquivo para que eu pudesse lê-lo e tokeniza-lo assim poderia comparar com a tabela hash do exercício 1 e tirar as intersecções. Segue abaixo o código usado para tal:

~~~
void interseccaoEntreLinhas(){
    cout<<"Intersecções entre as combinações e a Hash 1"<<endl;
    string line;
    char *output;
    char *token;
    ifstream myfile ("src/texto.txt"); 
    if (myfile.is_open()){
        while (! myfile.eof() ){
            for (auto mapIt = begin(texto); mapIt != end(texto); ++mapIt){ 
                getline (myfile,line);
                output = const_cast<char *>(line.c_str());
                token = strtok(output, ",");
                if(mapIt->first == token){
                    cout<<token<<endl;
                    encontroCombinacoes.push_back(token);
                }
            }
        }
        myfile.close();
    }
    else cout << "Não abriu o arquivo!!"; 
    myfile.close();
}
~~~

Na segunda parte do trabalho foi pedido a intersecção dos valores da combinação com os valores de cada classe de flor para que pudessemos encontrar a classe que tivesse mais iterações, entretando como o tempo não jogou ao meu favor nessas últimas semanas não pude concluir esta etapa do processo, sendo preterida para a Etapa 4.

<strong>Compilação</strong><p>
    
    Para utilizar o software e observar os passos é necessário seguir a ordem de etapas e dentro delas seguir a ordem crescente de opções, clicando em todas para que possa ser carregado os processos. Vale ressaltar que nessa etapa não teve apenas a implementação dos requesitos da terceira etapa mas sim a melhora da primeira etapa e melhora da combinação da segunda etapa, sendo um trabalho bem mais abrangente do que as etapas anteriores. O programa foi feito em ambiente Windows 11, sendo executado no WSL(virtualizador do Linux Ubuntu), utilizando makefile. 

<h2>Etapa 4</h2>

<h1>Referências</h1>

 *  SistemasOperacionaisModernosTanenbaum4Edio [1]
