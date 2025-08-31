#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main(){

    char coluna[50] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //variavel que sinaliza se houveram navios
    int conflito = 0;
    int matriz[LINHAS][COLUNAS];

       int matriz_cone[5][5];
        int matriz_cruz[5][5];
        int matriz_octaedro[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 0 && j == 2) {
                    matriz_cone[i][j] = 1;
                } else if (i == 1 && (j >= 1 && j <= 3)) {
                    matriz_cone[i][j] = 1;
                } else if (i == 2 && (j >= 0 && j <= 4)) {
                    matriz_cone[i][j] = 1;
                } else {
                    matriz_cone[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == 2 || j == 2) {
                    matriz_cruz[i][j] = 1;
                } else {
                    matriz_cruz[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int distancia_linha_centro = i - 2;
                if (distancia_linha_centro < 0) distancia_linha_centro = -distancia_linha_centro;
                int distancia_coluna_centro = j - 2;
                if (distancia_coluna_centro < 0) distancia_coluna_centro = -distancia_coluna_centro;
                if ( (distancia_linha_centro + distancia_coluna_centro) <= 2 ) {
                    matriz_octaedro[i][j] = 1;
                } else {
                    matriz_octaedro[i][j] = 0;
                }
            }
        }

    for(int i =0; i<LINHAS;i++){
        for(int j=0;j<COLUNAS;j++){
             matriz[i][j] = 0;
        }
    }

    //esse navio começa na 3 linha, 4 coluna (D)
    int posicao_navio_horizontal[1][2] = {
        {2,4}
    };

    //esse navio começa na linha 7, 3 coluna (C)
    int posicao_navio_vertical[1][2] = {
        {6,2}
    };

    //navio para diagonal, baixo esquerda
    int posicao_navio_diagonal_1[1][2] = {
        {2,2}
    };

    //navio para diagonal, cima direita
    int posicao_navio_diagonal_2[1][2] = {
        {8,6}
    };

    int linha_navio_horizontal = posicao_navio_horizontal[0][0];
    int coluna_navio_horizontal = posicao_navio_horizontal[0][1];

    int linha_navio_vertical = posicao_navio_vertical[0][0];
    int coluna_navio_vertical = posicao_navio_vertical[0][1];

    int linha_navio_diagonal_1 = posicao_navio_diagonal_1[0][0];
    int coluna_navio_diagonal_1 = posicao_navio_diagonal_1[0][1];

    int linha_navio_diagonal_2 = posicao_navio_diagonal_2[0][0];
    int coluna_navio_diagonal_2 = posicao_navio_diagonal_2[0][1];

    for(int i=0;i<TAMANHO_NAVIO;i++){
        //inclui o navio na horizontal
        if(conflito == 1){
            break;
        }
        matriz[linha_navio_horizontal][coluna_navio_horizontal] = 3;
        coluna_navio_horizontal++;

        //inclui o navio na vertical
        if( matriz[linha_navio_vertical][coluna_navio_vertical] == 3){
            conflito = 1;
        }
        matriz[linha_navio_vertical][coluna_navio_vertical] = 3;
        linha_navio_vertical++;

        //incue o navio para diagonal, baixo esquerda a partir da linha e coluna definida
        if( matriz[linha_navio_diagonal_1][coluna_navio_diagonal_1] == 3){
            conflito = 1;
            break;
        }
        matriz[linha_navio_diagonal_1][coluna_navio_diagonal_1] = 3;
        linha_navio_diagonal_1++;
        coluna_navio_diagonal_1--;

        //inclui o navio na diagonal, para cima e esquerda com base na linha e coluna definida inicialmente
        if( matriz[linha_navio_diagonal_2][coluna_navio_diagonal_2] == 3){
             conflito = 1;
             break;
        }
        matriz[linha_navio_diagonal_2][coluna_navio_diagonal_2] = 3;
        linha_navio_diagonal_2--;
        coluna_navio_diagonal_2--;

    }

    // pontos de origem das habilidades (linha, coluna)
    // Ajustados para acertar alguns navios
    int origem_cone_linha = 2;
    int origem_cone_coluna = 5;

    int origem_cruz_linha = 7;
    int origem_cruz_coluna = 2;

    int origem_octaedro_linha = 8;
    int origem_octaedro_coluna = 6;

        // sobrepor matriz_cone no tabuleiro, centrando no ponto de origem
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int tabuleiro_linha = origem_cone_linha - 2 + i;
                int tabuleiro_coluna = origem_cone_coluna - 2 + j;
                // Se está dentro do tabuleiro e é área de efeito da habilidade cone
                if (tabuleiro_linha >= 0 && tabuleiro_linha < LINHAS && tabuleiro_coluna >= 0 && tabuleiro_coluna < COLUNAS) {
                    if (matriz_cone[i][j] == 1) {
                        if (matriz[tabuleiro_linha][tabuleiro_coluna] == 3) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 5; // acertou navio
                        } else if (matriz[tabuleiro_linha][tabuleiro_coluna] == 0) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 1; // acertou água
                        }
                    }
                }
            }
        }

        // sobrepor matriz_cruz no tabuleiro, centrando no ponto de origem
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int tabuleiro_linha = origem_cruz_linha - 2 + i;
                int tabuleiro_coluna = origem_cruz_coluna - 2 + j;
                // Se está dentro do tabuleiro e é área de efeito da habilidade cruz
                if (tabuleiro_linha >= 0 && tabuleiro_linha < LINHAS && tabuleiro_coluna >= 0 && tabuleiro_coluna < COLUNAS) {
                    if (matriz_cruz[i][j] == 1) {
                        if (matriz[tabuleiro_linha][tabuleiro_coluna] == 3) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 5; // acertou navio
                        } else if (matriz[tabuleiro_linha][tabuleiro_coluna] == 0) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 1; // acertou água
                        }
                    }
                }
            }
        }

        // sobrepor matriz_octaedro no tabuleiro, centrando no ponto de origem
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int tabuleiro_linha = origem_octaedro_linha - 2 + i;
                int tabuleiro_coluna = origem_octaedro_coluna - 2 + j;
                // Se está dentro do tabuleiro e é área de efeito da habilidade octaedro
                if (tabuleiro_linha >= 0 && tabuleiro_linha < LINHAS && tabuleiro_coluna >= 0 && tabuleiro_coluna < COLUNAS) {
                    if (matriz_octaedro[i][j] == 1) {
                        if (matriz[tabuleiro_linha][tabuleiro_coluna] == 3) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 5; // acertou navio
                        } else if (matriz[tabuleiro_linha][tabuleiro_coluna] == 0) {
                            matriz[tabuleiro_linha][tabuleiro_coluna] = 1; // acertou água
                        }
                    }
                }
            }
        }


    //se teve conflito, encerra o jogo
    if(conflito == 1){
        printf("Navios na posicao incorreta");
        return 0;
    }

    //aqui imprime a letra de cada coluna
    printf("   ");
    for(int i = 0; i<COLUNAS; i++){
        printf("%c ", coluna[i]);
    }
    printf("\n");

    //imprime o tabuleiro
    for(int i = 0; i<LINHAS; i++){

        //imprime o numero da linha
        if(i<9){
           printf("%d  ", i+1);
        } else {
           printf("%d ", i+1);
        }

        for(int j = 0; j<COLUNAS; j++){
        if(j>0){
            printf("-");
        }
         printf("%d", matriz[i][j]);
        }
       printf("\n");
}

return 0;
}