#ifndef QUICK_TOOLS_H_INCLUDED
#define QUICK_TOOLS_H_INCLUDED

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>

/*
 * Fun��o limpa o prompt de comando
 */
void clearPrompt()
{
    system("cls");
}

/*
 * Fun��o pausa a aplica��o e mostra o texto "Pressione qualquer tecla para continuar..."
 */
void pausaSist()
{
    printf("\nPressione qualquer tecla para continuar . . .");
    getch();
}

/*
 * Fun��o para tornar arquivo temporario o arquivo principal, exemplo: substituiTemp("..\\data\\dados_arq.txt","..\\data\\temp.txt");
 */
int substituiTemp(char original[35], char temporario[35])
{

    if (chmod(original, S_IWUSR) == 0 && chmod(temporario, S_IWUSR) == 0)
    {
        remove(original);
        rename(temporario, original);
    }

    return 0;
}

/*
 * Fun��o para contar linhas de um arquivo, exemplo: contadorLinhas("..\\data\\dados_nomeArq.txt");
 */
int contadorLinhas(char fileName[35])
{
    FILE *pF;
    char linha[1000];
    int qtdLinhas = 1;
    pF = fopen(fileName, "r");
    while (fgets(linha, sizeof(linha), pF) != NULL)
    {
        qtdLinhas++;
    }
    fclose(pF);
    return qtdLinhas;
}

#endif