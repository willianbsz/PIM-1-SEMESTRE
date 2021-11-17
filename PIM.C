#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define TAM 100
#define NOMETAM 100

//==UTILS==
void LimparTela()
{
    system("cls");
}

void LinhaDivisoria()
{
    printf("\n----------------------------------------------------------------------------\n");
}

void PularLinha()
{
    printf("\n");
}

void FecharPrograma()
{
    LimparTela();
    printf("Ok, até a próxima!!!");
    getch();
    system("exit");
}

void MostrarTitulo(const char titulo[TAM])
{
    LinhaDivisoria();
    printf(titulo);
    LinhaDivisoria();
    PularLinha();
}

// ATLETAS
struct ATLETA
{
    char nome[NOMETAM];
    int idade;
    Modalidade modalidade;
    Pais pais;
    Equipe equipe;
    Alojamento alojamento;
    Medalha medalhas[TAM];
} Atletas[TAM];

// MEDALHA
struct Medalha
{
    TipoMedalha tipo;
};

enum TipoMedalha
{
    Ouro,
    Prata,
    Bronze
};

// MODALIDADE
struct Modalidade
{
    char nome[NOMETAM];
} Modalidades[TAM];

// PAIS
struct Pais
{
    char nome[NOMETAM];
} Paises[TAM];

// EQUIPE
struct Equipe
{
    char nome[NOMETAM];
} Equipes[TAM];

// ALOJAMENTO
struct Alojamento
{
    char nome[NOMETAM];
    Local local;
} Alojamentos[TAM];

// LOCAL
struct Local
{
    char rua[NOMETAM];
    int numero;
} Localis[TAM];

// FUNCIONARIO
struct Funcionario
{
    char nome[NOMETAM];
} Funcionarios[TAM];

// VOLUNTARIO
struct Voluntario
{
    char nome[NOMETAM];
} Voluntarios[TAM];

//==LOGIN==
struct ModeloDeLogin
{
    char usuario[50];
    char senha[8];
} usuarios[TAM];

FILE *loginFile;

FILE *AbrirTxt(FILE *arq, const char *nomeDoArquivo, const char *acao)
{
    arq = fopen(nomeDoArquivo, acao); // fopen cria arquivo de entrada
    if (arq == NULL)
    {                                                               // caso o sistema não consiga criar o arquivo
        printf("Erro!\nO arquivo da lista não pode ser aberto!\n"); // sera mostrada esta mensagen
        getch();                                                    // espera que o usuário pressione uma tecla
        exit(1);                                                    // caso esse erro ocorra este comando encerra o programa
    }
    return arq;
}

ModeloDeLogin MostrarFormularioLogin(ModeloDeLogin login)
{
    printf("Digite o seu usuario: \n");
    scanf("%s", login.usuario);

    printf("Digite sua senha: \n");
    scanf("%s", login.senha);

    return login;
}

bool BuscarUsuario(ModeloDeLogin login)
{
    loginFile = AbrirTxt(loginFile, "login.txt", "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&usuarios[i], sizeof(ModeloDeLogin), 1, loginFile);

        if (encontrado == 0)
        {
            printf("\nNão foi possivel encontrar o usuário");
            break;
        }
        else if (strcmp(login.usuario, usuarios[i].usuario) == 0 && strcmp(login.senha, usuarios[i].senha) == 0)
        {
            return true;
        }
        else
        {
            i++;
            continue;
        }
    }
    return false;
}

bool Login()
{
    ModeloDeLogin login;
    login = MostrarFormularioLogin(login);
    return BuscarUsuario(login);
}

void CadastrarUsuario()
{
    loginFile = AbrirTxt(loginFile, "login.txt", "a");

    printf(" Digite o nome de usuario: ");
    gets(usuarios[0].usuario);
    printf(" Digite a senha: ");
    gets(usuarios[0].senha);

    int retorno = fwrite(&usuarios[0], sizeof(ModeloDeLogin), 1, loginFile);

    printf("retorno");
    printf("%d", retorno);
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(loginFile);
    }
}

void MostrarMenuCadastroUsuarios()
{
    MostrarTitulo("                        Cadastro de usuários                        ");
    loginFile = AbrirTxt(loginFile, "login.txt", "r");

    int encontrado = 1;
    int i = 0;

    printf("Usuários:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&usuarios[i], sizeof(ModeloDeLogin), 1, loginFile);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem usuários cadastrados**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(usuarios[i].usuario);
            PularLinha();
            i++;
            continue;
        }
    }

    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("2 - Editar\n");
    printf("3 - Voltar\n");
    printf("0 - Sair\n");
}

void MenuCadastroUsuarios()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroUsuarios();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarUsuario();
            break;
        case 2:
            printf("Editando usuário");
            break;
        case 3:
            printf("Voltando");
            break;
        case 0:
            FecharPrograma();
            break;
        default:
            printf("Opção inválida, tente novamente");
            break;
        }
    } while (tentarNovamente);
}

// MENU CADASTROS
void MostrarMenuCadastros()
{
    LimparTela();
    MostrarTitulo("                        Menu de cadastros                      ");
    printf("1 - Cadastrar atleta\n");
    printf("2 - Cadastrar equipe medica\n");
    printf("3 - Cadastrar funcionarios\n");
    printf("4 - Cadastrar voluntarios\n");
    printf("5 - Usuários do sistema\n");
    printf("6 - Voltar\n");
    printf("0 - Sair\n");
}

void MenuCadastros()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastros();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            break;
        case 2:
            // CadastrarAtleta();
            break;
        case 5:
            MenuCadastroUsuarios();
            break;
        case 0:
            FecharPrograma();
            break;
        default:
            printf("Opção inválida, tente novamente");
            break;
        }
    } while (tentarNovamente);
}

// MENU PRINCIPAL
void MostrarMenuPrincipal()
{
    printf("O que você deseja fazer?\n\n");
    printf("1 - Cadastros\n");
    printf("2 - Relatórios\n");
    printf("0 - Sair\n");
}

void MenuPrincipal()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuPrincipal();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            MenuCadastros();
            break;
        case 2:
            // CadastrarEquipeMedica
            break;
        case 3:
            // CadastrarFuncionarios
        case 4:
            // CadastrarVoluntarios
            break;
        default:
            printf("Opção inválida, tente novamente");
            tentarNovamente = true;
            break;
        }
    } while (tentarNovamente);
}

// MENU INICIAL
void MostrarMenuInicial()
{
    MostrarTitulo("Bem vindo ao gerenciamento das olimpiadas");

    printf("O que você deseja fazer?\n\n");
    printf("1 - Login\n");
    printf("2 - Cadastrar\n");
    printf("0 - Sair\n");
}

void MenuInicial()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuInicial();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            bool isLogedIn;
            isLogedIn = Login();

            if (isLogedIn)
            {
                MenuPrincipal();
            }
            break;
        case 2:
            CadastrarUsuario();
            break;
        case 0:
            FecharPrograma();
            break;
        default:
            printf("Opção inválida, tente novamente");
            break;
        }
    } while (tentarNovamente);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    MenuInicial();
    return 0;
}