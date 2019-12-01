# Campo-Minado
Um código que gera um campo minado alocado dinamicamente.
![Logo](https://user-images.githubusercontent.com/50359547/69586461-6a046880-0fc1-11ea-89aa-247a28c0f629.png)


# Funcões
Campominado - campominado(int n).

Essa função aloca a matriz que vai servir de matriz secundária, onde será feita a colocação das bombas. Na chamada dessa função é necessário adicionar um valor inteiro que vai servir para definir a dificuldade (quanto mais perto de 2, mais bombas serão geradas).

Dificuldade - dificuldade().

É uma função void que que pegar um valor digitado pelo usuário entre 2 a 8 e categoriza esses valores em níveis (2 - Díficil e 8 - Fácil).

Criar - criar ()

Função void, que aloca dinamicamente uma matriz global utilizando os valores de linhas e colunas também globais, que são definidos dentro do main do código.

Jogar - jogar(m,n)

Função que vai acontecer o jogo de uma visão se o usuário acertou ou não uma bomba a partir de uma função "bombas" que a recebe a posição digitada pelo usuário e retorna 0 se ele continua vivo (não acertou uma bomba) ou 1 se ele acertou uma bomba, o jogo se encerra se o usuário acerta alguma bomba.
