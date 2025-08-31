#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3

int main(){

    char coluna[50] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //variavel que sinaliza se houveram navios
    int conflito = 0;
    int matriz[LINHAS][COLUNAS];

    //preenchendo a matriz com 0
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

    //codigo comentado para exibir a logica inicial
    //codigo comentado para que futuramente seja necessario tratar cada navio individualmente
    /*
    //aqui mantenho a linha do navio e vou percorrendo as colunas para preencher na horizontal
    for(int i=0;i<3;i++){
        matriz[linha_navio_horizontal][coluna_navio_horizontal] = 3;
        coluna_navio_horizontal++;
    }

    //aqui mantenho a coluna do navio e vou percorrendo as linhas para preencher na vertical
    for(int j=0;j<3;j++){
        if( matriz[linha_navio_vertical][coluna_navio_vertical] == 3){
            conflito = 1;
        }
        matriz[linha_navio_vertical][coluna_navio_vertical] = 3;
        linha_navio_vertical++;
    }

    //navio diagonal
    //incue o navio para diagonal, baixo esquerda a partir da linha e coluna definida
    for(int j=0;j<3;j++){
        if( matriz[linha_navio_diagonal_1][coluna_navio_diagonal_1] == 3){
            conflito = 1;
            break;
        }
        matriz[linha_navio_diagonal_1][coluna_navio_diagonal_1] = 3;
        linha_navio_diagonal_1++;
        coluna_navio_diagonal_1--;
    }

    for(int j=0;j<3;j++){
        if( matriz[linha_navio_diagonal_2][coluna_navio_diagonal_2] == 3){
            conflito = 1;
            printf("Posicao do erro: [%d] - [%d]",linha_navio_diagonal_2,coluna_navio_diagonal_2);
            break;
        }
        matriz[linha_navio_diagonal_2][coluna_navio_diagonal_2] = 3;
        linha_navio_diagonal_2--;
        coluna_navio_diagonal_2++;
    }
    */

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