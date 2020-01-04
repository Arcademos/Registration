#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include <locale.h>
struct cadastro
{
    char login[200];
    char nome[200];
    char senha[8];
};
int testa(char *nm, char *se)
{
    FILE *farq;
    struct cadastro u;
    farq = fopen("arqsenhas.arq", "r");      
    if(farq == NULL)
    {
        printf( "Erro na abertura do arquivo");
        exit(1);
    }
    while(!feof(farq)) 
    {
        fread(&u, 109, 1, farq);
        if (strcmp(u.nome,nm)) 
        {
        if(strcmp(u.senha,se)) 
        {
        return 0;
        }
        }
    }
}
int main()
{
    int opcao;
    char confirma[8];
    int i;
    struct cadastro usuario;
    struct cadastro x;
    FILE *farq;
    do
    {
        printf("---------------------------\n");
        printf("|\t");
        printf("1- para entrar\n");
        printf("|\t");
        printf("2- Para fazer cadastro\n");
        printf("|\t");
        printf("3- Para fazer sair\n");
        printf("---------------------------\n");
        printf("Digite uma opcao\n");
        scanf("%i",&opcao);
        switch (opcao)
        {           
            case 1:
                fflush(stdin);
                farq = fopen("cadastro.arq", "ab");
                printf("Digite o login:\n");
                gets(usuario.login);
                usuario.nome[strlen(usuario.login)]='\0';
                printf("Digite a senha:\n");
                gets(usuario.senha);
                printf("confirmar senha:\n");
                gets(confirma);
                if (strcmp(usuario.senha,confirma)==0)
                {
                    fwrite(&usuario, 408, 1, farq); // grava a cadeia texto no arquivo
                    printf("Hello\n");
                }  
                else 
                {
                    printf("Senha nao coincidem\n");
                }
                fclose(farq);
            break;
            case 2:
                fflush(stdin);
                farq = fopen("cadastro.arq","a");
                if(farq == NULL)
                {
                    printf("Erro na abertura do arquivo!\n");
                    return 1;
                }
                printf("Digite seu nome:\n");
                gets(x.nome);
                fprintf(farq, "%s \n",x.nome);
                printf("Digite um login:\n");
                gets(x.login);
                fprintf(farq, "%s \n",x.login);
                printf("Digite uma senha:\n");
                gets(x.senha);
                fprintf(farq, "%s \n",x.senha);
                fclose(farq);
            break;
            case 3:
                return 0;
            break;
            default:
                printf("Opcao invalida!");
            break;
        }
    } while (opcao !=3);
	system("PAUSE");
    return 0;	
}