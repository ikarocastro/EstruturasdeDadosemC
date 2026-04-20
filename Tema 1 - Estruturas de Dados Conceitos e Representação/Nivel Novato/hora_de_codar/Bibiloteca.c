// =============================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de livros usando um array estático.
// Foco em structs, entrada/saída de dados e organização básica.

#include <stdio.h> // Biblioteca padrão para entrada e saída de dados
#include <stdlib.h> // Biblioteca padrão para funções de alocação de memória, controle de processos, conversões e outras utilidades
#include <string.h>// Biblioteca.h - Definição da struct Livro e protótipos de funções para strcspn e outras operações de string

//  ------- Constantes Globais ---------
#define MAX_LIVROS 50 // Capacidade máxima de livros na biblioteca
#define TAM_STRING 100 // Tamanho máximo para strings

//------- Definição da (Struct) Livro ---------

     //Vetores do tipo char para armazenar o nome, autor e editora do livro, cada um com um tamanho definido por TAM_STRING.
struct Livro {
    char nome [TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

//funçAo de limpar o buff de entrada para evitar problemas com fgets e scanf
void limparBufferEntrada() {  
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
        limparBufferEntrada(); // Limpa o \n deixado pelo scanf

        //--------- Processamento da opção escolhida ---------
        switch (opcao) {
            case 1: // Cadastrar Livro
                    printf("\n=== CADASTRO DE NOVO LIVRO ===\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin); // para buscar o nome do livro, autor e editora usando 'fgets' para permitir espaços
                    
                    printf("Digite o autor do livro: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                    
                    printf("Digite a editora do livro: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0'; // Remove o \n
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0'; // Remove o \n
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0'; // Remove o \n

                    printf("Digite a edicao do livro: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada(); // Limpa o \n deixado pelo scanf

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
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                        printf("-----------------------------\n");
                    }
                }
                // A pausa é crucial para que o usuario veja a lista antes do proximo loop limpar a tela ou mostrar o menu novamente
                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu
                break;

                case 3: // Sair
                    printf("Saindo do sistema. Obrigado por usar a biblioteca!\n");
                    break;

                default: // Opção inválida
                printf("Opcao invalida! Por favor, escolha uma opcao valida.\n");
                printf("\nPressione Enter para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu
                break;

            }
    } while (opcao != 3);

    return 0;
}

