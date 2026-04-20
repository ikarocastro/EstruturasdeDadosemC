// =============================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de livros usando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>// Biblioteca.h - Definição da struct Livro e protótipos de funções

//  ------- Constantes Globais ---------
#define MAX_LIVROS 50 // Capacidade máxima de livros na biblioteca
#define TAM_STRING 100 // Tamanho máximo para strings

//------- Definição da (Struct) Livro ---------
typedef struct {
    //Vetores do tipo char para armazenar o nome, autor e editora do livro, cada um com um tamanho definido por TAM_STRING.
    char Nome [TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
} Livro;

//funçAo de limpar o buff de entrada para evitar problemas com fgets e scanf
void limparBuffer() {  
    int c; 
    while ((c = getchar()) != '\n' && c != EOF); 
}

//------ Função Principal (Main) ---------
int main() {
    struct Livro biblioteca[MAX_LIVROS]; // Array estático para armazenar os livros
    int totalLivros = 0; // Contador de livros cadastrados
    int opcao;

    do{
        //Exibe o menu de opções para o usuário
        printf("===============================\n");
        printf("\n=== SISTEMA DE BIBLIOTECA ===\n");
        printf("===============================\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        //Lê a opção escolhida pelo usuário
        scanf("%d", &opcao);
        //Limpa o buffer de entrada para evitar problemas com fgets
        limparBuffer(); // Limpa o \n deixado pelo scanf

        //--------- Processamento da opção escolhida ---------
        switch (opcao) {
            case 1: // Cadastrar Livro
                    printf("\n=== CADASTRO DE NOVO LIVRO ===\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].Nome, TAM_STRING, stdin);
                    biblioteca[totalLivros].Nome[strcspn(biblioteca[totalLivros].Nome, "\n")] = '\0'; // Remove o \n

                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0'; // Remove o \n

                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0'; // Remove o \n

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0'; // Remove o \n
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0'; // Remove o \n
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0'; // Remove o \n

                    printf("Digite a edicao do livro: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBuffer(); // Limpa o \n deixado pelo scanf

                    totalLivros++;
                    
                    printf("Livro cadastrado com sucesso!\n");
                } else {
                    printf("Biblioteca cheia!, nao é possivel cadastrar mais livros.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu
                break;

            case 2: // Listar Livros
                printf("\n=== LISTA DE LIVROS CADASTRADOS ===\n");

                if (totalLivros == 0) {
                    printf("Nenhum livro cadastrado ainda.\n");
                } else {
                    for (int i = 0; i < totalLivros; i++) {
                            printf("-----------------------------\n");
                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].Nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                        printf("-----------------------------\n");
                    }

                    printf("------------------------------\n");
                }
                // A pausa é crucial para que o usuario veja a lista antes do proximo loop limpar a tela ou mostrar o menu novamente
                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu
                break;

                case 0: // Sair
                    printf("Saindo do sistema. Obrigado por usar a biblioteca!\n");
                    break;

            }
    }
}
