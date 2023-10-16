#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick_tools.h"
#include "structs_hotel.h"

// Funá∆o para cadastrar um operador no sistema
int cadastrarOperador(str_op_sistemas operador) {
    FILE *foperador;
    foperador = fopen("..\\data\\dados_operadores.txt", "a");
    
    if (foperador == NULL) {
        return 1;  // Erro ao abrir o arquivo
    }
    
    operador.codigo = contadorLinhas("..\\data\\dados_operadores.txt") + 1;
    
    fprintf(foperador, "%d|", operador.codigo);
    fprintf(foperador, "%s|", operador.nome);
    fprintf(foperador, "%s|", operador.usuario);
    fprintf(foperador, "%s|", operador.senha);
    fprintf(foperador, "%s\n", operador.permissoes);

    fclose(foperador);
    return 0;  // Operador cadastrado com sucesso
}

// Funá∆o para pesquisar um operador pelo usu√°rio
int pesquisarOperadorPorUsuario(char pqusuario[20], str_op_sistemas *operador) {
    FILE *foperador;
    foperador = fopen("..\\data\\dados_operadores.txt", "r");
    str_op_sistemas dados;

    if (foperador == NULL) {
        return 1;  // Erro ao abrir o arquivo
    }

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &dados.codigo, dados.nome, dados.usuario, dados.senha, dados.permissoes) != EOF) {
        if (strcmp(pqusuario, dados.usuario) == 0) {
            operador->codigo = dados.codigo;
            strcpy(operador->nome, dados.nome);
            strcpy(operador->usuario, dados.usuario);
            strcpy(operador->senha, dados.senha);
            strcpy(operador->permissoes, dados.permissoes);
            fclose(foperador);
            return 0;  // Operador encontrado
        }
    }

    fclose(foperador);
    return 1;  // Operador n∆o encontrado
}

// Funá∆o para editar um operador
int editarOperador(char pqusuario[20], str_op_sistemas operador) {
    FILE *ftemp, *foperador;
    str_op_sistemas temp;

    foperador = fopen("..\\data\\dados_operadores.txt", "r");
    ftemp = fopen("..\\data\\temp.txt", "w");

    if (foperador == NULL || ftemp == NULL) {
        return 1;  // Erro ao abrir arquivos
    }

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &temp.codigo, temp.nome, temp.usuario, temp.senha, temp.permissoes) != EOF) {
        if (strcmp(temp.usuario, pqusuario) != 0) {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        } else {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", operador.nome);
            fprintf(ftemp, "%s|", operador.usuario);
            fprintf(ftemp, "%s|", operador.senha);
            fprintf(ftemp, "%s\n", operador.permissoes);
        }
    }

    fclose(foperador);
    fclose(ftemp);

    if (substituiTemp("..\\data\\dados_operadores.txt", "..\\data\\temp.txt") == 0) {
        return 0;  // Operador editado com sucesso
    }

    return 1;  // Falha ao editar o operador
}

// Funá∆o para excluir um operador
int excluirOperador(char pqusuario[20]) {
    FILE *ftemp, *foperador;
    str_op_sistemas temp;

    foperador = fopen("..\\data\\dados_operadores.txt", "r");
    ftemp = fopen("..\\data\\temp.txt", "w");

    if (foperador == NULL || ftemp == NULL) {
        return 1;  // Erro ao abrir arquivos
    }

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &temp.codigo, temp.nome, temp.usuario, temp.senha, temp.permissoes) != EOF) {
        if (strcmp(temp.usuario, pqusuario) != 0) {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        } else {
            fprintf(ftemp, "0|");  // Marca o operador como exclu°do
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        }
    }

    fclose(foperador);
    fclose(ftemp);

    if (substituiTemp("..\\data\\dados_operadores.txt", "..\\data\\temp.txt") == 0) {
        return 0;  // Operador exclu°do com sucesso
    }

    return 1;  // Falha ao excluir o operador
}