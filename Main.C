#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 100

void MostrarTitulo(char titulo[TAM])
{
    printf("---------------------------------------------------------------------------- \n");
    printf(titulo);
    printf("\n---------------------------------------------------------------------------- \n\n");
}

struct ModeloDeLogin
{
    char usuario[50];
    char senha[8];
};

FILE *loginFile;

void Login()
{
    struct ModeloDeLogin login;

    MostrarTitulo("Tela de login");
    printf("Digite o seu usuario: \n");
    scanf("%s", login.usuario);

    printf("Digite sua senha: \n");
    scanf("%s", login.senha);
}

typedef struct Agenda
{
    char nome[50];
    char cpf[15];
    char dia[2];
    char mes[2];
} contatos;

contatos max[TAM];
FILE *arq;

char AddMais()
{
    char op;
    do
    {
        printf("\n Deseja inserir novos dados? [S ou N]? ");
        op = getch();
        printf("\n");
    } while (op != 's' && op != 'n');
    return op;
}

void Incluir(void)
{
    int cont = 0;
    int retorno;
    char op = 's';

    arq = fopen("agenda.txt", "a"); // fopen cria arquivo de entrada
    if (arq == NULL)
    {                                                               // caso o sistema não consiga criar o arquivo
        printf("Erro!\nO arquivo da lista não pode ser aberto!\n"); // sera mostrada esta mensagen
        getch();                                                    // espera que o usuário pressione uma tecla
        exit(1);                                                    // caso esse erro ocorra este comando encerra o programa
    }
    while ((cont < TAM) && (op == 's'))
    {
        printf(" Digite o nome: ");
        gets(max[cont].nome);
        printf(" Digite o CPF: ");
        gets(max[cont].cpf);
        printf(" Digite o dia do treinamento: ");
        gets(max[cont].dia);
        printf("Informe o mes do treinamento: ");
        gets(max[cont].mes);

        retorno = fwrite(&max[cont], sizeof(contatos), 1, arq);
        if (retorno == 1)
        {
            printf("\n Gravacao ok! ");
        }
        cont++;         // enquanto cont for menor 100 adiciona mais um contato
        op = AddMais(); // chama a função que pergunta se deseja inserir novos contatos
    }
    fclose(arq); // fecha o arquivo agenda.txt
}

void Pesquisar(void)
{
    int i = 0, retorno = 1, cont = 0; //
    char nome[50], op;                // A variavel nome se refere ao nome a ser pesquisado

    arq = fopen("agenda.txt", "r"); // fopen abre o arquivo no modo leitura "r"
    if (arq == NULL)
    {                                                                 // caso o SO não consiga abrir o arquivo
        printf(" Erro!\nO arquivo da lista não pode ser aberto! \n"); // sera mostrada esta mensagens
        getch();                                                      // espera que o usuário pressione uma tecla
        exit(1);                                                      // caso esse erro ocorra este comando encerra o programa
    }
    printf(" Digite o nome completo: "); // para procurar contato pelo nome
    gets(nome);
    retorno = fread(&max[i], sizeof(contatos), 1, arq); // fread le apenas 1 contato do arquivo
    while (retorno == 1)
    { // o retorno recebe a quantidade de contatos lidos no fread
        if (strcmp(nome, max[i].nome) == 0)
        { // strcmp compara as strings das variaveis
            printf("\n Nome....: %s", max[i].nome);
            printf("\n CPF....: %s", max[i].cpf);
            printf("\n Treinamento agendado....: %.2s/%.2s", max[i].dia, max[i].mes);
            cont++;
        }
        i++;
        retorno = fread(&max[i], sizeof(contatos), 1, arq); // fread vai ler o proximo contato
    }
    if (cont == 0)
    {                                                // se strcmp não encontrar strings iguais
        printf("Nao ha contatos com este nome!\n "); // sera mostrada essa mensagen
    }
    getch();     // espera que o usuário pressione uma tecla
    fclose(arq); // fecha o arquivo agenda.txt
}

void menu_treinamento(void)
{
    char op; // variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tAGENDAMENTO DE TREINAMENTO\n");
        printf("\n 1 - Incluir\n 2 - Pesquisar\n");
        printf(" 3 - Sair\n\n");
        op = getch();
        switch (op)
        {
        case '1':
            Incluir();
            break;
        case '2':
            Pesquisar();
            break;
        case '3':
            system("cls");
            break;
        default:
            printf("\a Digite uma opção valida\n");
            getch();
        }
    } while (op);
}

int main()
{
    int var;
    setlocale(LC_ALL, "Portuguese");
    menu_treinamento();
    system("pause");
}