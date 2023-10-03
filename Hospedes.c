#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "quick_tools.h"
#include "structs_hotel.h"
#include "hospedes_hotel.h"

int main()
{
    int choice; // op‡äes selecionadas pelo usu rio
    int ret;    // valor de return das subrotinas

    // Structs para cada
    str_hospedes hospedes;

    while (1)
    {
        clearPrompt();
        // menu principal da se‡Æo cadastro de hospedes
        printf("Cadastro e GestÆo de H¢spedes:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1: // ===== CADASTRAR HàSPEDE =====

            // recolhendo dados do novo hospede
            fflush(stdin);
            printf("Indique o nome               : ");
            scanf(" %[^\n]", hospedes.nome);

            fflush(stdin); // Limpa o buffer
            printf("Indique o endere‡o completo  : ");
            scanf(" %[^\n]", hospedes.end_completo);

            fflush(stdin);
            printf("Indique o CPF                : ");
            scanf(" %[^\n]", hospedes.cpf);

            fflush(stdin);
            printf("Indique o telefone           : ");
            scanf(" %[^\n]", hospedes.telefone);

            fflush(stdin);
            printf("Indique o e-mail             : ");
            scanf(" %[^\n]", hospedes.email);

            fflush(stdin);
            printf("Indique o sexo               : ");
            hospedes.sexo = getch();
            printf("%c\n", hospedes.sexo);

            fflush(stdin);
            printf("Indique o estado civil       : ");
            scanf("%[^\n]", hospedes.estado_civil);

            fflush(stdin);
            printf("Indique a data de nascimento : ");
            scanf("%[^\n]", hospedes.data_nasc);

            // fun‡Æo cadastra os h¢spedes
            ret = cadastrarHospede(hospedes);

            if (ret == 0)
            {
                printf("\nH¢spede cadastrado com sucesso!");
                pausaSist();
            }
            else
            {
                printf("Erro ao acessar o arquivo dados_hospedes.txt\n");
                pausaSist();
            }

            break;

        case 2: // ===== PESQUISAR HàSPEDE =====
            printf("Pesquisar H¢spede: \n");
            printf("CPF do h¢spede (XXX.XXX.XXX-XX): ");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            ret = pesquisarHospede(hospedes.cpf, hospedes, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

            if (ret == 0)
            {
                printf("=> Cliente encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Endere‡o           : %s\n", hospedes.end_completo);
                printf("CPF                : %s\n", hospedes.cpf);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("E-mail             : %s\n", hospedes.email);
                printf("Sexo               : %c\n", hospedes.sexo);
                printf("Estado Civil       : %s\n", hospedes.estado_civil);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                pausaSist();
            }
            else
            {
                printf("=> H¢spede nÆo encontrado!\n");
                pausaSist();
            }
            break;
        case 3: // ===== ALTERAR HàSPEDE =====
            clearPrompt();
            printf("Alterar h¢spede:\n");

            printf("Informe o CPF: \n");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            printf("\n");

            ret = pesquisarHospede(hospedes.cpf, hospedes, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

            if (ret == 0)
            {
                printf("=> Cliente encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("Sexo               : %c\n", hospedes.sexo);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                printf("=========================================\n");
                printf("Deseja alterar este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    AnsiUpper(hospedes.nome);
                    clearPrompt();
                    printf("Alterar h¢spede: %s\n", hospedes.nome);
                    fflush(stdin);
                    printf("Indique o nome               : ");
                    scanf(" %[^\n]", hospedes.nome);

                    fflush(stdin);
                    printf("Indique o endere‡o completo  : ");
                    scanf(" %[^\n]", hospedes.end_completo);

                    fflush(stdin);
                    printf("Indique o CPF                : ");
                    scanf(" %[^\n]", hospedes.cpf);

                    fflush(stdin);
                    printf("Indique o telefone           : ");
                    scanf(" %[^\n]", hospedes.telefone);

                    fflush(stdin);
                    printf("Indique o e-mail             : ");
                    scanf(" %[^\n]", hospedes.email);

                    fflush(stdin);
                    printf("Indique o sexo               : ");
                    hospedes.sexo = getch();
                    printf("%c\n", hospedes.sexo);

                    fflush(stdin);
                    printf("Indique o estado civil       : ");
                    scanf("%[^\n]", hospedes.estado_civil);

                    fflush(stdin);
                    printf("Indique a data de nascimento : ");
                    scanf("%[^\n]", hospedes.data_nasc);

                    ret = alterarHospede(hospedes.cpf, hospedes);
                    renomeiaFile(); // medida provis¢ria

                    if (ret == 0)
                    {
                        printf("H¢spede alterado com sucesso");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao alterar h¢spede");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("=> H¢spede nÆo encontrado!\n");
                pausaSist();
            }

            break;
        case 4: // ===== EXCLUIR HàSPEDE =====
            clearPrompt();
            printf("Excluir h¢spede:\n");

            printf("Informe o CPF: \n");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            printf("\n");

            ret = pesquisarHospede(hospedes.cpf, hospedes, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

            if (ret == 0)
            {
                printf("=> Cliente encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("Sexo               : %c\n", hospedes.sexo);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                printf("=========================================\n");
                printf("Deseja excluir este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirHospede(hospedes.cpf);
                    renomeiaFile(); // medida provis¢ria

                    if (ret == 0)
                    {
                        printf("H¢spede exclu¡do com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao excluir h¢spede!");
                        pausaSist();
                    }
                }
            }
            break;
        case 24:
            renomeiaFile();
            break;

        default: // ===== EM CASO DE OUTRA OP€ÇO =====
            printf("\n[X] ERRO - Insira um valor v lido!");
            pausaSist();
            break;
        }
    }

    return 0;
}