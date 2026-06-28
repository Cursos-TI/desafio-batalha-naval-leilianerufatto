#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};


    int linhaH = 2; 
    int colunaH = 3; 


    int linhaV = 5; 
    int colunaV = 7;


    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

 
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

  
    printf("TABULEIRO BATALHA NAVAL\n");


    printf("   "); 
    for (int j = 0; j < 10; j++) {
        printf("%c ", letras[j]);
    }
    printf("\n");

    for (int l = 0; l < 10; l++) {
        if (l < 9) {
            printf(" %d ", l + 1); 
        } else {
            printf("%d ", l + 1);  
        }

        for (int c = 0; c < 10; c++) {
            printf("%d ", tabuleiro[l][c]);
        }
        printf("\n"); 
    }

    return 0;
}