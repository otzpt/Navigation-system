#include <stdio.h>
#include <string.h>

int eh_obstaculo(int x, int y) {
    char lab[5][5] = {
        {'l','l','p','l','l'},
        {'l','l','l','l','l'},
        {'p','l','p','p','p'},
        {'p','l','l','l','l'},
        {'l','l','p','p','l'}
    };

    return lab[x][y] == 'p';
}

void tabuleiro(int x_atual, int y_atual) {
    char tab[5][5];
    int i, j;

    for(i = 0; i <= 4; i++) {
        for(j = 0; j <= 4; j++) {
            if (eh_obstaculo(i, j)) {
                tab[i][j] = '#';
            } else {
                tab[i][j] = '.';
            }
        }
    }

    tab[4][4] = 'D';
    tab[x_atual][y_atual] = 'x';

    for(i = 0; i <= 4; i++) {
        for(j = 0; j <= 4; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int x_atual = 0, y_atual = 0;
    int x_novo, y_novo;
    char direcao[10];

    printf("Quadro inicial:\n");
    tabuleiro(x_atual, y_atual);

    while (1) {
        if (x_atual == 4 && y_atual == 4) {
            printf("Parabéns! O robô chegou ao destino sem bater nos obstáculos.\n");
            break;
        }

        printf("Movimento (Norte/Sul/Este/Oeste): ");
        scanf("%s", direcao);

        x_novo = x_atual;
        y_novo = y_atual;

        if (strcmp(direcao, "Norte") == 0) {
            x_novo = x_atual - 1;
        } else if (strcmp(direcao, "Sul") == 0) {
            x_novo = x_atual + 1;
        } else if (strcmp(direcao, "Este") == 0) {
            y_novo = y_atual + 1;
        } else if (strcmp(direcao, "Oeste") == 0) {
            y_novo = y_atual - 1;
        } else {
            printf("Direção inválida.\n");
            continue;
        }

        if (x_novo < 0 || x_novo > 4 || y_novo < 0 || y_novo > 4) {
            printf("Movimento inválido: fora dos limites!\n");
            continue;
        }

        if (eh_obstaculo(x_novo, y_novo)) {
            printf("Movimento inválido: obstáculo!\n");
            continue;
        }

        x_atual = x_novo;
        y_atual = y_novo;

        printf("Movimento: %s\n", direcao);
        tabuleiro(x_atual, y_atual);
    }

    return 0;
}