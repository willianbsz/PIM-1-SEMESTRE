#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#define TAM 100

//==UTILS==
void LimparTela()
{
    system("cls");
}

//==LOGIN==
struct ModeloDeLogin
{
    char usuario[50];
    char senha[8];
};

FILE *loginFile;
ModeloDeLogin usuarios[TAM];

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

void BuscarUsuario(ModeloDeLogin login)
{
    loginFile = AbrirTxt(loginFile, "login.txt", "r");

    int encontrado = 1;
    int i = 0;

    while (encontrado == 1)
    {
        printf("Procurando na posição\n");
        printf("%d", i + 1);
        printf("\n\n");
        encontrado = fread(&usuarios[i], sizeof(ModeloDeLogin), 1, loginFile);

        if (encontrado == 0)
        {
            printf("\nNão foi possivel encontrar o usuário");
            break;
        }
        else if (strcmp(login.usuario, usuarios[i].usuario) == 0 && strcmp(login.senha, usuarios[i].senha) == 0)
        {
            printf("\nEncontrei o usuario");
            break;
        }
        else
        {
            i++;
            continue;
        }
    }
}

void Login()
{
    struct ModeloDeLogin login;
    login = MostrarFormularioLogin(login);
    BuscarUsuario(login);
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

int main()
{
    setlocale(LC_ALL, "Portuguese");
    CadastrarUsuario();
    Login();
    return 0;
}