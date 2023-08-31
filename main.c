#include <stdio.h>
#include <stdlib.h>

int **alocacaoDeMemoria(int linhas, int colunas);
void limpaMemoria(int **listaDeUsuarios, int linhas);
void imprimir(int **listaDeUsuarios, int linhas, int colunas);
int preencherMatriz(int **matriz, int linhas, int colunas);

int main()
{
    int **matriz;
    int linhas = 2, colunas = 2;
    int opcaoEscolhida;

    while (1)
    {
        printf("\n\n");
        printf("=================================\n");
        printf("selecione uma opcao do menu: \n");
        printf("1- alocar\n2- preencher matriz\n3- imprimir matriz\n4- fechar programa\nescolha: ");
        scanf("%d", &opcaoEscolhida);

        fflush(stdin);

        switch(opcaoEscolhida){
            case 1:
                matriz = alocacaoDeMemoria(linhas, colunas);
                printf("matriz alocada");
                break;
            case 2:
                preencherMatriz(matriz, linhas, colunas);
                break;
            case 3:
                imprimir(matriz, linhas, colunas);
                limpaMemoria(matriz, linhas);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
}

int **alocacaoDeMemoria(int linhas, int colunas)
{
    int **matriz =(int**)malloc(linhas * sizeof(int*));
    for(int i = 0; i < linhas; i++){
        matriz[i] =(int*)malloc(colunas * sizeof(int));
    }

    return matriz;
}

void limpaMemoria(int **matriz, int linhas)
{
    for(int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void imprimir(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%2d", matriz[i][j]);
        }
        printf("\n");
    }
}

int preencherMatriz(int **matriz , int linhas, int colunas)
{
    matriz = alocacaoDeMemoria(linhas, colunas);
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            matriz[i][j] = i + j;
        }
        printf("\n");
    }
}
