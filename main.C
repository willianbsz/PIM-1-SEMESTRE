#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define TAM 100
#define NOMETAM 100

//==UTILS==
int contador = 1;

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
    exit(0);
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
    arq = fopen(nomeDoArquivo, acao);
    if (arq == NULL)
    {
        printf("Erro!\n O arquivo da lista não pode ser aberto!\n");
        getch();
        exit(1);
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

Modalidade PegarUmaModalidade(int index)
{
    ArquivoModalidade = AbrirTxt(ArquivoModalidade, NomeArquivoModalidade, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Modalidades[i], sizeof(Modalidade), 1, ArquivoModalidade);

        if (index == i)
        {
            return Modalidades[index];
        }
        i++;
    }
}

void MostrarModalidades()
{
    ArquivoModalidade = AbrirTxt(ArquivoModalidade, NomeArquivoModalidade, "r");

    int encontrado = 1;
    int i = 0;

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
}
void MostrarMenuCadastroModalidade()
{
    MostrarTitulo("                        Cadastro de modalidade                        ");
    printf("Modalidades:\n");
    MostrarModalidades();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}
void CadastrarModalidade()
{
    LimparTela();
    ArquivoModalidade = AbrirTxt(ArquivoModalidade, NomeArquivoModalidade, "a");

    printf(" Digite o nome da modalidade: ");
    scanf("%s", Modalidades[0].nome);

    int retorno = fwrite(&Modalidades[0], sizeof(Modalidade), 1, ArquivoModalidade);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroModalidade();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarModalidade();
            tentarNovamente = true;
            break;
        case 0:
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

Pais PegarUmPais(int index)
{
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Paises[index], sizeof(Pais), 1, ArquivoPais);

        if (index == i)
        {
            return Paises[index];
        }
        i++;
    }
}

void MostrarPaises()
{
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "r");

    int encontrado = 1;
    int i = 0;

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
}

void MostrarMenuCadastroPais()
{
    MostrarTitulo("                        Cadastro de Pais                        ");
    printf("Paises:\n");
    MostrarPaises();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}
void CadastrarPaises()
{
    LimparTela();
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "a");

    printf(" Digite o nome do Pais: ");
    scanf("%s", Paises[0].nome);

    int retorno = fwrite(&Paises[0], sizeof(Pais), 1, ArquivoPais);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroPais();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarPaises();
            tentarNovamente = true;
            break;
        case 0:
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
const char NomeArquivoEquipe[] = "equipes.txt";

Equipe PegarUmaEquipe(int index)
{
    ArquivoEquipe = AbrirTxt(ArquivoEquipe, NomeArquivoEquipe, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Equipes[index], sizeof(Equipe), 1, ArquivoEquipe);

        if (index == i)
        {
            return Equipes[index];
        }
        i++;
    }
}

void MostrarEquipes()
{
    ArquivoEquipe = AbrirTxt(ArquivoEquipe, NomeArquivoEquipe, "r");

    int encontrado = 1;
    int i = 0;

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
}
void MostrarMenuCadastroEquipe()
{
    MostrarTitulo("                        Cadastro de equipes                        ");
    printf("Equipes:\n");
    MostrarEquipes();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}
void CadastrarEquipes()
{
    LimparTela();
    ArquivoEquipe = AbrirTxt(ArquivoEquipe, NomeArquivoEquipe, "a");

    printf(" Digite o nome da equipe: ");
    scanf("%s", Paises[0].nome);

    int retorno = fwrite(&Equipes[0], sizeof(Equipe), 1, ArquivoEquipe);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroEquipe();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarEquipes();
            tentarNovamente = true;
            break;
        case 0:
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

const char NomeArquivoLocal[] = "locais.txt";
Local PegarUmaLocal(int index)
{
    ArquivoLocal = AbrirTxt(ArquivoLocal, NomeArquivoLocal, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Locais[index], sizeof(Local), 1, ArquivoLocal);

        if (index == i)
        {
            return Locais[index];
        }
        i++;
    }
}

void MostrarLocais()
{
    ArquivoLocal = AbrirTxt(ArquivoLocal, NomeArquivoLocal, "r");

    int encontrado = 1;
    int i = 0;

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
}
void MostrarMenuCadastroLocal()
{
    MostrarTitulo("                        Cadastro de locais                        ");
    printf("Locais:\n");
    MostrarLocais();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}
void CadastrarLocais()
{
    LimparTela();
    ArquivoLocal = AbrirTxt(ArquivoLocal, NomeArquivoLocal, "a");

    printf(" Digite o nome do Local: ");
    scanf("%s", Locais[0].rua);
    PularLinha();

    printf(" Digite o numero do Local: ");
    scanf("%d", Locais[0].numero);

    int retorno = fwrite(&Locais[0], sizeof(Local), 1, ArquivoLocal);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroLocal();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarLocais();
            tentarNovamente = true;
            break;
        case 0:
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

const char NomeArquivoAlojamento[] = "alojamentos.txt";

Alojamento PegarUmaAlojamento(int index)
{
    ArquivoAlojamento = AbrirTxt(ArquivoAlojamento, NomeArquivoAlojamento, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Alojamentos[index], sizeof(Alojamento), 1, ArquivoAlojamento);

        if (index == i)
        {
            return Alojamentos[index];
        }
        i++;
    }
}
void MostrarAlojamentos()
{
    ArquivoAlojamento = AbrirTxt(ArquivoAlojamento, NomeArquivoAlojamento, "r");

    int encontrado = 1;
    int i = 0;

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
}
void MostrarMenuCadastroAlojamento()
{
    MostrarTitulo("                        Cadastro de Alojamento                        ");
    printf("Alojamentos:\n");
    MostrarAlojamentos();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}

void CadastrarAlojamento()
{
    LimparTela();
    ArquivoAlojamento = AbrirTxt(ArquivoAlojamento, NomeArquivoAlojamento, "a");

    printf(" Digite o nome d]o Alojamento: ");
    scanf("%s", Alojamentos[0].nome);

    int retorno = fwrite(&Alojamentos[0], sizeof(Alojamento), 1, ArquivoAlojamento);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroAlojamento();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarAlojamento();
            tentarNovamente = true;
            break;
        case 0:
            break;
        default:
            printf("Opção inválida, tente novamente");
            break;
        }
    } while (tentarNovamente);
}

// ATLETAS
struct ATLETA
{
    char id[4];
    char nome[NOMETAM];
    char idade[2];
    Modalidade modalidade;
    Pais pais;
    Equipe equipe;
    Alojamento alojamento;
} Atletas[TAM];

FILE *arquivoAtletas;
char NomeArquivoAtleta[] = "atletas.txt";

ATLETA PegarUmAtleta(int index)
{
    arquivoAtletas = AbrirTxt(arquivoAtletas, NomeArquivoAtleta, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Atletas[i], sizeof(ATLETA), 1, arquivoAtletas);

        if (index == i)
        {
            return Atletas[index];
        }
        i++;
    }
}

void MostrarAtletas()
{
    arquivoAtletas = AbrirTxt(arquivoAtletas, NomeArquivoAtleta, "r");

    int encontrado = 1;
    int i = 0;

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
            printf(" - ");
            printf(Atletas[i].pais.nome);
            PularLinha();
            i++;
            continue;
        }
    }
}
void MostrarMenuCadastroAtletas()
{
    MostrarTitulo("                        Cadastro de atletas                        ");
    printf("Atletas:\n");
    MostrarAtletas();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Cadastrar\n");
    printf("0 - Voltar\n");
}

void CadastrarAtleta()
{
    LimparTela();
    arquivoAtletas = AbrirTxt(arquivoAtletas, NomeArquivoAtleta, "a");
    int resposta;
    printf("Digite o nome do atleta: ");
    scanf("%s", Atletas[0].nome);

    printf("Digite a idade do atleta: ");
    scanf("%s", Atletas[0].idade);

    LimparTela();
    printf("Selecione o pais do atleta: ");
    PularLinha();
    MostrarPaises();
    scanf("%d", &resposta);
    Atletas[0].pais = PegarUmPais(resposta - 1);

    LimparTela();
    printf("Selecione o alojamento do atleta: ");
    PularLinha();
    MostrarAlojamentos();
    scanf("%d", &resposta);
    Atletas[0].alojamento = PegarUmaAlojamento(resposta - 1);

    LimparTela();
    printf("Selecione a equipe do atleta: ");
    PularLinha();
    MostrarEquipes();
    scanf("%d", &resposta);
    Atletas[0].equipe = PegarUmaEquipe(resposta - 1);

    LimparTela();
    printf("Selecione a modalidade em que o atleta concorre: ");
    PularLinha();
    MostrarModalidades();
    PularLinha();
    scanf("%d", &resposta);
    Atletas[0].modalidade = PegarUmaModalidade(resposta - 1);

    srand(time(NULL));
    int id = rand() % 1000;
    printf("Aleatorio");
    printf("%d", id);
    sprintf(Atletas[0].id, "%d", id);

    int retorno = fwrite(&Atletas[0], sizeof(ATLETA), 1, arquivoAtletas);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastroAtletas();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarAtleta();
            tentarNovamente = true;
            break;
        case 0:
            break;
        default:
            printf("Opção inválida, tente novamente");
            break;
        }
    } while (tentarNovamente);
}

// MEDALHA
struct Medalha
{
    char tipo[7];
    ATLETA atleta;
} Medalhas[TAM];

FILE *ArquivoMedalha;

const char NomeArquivoMedalha[] = "medalhas.txt";

Medalha PegarUmaMedalha(int index)
{
    ArquivoMedalha = AbrirTxt(ArquivoMedalha, NomeArquivoMedalha, "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Medalhas[i], sizeof(ATLETA), 1, ArquivoMedalha);

        if (index == i)
        {
            return Medalhas[index];
        }
        i++;
    }
}

void MostrarMedalhasDoAtleta(ATLETA atleta, int index)
{
    ArquivoMedalha = AbrirTxt(ArquivoMedalha, NomeArquivoMedalha, "r");

    int encontrado = 1;
    int i = 0;
    int ouro = 0;
    int prata = 0;
    int bronze = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Medalhas[i], sizeof(Medalha), 1, ArquivoMedalha);

        if (encontrado == 0)
            break;

        if (strcmp(Medalhas[i].atleta.id, atleta.id) == 0)
        {
            if (strcmp(Medalhas[i].tipo, "Ouro") == 0)
            {
                ouro++;
            }
            if (strcmp(Medalhas[i].tipo, "Prata") == 0)
            {
                prata++;
            }
            if (strcmp(Medalhas[i].tipo, "Bronze") == 0)
            {
                bronze++;
            }
        }

        i++;
        continue;
    }

    PularLinha();
    printf("%d - ", index + 1);
    printf(atleta.nome);
    printf(" %d", ouro);
    printf(" %d", prata);
    printf(" %d", bronze);
}

void MostrarMedalhasDoPais(Pais pais, int index)
{
    ArquivoMedalha = AbrirTxt(ArquivoMedalha, NomeArquivoMedalha, "r");

    int encontrado = 1;
    int i = 0;
    int ouro = 0;
    int prata = 0;
    int bronze = 0;

    while (encontrado == 1)
    {
        encontrado = fread(&Medalhas[i], sizeof(Medalha), 1, ArquivoMedalha);

        if (encontrado == 0)
            break;

        if (strcmp(Medalhas[i].atleta.pais.nome, pais.nome) == 0)
        {
            if (strcmp(Medalhas[i].tipo, "Ouro") == 0)
            {
                ouro++;
            }
            if (strcmp(Medalhas[i].tipo, "Prata") == 0)
            {
                prata++;
            }
            if (strcmp(Medalhas[i].tipo, "Bronze") == 0)
            {
                bronze++;
            }
        }

        i++;
        continue;
    }

    PularLinha();
    printf("%d - ", index + 1);
    printf(pais.nome);
    printf(" %d", ouro);
    printf(" %d", prata);
    printf(" %d", bronze);
}

void MostrarMedalhas()
{
    arquivoAtletas = AbrirTxt(arquivoAtletas, NomeArquivoAtleta, "r");

    int encontrado = 1;
    int i = 0;
    printf("NOME    -    OURO    -    PRATA    -    BRONZE\n");
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
            MostrarMedalhasDoAtleta(Atletas[i], i);
            i++;
            continue;
        }
    }
}

void MostrarMedalhasPorPais()
{
    LimparTela();
    ArquivoPais = AbrirTxt(ArquivoPais, NomeArquivoPais, "r");

    int encontrado = 1;
    int i = 0;
    printf("NOME DO PAIS    -    OURO    -    PRATA    -    BRONZE\n");
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
            MostrarMedalhasDoPais(Paises[i], i);
            i++;
            continue;
        }
    }
    getch();
}

void MostrarMenuCadastroMedalha()
{
    MostrarTitulo("                        Medalhas                        ");
    MostrarMedalhas();
    LinhaDivisoria();
    PularLinha();
    printf("1 - Adicionar medalha a atleta\n");
    printf("2 - Mostrar medalhas por Pais\n");
    printf("0 - Voltar\n");
}

void CadastrarMedalha()
{
    LimparTela();
    ArquivoMedalha = AbrirTxt(ArquivoMedalha, NomeArquivoMedalha, "a");
    int resposta;

    printf("Selecione o tipo de medalha:\n");

    printf("1 - Ouro\n");
    printf("2 - Prata\n");
    printf("3 - Bronze\n");
    scanf("%d", &resposta);

    switch (resposta)
    {
    case 1:
        strcpy(Medalhas[0].tipo, "Ouro");
        break;
    case 2:
        strcpy(Medalhas[0].tipo, "Prata");
        break;
    case 3:
        strcpy(Medalhas[0].tipo, "Bronze");
        break;
    default:
        break;
    }

    LimparTela();
    printf("Selecione o atleta que receberá a medalha:\n");
    MostrarAtletas();
    int respostaAtleta;
    scanf("%d", &respostaAtleta);
    Medalhas[0].atleta = PegarUmAtleta(respostaAtleta - 1);

    int retorno = fwrite(&Medalhas[0], sizeof(Medalha), 1, ArquivoMedalha);

    if (retorno == 1)
    {
        printf("\nGravacao ok!");
        getch();
        LimparTela();
        fclose(ArquivoMedalha);
    }
}

void MenuCadastroMedalha()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        bool tentarNovamente = true;
        LimparTela();
        MostrarMenuCadastroMedalha();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            CadastrarMedalha();
            tentarNovamente = true;
            break;
        case 2:
            MostrarMedalhasPorPais();
            tentarNovamente = true;
            break;
        case 0:
            break;
        default:
            printf("Opção inválida, tente novamente");
            tentarNovamente = true;
            break;
        }
    } while (tentarNovamente);
}

//==LOGIN==
struct ModeloDeLogin
{
    char usuario[50];
    char senha[8];
} usuarios[TAM];

FILE *loginFile;

ModeloDeLogin MostrarFormularioLogin(ModeloDeLogin login)
{
    LimparTela();
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
    LimparTela();
    loginFile = AbrirTxt(loginFile, "login.txt", "a");

    printf(" Digite o nome de usuario: ");
    scanf("%s", usuarios[0].usuario);
    printf(" Digite a senha: ");
    scanf("%s", usuarios[0].senha);

    int retorno = fwrite(&usuarios[0], sizeof(ModeloDeLogin), 1, loginFile);

    if (retorno == 1)
    {
        printf("\nGravacao ok! ");
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
    printf("0 - Voltar\n");
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
        case 0:
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
    printf("2 - Usuários do sistema\n");
    printf("3 - Cadastro de modalidade\n");
    printf("4 - Cadastro de paises\n");
    printf("5 - Cadastrar equipe\n");
    printf("6 - Cadastrar local\n");
    printf("7 - Cadastrar alojamento\n");
    printf("0 - Voltar\n");
}

void MenuCadastros()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        tentarNovamente = false;
        LimparTela();
        MostrarMenuCadastros();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            MenuCadastroAtletas();
            tentarNovamente = true;
            break;
        case 2:
            MenuCadastroUsuarios();
            tentarNovamente = true;
            break;
        case 3:
            MenuCadastroModalidade();
            tentarNovamente = true;
            break;
        case 4:
            MenuCadastroPais();
            tentarNovamente = true;
            break;
        case 5:
            MenuCadastroEquipe();
            tentarNovamente = true;
            break;
        case 6:
            MenuCadastroLocal();
            tentarNovamente = true;
            break;
        case 7:
            MenuCadastroAlojamento();
            tentarNovamente = true;
            break;
        case 0:
            break;
        default:
            break;
            printf("Opção inválida, tente novamente");
        }
    } while (tentarNovamente);
}

// MENU PRINCIPAL
void MostrarMenuPrincipal()
{
    printf("O que você deseja fazer?\n\n");
    printf("1 - Cadastros\n");
    printf("2 - Medalhas\n");
    printf("0 - Sair\n");
}

void MenuPrincipal()
{
    int resposta;
    bool tentarNovamente = false;

    do
    {
        tentarNovamente = false;
        LimparTela();
        MostrarMenuPrincipal();
        scanf("%d", &resposta);
        switch (resposta)
        {
        case 1:
            MenuCadastros();
            tentarNovamente = true;
            break;
        case 2:
            MenuCadastroMedalha();
            tentarNovamente = true;
            break;
        case 0:
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
        tentarNovamente = false;
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

//Em futuras versões pretendemos ter também o calendário olimpico, que por ora não foi implementado.
