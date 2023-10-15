#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "quick_tools.h"
#include "structs_hotel.h"

/**
 * Cadastra o H¢spede (ParÉmetro: struct com todos os dados)
 */
int cadastrarHospede(str_hospedes hospedes)
{
    FILE *pF_hosped;
    pF_hosped = fopen("..\\data\\dados_hospedes.txt", "a");
    if (pF_hosped == NULL)
    {
        exit(1);
    }

    hospedes.codigo = contadorLinhas("..\\data\\dados_hospedes.txt");
    fprintf(pF_hosped, "%d|", hospedes.codigo);
    fprintf(pF_hosped, "%s|", hospedes.nome);
    fprintf(pF_hosped, "%s|", hospedes.end_completo);
    fprintf(pF_hosped, "%s|", hospedes.cpf);
    fprintf(pF_hosped, "%s|", hospedes.telefone);
    fprintf(pF_hosped, "%s|", hospedes.email);
    fprintf(pF_hosped, "%c|", hospedes.sexo);
    fprintf(pF_hosped, "%s|", hospedes.estado_civil);
    fprintf(pF_hosped, "%s\n", hospedes.data_nasc);

    fclose(pF_hosped);
    return 0;
}

/*
 * Pesquisa o H¢spede (precisa ser chamado com os endereáos de mem¢ria de todos as vari†veis)
 */
int pesquisarHospede(char pesQ_cpf[15], int *pCodigo, char *pNome, char *pEnd_Comp, char *pCpf, char *pTelefone,
                     char *pEmail, char *pSexo, char *pEstadoCiv, char *pDataNasc)
{
    FILE *pF_hosped;
    pF_hosped = fopen("..\\data\\dados_hospedes.txt", "r");
    str_hospedes h; // struct hospedes

    if (pF_hosped == NULL)
    {
        exit(1);
    }

    while (fscanf(pF_hosped, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &h.codigo, h.nome, h.end_completo, h.cpf, h.telefone,
                  h.email, &h.sexo, h.estado_civil, h.data_nasc) != EOF)
    {
        if (strcmp(h.cpf, pesQ_cpf) == 0 && h.codigo != 0)
        {
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
 * Faz a alteraá∆o do h¢spede (selecionado pelo CPF)
 */
int alterarHospede(char cpf[15], str_hospedes att_hosped)
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

    while (fscanf(pF_hospedes, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                  tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
    {
        // caso h¢spede n∆o seja o pesquisado, ser† escrito diretamente o conteudo do arquivo original no tempor†rio
        if (strcmp(tmp.cpf, cpf) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.cpf);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s|", tmp.email);
            fprintf(pF_temp, "%c|", tmp.sexo);
            fprintf(pF_temp, "%s|", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
        // caso o h¢spede seja o pesquisado, ele ser† escrito no arquivo tempor†rio s¢ que com os novos dados
        else
        {
            att_hosped.codigo = tmp.codigo;
            fprintf(pF_temp, "%d|", att_hosped.codigo);
            fprintf(pF_temp, "%s|", att_hosped.nome);
            fprintf(pF_temp, "%s|", att_hosped.end_completo);
            fprintf(pF_temp, "%s|", att_hosped.cpf);
            fprintf(pF_temp, "%s|", att_hosped.telefone);
            fprintf(pF_temp, "%s|", att_hosped.email);
            fprintf(pF_temp, "%c|", att_hosped.sexo);
            fprintf(pF_temp, "%s|", att_hosped.estado_civil);
            fprintf(pF_temp, "%s\n", att_hosped.data_nasc);
        }
    }

    // fechando arquivos
    fclose(pF_hospedes);
    fclose(pF_temp);


    // Reescrevendo os dados do arquivo tempor†rio no arquivo principal
    pF_temp = fopen("..\\data\\temp.txt", "r");
    pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "w");
    if (pF_hospedes == NULL || pF_temp == NULL)
    {
        exit(1);
    }

    // funá∆o vai copiar os dados do arquivo tempor†rio de volta para o original
    copiarArquivo(pF_temp, pF_hospedes);

    fclose(pF_temp);
    fclose(pF_hospedes);

    return 0;
}

/**
 * Exclui o h¢spede selecionado
 */
int excluirHospede(char cpf[15])
{
    // declarando ponteiros de arquivos
    FILE *pF_hospedes;
    FILE *pF_temp;

    str_hospedes tmp;

    // abrindo arquivos
    pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "r");
    pF_temp = fopen("..\\data\\temp.txt", "w"); // arquivo tempor†rio

    // caso n∆o seja poss°vel abrir o arquivo
    if (pF_hospedes == NULL || pF_temp == NULL)
    {
        exit(1);
    }

    // lendo arquivo original linha por linha
    while (fscanf(pF_hospedes, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                  tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
    {
        // caso h¢spede n∆o seja o pesquisado, ser† escrito diretamente o conteudo do arquivo original no tempor†rio
        if (strcmp(tmp.cpf, cpf) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.cpf);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s|", tmp.email);
            fprintf(pF_temp, "%c|", tmp.sexo);
            fprintf(pF_temp, "%s|", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
        // caso o h¢spede seja o pesquisado, ele ser† escrito no arquivo tempor†rio s¢ que com o c¢digo igual a 0
        else
        {
            fprintf(pF_temp, "0|");
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.cpf);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s|", tmp.email);
            fprintf(pF_temp, "%c|", tmp.sexo);
            fprintf(pF_temp, "%s|", tmp.estado_civil);
            fprintf(pF_temp, "%s\n", tmp.data_nasc);
        }
    }

    // fechando arquivos
    fclose(pF_hospedes);
    fclose(pF_temp);

    // Reescrevendo os dados do arquivo tempor†rio no arquivo principal
    pF_temp = fopen("..\\data\\temp.txt", "r");
    pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "w");
    if (pF_hospedes == NULL || pF_temp == NULL)
    {
        exit(2);
    }

    // funá∆o vai copiar os dados do arquivo tempor†rio de volta para o original
    copiarArquivo(pF_temp, pF_hospedes);

    fclose(pF_temp);
    fclose(pF_hospedes);

    return 0;
}