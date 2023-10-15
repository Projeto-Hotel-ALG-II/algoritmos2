#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "quick_tools.h"

// TODAS AS STRUCTS
#include "structs_hotel.h"

// FUN€åES: GEST¶O E CADASTROS
#include "hospedes_hotel.h"
#include "fornecedores_hotel.h"

// FUN€åES: RESERVAS
#include "reservas_hotel.h"

int main()
{
    // STRUCTS CADASTRO E GESTÇO
    str_hotel hotel;
    str_hospedes hospedes;
    // str_acomodacoes acomod;
    str_fornecedores fornecedores;

    // STRUCTS RESERVAS
    // str_reservas reserva;

    AnsiUpper(strcpy(hotel.nome_fantasia, "Muk-Luk Lodge")); // Nome provis¢rio pro hotel

    int choice; // variavel armazena as escolhas feitas pelo usu rio
    int ret;    // variavel armazena os dados retornados das fun‡äes

    char nomeTemp[35];
    char nomeOrg[35];

    // La‡o de repeti‡Æo principal
    while (1)
    {
        choice = 0; // evitando lixo de memoria

        clearPrompt(); // Limpando prompt

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
                clearPrompt();
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
                    strcpy(nomeTemp, "..\\data\\temp.txt");
                    strcpy(nomeOrg, "..\\data\\dados_hospedes.txt");
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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

                            if (ret == 0)
                            {
                                printf("=> H¢spede encontrado!\n");
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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

                            if (ret == 0)
                            {
                                printf("=> H¢spede encontrado!\n");
                                printf("=========================================\n");
                                printf("C¢digo             : %d\n", hospedes.codigo);
                                printf("Nome               : %s\n", hospedes.nome);
                                printf("Telefone           : %s\n", hospedes.telefone);
                                printf("Email              : %s\n", hospedes.email);
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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes.codigo, hospedes.nome, hospedes.end_completo, hospedes.cpf, hospedes.telefone, hospedes.email, &hospedes.sexo, hospedes.estado_civil, hospedes.data_nasc);

                            if (ret == 0)
                            {
                                printf("=> H¢spede encontrado!\n");
                                printf("=========================================\n");
                                printf("C¢digo             : %d\n", hospedes.codigo);
                                printf("Nome               : %s\n", hospedes.nome);
                                printf("Telefone           : %s\n", hospedes.telefone);
                                printf("Email              : %s\n", hospedes.email);
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

                                    if (ret == 0)
                                    {
                                        printf("H¢spede exclu¡do com sucesso!");
                                        pausaSist();
                                    }
                                    else
                                    {
                                        printf("=> Falha ao excluir h¢spede.");
                                        pausaSist();
                                    }
                                }
                            }
                            else
                            {
                                printf("H¢spede nÆo encontrado.");
                                pausaSist();
                            }
                            break;
                        default: // ===== EM CASO DE OUTRA OP€ÇO =====
                            printf("\n[X] ERRO - Insira um valor v lido!");
                            pausaSist();
                            break;
                        }
                    }
                    break;
                case 3: // Campo 3 - Acomoda‡äes - Iasmim Garcia *

                    break;
                case 4: // Campo 4 - Categoria de Acomoda‡äes - Iasmim Garcia *

                    break;
                case 5: // Campo 5 - Fornecedores - Matheus Garcia *
                    while (1)
                    {
                        clearPrompt();
                        // menu principal da se‡Æo funcionarios
                        printf("Cadastro e GestÆo de Fornecedores:\n");
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
                            printf("Indique a razÆo social       : ");
                            scanf(" %[^\n]", fornecedores.razao_social);

                            fflush(stdin);
                            printf("Indique a inscri‡Æo estadual : ");
                            scanf(" %[^\n]", fornecedores.inscricao_estadual);

                            fflush(stdin);
                            printf("Indique o cnpj               : ");
                            scanf(" %[^\n]", fornecedores.cnpj);

                            fflush(stdin);
                            printf("Indique o endere‡o completo  : ");
                            scanf(" %[^\n]", fornecedores.end_completo);

                            fflush(stdin);
                            printf("Indique o telefone           : ");
                            scanf(" %[^\n]", fornecedores.telefone);

                            fflush(stdin);
                            printf("Indique o email              : ");
                            scanf(" %[^\n]", fornecedores.email);

                            // fun‡Æo cadastra o fornecedor
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
                                printf("RazÆo Social       : %s\n", fornecedores.razao_social);
                                printf("Inscri‡Æo Estadual : %s\n", fornecedores.inscricao_estadual);
                                printf("CNPJ               : %s\n", fornecedores.cnpj);
                                printf("Endere‡o Completo  : %s\n", fornecedores.end_completo);
                                printf("Telefone           : %s\n", fornecedores.telefone);
                                printf("Email              : %s\n", fornecedores.email);
                                pausaSist();
                            }
                            else
                            {
                                printf("=> Fornecedor nÆo encontrado!\n");
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
                                printf("0 - NÆo\n");
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
                                    printf("Indique a nova razÆo social       : ");
                                    scanf(" %[^\n]", fornecedores.razao_social);

                                    fflush(stdin);
                                    printf("Indique a nova inscri‡Æo estadual : ");
                                    scanf(" %[^\n]", fornecedores.inscricao_estadual);

                                    fflush(stdin);
                                    printf("Indique o novo cnpj               : ");
                                    scanf(" %[^\n]", fornecedores.cnpj);

                                    fflush(stdin);
                                    printf("Indique o novo endere‡o completo  : ");
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
                                printf("=> Fornecedor nÆo encontrado!\n");
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
                                printf("0 - NÆo\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    ret = excluirFornecedor(fornecedores.cnpj);

                                    if (ret == 0)
                                    {
                                        printf("Fornecedor exclu¡do com sucesso!");
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
                                printf("Fornecedor nÆo encontrado.");
                                pausaSist();
                            }

                            break;
                        default: // ===== EM CASO DE OUTRA OP€ÇO =====
                            printf("\n[X] ERRO - Insira um valor v lido!");
                            pausaSist();
                            break;
                        }
                    }

                    break;
                case 6: // Campo 6 - Produtos - JoÆo Vitor *

                    break;
                case 7: // Campo 7 - Operadores - Iasmim Garcia *

                    break;
                default: // Nenhuma das op‡äes
                    printf("\n[X] ERRO - Insira um valor v lido!");
                    pausaSist();
                    break;
                }
            }
            break;

        case 2: // M¢dulo 2 - Reservas
            
            break;
        case 3: // M¢dulo 3 - Transa‡äes
            while (1)
            {
                clearPrompt();
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
                    printf("\n[X] ERRO - Insira um valor v lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 4: // M¢dulo 4 - Feedback
            while (1)
            {
                clearPrompt();
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
                    printf("\n[X] ERRO - Insira um valor v lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 5: // M¢dulo 5 - Importa‡Æo/Exporta‡Æo de Dados
            while (1)
            {
                clearPrompt();
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
            clearPrompt();
            printf("Tem certeza que deseja sair do sistema?\n");
            printf("                                       \n");
            printf("       1 - Sim     |     2 - NÆo       \n");
            printf("=> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                rmvTemp();
                clearPrompt();
                return 0;
            }
            break;

        default: // Nenhuma das op‡äes
            printf("\n[X] ERRO - Insira um valor v lido!");
            pausaSist();
            break;
        }
    }

    return 0;
}