# Jogo-da-Velha

- Integrantes do Grupo 09: Pedro Henrique, Pedro Galvão, Raphael Procopio e Tiago Cypriano

## Requisitos

- Compilador C (GCC)
- Sistema Operacional Windows, Linux ou MacOs
- Terminal / Prompt de Comando

## Compilação e Execução

No diretório onde estão os arquivos, execute o comando:

'''bash
gcc main.c -o jogo

Após a compilação, execute o programa:

Linux/MacOs:

./jogo

Windows:

jogo.exe

## Como jogar:
- Toda a interação com o jogo ocorre através do teclado.
- O jogador utiliza o teclado para escolher onde irá jogar, escolhendo a linha e a coluna.
- O jogador é representado por X
- O computador é representado por O
- O jogo termina quando há um vencedor ou quando o jogo empata

## Estratégia utilizada pelo computador:
O computador utiliza o algoritmo Minimax para tomar decisões durante o jogo. Esse algoritmo simula todas as jogadas possíveis a partir do estado atual do tabuleiro, considerando que o jogador humano também faça jogadas boas.

Cada estado final do jogo recebe uma pontuação:
- vitória do computador: valor positivo
- vitória do jogador: valor negativo
- empate: valor neutro

Com base nessa análise, o computador escolhe sempre a jogada que maximiza suas chances de vitória ou, no pior caso, garante o empate garantindo que nunca seja derrotado.


