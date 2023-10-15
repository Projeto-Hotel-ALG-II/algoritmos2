#ifndef FORNECEDORES_HOTEL_H_INCLUDED
#define FORNECEDORES_HOTEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "quick_tools.h"
#include "structs_hotel.h"

/*
 * Faz o cadastro do fornecedor
 */
int cadastrarFornecedor(str_fornecedores fornecedor)
{
    FILE *pF_fornec;
    pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "a");
    if (pF_fornec == NULL)
    {
        exit(1);
    }

    fornecedor.codigo = contadorLinhas("..\\data\\dados_fornecedores.txt");
    fprintf(pF_fornec, "%d|", fornecedor.codigo);
    fprintf(pF_fornec, "%s|", fornecedor.nome);
    fprintf(pF_fornec, "%s|", fornecedor.razao_social);
    fprintf(pF_fornec, "%s|", fornecedor.inscricao_estadual);
    fprintf(pF_fornec, "%s|", fornecedor.cnpj);
    fprintf(pF_fornec, "%s|", fornecedor.end_completo);
    fprintf(pF_fornec, "%s|", fornecedor.telefone);
    fprintf(pF_fornec, "%s\n", fornecedor.email);

    // fechando file
    fclose(pF_fornec);
    return 0;
}

/**
 * Faz a pesquisa do fornecedor
 */
int pesquisarFornecedor(char cnpj_pesq[15], int *pCodigo, char *pNome, char *pRazSocial, char *pInscEstadual, char *pCnpj, char *pEndCompleto,
                        char *pTelefone, char *pEmail)
{
    FILE *pF_fornec;
    pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "r");
    str_fornecedores f; // struct fornecedores

    if (pF_fornec == NULL)
    {
        exit(1);
    }

    while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &f.codigo, f.nome, f.razao_social, f.inscricao_estadual, f.cnpj, f.end_completo, f.telefone, f.email) != EOF)
    {
        if (strcmp(cnpj_pesq, f.cnpj) == 0 && f.codigo != 0)
        {
            *pCodigo = f.codigo;
            strcpy(pNome, f.nome);
            strcpy(pRazSocial, f.razao_social);
            strcpy(pInscEstadual, f.inscricao_estadual);
            strcpy(pCnpj, f.cnpj);
            strcpy(pEndCompleto, f.end_completo);
            strcpy(pTelefone, f.telefone);
            strcpy(pEmail, f.email);
            return 0;
        }
    }

    // fechando file
    fclose(pF_fornec);
    return 1;
}

int alterarFornecedor(char cnpj_forn[15], str_fornecedores att_fornec)
{
    FILE *pF_temp, *pF_fornec;
    str_fornecedores tmp; // struct para os dados tempor�rios

    // abrindo arquivos
    pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "r");
    pF_temp = fopen("..\\data\\temp.txt", "w");

    while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.razao_social, tmp.inscricao_estadual,
                  tmp.cnpj, tmp.end_completo, tmp.telefone, tmp.email) != EOF)
    {
        // caso o fornecedor n�o seja o que se deseja alterar ser� copiado os dados diretamente do arquivo original para o tempor�rio
        if (strcmp(tmp.cnpj, cnpj_forn) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
        // caso o fornecedor seja o que se deseja alterar ser� escrito no arquivo tempor�rio os novos dados
        else
        {
            fprintf(pF_temp, "%d|", att_fornec.codigo);
            fprintf(pF_temp, "%s|", att_fornec.nome);
            fprintf(pF_temp, "%s|", att_fornec.razao_social);
            fprintf(pF_temp, "%s|", att_fornec.inscricao_estadual);
            fprintf(pF_temp, "%s|", att_fornec.cnpj);
            fprintf(pF_temp, "%s|", att_fornec.end_completo);
            fprintf(pF_temp, "%s|", att_fornec.telefone);
            fprintf(pF_temp, "%s\n", att_fornec.email);
        }
    }

    // fechando files
    fclose(pF_fornec);
    fclose(pF_temp);

    // torna arquivo tempor�rio original
    substituiTemp("..\\data\\dados_fornecedores.txt", "..\\data\\temp.txt");

    return 0;
}

int excluirFornecedor(char cnpj_forn[15])
{
    FILE *pF_temp, *pF_fornec;
    str_fornecedores tmp; // struct para os dados tempor�rios
    // abrindo arquivos
    pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "r");
    pF_temp = fopen("..\\data\\temp.txt", "w");

    while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.razao_social, tmp.inscricao_estadual,
                  tmp.cnpj, tmp.end_completo, tmp.telefone, tmp.email) != EOF)
    {
        // caso o fornecedor n�o seja o que se deseja excluir, ser� copiado os dados diretamente do arquivo original para o tempor�rio
        if (strcmp(tmp.cnpj, cnpj_forn) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
        // caso o fornecedor seja o que se deseja excluir, ele ser� escrito no arquivo tempor�rio s� que com c�digo igual a 0
        else
        {
            fprintf(pF_temp, "0|"); // fornecedor excluido - codigo = 0
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
    }

    // fechando files
    fclose(pF_fornec);
    fclose(pF_temp);

    // torna arquivo tempor�rio original
    substituiTemp("..\\data\\dados_fornecedores.txt", "..\\data\\temp.txt");

    return 0;
}

#endif