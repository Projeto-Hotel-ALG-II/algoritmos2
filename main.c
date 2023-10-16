#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "quick_tools.h"

// TODAS AS STRUCTS
#include "structs_hotel.h"

// FUN��ES: GEST�O E CADASTROS
#include "hospedes_hotel.h"
#include "fornecedores_hotel.h"
#include "cadastro_operador.h"
#include "cadastro_acomodacoes.h"

// FUN��ES: RESERVAS
#include "reservas_hotel.h"

int main()
{
    // STRUCTS CADASTRO E GEST�O
    str_hotel hotel;
    str_hospedes hospedes;
    str_fornecedores fornecedores;
    str_op_sistemas operador;
    str_categ_acomodacoes categoria;
    str_acomodacoes acomodacao;

    // STRUCTS RESERVAS
    // str_reservas reserva;

    int choice; // variavel armazena as escolhas feitas pelo usu�rio
    int ret;    // variavel armazena os dados retornados das fun��es

    char nomeTemp[35];
    char nomeOrg[35];

    // La�o de repeti��o principal
    while (1)
    {
        AnsiUpper(strcpy(hotel.nome_fantasia, "Muk-Luk Lodge")); // Nome provis�rio pro hotel
        choice = 0;                                              // evitando lixo de memoria

        clearPrompt(); // Limpando prompt

        // Menu Principal
        printf("BEM VINDO AO HOTEL: %s!\n", hotel.nome_fantasia);
        printf("Selecione uma op��o:\n");
        printf("1 - Cadastro e Gest�o de Dados\n");
        printf("2 - Reservas\n");
        printf("3 - Transa��es\n");
        printf("4 - Feedback\n");
        printf("5 - Importa��o/Exporta��o de Dados\n");
        printf("6 - Sair\n");
        printf("=> ");
        scanf("%d", &choice);

        // Swich para os M�dulos
        switch (choice)
        {
        case 1: // M�dulo 1 - Cadastro e Gest�o de Dados
            while (1)
            {
                clearPrompt();
                printf("=> CADASTRO E GEST�O DE DADOS\n");
                printf("Selecione uma op��o: \n");
                printf("1 - Hotel\n");
                printf("2 - H�spedes\n");
                printf("3 - Acomoda��es\n");
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
                case 1: // Campo 1 - Hotel - Jo�o Vitor *

                    break;
                case 2: // Campo 2 - H�spedes - Matheus Garcia *
                    strcpy(nomeTemp, "..\\data\\temp.txt");
                    strcpy(nomeOrg, "..\\data\\dados_hospedes.txt");
                    while (1)
                    {
                        clearPrompt();
                        // menu principal da se��o cadastro de hospedes
                        printf("Cadastro e Gest�o de H�spedes:\n");
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
                        case 1: // ===== CADASTRAR H�SPEDE =====

                            // recolhendo dados do novo hospede
                            fflush(stdin);
                            printf("Indique o nome               : ");
                            scanf(" %[^\n]", hospedes.nome);

                            fflush(stdin); // Limpa o buffer
                            printf("Indique o endere�o completo  : ");
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

                            // fun��o cadastra os h�spedes
                            ret = cadastrarHospede(hospedes);

                            if (ret == 0)
                            {
                                printf("\nH�spede cadastrado com sucesso!");
                                pausaSist();
                            }
                            else
                            {
                                printf("Erro ao acessar o arquivo dados_hospedes.txt\n");
                                pausaSist();
                            }

                            break;

                        case 2: // ===== PESQUISAR H�SPEDE =====
                            printf("Pesquisar H�spede: \n");
                            printf("CPF do h�spede (XXX.XXX.XXX-XX): ");
                            fflush(stdin);
                            scanf("%s", hospedes.cpf);

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

                            if (ret == 0)
                            {
                                printf("=> H�spede encontrado!\n");
                                printf("=========================================\n");
                                printf("C�digo             : %d\n", hospedes.codigo);
                                printf("Nome               : %s\n", hospedes.nome);
                                printf("Endere�o           : %s\n", hospedes.end_completo);
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
                                printf("=> H�spede n�o encontrado!\n");
                                pausaSist();
                            }
                            break;
                        case 3: // ===== ALTERAR H�SPEDE =====
                            clearPrompt();
                            printf("Alterar h�spede:\n");

                            printf("Informe o CPF: \n");
                            fflush(stdin);
                            scanf("%s", hospedes.cpf);

                            printf("\n");

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

                            if (ret == 0)
                            {
                                printf("=> H�spede encontrado!\n");
                                printf("=========================================\n");
                                printf("C�digo             : %d\n", hospedes.codigo);
                                printf("Nome               : %s\n", hospedes.nome);
                                printf("Telefone           : %s\n", hospedes.telefone);
                                printf("Email              : %s\n", hospedes.email);
                                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                                printf("=========================================\n");
                                printf("Deseja alterar este h�spede?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    AnsiUpper(hospedes.nome);
                                    clearPrompt();
                                    printf("Alterar h�spede: %s\n", hospedes.nome);
                                    fflush(stdin);
                                    printf("Indique o nome               : ");
                                    scanf(" %[^\n]", hospedes.nome);

                                    fflush(stdin);
                                    printf("Indique o endere�o completo  : ");
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
                                        printf("H�spede alterado com sucesso");
                                        pausaSist();
                                    }
                                    else
                                    {
                                        printf("=> Falha ao alterar h�spede");
                                        pausaSist();
                                    }
                                }
                            }
                            else
                            {
                                printf("=> H�spede n�o encontrado!\n");
                                pausaSist();
                            }

                            break;
                        case 4: // ===== EXCLUIR H�SPEDE =====
                            clearPrompt();
                            printf("Excluir h�spede:\n");

                            printf("Informe o CPF: \n");
                            fflush(stdin);
                            scanf("%s", hospedes.cpf);

                            printf("\n");

                            ret = pesquisarHospede(hospedes.cpf, &hospedes);

                            if (ret == 0)
                            {
                                printf("=> H�spede encontrado!\n");
                                printf("=========================================\n");
                                printf("C�digo             : %d\n", hospedes.codigo);
                                printf("Nome               : %s\n", hospedes.nome);
                                printf("Telefone           : %s\n", hospedes.telefone);
                                printf("Email              : %s\n", hospedes.email);
                                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                                printf("=========================================\n");
                                printf("Deseja excluir este h�spede?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    ret = excluirHospede(hospedes.cpf);

                                    if (ret == 0)
                                    {
                                        printf("H�spede exclu�do com sucesso!");
                                        pausaSist();
                                    }
                                    else
                                    {
                                        printf("=> Falha ao excluir h�spede.");
                                        pausaSist();
                                    }
                                }
                            }
                            else
                            {
                                printf("H�spede n�o encontrado.");
                                pausaSist();
                            }
                            break;
                        default: // ===== EM CASO DE OUTRA OP��O =====
                            printf("\n[X] ERRO - Insira um valor v�lido!");
                            pausaSist();
                            break;
                        }
                    }
                    break;
                    
                case 3: // Campo 3 - Acomoda��es - Iasmim Garcia *
                    while (1)
                    {
                        clearPrompt();
                        printf("Cadastro e Gest�o de Acomoda��es e Categorias:\n");
                        printf("1 - Cadastrar Categoria de Acomoda��o\n");
                        printf("2 - Pesquisar Categoria de Acomoda��o\n");
                        printf("3 - Editar Categoria de Acomoda��o\n");
                        printf("4 - Excluir Categoria de Acomoda��o\n");
                        printf("5 - Cadastrar Acomoda��o\n");
                        printf("6 - Pesquisar Acomoda��o\n");
                        printf("7 - Editar Acomoda��o\n");
                        printf("8 - Excluir Acomoda��o\n");
                        printf("9 - Listar Categorias\n");
                        printf("10 - Listar Acomoda��es\n");
                        printf("11 - Sair\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if(choice == 11){
                            break;
                        }

                        switch (choice)
                        {
                        case 1:
                            printf("Informe a descri��o da categoria: ");
                            scanf(" %[^\n]", categoria.descricao);
                            printf("Informe o valor da diária: ");
                            scanf("%f", &categoria.valor_diaria);
                            printf("Informe a quantidade de pessoas: ");
                            scanf("%d", &categoria.qtd_pessoas);
                            cadastrarCategoria(categoria);
                            pausaSist();
                            break;

                        case 2:
                            printf("Informe o c�digo da categoria de acomoda��o: ");
                            int codigoCategoria;
                            scanf("%d", &codigoCategoria);

                            if (pesquisarCategoria(codigoCategoria, &categoria))
                            {
                                printf("Categoria de Acomoda��o encontrada!\n");
                                printf("C�digo: %d\n", categoria.codigo);
                                printf("Descri��o: %s\n", categoria.descricao);
                                printf("Valor da Diária: %.2f\n", categoria.valor_diaria);
                                printf("Quantidade de Pessoas: %d\n", categoria.qtd_pessoas);
                            }
                            else
                            {
                                printf("Categoria de Acomoda��o n�o encontrada.\n");
                            }

                            pausaSist();
                            break;

                        case 3:
                            printf("Informe o c�digo da categoria a ser editada: ");
                            int codigoEditar;
                            scanf("%d", &codigoEditar);
                            if (pesquisarCategoria(codigoEditar, &categoria))
                            {
                                printf("Informe a nova descri��o da categoria: ");
                                scanf(" %[^\n]", categoria.descricao);
                                printf("Informe o novo valor da diária: ");
                                scanf("%f", &categoria.valor_diaria);
                                printf("Informe a nova quantidade de pessoas: ");
                                scanf("%d", &categoria.qtd_pessoas);
                                editarCategoria(codigoEditar, categoria);
                            }
                            pausaSist();
                            break;

                        case 4:
                            printf("Informe o c�digo da categoria a ser excluída: ");
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
                            printf("Informe a descri��o da acomoda��o: ");
                            scanf(" %[^\n]", acomodacao.descricao);
                            printf("Informe as facilidades: ");
                            scanf(" %[^\n]", acomodacao.facilidades);
                            printf("Informe o c�digo da categoria da acomoda��o: ");
                            scanf("%d", &acomodacao.catec_acomod.codigo);
                            if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod))
                            {
                                cadastrarAcomodacao(acomodacao);
                            }
                            else
                            {
                                printf("Categoria de acomoda��o n�o encontrada.\n");
                            }
                            pausaSist();
                            break;

                        case 6:
                            printf("Informe o c�digo da acomoda��o: ");
                            int codigoAcomodacao;
                            scanf("%d", &codigoAcomodacao);
                            if (pesquisarAcomodacao(codigoAcomodacao, &acomodacao))
                            {
                                // Acomoda��o encontrada
                            }
                            pausaSist();
                            break;

                        case 7:
                            printf("Informe o c�digo da acomoda��o a ser editada: ");
                            int codigoEditarAcomodacao;
                            scanf("%d", &codigoEditarAcomodacao);
                            if (pesquisarAcomodacao(codigoEditarAcomodacao, &acomodacao))
                            {
                                printf("Informe a nova descri��o da acomoda��o: ");
                                scanf(" %[^\n]", acomodacao.descricao);
                                printf("Informe as novas facilidades: ");
                                scanf(" %[^\n]", acomodacao.facilidades);
                                printf("Informe o novo c�digo da categoria da acomoda��o: ");
                                scanf("%d", &acomodacao.catec_acomod.codigo);
                                if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod))
                                {
                                    editarAcomodacao(codigoEditarAcomodacao, acomodacao);
                                }
                                else
                                {
                                    printf("Categoria de acomoda��o n�o encontrada.\n");
                                }
                            }
                            pausaSist();
                            break;

                        case 8:
                            printf("Informe o c�digo da acomoda��o a ser excluída: ");
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
                            printf("Op��o inválida. Tente novamente.\n");
                            pausaSist();
                            break;
                        }
                    }
                    break;
                case 4: // Campo 5 - Fornecedores - Matheus Garcia *
                    while (1)
                    {
                        clearPrompt();
                        // menu principal da se��o funcionarios
                        printf("Cadastro e Gest�o de Fornecedores:\n");
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
                            printf("Indique a raz�o social       : ");
                            scanf(" %[^\n]", fornecedores.razao_social);

                            fflush(stdin);
                            printf("Indique a inscri��o estadual : ");
                            scanf(" %[^\n]", fornecedores.inscricao_estadual);

                            fflush(stdin);
                            printf("Indique o cnpj               : ");
                            scanf(" %[^\n]", fornecedores.cnpj);

                            fflush(stdin);
                            printf("Indique o endere�o completo  : ");
                            scanf(" %[^\n]", fornecedores.end_completo);

                            fflush(stdin);
                            printf("Indique o telefone           : ");
                            scanf(" %[^\n]", fornecedores.telefone);

                            fflush(stdin);
                            printf("Indique o email              : ");
                            scanf(" %[^\n]", fornecedores.email);

                            // fun��o cadastra o fornecedor
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
                                printf("C�digo             : %d\n", fornecedores.codigo);
                                printf("Nome Fornecedor    : %s\n", fornecedores.nome);
                                printf("Raz�o Social       : %s\n", fornecedores.razao_social);
                                printf("Inscri��o Estadual : %s\n", fornecedores.inscricao_estadual);
                                printf("CNPJ               : %s\n", fornecedores.cnpj);
                                printf("Endere�o Completo  : %s\n", fornecedores.end_completo);
                                printf("Telefone           : %s\n", fornecedores.telefone);
                                printf("Email              : %s\n", fornecedores.email);
                                pausaSist();
                            }
                            else
                            {
                                printf("=> Fornecedor n�o encontrado!\n");
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
                                printf("C�digo             : %d\n", fornecedores.codigo);
                                printf("Nome               : %s\n", fornecedores.nome);
                                printf("Telefone           : %s\n", fornecedores.telefone);
                                printf("Email              : %s\n", fornecedores.email);
                                printf("CNPJ               : %s\n", fornecedores.cnpj);
                                printf("=========================================\n");
                                printf("Deseja alterar este fornecedor?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
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
                                    printf("Indique a nova raz�o social       : ");
                                    scanf(" %[^\n]", fornecedores.razao_social);

                                    fflush(stdin);
                                    printf("Indique a nova inscri��o estadual : ");
                                    scanf(" %[^\n]", fornecedores.inscricao_estadual);

                                    fflush(stdin);
                                    printf("Indique o novo cnpj               : ");
                                    scanf(" %[^\n]", fornecedores.cnpj);

                                    fflush(stdin);
                                    printf("Indique o novo endere�o completo  : ");
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
                                printf("=> Fornecedor n�o encontrado!\n");
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
                                printf("C�digo             : %d\n", fornecedores.codigo);
                                printf("Nome               : %s\n", fornecedores.nome);
                                printf("Telefone           : %s\n", fornecedores.telefone);
                                printf("Email              : %s\n", fornecedores.email);
                                printf("CNPJ               : %s\n", fornecedores.cnpj);
                                printf("=========================================\n");
                                printf("Deseja excluir este fornecedor?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    ret = excluirFornecedor(fornecedores.cnpj);

                                    if (ret == 0)
                                    {
                                        printf("Fornecedor exclu�do com sucesso!");
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
                                printf("Fornecedor n�o encontrado.");
                                pausaSist();
                            }

                            break;
                        default: // ===== EM CASO DE OUTRA OP��O =====
                            printf("\n[X] ERRO - Insira um valor v�lido!");
                            pausaSist();
                            break;
                        }
                    }

                    break;
                case 5: // Campo 6 - Produtos - Jo�o Vitor *

                    break;
                case 6: // Campo 7 - Operadores - Iasmim Garcia *
                    while (1)
                    {
                        clearPrompt();
                        printf("Cadastro e Gest�o de Operadores do Sistema:\n");
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
                            printf("Indique as permiss�es (separadas por v�rgulas) : ");
                            scanf(" %[^\n]", operador.permissoes);

                            // Fun��o cadastra o operador
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
                                printf("C�digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permiss�es  : %s\n", operador.permissoes);
                                pausaSist();
                            }
                            else
                            {
                                printf("=> Operador n�o encontrado!\n");
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
                                printf("C�digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permiss�es  : %s\n", operador.permissoes);
                                printf("=========================================\n");
                                printf("Deseja alterar este operador?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
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
                                    printf("Indique as novas permiss�es (separadas por v�rgulas) : ");
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
                                printf("=> Operador n�o encontrado!\n");
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
                                printf("C�digo      : %d\n", operador.codigo);
                                printf("Nome        : %s\n", operador.nome);
                                printf("Login       : %s\n", operador.usuario);
                                printf("Permiss�es  : %s\n", operador.permissoes);
                                printf("=========================================\n");
                                printf("Deseja excluir este operador?\n");
                                printf("1 - Sim\n");
                                printf("0 - N�o\n");
                                printf("=> ");
                                scanf("%d", &choice);

                                if (choice == 1)
                                {
                                    ret = excluirOperador(operador.usuario);

                                    if (ret == 0)
                                    {
                                        printf("Operador exclu�do com sucesso!");
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
                                printf("Operador n�o encontrado.");
                                pausaSist();
                            }
                            break;

                        default: // EM CASO DE OUTRA OP��O
                            printf("\n[X] ERRO - Insira um valor V�lido!");
                            pausaSist();
                            break;
                        }
                    }

                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;

        case 2: // M�dulo 2 - Reservas

            break;
        case 3: // M�dulo 3 - Transa��es
            while (1)
            {
                clearPrompt();
                printf("=> TRANSA��ES\n");
                printf("Selecione uma op��o: \n");
                printf("1 - Check-in\n");
                printf("2 - Check-out\n");
                printf("3 - Sa�da de Produtos\n");
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
                case 1: // Se��o 1 - Check-in

                    break;
                case 2: // Se��o 2 - Check-out

                    break;
                case 3: // Transa��o 1 - Sa�da de produtos(venda)

                    break;
                case 4: // Constrole de caixa

                    break;
                case 5: // Transa��o 2 - Contas a Receber

                    break;
                case 6: // Transa��o 3 - Contas a Pagar

                    break;
                case 7: // Transa��o 4 - Entrada de Produtos Industrializados

                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 4: // M�dulo 4 - Feedback
            while (1)
            {
                clearPrompt();
                printf("=> FEEDBACK\n");
                printf("Selecione uma op��o: \n");
                printf(" 1 - Listagem de H�spedes\n");
                printf(" 2 - Listagem de Acomoda��es\n");
                printf(" 3 - Listagem de Reservas\n");
                printf(" 4 - Produtos em Estoque M�nimo\n");
                printf(" 5 - Listagem de Produtos de Consumo\n");
                printf(" 6 - Listagem de Movimenta��o das Acomoda��es\n");
                printf(" 7 - Vendas\n");
                printf(" 8 - Contas a Receber\n");
                printf(" 9 - Contas a Pagar\n");
                printf("10 - Movimenta��o de Caixa\n");
                printf("11 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 11)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Relat�rio 1 - Listagem de H�spedes

                    break;
                case 2: // Relat�rio 2 - Listagem de Acomoda��es

                    break;
                case 3: // Relat�rio 3 - Listagem de Reservas

                    break;
                case 4: // Relat�rio 4 - Produtos em Estoque M�nimo

                    break;
                case 5: // Relat�rio 5 - Listagem de Produtos de Consumo

                    break;
                case 6: // Relat�rio 6 - Listagem de Movimenta��o das Acomoda��es

                    break;
                case 7: // Relat�rio 7 - Vendas

                    break;
                case 8: // Relat�rio 8 - Contas a Receber

                    break;
                case 9: // Relat�rio 9 - Contas a Pagar

                    break;
                case 10: // Relat�rio 10 - Movimenta��o de caixa

                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 5: // M�dulo 5 - Importa��o/Exporta��o de Dados
            while (1)
            {
                clearPrompt();
                printf("=> Cadastro e Gest�o - H�spedes:\n");
                printf("Selecione uma op��o: \n");
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
                    printf("\n[X] ERRO - Insira um valor v�lido! Pressione qualquer tecla para voltar");
                    getch();
                    break;
                }
            }
            break;
        case 6:
            clearPrompt();
            printf("Tem certeza que deseja sair do sistema?\n");
            printf("                                       \n");
            printf("       1 - Sim     |     2 - N�o       \n");
            printf("=> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                rmvTemp();
                clearPrompt();
                return 0;
            }
            break;

        default: // Nenhuma das op��es
            printf("\n[X] ERRO - Insira um valor v�lido!");
            pausaSist();
            break;
        }
    }

    return 0;
}