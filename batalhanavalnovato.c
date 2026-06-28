#include <stdio.h>

int main() {
   
    int tabuleiro[10][10] = {0}; 
    
     
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    
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