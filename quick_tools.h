#ifndef quick_tools_h
#define quick_tools_h

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
 * Fun��o apaga o arquivo tempor�rio
 */
void rmvTemp()
{
    remove("..\\data\\temp.txt");
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

    // � somada uma unidade ao contador de linhas cada vez que o arquivo l� uma linha
    while (fgets(linha, sizeof(linha), pF) != NULL)
    {
        qtdLinhas++;
    }
    fclose(pF);
    return qtdLinhas;
}

/*
 * Fun?�o para tornar arquivo temporario o arquivo principal, exemplo: substituiTemp("..\\data\\dados_arq.txt","..\\data\\temp.txt");
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
 * Fun��o copia arquivo para outro, Primeiro argumento deve ser do arquivo que sera copiado e o segundo deve ser do arquivo que recebera os dados copiados
 */
void copiarArquivo(FILE *pF_fileCopiada, FILE *pF_fileCriada)
{
    char linha[1000]; // leitor tempor�rio para cada linha lida do arquivo

    // A cada linha lida no arquivo tempor�rio a mesma � escrita no arquivo original
    while (fgets(linha, sizeof(linha), pF_fileCopiada) != NULL)
    {
        fputs(linha, pF_fileCriada);
    }
}

#endif