#ifndef quick_tools_h
#define quick_tools_h

#include <stdio.h>
#include <conio.h>
#include <windows.h>
/*
 * Fun‡Æo limpa o prompt de comando 
*/
void clearPrompt(){
    system("cls");
}

/*
 * Fun‡Æo pausa a aplica‡Æo e mostra o texto "Pressione qualquer tecla para continuar..." 
*/
void pausaSist(){
    printf("\nPressione qualquer tecla para continuar . . .");
    getch();
}

/*
 * Utilizada para tornar a pasta tempor ria principal
 */
int renomeiaFile(char temporario[35], char original[35])
{
    int ret;
    ret = remove(original);
    if (ret != 0)
        printf("ERRO AO REMOVER");
    pausaSist();

    ret = rename(temporario, original);
    if (ret != 0)
        printf("ERRO AO RENOMEAR");
    pausaSist();

    return 0;
}

#endif