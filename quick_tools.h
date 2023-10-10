#ifndef quick_tools_h
#define quick_tools_h

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>

/*
 * Fun‡Æo limpa o prompt de comando
 */
void clearPrompt()
{
    system("cls");
}

/*
 * Fun‡Æo pausa a aplica‡Æo e mostra o texto "Pressione qualquer tecla para continuar..."
 */
void pausaSist()
{
    printf("\nPressione qualquer tecla para continuar . . .");
    getch();
}

/*
 * Fun‡Æo para tornar arquivo temporario o arquivo principal, exemplo: substituiTemp("..\\data\\dados_arq.txt","..\\data\\temp.txt");
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
 * Fun‡Æo para contar linhas de um arquivo, exemplo: contadorLinhas("..\\data\\dados_nomeArq.txt");
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