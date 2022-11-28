## Este repositório contempla os exemplos de Swarm do Livro Docker, criado pela turma de computação 2020 do CEFET-MG

O modo Swarm é um recurso do Docker que fornece funcionalidades de orquestração de contêiner, incluindo clustering nativo de hosts do Docker e agendamento de cargas de trabalho de contêineres. Um grupo de hosts do Docker formam um cluster "Swarm" quando seus mecanismos do Docker estão em execução juntos no "modo Swarm". Em português seria algo como "modo enxame".

![dockerswarm1](https://user-images.githubusercontent.com/78708394/204395465-8cfcc3c5-62ba-42a4-8c01-2afa3d0faab4.png)

As versões atuais do Docker incluem o modo de swarm para gerenciar nativamente um cluster dos Docker Engines chamados de swarm. Os principais destaques deste recurso são: Gerenciamento de cluster integrado ao Docker Engine, Design descentralizado, Modelo de serviço declarativo, escala, reconciliação estatal desejada, rede multi-host, descoberta de serviço, balanceamento de serviço, balanceamento de carga, seguro por padrão e atualizações sem intermitência. Estas são as principais funcionalidades do Swarm ferramenta que vem em uma constante crecente no meio DevOps. 

Bom tendo uma breve introdução feita, é hora de ir para os exemplos do livro.

## Exemplo 1

Nesse primeiro exemplo criei um arquivo Go para fazer uma pequena página web para subirmos para um conteiner e usarmos o swarm. O código ficou da seguinte maneira:

~~~
func main() {
http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
    w.Write([]byte("<h1>Hello World</h1>"))
})  
http.ListenAndServe(":8080", nil)
}
~~~

Para rodar o código e ver a página basta digitar a seguinte sentença no terminal:

~~~
go run server.go
~~~

Após essa execução entre no seu navegador e digite:

~~~
localhost:8080
~~~

Agora é hora de colocarmos em conteineres, para isso vamos criar um manifesto Docker para fazermos uma imagem da aplicação.

~~~
FROM golang:1.16
COPY . .
RUN go build -o server server.go
CMD ["./server"]
~~~

Após a criação do arquivo Dockerfile vamos executalo no terminal com a seguinte sentença:

~~~
docker build -t nome_do_seu_docker/nome_do_dominio:latest .
~~~

Criada a imagem é hora de subir a imagem para o Docker com o Docker push:

~~~
docker push (nome_do_dominio):latest
~~~

Depois vamos direcionar a porta 8080 do meu computador para porta 8080 do docker com o seguinte comando:

~~~
docker run -rm -p 8080:8080 nome_do_seu_docker/nome_do_dominio:latest
~~~

Agora vamos iniciar o swarm com o seguinte comando:

~~~
docker swarm init --advertise--addr (número de IP)
~~~

Tendo feito o comando acima o swarm foi ativado, para ver os clusters online, digite o seguinte comando:

~~~
docker node list
~~~

## Exemplo 2

Neste exemplo vamos usar o swarm em aplicativos com arquivos de configuração de pilha. O Swarm nunca cria contêineres individuais. Em vez disso, todas as cargas de trabalho do Swarm são agendadas como serviços, que são grupos escalonáveis de contêineres com recursos de rede adicionais mantidos automaticamente pelo Swarm. Todos os objetos Swarm podem ser escritos em manifestos chamados arquivos de pilha, estes manifestos são para criar imagens do container para assim conseguir fazer a "orquestração". Esses arquivos são os .YAML, estes descrevem todos os componentes e configurações do seu aplicativo Swarm e podem ser usados para criar e destruir facilmente seu aplicativo em qualquer ambiente Swarm.

Vamos fazer um arquivo de teste, o qual recebera o seguinte nome: "arquivo-teste".

~~~
version: '3.7'

services:
  bb-app:
    image: arquivo-teste
    ports:
      - "8000:3000"
~~~

Neste exemplo temos apenas um objeto do arquivo YAML do Swarm, nele é descrito o grupo escalonável de contêineres idênticos. Nesse caso, vocÊ obterá apenas um único contêiner padrão. Também definimos que todo o tráfego que chega à porta 8000 em nossa máquina de desenvolvimento vá para a porta 3000 dentro do contêiner.

Para implantar o aplicativo que fizemos usando o arquivo YAML, vamos digitar a seguinte sentença no terminal:

~~~
docker stack deploy -c bb-stack.yaml demo
~~~

Se tudo estiver dentro dos conformes, o Swarm relatará a a criação de todos os seus objetos de pilha sem reclamações no terminal, algo nesse sentido:

~~~
Creating network demo_default
Creating service demo_bb-app
~~~

Observe que, além do serviço, o Swarm também cria uma rede do Docker por padrão para isolar os contêineres implantados como parte de sua pilha.

Para se certificar que tudo deu certo execute o seguinte comando no termianal:

~~~
docker service ls
~~~

Tudo estará nos conformes se for retornado as seguintes réplicas:

~~~
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
il7elwunymbs        demo_bb-app         replicated          1/1                 getting-started:latest   *:8000->3000/tcp
~~~

Isso indica que 1/1 contêiner que você solicitou como parte de seus serviços estão em funcionamento. Além disso, vemos que a porta 8000 em sua máquina de desenvolvimento está sendo encaminhada para a porta 3000 em seu contêiner de introdução. Digitando o "localhost:8000" você acessa a aplicação.

Em caso de destruição do aplicativo, digite a seguinte sentença em seu terminal:

~~~
docker stack rm demo
~~~

