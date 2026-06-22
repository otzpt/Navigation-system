#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TAM 10

void clear() {
    system("clear");
}

int eh_obstaculo(int x, int y) {
    char lab[TAM][TAM] = {
        {'.', '.', '.', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '.', '.', '.', '.', '#', '#', '#', '#'},
        {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
        {'#', '#', '.', '#', '.', '.', '.', '#', '#', '#'},
        {'#', '.', '.', '#', '#', '#', '.', '#', '#', '#'},
        {'#', '.', '#', '#', '#', '#', '.', '.', '#', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '.', '#', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '#', '#'},
        {'#', '.', '.', '.', '#', '#', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '.', '.'}
    };

    return lab[x][y] == '#';
}

void tabuleiro(int x_atual, int y_atual) {
    char tab[TAM][TAM];
    int i, j;

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            if (eh_obstaculo(i, j)) {
                tab[i][j] = '#';
            } else {
                tab[i][j] = '.';
            }
        }
    }

    tab[TAM-1][TAM-1] = 'D';
    tab[x_atual][y_atual] = 'x';

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int x_atual = 0, y_atual = 0;
    int x_novo, y_novo;
    char direcao[TAM];
    int visitado[TAM][TAM];
    int pai[TAM][TAM][2];
    int fila[TAM*TAM][2];

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            visitado[i][j] = 0;
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            pai[i][j][0] = -1;
            pai[i][j][1] = -1;
        }
    }

    int inicio = 0;
    int fim = 0;

    printf("Quadro inicial:\n");
    tabuleiro(x_atual, y_atual);

    fila[fim][0] = 0;
    fila[fim][1] = 0;
    fim++;

    visitado[0][0] = 1;

    int dir[4][2] = {{-1, 0}, {1,0}, {0,1}, {0,-1}};

    while(inicio < fim) {
        int x = fila[inicio][0];
        int y = fila[inicio][1];
        inicio++;

        if (x == TAM-1 && y == TAM-1) {
            break;
        }

        for(int d = 0; d < 4; d++) {
            int nx = x + dir[d][0];
            int ny = y + dir[d][1];

            if (nx >= 0 && nx <= TAM-1 && ny >= 0 && ny <= TAM-1) {
                if (!eh_obstaculo(nx, ny) && !visitado[nx][ny]) {
                    visitado[nx][ny] = 1;

                    pai[nx][ny][0] = x;
                    pai[nx][ny][1] = y;

                    fila[fim][0] = nx;
                    fila[fim][1] = ny;
                    fim++;
                }
            }
        }
    }

    int caminho[TAM*TAM][2];
    int tamanho = 0;
    int cx = TAM-1, cy = TAM-1;

    while(cx != -1 && cy != -1) {
        caminho[tamanho][0] = cx;
        caminho[tamanho][1] = cy;
        tamanho++;

        int px = pai[cx][cy][0];
        int py = pai[cx][cy][1];

        cx = px;
        cy = py;
    }

    for (int i = tamanho - 1; i >= 0; i--) {
        clear();
        tabuleiro(caminho[i][0], caminho[i][1]);
        fflush(stdout);
        usleep(1000000);
    }

    printf("O robo chegou ao destino\n");

    for (int i = 0; i < tamanho; i++) {
        clear();
        tabuleiro(caminho[i][0], caminho[i][1]);
        fflush(stdout);
        usleep(600000);
    }

    return 0;
}