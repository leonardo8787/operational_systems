<h2>Sumário</h2>

* Introdução
* Conceitos Iniciais
* Breve estudo da arte
* Arquitetura dos Sistemas Operacionais
* Processos
* Sistemas de Arquivos
* Um breve comparativo
* Tipos de estruturas de um sistema operacional
* Bootstrapping

<h2>Conceitos Iniciais</h2>

* Criação de programas que possam utilizar o alto poder computacional para possibilitar que todo o conjunto (hardware e software) trabalhe corretamente;
* Otimizar a capacidade de processamento buscando melhorar o desempenho e a garantia de execução de tarefas no menor tempo possível;
* Sincronizar as aplicações gerando mecanismos de controle de concorrência;

<strong>O que é um sistema operacional? </strong><p>

* <strong>É uma máquina estendida</strong>, tem a capacidade de ocultar detalhes complitados e execuções em hardware, como também, apresenta-se para o usuário como uma máquina virtual mais agradável de se utilizar.

* <strong>É um gerenciador de recursos</strong>, Gerencia a utilização de todos recursos disponíveis para os usuários fazendo uso de conceitos de tempo e espaço para ser justo ao decorrer das solicitações.

<p align = "center">
    <img src="https://image.slidesharecdn.com/cap01-111104074542-phpapp01/85/tanenbaum-sistemas-operacionais-cap-01-3-320.jpg?cb=1320393051" width="350"></img>

<h2>Arquitetura dos Sistemas Operacionais</h2>

* Sistema mono-processadores: Encontrados desde PDA's a Mainframes.
* Sistemas multi-processadores: Apresentam throughput aumentado, economia de escala e confiabilidade aumentada - SMP's (multiprocessamento simétrico). Um exemplo é o chamado servidor blade cujo objetivo é multiplicar os recursos de hardware para maximizar o poder de processamento.
* Sistemas embarcados: Sstemas que estão contidos em chips e executam operações limitadas - Smart Cards, Iot.
* Sistemas Agrupados: Fazem uso de múltiplas máquinas para executar suas tarefas e prover alta disponibilidade - Clusters, Sistemas Distribuídos, Grids, Cloud.

<h2>Processos e Arquivos</h2>

Todo sistema é constituído de dois conjuntos básicos: processos e arquivos.

* Um processo é basicamente, a grosso modo, um programa em execução.
* Processos são compostos de, código executável, dados, atribuídos do código, pilha de execução, registradores de hardware e conjunto de instruções.
* Para que dois ou mais processos troquem informação o Sistema Operacional faz uso dos chamados pipes.




