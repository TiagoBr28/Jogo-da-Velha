#include <stdio.h>
#include <stdbool.h>

#define HUMANO 'X'
#define COMPUTADOR 'O'
#define VAZIO ' '

char tabuleiro[3][3];

/* Inicializa o tabuleiro */
void iniciarTabuleiro() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = VAZIO;
}

/* Mostra o tabuleiro */
void mostrarTabuleiro() {
    printf("   0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            printf("[%c]", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("\n");
    }
}

/* Verifica vitória */
bool verificarVitoria(char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;

        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true;
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;

    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;

    return false;
}

/* Verifica empate */
bool verificarEmpate() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == VAZIO)
                return false;
    return true;
}

/* ---------- MINIMAX ---------- */

int minimax(bool ehMax) {

    if (verificarVitoria(COMPUTADOR)) return 10;
    if (verificarVitoria(HUMANO)) return -10;
    if (verificarEmpate()) return 0;

    if (ehMax) {
        int melhor = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    tabuleiro[i][j] = COMPUTADOR;
                    int valor = minimax(false);
                    tabuleiro[i][j] = VAZIO;
                    if (valor > melhor)
                        melhor = valor;
                }
            }
        }
        return melhor;
    } else {
        int melhor = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == VAZIO) {
                    tabuleiro[i][j] = HUMANO;
                    int valor = minimax(true);
                    tabuleiro[i][j] = VAZIO;
                    if (valor < melhor)
                        melhor = valor;
                }
            }
        }
        return melhor;
    }
}

/* Jogada do computador */
void jogadaComputador() {
    int melhorValor = -1000;
    int linha = -1, coluna = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == VAZIO) {
                tabuleiro[i][j] = COMPUTADOR;
                int valor = minimax(false);
                tabuleiro[i][j] = VAZIO;

                if (valor > melhorValor) {
                    melhorValor = valor;
                    linha = i;
                    coluna = j;
                }
            }
        }
    }

    tabuleiro[linha][coluna] = COMPUTADOR;
}

/* Jogada de um jogador */
void jogadaJogador(char simbolo) {
    int linha, coluna;
    do {
        printf("Jogador %c - Digite linha e coluna (0-2): ", simbolo);
        scanf("%d %d", &linha, &coluna);
    } while (linha < 0 || linha > 2 ||
             coluna < 0 || coluna > 2 ||
             tabuleiro[linha][coluna] != VAZIO);

    tabuleiro[linha][coluna] = simbolo;
}

/* ---------- MODOS DE JOGO ---------- */

void jogadorVsComputador() {
    iniciarTabuleiro();

    char primeiro;
    printf("Quem começa? (H - Humano | C - Computador): ");
    scanf(" %c", &primeiro);

    bool vezHumano = (primeiro == 'H' || primeiro == 'h');

    while (true) {
        mostrarTabuleiro();

        if (vezHumano) {
            jogadaJogador(HUMANO);
            if (verificarVitoria(HUMANO)) {
                mostrarTabuleiro();
                printf("Você venceu!\n");
                break;
            }
        } else {
            printf("Vez do Computador...\n");
            jogadaComputador();
            if (verificarVitoria(COMPUTADOR)) {
                mostrarTabuleiro();
                printf("O Computador venceu!\n");
                break;
            }
        }

        if (verificarEmpate()) {
            mostrarTabuleiro();
            printf("Empate!\n");
            break;
        }

        vezHumano = !vezHumano;
    }
}

void jogadorVsJogador() {
    iniciarTabuleiro();
    bool vezJogador1 = true;

    while (true) {
        mostrarTabuleiro();

        if (vezJogador1) {
            jogadaJogador('X');
            if (verificarVitoria('X')) {
                mostrarTabuleiro();
                printf("Jogador X venceu!\n");
                break;
            }
        } else {
            jogadaJogador('O');
            if (verificarVitoria('O')) {
                mostrarTabuleiro();
                printf("Jogador O venceu!\n");
                break;
            }
        }

        if (verificarEmpate()) {
            mostrarTabuleiro();
            printf("Empate!\n");
            break;
        }

        vezJogador1 = !vezJogador1;
    }
}

/* ---------- MAIN ---------- */

int main() {
    int opcao;

    do {
        printf("\n=== JOGO DA VELHA ===\n");
        printf("1 - Jogador vs Computador\n");
        printf("2 - Jogador vs Jogador\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
            jogadorVsComputador();
        else if (opcao == 2)
            jogadorVsJogador();

    } while (opcao != 0);

    return 0;
}
