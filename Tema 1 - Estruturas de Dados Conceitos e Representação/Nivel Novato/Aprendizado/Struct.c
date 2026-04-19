//Uma struct permite agrupar diferentes informações (de tipos variados) sobre um mesmo objeto. 
//Mas o que é exatamente uma struct? Também chamada de estrutura, é um tipo de dado composto que permite agrupar diferentes variáveis sob um mesmo nome, facilitando a organização de informações relacionadas. Cada variável em uma struct é chamada de membro ou campo, e pode ter um tipo diferente.

//Por exemplo, uma estrutura que representa um aluno pode agrupar seu nome, idade e media em um único bloco de dados.

// O campo nome é do tipo char.
// O campo idade é do tipo int.
// O campo media é do tipo float.

//Desta forma, podemos implementar essa ideia na prática com a seguinte declaração:

#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;
//Declarei minha struct usando a palavra-chave typedef, que é uma conveniência para criar um novo tipo de dado. Com typedef, podemos usar o nome Aluno diretamente para declarar variáveis do tipo struct, sem precisar escrever struct Aluno toda vez.
// A palavra-chave typedef é usada para criar um novo tipo de dado chamado Aluno, que é uma estrutura contendo os campos nome, idade e media. Agora, podemos criar variáveis do tipo Aluno para armazenar informações sobre diferentes alunos.

int main() { // Função principal do programa

    // Criando e inicializandouma variável do tipo Aluno
    Aluno aluno1 = {"João", 20, 8.5};

    // Acessando os dados com o operador ponto (.)
    // O operador ponto é usado para acessar os membros de uma struct. Para acessar o nome do aluno, usamos aluno1.nome; para acessar a idade, usamos aluno1.idade; e para acessar a média, usamos aluno1.media.
    printf("Aluno: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Média: %.2f\n", aluno1.media);

    return 0;

}