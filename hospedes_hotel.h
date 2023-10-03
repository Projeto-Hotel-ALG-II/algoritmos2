#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "quick_tools.h"
#include "structs_hotel.h"

/*
 * Faz a contagem das linhas de codigo e cadastra o proximo hospede com o n£mero de sua linha
 */
int contadorCodigos()
{
    FILE *pF;
    char linha[1000];
    int qtdLinhas = 1;
    pF = fopen("..\\data\\dados_hospedes.txt", "r");
    while (fgets(linha, sizeof(linha), pF) != NULL)
    {
        qtdLinhas++;
    }
    fclose(pF);
    return qtdLinhas;
}

/*
 * Utilizada para tornar a pasta tempor ria principal
 */
int renomeiaFile()
{
    remove("..\\data\\dados_hospedes.txt");
    rename("..\\data\\temp.txt", "..\\data\\dados_hospedes.txt");
    return 0;
}

/**
 * Cadastra o H¢spede (Parƒmetro: struct com todos os dados)
 */
int cadastrarHospede(str_hospedes hospedes)
{
    FILE *pF_hosped;
    pF_hosped = fopen("..\\data\\dados_hospedes.txt", "a");
    if (pF_hosped == NULL)
    {
        exit(1);
    }
    
    hospedes.codigo = contadorCodigos();
    fprintf(pF_hosped, "%d,", hospedes.codigo);
    fprintf(pF_hosped, "%s,", hospedes.nome);
    fprintf(pF_hosped, "%s,", hospedes.end_completo);
    fprintf(pF_hosped, "%s,", hospedes.cpf);
    fprintf(pF_hosped, "%s,", hospedes.telefone);
    fprintf(pF_hosped, "%s,", hospedes.email);
    fprintf(pF_hosped, "%c,", hospedes.sexo);
    fprintf(pF_hosped, "%s,", hospedes.estado_civil);
    fprintf(pF_hosped, "%s\n", hospedes.data_nasc);

    fclose(pF_hosped);
    return 0;
}

/*
 * Pesquisa o H¢spede (precisa ser chamado com os endere‡os de mem¢ria de todos as vari veis)
 */
int pesquisarHospede(char pesQ_cpf[15], str_hospedes h, int *pCodigo, char *pNome, char *pEnd_Comp, char *pCpf, char *pTelefone, char *pEmail, char *pSexo, char *pEstadoCiv, char *pDataNasc)
{
    FILE *pF_hosped;
    pF_hosped = fopen("..\\data\\dados_hospedes.txt", "r");

    if (pF_hosped == NULL)
    {
        exit(1);
    }

    while (fscanf(pF_hosped, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%c,%[^,],%[^\n]\n", &h.codigo, h.nome, h.end_completo, h.cpf, h.telefone, h.email, &h.sexo, h.estado_civil, h.data_nasc) != EOF)
    {
        if (strcmp(h.cpf, pesQ_cpf) == 0)
        {
            if (h.codigo == 0)
            {
                break;
            }
            *pCodigo = h.codigo;
            strcpy(pNome, h.nome);
            strcpy(pEnd_Comp, h.end_completo);
            strcpy(pCpf, h.cpf);
            strcpy(pTelefone, h.telefone);
            strcpy(pEmail, h.email);
            *pSexo = h.sexo;
            strcpy(pEstadoCiv, h.estado_civil);
            strcpy(pDataNasc, h.data_nasc);
            return 0;
        }
    }
    fclose(pF_hosped);
    return 1;
}

/**
 * Faz a altera‡Æo do h¢spede (selecionado pelo CPF)
 */
int alterarHospede(char cpf[15], str_hospedes hospedes)
{
    FILE *pF_hospedes;
    FILE *pF_temp;
    str_hospedes tmp;
    int encontrado = 0;

    pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "r");
    pF_temp = fopen("..\\data\\temp.txt", "w");

    if (pF_hospedes == NULL || pF_temp == NULL)
    {
        exit(1);
    }

    while (fscanf(pF_hospedes, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%c,%[^,],%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                  tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
    {
        if (strcmp(tmp.cpf, cpf) != 0)
        {
            fprintf(pF_temp, "%d,", tmp.codigo);
            fprintf(pF_temp, "%s,", tmp.nome);
            fprintf(pF_temp, "%s,", tmp.end_completo);
            fprintf(pF_temp, "%s,", tmp.cpf);
            fprintf(pF_temp, "%s,", tmp.telefone);
            fprintf(pF_temp, "%s,", tmp.email);
            fprintf(pF_temp, "%c,", tmp.sexo);
            fprintf(pF_temp, "%s,", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
        else
        {
            hospedes.codigo = tmp.codigo;
            encontrado = 1;
        }
    }

    if (encontrado == 1)
    {
        fprintf(pF_temp, "%d,", hospedes.codigo);
        fprintf(pF_temp, "%s,", hospedes.nome);
        fprintf(pF_temp, "%s,", hospedes.end_completo);
        fprintf(pF_temp, "%s,", hospedes.cpf);
        fprintf(pF_temp, "%s,", hospedes.telefone);
        fprintf(pF_temp, "%s,", hospedes.email);
        fprintf(pF_temp, "%c,", hospedes.sexo);
        fprintf(pF_temp, "%s,", hospedes.estado_civil);
        fprintf(pF_temp, "%s\n", hospedes.data_nasc);
    }

    fclose(pF_hospedes);
    fclose(pF_temp);

    remove("data\\dados_hospedes.txt");
    rename("data\\temp.txt", "..\\data\\dados_hospedes.txt");

    return 0;
}

/**
 * Exclui o h¢spede selecionado
 */
int excluirHospede(char cpf[15])
{

    FILE *pF_hospedes;
    FILE *pF_temp;

    str_hospedes tmp;

    pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "r");
    pF_temp = fopen("..\\data\\temp.txt", "w");

    if (pF_hospedes == NULL || pF_temp == NULL)
    {
        exit(1);
    }

    while (fscanf(pF_hospedes, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%c,%[^,],%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                  tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
    {
        if (strcmp(tmp.cpf, cpf) != 0)
        {
            fprintf(pF_temp, "%d,", tmp.codigo);
            fprintf(pF_temp, "%s,", tmp.nome);
            fprintf(pF_temp, "%s,", tmp.end_completo);
            fprintf(pF_temp, "%s,", tmp.cpf);
            fprintf(pF_temp, "%s,", tmp.telefone);
            fprintf(pF_temp, "%s,", tmp.email);
            fprintf(pF_temp, "%c,", tmp.sexo);
            fprintf(pF_temp, "%s,", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
        else
        {
            fprintf(pF_temp, "0,");
            fprintf(pF_temp, "%s,", tmp.nome);
            fprintf(pF_temp, "%s,", tmp.end_completo);
            fprintf(pF_temp, "%s,", tmp.cpf);
            fprintf(pF_temp, "%s,", tmp.telefone);
            fprintf(pF_temp, "%s,", tmp.email);
            fprintf(pF_temp, "%c,", tmp.sexo);
            fprintf(pF_temp, "%s,", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
    }

    fclose(pF_hospedes);
    fclose(pF_temp);
    return 0;
}