#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "structs_hotel.h"
#include "quick_tools.h"

int main()
{
    str_hotel hotel;                                         // Exemplo de declara‡Æo da struct
    AnsiUpper(strcpy(hotel.nome_fantasia, "Muk-Luk Lodge")); // Nome provis¢rio pro hotel

    int choice;

    // La‡o de repeti‡Æo principal
    while (1)
    {
        choice = 0; // evitando lixo de memoria

        clear(); // Limpando prompt

        // Menu Principal
        printf("BEM VINDO AO HOTEL: %s!\n", hotel.nome_fantasia);
        printf("Selecione uma op‡Æo:\n");
        printf("1 - Cadastro e GestÆo de Dados\n");
        printf("2 - Reservas\n");
        printf("3 - Transa‡äes\n");
        printf("4 - Feedback\n");
        printf("5 - Importa‡Æo/Exporta‡Æo de Dados\n");
        printf("6 - Sair\n");
        printf("=> ");
        scanf("%d", &choice);

        // Swich para os M¢dulos
        switch (choice)
        {
        case 1: // M¢dulo 1 - Cadastro e GestÆo de Dados
            while (1)
            {
                clear();
                printf("=> CADASTRO E GESTÇO DE DADOS\n");
                printf("Selecione uma op‡Æo: \n");
                printf("1 - Hotel\n");
                printf("2 - H¢spedes\n");
                printf("3 - Acomoda‡äes\n");
                printf("4 - Categoria de Acomoda‡äes\n");
                printf("5 - Fornecedores\n");
                printf("6 - Produtos\n");
                printf("7 - Operadores\n");
                printf("8 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 8)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Campo 1 - Hotel - JoÆo Vitor *

                    break;
                case 2: // Campo 2 - H¢spedes - Matheus Garcia *

                    break;
                case 3: // Campo 3 - Acomoda‡äes - Iasmim Garcia *

                    break;
                case 4: // Campo 4 - Categoria de Acomoda‡äes

                    break;
                case 5: // Campo 5 - Fornecedores

                    break;
                case 6: // Campo 6 - Produtos

                    break;
                case 7: // Campo 7 - Operadores

                    break;
                default: // Nenhuma das op‡äes
                    printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
                    getch();
                    break;
                }
            }
            break;

        case 2: // M¢dulo 2 - Reservas
            while (1)
            {
                clear();
                printf("=> RESERVAS:\n");
                printf("Selecione uma op‡Æo: \n");
                printf("1 - Fazer Reserva\n");
                printf("2 - Cancelamento\n");
                printf("3 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 3)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Fazer Reserva

                    break;
                case 2: // Cancelamento

                    break;
                default:
                    printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
                    getch();
                    break;
                }
            }
            break;
        case 3: // M¢dulo 3 - Transa‡äes
            while (1)
            {
                clear();
                printf("=> TRANSA€åES\n");
                printf("Selecione uma op‡Æo: \n");
                printf("1 - Check-in\n");
                printf("2 - Check-out\n");
                printf("3 - Sa¡da de Produtos\n");
                printf("4 - Controle de Caixa\n");
                printf("5 - Contas a Receber\n");
                printf("6 - Contas a Pagar\n");
                printf("7 - Entrada de Produtos Industrializados\n");
                printf("8 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 8)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Se‡Æo 1 - Check-in

                    break;
                case 2: // Se‡Æo 2 - Check-out

                    break;
                case 3: // Transa‡Æo 1 - Sa¡da de produtos(venda)

                    break;
                case 4: // Constrole de caixa

                    break;
                case 5: // Transa‡Æo 2 - Contas a Receber

                    break;
                case 6: // Transa‡Æo 3 - Contas a Pagar

                    break;
                case 7: // Transa‡Æo 4 - Entrada de Produtos Industrializados

                    break;
                default: // Nenhuma das op‡äes
                    printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
                    getch();
                    break;
                }
            }
            break;
        case 4: // M¢dulo 4 - Feedback
            while (1)
            {
                clear();
                printf("=> FEEDBACK\n");
                printf("Selecione uma op‡Æo: \n");
                printf(" 1 - Listagem de H¢spedes\n");
                printf(" 2 - Listagem de Acomoda‡äes\n");
                printf(" 3 - Listagem de Reservas\n");
                printf(" 4 - Produtos em Estoque M¡nimo\n");
                printf(" 5 - Listagem de Produtos de Consumo\n");
                printf(" 6 - Listagem de Movimenta‡Æo das Acomoda‡äes\n");
                printf(" 7 - Vendas\n");
                printf(" 8 - Contas a Receber\n");
                printf(" 9 - Contas a Pagar\n");
                printf("10 - Movimenta‡Æo de Caixa\n");
                printf("11 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 11)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Relat¢rio 1 - Listagem de H¢spedes

                    break;
                case 2: // Relat¢rio 2 - Listagem de Acomoda‡äes

                    break;
                case 3: // Relat¢rio 3 - Listagem de Reservas

                    break;
                case 4: // Relat¢rio 4 - Produtos em Estoque M¡nimo

                    break;
                case 5: // Relat¢rio 5 - Listagem de Produtos de Consumo

                    break;
                case 6: // Relat¢rio 6 - Listagem de Movimenta‡Æo das Acomoda‡äes

                    break;
                case 7: // Relat¢rio 7 - Vendas

                    break;
                case 8: // Relat¢rio 8 - Contas a Receber

                    break;
                case 9: // Relat¢rio 9 - Contas a Pagar

                    break;
                case 10: // Relat¢rio 10 - Movimenta‡Æo de caixa

                    break;
                default: // Nenhuma das op‡äes
                    printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
                    getch();
                    break;
                }
            }
            break;
        case 5: // M¢dulo 5 - Importa‡Æo/Exporta‡Æo de Dados
                    while (1)
                    {
                        clear();
                        printf("=> Cadastro e GestÆo - H¢spedes:\n");
                        printf("Selecione uma op‡Æo: \n");
                        printf("1 - Importar\n");
                        printf("2 - Exportar\n");
                        printf("3 - Voltar\n");
                        printf("=> ");
                        scanf("%d", &choice);
                        if (choice == 3)
                        {
                            break;
                        }
                        switch (choice)
                        {
                        case 1: // Importar

                            break;
                        case 2: // Exportar

                            break;
                        default:
                            printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
                            getch();
                            break;
                        }
                    }
            break;
        case 6:
            clear();
            printf("Tem certeza que deseja sair do sistema?\n");
            printf("                                       \n");
            printf("       1 - Sim     |     2 - NÆo       \n");
            printf("=> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                clear();
                return 0;
            }
            break;

        default: // Nenhuma das op‡äes
            printf("\n[X] ERRO - Insira um valor v lido! Pressione qualquer tecla para voltar");
            getch();
            break;
        }
    }

    return 0;
}