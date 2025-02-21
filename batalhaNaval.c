#include <stdio.h>
#define LINHA 10
#define COLUNA 10
#define NAVIO 3
#define AGUA 0
#define NAO_AFETADO 0
#define AFETADO 1

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    /*
    int tabuleiro[5][5] = {
        {0,1,1,1,0},
        {0,0,0,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };
    printf("A coordenada e %d\n", tabuleiro[0][1]);
    printf("A coordenada e %d\n", tabuleiro[0][2]);
    printf("A coordenada e %d\n", tabuleiro[0][3]);
    printf("A coordenada e %d\n", tabuleiro[2][2]);
    printf("A coordenada e %d\n", tabuleiro[3][2]);
    printf("A coordenada e %d\n", tabuleiro[4][2]);
    */

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    /*
    int tabuleiro[LINHA][COLUNA];
    
    // preenchendo o tabuleiro com AGUA
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = AGUA;
        }
        
    }

    // Calculando a posição inicial do navio
    int linha_navio = 0;  // Primeira linha
    int coluna_navio = COLUNA / 2 - 1;  // Centralizando na metade da matriz

    // Posicionando o navio de forma automática na horizontal
    for (int j = coluna_navio; j < coluna_navio + 3 && j < COLUNA; j++) {
        tabuleiro[linha_navio][j] = NAVIO;
    }
    
    // Posicionando o navio verticalmente, centralizado na matriz
    linha_navio = LINHA / 2 - 1; // Centralizando na vertical
    coluna_navio = COLUNA / 3;   // Posicionando em uma coluna válida

    for (int i = linha_navio; i < linha_navio + 3 && i < LINHA; i++) {
        tabuleiro[i][coluna_navio] = NAVIO;
    } 
    
    // Posicionando navio na diagonal principal (\)
    for (int i = 0; i < 3 && i < LINHA && i < COLUNA; i++) {
        tabuleiro[i][i] = NAVIO;
    }

    // Posicionando navio na diagonal secundária (/)
    for (int i = 0; i < 3 && i < LINHA && (COLUNA - 1 - i) >= 0; i++) {
        tabuleiro[i][COLUNA - 1 - i] = NAVIO;
    }

    // imprimindo os valores da matriz
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }    
    */

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    void exibirTabuleiro(int tabuleiro[LINHA][COLUNA]) {
        for (int i = 0; i < LINHA; i++) {
            for (int j = 0; j < COLUNA; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Preenche habilidade em formato de cone
    void habilidadeCone(int tabuleiro[LINHA][COLUNA], int x, int y) {
        if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA) tabuleiro[x][y] = AFETADO;
        if (x + 1 < LINHA) {
            if (y > 0) tabuleiro[x + 1][y - 1] = AFETADO;
            tabuleiro[x + 1][y] = AFETADO;
            if (y + 1 < COLUNA) tabuleiro[x + 1][y + 1] = AFETADO;
        }
        if (x + 2 < LINHA) {
            for (int j = y - 2; j <= y + 2; j++) {
                if (j >= 0 && j < COLUNA) tabuleiro[x + 2][j] = AFETADO;
            }
        }
    }
    
    // Preenche habilidade em formato de cruz
    void habilidadeCruz(int tabuleiro[LINHA][COLUNA], int x, int y) {
        for (int i = 0; i < LINHA; i++) {
            tabuleiro[i][y] = AFETADO;
        }
        for (int j = 0; j < COLUNA; j++) {
            tabuleiro[x][j] = AFETADO;
        }
    }
    
    // Preenche habilidade em formato de octaedro
    void habilidadeOctaedro(int tabuleiro[LINHA][COLUNA], int x, int y) {
        if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA) tabuleiro[x][y] = AFETADO;
        if (x - 1 >= 0) tabuleiro[x - 1][y] = AFETADO;
        if (x + 1 < LINHA) tabuleiro[x + 1][y] = AFETADO;
        if (y - 1 >= 0) tabuleiro[x][y - 1] = AFETADO;
        if (y + 1 < COLUNA) tabuleiro[x][y + 1] = AFETADO;
    }
    
    int main() {
        int tabuleiro[LINHA][COLUNA];
    
        // Teste da habilidade Cone
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                tabuleiro[i][j] = NAO_AFETADO;
    
        habilidadeCone(tabuleiro, 0, 2);
        printf("Habilidade em Cone:\n");
        exibirTabuleiro(tabuleiro);
    
        // Teste da habilidade Cruz
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                tabuleiro[i][j] = NAO_AFETADO;
    
        habilidadeCruz(tabuleiro, 2, 2);
        printf("Habilidade em Cruz:\n");
        exibirTabuleiro(tabuleiro);
    
        // Teste da habilidade Octaedro
        for (int i = 0; i < LINHA; i++)
            for (int j = 0; j < COLUNA; j++)
                tabuleiro[i][j] = NAO_AFETADO;
    
        habilidadeOctaedro(tabuleiro, 2, 2);
        printf("Habilidade em Octaedro:\n");
        exibirTabuleiro(tabuleiro);
    
        return 0;
    }


    //return 0;
//}
