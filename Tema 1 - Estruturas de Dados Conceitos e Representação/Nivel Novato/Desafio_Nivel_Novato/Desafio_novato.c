#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TERRITORIOS 5 // Definindo o número máximo de territórios
#define MAX_STRING 30 // Definindo o tamanho máximo para strings

// Definição da struct para representar um território
struct territorio{
    char nome[30];
    char cor[10];
    int tropas;
};

//função de limpar o buff de entrada para evitar problemas com fgets e scanf
void limparBufferEntrada() {  
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
}

int main() {
    struct territorio mapa[MAX_TERRITORIOS]; // Array para armazenar os territórios
    int totalTerritorios = 0; // Contador de territórios cadastrados
    int opcao;

    do {
        // Exibe o menu de opções para o usuário
        printf("===============================\n");
        printf("\n=== SISTEMA DE MAPA DE RISCO ===\n");
        printf("===============================\n");
        printf("1. Cadastrar Territorio\n");
        printf("2. Listar Territorios\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        // Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);
        // Limpa o buffer de entrada para evitar problemas com fgets
        limparBufferEntrada(); // Limpa o \n deixado pelo scanf

        // Processamento da opção escolhida
        switch (opcao) {
            case 1: // ----------------------------------- Cadastrar Territorio -----------------------------------
                if (totalTerritorios < MAX_TERRITORIOS) {
                    printf("\n=== CADASTRO DE NOVO TERRITORIO ===\n");
                    printf("Digite o nome do territorio: ");
                    fgets(mapa[totalTerritorios].nome, MAX_STRING, stdin); // para buscar o nome do território usando 'fgets' para permitir espaços
                    
                    printf("Digite a cor do territorio: ");
                    fgets(mapa[totalTerritorios].cor, MAX_STRING, stdin);
                    
                    mapa[totalTerritorios].nome[strcspn(mapa[totalTerritorios].nome, "\n")] = '\0'; // Remove o \n
                    mapa[totalTerritorios].cor[strcspn(mapa[totalTerritorios].cor, "\n")] = '\0'; // Remove o \n

                    printf("Digite a quantidade de tropas no territorio: ");
                    scanf("%d", &mapa[totalTerritorios].tropas);
                    limparBufferEntrada(); // Limpa o \n deixado pelo scanf

                    totalTerritorios++; // Incrementa o contador de territórios cadastrados
                } else {
                    printf("Limite de territorios atingido!\n");
                }

                break;

            case 2: // ----------------------------------- Listar Territorios -----------------------------------
                if (totalTerritorios == 0) {
                    printf("\nNenhum territorio cadastrado!\n");
                } else {
                    printf("\n=== LISTA DE TERRITORIOS ===\n");
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("Territorio %d:\n", i + 1);
                        printf("Nome: %s\n", mapa[i].nome);
                        printf("Cor: %s\n", mapa[i].cor);
                        printf("Tropas: %d\n", mapa[i].tropas);
                        printf("-----------------------------\n");
                    }
                }
                break;

            case 3: // Sair
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}