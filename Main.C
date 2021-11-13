#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <locale.h>
#define TAM 100

typedef struct Agenda
{
    char nome[50];
    char cpf[15];
    char dia[2];
    char mes[2];
} contatos;

void Incluir(void);
void Pesquisar(void);
char AddMais();

static int qtd = 0;
contatos max[TAM];
FILE *arq;

/= == == == = Incluir Contatos na Agenda == == == == == = /
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
        qtd++;          // acrecenta 1 contato a mais
    }
    fclose(arq); // fecha o arquivo agenda.txt
}

/= == == == == == == = Adicionar mais Contatos == == == == == == == = /
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

/= == == == == == == = Pesquisar contato pelo nome == == == == == == == == == == = /
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

/= == == == == == == == == == == Menu == == == == == == == == == == == = /
                                                                         void menu_treinamento(void)
{
    char op; // variavel de opção
    do
    {
        system("cls"); // limpar tela
        printf("\n\n\t\tAGENDAMENTO DE TREINAMENTO\n");
        printf("\n 1 - Incluir\n 2 - Pesquisar\n");
        printf(" 3 - Voltar\n\n");
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
            main();
            break;
        default:
            printf("\a Digite uma opção valida\n");
            getch();
        }
    } while (op);
}

/= == == == == == Função Principal == == == == == == == == /
                                                               int main()
{
    int var;
    setlocale(LC_ALL, "Portuguese");
    printf("\n\n\t\tAGENDAMENTO DE TREINAMENTO\n\n");
    printf("\tVerifique as funções disponiveis no menu.\n");
    printf("\tUtilize os numeros para selecionar a opção desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou\n\tEspaço para sair do programa agora.\n\t");
    var = getch();
    if (var == 32)
    {
        exit(0);
    }
    menu_treinamento();
    system("pause");
}