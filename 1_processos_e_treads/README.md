<h1></h1>
Autor: Leonardo Campos<p>
linkedin: (https://www.linkedin.com/in/leonardo-de-oliveira-campos-60225720b/)

<h1></h1>
A explicação passo a passo da aplicação encontras-se na WIKI na barra superior deste repositório!
Click neste link para ser direcionado: https://github.com/leonardo8787/operational_systems/wiki

<h1></h1>

<h2>Dados gerais de compilação e afins</h2>

Este software foi produzido em ambiente virtual Linux, assim o meio de compilação utilizado foi o makefile que está na pasta "processos", é um makefile editado para uso pessoal, de forma a utilizar a depuração no processo de confecção e treads para compilações futuras. Vale ressaltar que alguns documentos .txt foram criados para fins de teste, e que não teêm nenhuma importância no montante final dos dados. Tendo essas informações em mente é hora de falar da compilação:

~~~
make clean 

make

make run
~~~

Caso queira registrar a saída do terminal em um arquivo para que fique mais fácil a vistoria dos resultados use o seguinte comando:

~~~
make clean && make 2> t.txt
~~~

Caso o custo esteja alto para máquina de testes, use o seguinte comando para dividir o processamento em vários núcleos através de treads de compilação:

~~~
make j(número de núcleos disponíveis do seu computador)
~~~

Para saber a quantidade de núcleos do seu computador basta jogar as informações do seu processador na internet!!!

<h1>Menu da aplicação</h1>

No menu inicial da aplicação é possível escolher por qual passo você vai, você pode ir passo a passo, para quem quer ver cada processo sendo executado. Você pode escolher fazer tudo de uma vez na opção 2, para quem quer ver a simulação mais rápida, utilizando o escalonamento FIFO. Já na terceira etapa temos a simulação utilizando o First Job como escalonador.

![image](https://user-images.githubusercontent.com/78708394/202824593-ebf3d1aa-3bbc-440f-9ddc-357e59cf9e39.png)

