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
#include "cadastro_operador.h"
#include "cadastro_acomodacoes.h"

// FUN€åES: RESERVAS
#include "reservas_hotel.h"

int main()
{
    // STRUCTS CADASTRO E GESTÇO
    str_hotel hotel;
    str_hospedes hospedes;
    str_fornecedores fornecedores;
    str_op_sistemas operador;
    str_categ_acomodacoes categoria;
    str_acomodacoes acomodacao;

    // STRUCTS RESERVAS
    // str_reservas reserva;

    int choice; // variavel armazena as escolhas feitas pelo usu rio
    int ret;    // variavel armazena os dados retornados das fun‡äes

    char nomeTemp[35];
    char nomeOrg[35];

    // La‡o de repeti‡Æo principal
    while (1)
    {
        AnsiUpper(strcpy(hotel.nome_fantasia, "Muk-Luk Lodge")); // Nome provis¢rio pro hotel
        choice = 0;                                              // evitando lixo de memoria

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
                printf("4 - Fornecedores\n");
                printf("5 - Produtos\n");
                printf("6 - Operadores\n");
                printf("7 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 7)
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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

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

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

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
                    while (1)
                    {
                        clearPrompt();
                        printf("Cadastro e GestÆo de Acomoda‡äes e Categorias:\n");
                        printf("1 - Cadastrar Categoria de Acomoda‡Æo\n");
                        printf("2 - Pesquisar Categoria de Acomoda‡Æo\n");
                        printf("3 - Editar Categoria de Acomoda‡Æo\n");
                        printf("4 - Excluir Categoria de Acomoda‡Æo\n");
                        printf("5 - Cadastrar Acomoda‡Æo\n");
                        printf("6 - Pesquisar Acomoda‡Æo\n");
                        printf("7 - Editar Acomoda‡Æo\n");
                        printf("8 - Excluir Acomoda‡Æo\n");
                        printf("9 - Listar Categorias\n");
                        printf("10 - Listar Acomoda‡äes\n");
                        printf("11 - Sair\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if(choice == 11){
                            break;
                        }

                        switch (choice)
                        {
                        case 1:
                            printf("Informe a descri‡Æo da categoria: ");
                            scanf(" %[^\n]", categoria.descricao);
                            printf("Informe o valor da diÃ¡ria: ");
                            scanf("%f", &categoria.valor_diaria);
                            printf("Informe a quantidade de pessoas: ");
                            scanf("%d", &categoria.qtd_pessoas);
                            cadastrarCategoria(categoria);
                            pausaSist();
                            break;

                        case 2:
                            printf("Informe o c¢digo da categoria de acomoda‡Æo: ");
                            int codigoCategoria;
                            scanf("%d", &codigoCategoria);

                            if (pesquisarCategoria(codigoCategoria, &categoria))
                            {
                                printf("Categoria de Acomoda‡Æo encontrada!\n");
                                printf("C¢digo: %d\n", categoria.codigo);
                                printf("Descri‡Æo: %s\n", categoria.descricao);
                                printf("Valor da DiÃ¡ria: %.2f\n", categoria.valor_diaria);
                                printf("Quantidade de Pessoas: %d\n", categoria.qtd_pessoas);
                            }
                            else
                            {
                                printf("Categoria de Acomoda‡Æo nÆo encontrada.\n");
                            }

                            pausaSist();
                            break;

                        case 3:
                            printf("Informe o c¢digo da categoria a ser editada: ");
                            int codigoEditar;
                            scanf("%d", &codigoEditar);
                            if (pesquisarCategoria(codigoEditar, &categoria))
                            {
                                printf("Informe a nova descri‡Æo da categoria: ");
                                scanf(" %[^\n]", categoria.descricao);
                                printf("Informe o novo valor da diÃ¡ria: ");
                                scanf("%f", &categoria.valor_diaria);
                                printf("Informe a nova quantidade de pessoas: ");
                                scanf("%d", &categoria.qtd_pessoas);
                                editarCategoria(codigoEditar, categoria);
                            }
                            pausaSist();
                            break;

                        case 4:
                            printf("Informe o c¢digo da categoria a ser excluÃ­da: ");
                            int codigoExcluirCategoria;
                            scanf("%d", &codigoExcluirCategoria);
                            if (excluirCategoria(codigoExcluirCategoria))
                            {
                                pausaSist();
                            }
                            else
                            {
                                pausaSist();
                            }
                            break;

                        case 5:
                            printf("Informe a descri‡Æo da acomoda‡Æo: ");
                            scanf(" %[^\n]", acomodacao.descricao);
                            printf("Informe as facilidades: ");
                            scanf(" %[^\n]", acomodacao.facilidades);
                            printf("Informe o c¢digo da categoria da acomoda‡Æo: ");
                            scanf("%d", &acomodacao.catec_acomod.codigo);
                            if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod))
                            {
                                cadastrarAcomodacao(acomodacao);
                            }
                            else
                            {
                                printf("Categoria de acomoda‡Æo nÆo encontrada.\n");
                            }
                            pausaSist();
                            break;

                        case 6:
                            printf("Informe o c¢digo da acomoda‡Æo: ");
                            int codigoAcomodacao;
                            scanf("%d", &codigoAcomodacao);
                            if (pesquisarAcomodacao(codigoAcomodacao, &acomodacao))
                            {
                                // Acomoda‡Æo encontrada
                            }
                            pausaSist();
                            break;

                        case 7:
                            printf("Informe o c¢digo da acomoda‡Æo a ser editada: ");
                            int codigoEditarAcomodacao;
                            scanf("%d", &codigoEditarAcomodacao);
                            if (pesquisarAcomodacao(codigoEditarAcomodacao, &acomodacao))
                            {
                                printf("Informe a nova descri‡Æo da acomoda‡Æo: ");
                                scanf(" %[^\n]", acomodacao.descricao);
                                printf("Informe as novas facilidades: ");
                                scanf(" %[^\n]", acomodacao.facilidades);
                                printf("Informe o novo c¢digo da categoria da acomoda‡Æo: ");
                                scanf("%d", &acomodacao.catec_acomod.codigo);
                                if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod))
                                {
                                    editarAcomodacao(codigoEditarAcomodacao, acomodacao);
                                }
                                else
                                {
                                    printf("Categoria de acomoda‡Æo nÆo encontrada.\n");
                                }
                            }
                            pausaSist();
                            break;

                        case 8:
                            printf("Informe o c¢digo da acomoda‡Æo a ser excluÃ­da: ");
                            int codigoExcluirAcomodacao;
                            scanf("%d", &codigoExcluirAcomodacao);
                            if (excluirAcomodacao(codigoExcluirAcomodacao))
                            {
                                pausaSist();
                            }
                            else
                            {
                                pausaSist();
                            }
                            break;

                        case 9:
                            listarCategorias();
                            pausaSist();
                            break;

                        case 10:
                            listarAcomodacoes();
                            pausaSist();
                            break;

                        default:
                            printf("Op‡Æo invÃ¡lida. Tente novamente.\n");
                            pausaSist();
                            break;
                        }
                    }
                    break;
                case 4: // Campo 5 - Fornecedores - Matheus Garcia *
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

                            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores);

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

                            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores);

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

                            ret = pesquisarFornecedor(fornecedores.cnpj, &fornecedores);

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
                case 5: // Campo 6 - Produtos - JoÆo Vitor *

                    break;
                case 6: // Campo 7 - Operadores - Iasmim Garcia *
                    while (1)
                    {
                        clearPrompt();
                        printf("Cadastro e GestÆo de Operadores do Sistema:\n");
                        printf("1 - Cadastrar\n");
                        printf("2 - Pesquisar\n");
                        printf("3 - Alterar\n");
                        printf("4 - Excluir\n");
                        printf("5 - Voltar\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if (choice == 5)
                        {
                            break; // Sai do loop quando a escolha for 5
                        }

                        switch (choice)
                        {
                        case 1: // CADASTRAR OPERADOR
                            // Recolhendo dados do novo operador
                            fflush(stdin);
                            printf("Indique o nome   : ");
                            scanf(" %[^\n]", operador.nome);

                            fflush(stdin);
                            printf("Indique o login  : ");
                            scanf(" %[^\n]", operador.usuario);

                            fflush(stdin);
                            printf("Indique a senha  : ");
                            scanf(" %[^\n]", operador.senha);

                            fflush(stdin);
                            printf("Indique as permissäes (separadas por v¡rgulas) : ");
                            scanf(" %[^\n]", operador.permissoes);

                            // Fun‡Æo cadastra o operador
                            ret = cadastrarOperador(operador);

                            if (ret == 0)
                            {
                                printf("\nOperador cadastrado com sucesso!");
                                pausaSist();
                            }
                            else
                            {
                                printf("Erro ao acessar o arquivo operadores.txt\n");
                                pausaSist();
                            }
                            break;

                        case 2: // PESQUISAR OPERADOR
                            printf("Pesquisar Operador: \n");
                            printf("Login do operador: ");
                            fflush(stdin);
                            scanf("%s", operador.usuario);

                            ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                            if (ret == 0)
                            {
                                printf("=> Operador encontrado!\n");
                                printf("=========================================\n");
                                printf("C¢digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permissäes  : %s\n", operador.permissoes);
                                pausaSist();
                            }
                            else
                            {
                                printf("=> Operador nÆo encontrado!\n");
                                pausaSist();
                            }
                            break;

                        case 3: // ALTERAR OPERADOR
                            clearPrompt();
                            printf("Alterar operador:\n");
                            printf("Informe o login: \n");
                            fflush(stdin);
                            scanf("%s", operador.usuario);

                            printf("\n");
                            ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                            if (ret == 0)
                            {
                                printf("=> Operador encontrado!\n");
                                printf("=========================================\n");
                                printf("C¢digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permissäes  : %s\n", operador.permissoes);
                                printf("=========================================\n");
                                printf("Deseja alterar este operador?\n");
                                printf("1 - Sim\n");
                                printf("0 - NÆo\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    clearPrompt();
                                    fflush(stdin);
                                    printf("Indique o novo nome        : ");
                                    scanf(" %[^\n]", operador.nome);

                                    fflush(stdin);
                                    printf("Indique a nova senha       : ");
                                    scanf(" %[^\n]", operador.senha);

                                    fflush(stdin);
                                    printf("Indique as novas permissäes (separadas por v¡rgulas) : ");
                                    scanf(" %[^\n]", operador.permissoes);

                                    ret = editarOperador(operador.usuario, operador);

                                    if (ret == 0)
                                    {
                                        printf("Operador alterado com sucesso!");
                                        pausaSist();
                                    }
                                    else
                                    {
                                        printf("=> Falha ao alterar operador.");
                                        pausaSist();
                                    }
                                }
                            }
                            else
                            {
                                printf("=> Operador nÆo encontrado!\n");
                                pausaSist();
                            }
                            break;

                        case 4: // EXCLUIR OPERADOR
                            clearPrompt();
                            printf("Excluir operador:\n");
                            printf("Informe o login: \n");
                            fflush(stdin);
                            scanf("%s", operador.usuario);

                            printf("\n");

                            ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                            if (ret == 0)
                            {
                                printf("=> Operador encontrado!\n");
                                printf("=========================================\n");
                                printf("C¢digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permissäes  : %s\n", operador.permissoes);
                                printf("=========================================\n");
                                printf("Deseja excluir este operador?\n");
                                printf("1 - Sim\n");
                                printf("0 - NÆo\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    ret = excluirOperador(operador.usuario);

                                    if (ret == 0)
                                    {
                                        printf("Operador exclu¡do com sucesso!");
                                        pausaSist();
                                    }
                                    else
                                    {
                                        printf("=> Falha ao excluir operador.");
                                        pausaSist();
                                    }
                                }
                            }
                            else
                            {
                                printf("Operador nÆo encontrado.");
                                pausaSist();
                            }
                            break;

                        default: // EM CASO DE OUTRA OP€ÇO
                            printf("\n[X] ERRO - Insira um valor V lido!");
                            pausaSist();
                            break;
                        }
                    }

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