#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "quick_tools.h"
#include "structs_hotel.h"
#include "fornecedores_hotel.h"

int main()
{
    char nomeTemp[35], nomeOrg[35];
    int choice, ret;
    str_fornecedores fornecedores;
    strcpy(nomeTemp, "temp.txt");
    strcpy(nomeOrg, "dados_fornecedores.txt");

    while (1)
    {
        clearPrompt();
        // menu principal da seá∆o funcionarios
        printf("Cadastro e Gest∆o de Fornecedores:\n");
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
        case 1: // ===== CADASTRAR FORNECEDOR =====

            // recolhendo dados do novo fornecedor
            fflush(stdin);
            printf("Indique o nome               : ");
            scanf(" %[^\n]", fornecedores.nome);

            fflush(stdin);
            printf("Indique a raz∆o social       : ");
            scanf(" %[^\n]", fornecedores.razao_social);

            fflush(stdin);
            printf("Indique a inscriá∆o estadual : ");
            scanf(" %[^\n]", fornecedores.inscricao_estadual);

            fflush(stdin);
            printf("Indique o cnpj               : ");
            scanf(" %[^\n]", fornecedores.cnpj);

            fflush(stdin);
            printf("Indique o endereáo completo  : ");
            scanf(" %[^\n]", fornecedores.end_completo);

            fflush(stdin);
            printf("Indique o telefone           : ");
            scanf(" %[^\n]", fornecedores.telefone);

            fflush(stdin);
            printf("Indique o email              : ");
            scanf(" %[^\n]", fornecedores.email);

            // funá∆o cadastra o fornecedor
            ret = cadastrarFornecedor(fornecedores);

            if (ret == 0)
            {
                printf("\nFornecedor cadastrado com sucesso!");
                pausaSist();
            }
            else
            {
                printf("Erro ao acessar o arquivo dados_fornecedores.txt\n");
                pausaSist();
            }
            break;
        case 2: // ===== PESQUISAR FORNECEDOR =====
            printf("Pesquisar Fornecedor: \n");
            printf("CNPJ do fornecedor: ");
            fflush(stdin);
            scanf("%s", fornecedores.cnpj);

            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores.codigo, fornecedores.nome, fornecedores.razao_social, fornecedores.inscricao_estadual,
                                      fornecedores.cnpj, fornecedores.end_completo, fornecedores.telefone, fornecedores.email);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", fornecedores.codigo);
                printf("Nome Fornecedor    : %s\n", fornecedores.nome);
                printf("Raz∆o Social       : %s\n", fornecedores.razao_social);
                printf("Inscriá∆o Estadual : %s\n", fornecedores.inscricao_estadual);
                printf("CNPJ               : %s\n", fornecedores.cnpj);
                printf("Endereáo Completo  : %s\n", fornecedores.end_completo);
                printf("Telefone           : %s\n", fornecedores.telefone);
                printf("Email              : %s\n", fornecedores.email);
                pausaSist();
            }
            else
            {
                printf("=> Fornecedor n∆o encontrado!\n");
                pausaSist();
            }
            break;
        case 3: // ===== ALTERAR FORNECEDOR =====
            clearPrompt();
            printf("Alterar fornecedor:\n");

            printf("Informe o CNPJ: \n");
            fflush(stdin);
            scanf("%s", fornecedores.cnpj);

            printf("\n");

            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores.codigo, fornecedores.nome, fornecedores.razao_social, fornecedores.inscricao_estadual,
                                      fornecedores.cnpj, fornecedores.end_completo, fornecedores.telefone, fornecedores.email);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", fornecedores.codigo);
                printf("Nome               : %s\n", fornecedores.nome);
                printf("Telefone           : %s\n", fornecedores.telefone);
                printf("Email              : %s\n", fornecedores.email);
                printf("CNPJ               : %s\n", fornecedores.cnpj);
                printf("=========================================\n");
                printf("Deseja alterar este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    AnsiUpper(fornecedores.nome);
                    clearPrompt();
                    fflush(stdin);
                    printf("Indique o novo nome               : ");
                    scanf(" %[^\n]", fornecedores.nome);

                    fflush(stdin);
                    printf("Indique a nova raz∆o social       : ");
                    scanf(" %[^\n]", fornecedores.razao_social);

                    fflush(stdin);
                    printf("Indique a nova inscriá∆o estadual : ");
                    scanf(" %[^\n]", fornecedores.inscricao_estadual);

                    fflush(stdin);
                    printf("Indique o novo cnpj               : ");
                    scanf(" %[^\n]", fornecedores.cnpj);

                    fflush(stdin);
                    printf("Indique o novo endereáo completo  : ");
                    scanf(" %[^\n]", fornecedores.end_completo);

                    fflush(stdin);
                    printf("Indique o novo telefone           : ");
                    scanf(" %[^\n]", fornecedores.telefone);

                    fflush(stdin);
                    printf("Indique o novo email              : ");
                    scanf(" %[^\n]", fornecedores.email);

                    ret = alterarFornecedor(fornecedores.cnpj, fornecedores);

                    if (ret == 0)
                    {
                        printf("Fornecedor alterado com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao alterar fornecedor.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("=> Fornecedor n∆o encontrado!\n");
                pausaSist();
            }

            break;
        case 4: // ===== EXCLUIR FORNECEDOR =====
            clearPrompt();
            printf("Excluir fornecedor:\n");

            printf("Informe o CNPJ: \n");
            fflush(stdin);
            scanf("%s", fornecedores.cnpj);

            printf("\n");

            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores.codigo, fornecedores.nome, fornecedores.razao_social, fornecedores.inscricao_estadual,
                                      fornecedores.cnpj, fornecedores.end_completo, fornecedores.telefone, fornecedores.email);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", fornecedores.codigo);
                printf("Nome               : %s\n", fornecedores.nome);
                printf("Telefone           : %s\n", fornecedores.telefone);
                printf("Email              : %s\n", fornecedores.email);
                printf("CNPJ               : %s\n", fornecedores.cnpj);
                printf("=========================================\n");
                printf("Deseja excluir este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirFornecedor(fornecedores.cnpj);

                    if (ret == 0)
                    {
                        printf("Fornecedor exclu°do com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao excluir fornecedor.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Fornecedor n∆o encontrado.");
                pausaSist();
            }

            break;
        default: // ===== EM CASO DE OUTRA OPÄ«O =====
            printf("\n[X] ERRO - Insira um valor v†lido!");
            pausaSist();
            break;
        }
    }

    return 0;
}