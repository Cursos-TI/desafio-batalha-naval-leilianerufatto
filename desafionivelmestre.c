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

   
    int linhaH = 0, colunaH = 2;   
    int linhaV = 2, colunaV = 0;   
    int linhaD1 = 1, colunaD1 = 5; 
    int linhaD2 = 7, colunaD2 = 4; 

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

    int habilidadeCone[5][5];
    int habilidadeCruz[5][5];
    int habilidadeOctaedro[5][5];
    
    int centro = 2; 

    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            
            if (c >= centro - l && c <= centro + l && l <= centro) {
                habilidadeCone[l][c] = 1;
            } else {
                habilidadeCone[l][c] = 0;
            }

            if (l == centro || c == centro) {
                habilidadeCruz[l][c] = 1;
            } else {
                habilidadeCruz[l][c] = 0;
            }

            int distLinha = l - centro;
            int distColuna = c - centro;

            if (distLinha < 0) {
                distLinha = distLinha * -1;
            }
            if (distColuna < 0) {
                distColuna = distColuna * -1;
            }

            if (distLinha + distColuna <= 2) {
                habilidadeOctaedro[l][c] = 1;
            } else {
                habilidadeOctaedro[l][c] = 0;
            }
        }
    }

    
    int origemConeL = 4, origemConeC = 4; 
    int origemCruzL = 7, origemCruzC = 8; 

    // Aplicando o Cone no Tabuleiro
    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            int tabL = origemConeL + (l - centro);
            int tabC = origemConeC + (c - centro);

            if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                if (habilidadeCone[l][c] == 1 && tabuleiro[tabL][tabC] == 0) {
                    tabuleiro[tabL][tabC] = 5;
                }
            }
        }
    }


    for (int l = 0; l < 5; l++) {
        for (int c = 0; c < 5; c++) {
            int tabL = origemCruzL + (l - centro);
            int tabC = origemCruzC + (c - centro);

            if (tabL >= 0 && tabL < 10 && tabC >= 0 && tabC < 10) {
                if (habilidadeCruz[l][c] == 1 && tabuleiro[tabL][tabC] == 0) {
                    tabuleiro[tabL][tabC] = 5;
                }
            }
        }
    }


    printf("==================== BATALHA NAVAL ====================\n\n");
    

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
    printf("\n=======================================================\n");

    return 0;
}