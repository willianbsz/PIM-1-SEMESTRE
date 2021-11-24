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

// ARQUIVO
FILE *AbrirTxt(FILE *arq, const char *nomeDoArquivo, const char *acao)
{
    arq = fopen(nomeDoArquivo, acao); // fopen cria arquivo de entrada
    if (arq == NULL)
    {                                                                // caso o sistema não consiga criar o arquivo
        printf("Erro!\n O arquivo da lista não pode ser aberto!\n"); // sera mostrada esta mensagen
        getch();                                                     // espera que o usuário pressione uma tecla
        exit(1);                                                     // caso esse erro ocorra este comando encerra o programa
    }
    return arq;
}

// MODALIDADE
struct Modalidade
{
    char nome[NOMETAM];
} Modalidades[TAM];

FILE *ArquivoModalidade;

const char NomeArquivoModalidade[] = "modalidades.txt";
void MostrarMenuCadastroModalidade()
{
    MostrarTitulo("                        Cadastro de modalidade                        ");
    ArquivoModalidade = AbrirTxt(ArquivoModalidade, NomeArquivoModalidade, "r");

    int encontrado = 1;
    int i = 0;

    printf("Modalidades:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Modalidades[i], sizeof(Modalidade), 1, ArquivoModalidade);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem modalidades cadastradas**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Modalidades[i].nome);
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
void CadastrarModalidade()
{
    ArquivoModalidade = AbrirTxt(ArquivoModalidade, NomeArquivoModalidade, "a");

    printf(" Digite o nome da modalidade: ");
    scanf("%s", Modalidades[0].nome);

    int retorno = fwrite(&Modalidades[0], sizeof(Modalidade), 1, ArquivoModalidade);

    printf("retorno");
    printf("%d", retorno);
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(ArquivoModalidade);
    }
}

void MenuCadastroModalidade()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroModalidade();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarModalidade();
            break;
        case 2:
            printf("Editando modalidade");
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

// PAIS
struct Pais
{
    char nome[NOMETAM];
} Paises[TAM];

FILE *ArquivoPais;

const char NomeArquivoPais[] = "paises.txt";
void MostrarMenuCadastroPais()
{
    MostrarTitulo("                        Cadastro de Pais                        ");
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "r");

    int encontrado = 1;
    int i = 0;

    printf("Paises:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Paises[i], sizeof(Pais), 1, ArquivoPais);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem Paises cadastrados**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Paises[i].nome);
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
void CadastrarPaises()
{
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "a");

    printf(" Digite o nome do Pais: ");
    scanf("%s", Paises[0].nome);

    int retorno = fwrite(&Paises[0], sizeof(Pais), 1, ArquivoPais);

    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(ArquivoPais);
    }
}

void MenuCadastroPais()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroPais();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarPaises();
            break;
        case 2:
            printf("Editando pais");
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

// EQUIPE
struct Equipe
{
    char nome[NOMETAM];
} Equipes[TAM];

FILE *ArquivoEquipe;

const char NomeArquivoEquipe[] = "equipe.txt";
void MostrarMenuCadastroEquipe()
{
    MostrarTitulo("                        Cadastro de equipes                        ");
    ArquivoEquipe = AbrirTxt(ArquivoEquipe, NomeArquivoEquipe, "r");

    int encontrado = 1;
    int i = 0;

    printf("Equipes:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Equipes[i], sizeof(Equipe), 1, ArquivoEquipe);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem equipes cadastradas**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Equipes[i].nome);
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
void CadastrarEquipes()
{
    ArquivoEquipe = AbrirTxt(ArquivoEquipe, NomeArquivoEquipe, "a");

    printf(" Digite o nome da equipe: ");
    scanf("%s", Paises[0].nome);

    int retorno = fwrite(&Equipes[0], sizeof(Equipe), 1, ArquivoEquipe);

    printf("retorno");
    printf("%d", retorno);
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(ArquivoEquipe);
    }
}

void MenuCadastroEquipe()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroEquipe();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarEquipes();
            break;
        case 2:
            printf("Editando equipes");
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

// LOCAL
struct Local
{
    char rua[NOMETAM];
    int numero;
} Locais[TAM];

FILE *ArquivoLocal;

const char NomeArquivoLocal[] = "local.txt";
void MostrarMenuCadastroLocal()
{
    MostrarTitulo("                        Cadastro de locais                        ");
    ArquivoLocal = AbrirTxt(ArquivoLocal, NomeArquivoLocal, "r");

    int encontrado = 1;
    int i = 0;

    printf("Locais:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Locais[i], sizeof(Local), 1, ArquivoLocal);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem Locais cadastrados**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Locais[i].rua);
            printf("%d ", Locais[i].numero);
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
void CadastrarLocais()
{
    ArquivoLocal = AbrirTxt(ArquivoLocal, NomeArquivoLocal, "a");

    printf(" Digite o nome do Local: ");
    scanf("%s", Locais[0].rua);
    PularLinha();

    printf(" Digite o numero do Local: ");
    scanf("%d", Locais[0].numero);

    int retorno = fwrite(&Locais[0], sizeof(Local), 1, ArquivoLocal);

    printf("retorno");
    printf("%d", retorno);
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(ArquivoLocal);
    }
}

void MenuCadastroLocal()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroLocal();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarLocais();
            break;
        case 2:
            printf("Editando Locais");
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

// ALOJAMENTO
struct Alojamento
{
    char nome[NOMETAM];
    Local local;
} Alojamentos[TAM];

FILE *ArquivoAlojamento;

const char NomeArquivoAlojamento[] = "alojamento.txt";
void MostrarMenuCadastroAlojamento()
{
    MostrarTitulo("                        Cadastro de Alojamento                        ");
    ArquivoAlojamento = AbrirTxt(ArquivoAlojamento, NomeArquivoAlojamento, "r");

    int encontrado = 1;
    int i = 0;

    printf("Alojamentos:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Alojamentos[i], sizeof(Alojamento), 1, ArquivoAlojamento);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem alojamentos cadastrados**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Alojamentos[i].nome);
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
void CadastrarAlojamento()
{
    ArquivoAlojamento = AbrirTxt(ArquivoAlojamento, NomeArquivoAlojamento, "a");

    printf(" Digite o nome d]o Alojamento: ");
    scanf("%s", Alojamentos[0].nome);

    int retorno = fwrite(&Alojamentos[0], sizeof(Alojamento), 1, ArquivoAlojamento);

    printf("retorno");
    printf("%d", retorno);
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(ArquivoAlojamento);
    }
}

void MenuCadastroAlojamento()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroAlojamento();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarAlojamento();
            break;
        case 2:
            printf("Editando modalidade");
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

// MEDALHA
enum TipoMedalha
{
    Ouro,
    Prata,
    Bronze
};

struct Medalha
{
    TipoMedalha tipo;
};

// ATLETAS
struct ATLETA
{
    char nome[NOMETAM];
    char idade[2];
    Modalidade modalidade;
    Pais pais;
    Equipe equipe;
    Alojamento alojamento;
    Medalha medalhas[TAM];
} Atletas[TAM];

FILE *arquivoAtletas;

void MostrarMenuCadastroAtletas()
{
    MostrarTitulo("                        Cadastro de atletas                        ");
    arquivoAtletas = AbrirTxt(arquivoAtletas, "atletas.txt", "r");

    int encontrado = 1;
    int i = 0;

    printf("Atletas:\n");
    while (encontrado == 1)
    {
        encontrado = fread(&Atletas[i], sizeof(ATLETA), 1, arquivoAtletas);

        if (encontrado == 0)
        {
            if (i == 0)
                printf("**Sem atletas cadastrados**");

            break;
        }
        else
        {
            printf("%d - ", i + 1);
            printf(Atletas[i].nome);
            printf(Atletas[i].pais.nome);
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

void CadastrarAtleta()
{
    arquivoAtletas = AbrirTxt(arquivoAtletas, "atletas.txt", "a");

    printf(" Digite o nome do atleta: ");
    scanf("%s", Atletas[0].nome);
    printf(" Digite a idade do atleta: ");
    scanf("%s", Atletas[0].idade);

    printf("Cadastrado");
    int retorno = fwrite(&Atletas[0], sizeof(ATLETA), 1, arquivoAtletas);
    
    if (retorno == 1)
    {
        printf("\n Gravacao ok! ");
        getch();
        LimparTela();
        fclose(arquivoAtletas);
    }
}

void MenuCadastroAtletas()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        LimparTela();
        MostrarMenuCadastroAtletas();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarAtleta();
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
    scanf("%s", usuarios[0].usuario);
    printf(" Digite a senha: ");
    scanf("%s", usuarios[0].senha);

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
    printf("6 - Cadastro de modalidade\n");
    printf("7 - Cadastro de paises\n");
    printf("8 - Cadastrar equipe\n");
    printf("9 - Cadastrar local\n");
    printf("10 - Cadastrar alojamento\n");
    printf("12 - Voltar\n");
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
            MenuCadastroAtletas();
            break;
        case 2:
            break;
        case 5:
            MenuCadastroUsuarios();
            break;
        case 6:
            MenuCadastroModalidade();
            break;
        case 7:
            MenuCadastroPais();
            break;
        case 8:
            MenuCadastroEquipe();
            break;
        case 9:
            MenuCadastroLocal();
            break;
        case 10:
            MenuCadastroAlojamento();
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
            //Relatorios
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