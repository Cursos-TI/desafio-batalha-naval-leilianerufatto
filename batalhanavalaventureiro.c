#include <stdio.h>

int main() {
    
    int tabuleiro[10][10];
    for (int l = 0; l < 10; l++) {
        for (int c = 0; c < 10; c++) {
            tabuleiro[l][c] = 0;
        }
    }

    
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    
    int navio[3] = {3, 3, 3};


    int linhaH = 1, colunaH = 2; 
    int linhaV = 4, colunaV = 1; 
    

    int linhaD1 = 2, colunaD1 = 5; 
    int linhaD2 = 7, colunaD2 = 5; 

 
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navio[i]; 
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navio[i]; 
    }

    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = navio[i];
    }

 
    printf("TABULEIRO BATALHA NAVAL (COM DIAGONAIS)\n");
    
 
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