#include <stdio.h>

int main(){

/*
codigo inicial para facil visualizacao e interpretacao
int matriz[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};
*/

int navio_v[3] = {3,3,3};
int navio_h[3] = {3,3,3};
char coluna[50] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

//variavel que sinaliza se houveram navios
int conflito = 0;
int matriz[10][10];

//preenchendo a matriz com 0
for(int i =0; i<10;i++){
    for(int j=0;j<10;j++){
         matriz[i][j] = 0;
    }
}

//esse navio começa na 3 linha, 4 coluna (D)
int posicao_navio_horizontal[1][2] = {
    {2,3}
};

//esse navio começa na linha 7, 3 coluna (C)
int posicao_navio_vertical[1][2] = {
    {6,2}
};

int linha_navio_horizontal = posicao_navio_horizontal[0][0];
int coluna_navio_horizontal = posicao_navio_horizontal[0][1];

int linha_navio_vertical = posicao_navio_vertical[0][0];
int coluna_navio_vertical = posicao_navio_vertical[0][1];


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

/** codigo antigo para facil entendimento*/
//aqui popula a matriz horizontalmente
//aqui eu comeco pela primeira linha e percorro horizontalmente ate o fim de cada linha
//apos isso, vou para a linha de baixo
//i representa linha
//j representa coluna
/*for(int i = 0; i<11; i++){
    //se estiver na linha e coluna correta
    if(posicao_navio_horizontal[0][0]==i && conflito == 0){
        //percorro a linha
        for(int j = 0; j<11; j++){
            //se estiver na posicao certa dentro da linha, coloco o navio
            if(posicao_navio_horizontal[0][1]==j && conflito == 0){
               for(int x =0; x<3; x++){
                   if( matriz[i][j] == 3){
                    conflito = 1;
                    break;
                   }
                   matriz[i][j] = navio_h[x];
                   j++;
               }
            }
        }
        //se ja preenchi horizontalmente, nao preciso mais percorrer a matriz
        break;
    }
}*/

/** codigo antigo para facil entendimento*/
/*if(conflito == 0){
    //aqui faco o inverso, percorro a matriz verticalmente
    //comeco pela primeira coluna, de cima para baixo
    // i representa linha
    // j representa coluna
    for(int j =0; j<11; j++){
        //se estiver na coluna e linha corretos
        if(posicao_navio_vertical[0][0]==j && conflito == 0){
            for(int i = 0; i<11; i++){
                //se estiver na coluna certa
                if(posicao_navio_vertical[0][1]==i && conflito == 0){
                    //aqui preenche o navio dentro da coluna
                    for(int x = 0;x<3;x++){
                    if( matriz[j][i] == 3){
                     conflito = 1;
                     break;
                    }
                        matriz[j][i] = navio_v[x];
                        j++;
                    }
                }
            }
            //se ja preenchi verticalmente, nao preciso mais percorrer a matriz
            break;
        }
    }
}*/

//se teve conflito, encerra o jogo
if(conflito == 1){
    printf("Navios na posicao incorreta");
    return 0;
}


//aqui imprime a letra de cada coluna
printf("   ");
for(int i = 0; i<10; i++){
    printf("%c ", coluna[i]);
}
printf("\n");

//imprime o tabuleiro
for(int i = 0; i<10; i++){

    //imprime o numero da linha
    if(i<9){
       printf("%d  ", i+1);
    } else {
       printf("%d ", i+1);
    }

    for(int j = 0; j<10; j++){
    if(j>0){
        printf("-");
    }
     printf("%d", matriz[i][j]);
    }
   printf("\n");
}

return 0;
}