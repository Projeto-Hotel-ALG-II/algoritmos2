#ifndef quick_tools_h
#define quick_tools_h

#include <stdio.h>
#include <conio.h>
#include <windows.h>
/*
 * Fun��o limpa o prompt de comando 
*/
void clearPrompt(){
    system("cls");
}

/*
 * Fun��o pausa a aplica��o e mostra o texto "Pressione qualquer tecla para continuar..." 
*/
void pausaSist(){
    printf("\nPressione qualquer tecla para continuar . . .");
    getch();
}

#endif