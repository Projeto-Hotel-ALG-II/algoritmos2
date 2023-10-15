#ifndef GERENCIA_OPERADORES_H_INCLUDED
#define GERENCIA_OPERADORES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um operador do sistema
typedef struct {
    int codigo;
    char nome[50];
    char usuario[20];
    char senha[20];  // Senha como uma string
    char permissoes[100];  // Permissões como uma string
} str_op_sistemas;

int contadorLinhas(const char *nomeArquivo);
void pausaSist();
void clearPrompt();
int substituirArquivo();

// Função para cadastrar um operador no sistema
int cadastrarOperador(str_op_sistemas operador) {
    FILE *foperador;
    foperador = fopen("operadores.txt", "a");
    
    if (foperador == NULL) {
        return 1;  // Erro ao abrir o arquivo
    }
    
    operador.codigo = contadorLinhas("operadores.txt") + 1;
    
    fprintf(foperador, "%d|", operador.codigo);
    fprintf(foperador, "%s|", operador.nome);
    fprintf(foperador, "%s|", operador.usuario);
    fprintf(foperador, "%s|", operador.senha);
    fprintf(foperador, "%s\n", operador.permissoes);

    fclose(foperador);
    return 0;  // Operador cadastrado com sucesso
}

// Função para pesquisar um operador pelo usuário
int pesquisarOperadorPorUsuario(char pqusuario[20], str_op_sistemas *operador) {
    FILE *foperador;
    foperador = fopen("operadores.txt", "r");
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
    return 1;  // Operador não encontrado
}

// Função para editar um operador
int editarOperador(char pqusuario[20], str_op_sistemas operador) {
    FILE *ftemp, *foperador;
    str_op_sistemas temp;

    foperador = fopen("operadores.txt", "r");
    ftemp = fopen("temp_operadores.txt", "w");

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

    if (substituirArquivo("operadores.txt", "temp_operadores.txt") == 0) {
        return 0;  // Operador editado com sucesso
    }

    return 1;  // Falha ao editar o operador
}

// Função para excluir um operador
int excluirOperador(char pqusuario[20]) {
    FILE *ftemp, *foperador;
    str_op_sistemas temp;

    foperador = fopen("operadores.txt", "r");
    ftemp = fopen("temp_operadores.txt", "w");

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
            fprintf(ftemp, "0|");  // Marca o operador como excluído
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        }
    }

    fclose(foperador);
    fclose(ftemp);

    if (substituirArquivo("operadores.txt", "temp_operadores.txt") == 0) {
        return 0;  // Operador excluído com sucesso
    }

    return 1;  // Falha ao excluir o operador
}

int substituirArquivo(const char *arquivoAntigo, const char *arquivoNovo) {
    if (remove(arquivoAntigo) == 0 && rename(arquivoNovo, arquivoAntigo) == 0) {
        return 0;  // Sucesso na substituição do arquivo
    } else {
        return 1;  // Falha na substituição do arquivo
    }
}

int contadorLinhas(const char *nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        return 0;
    }

    int linhas = 0;
    char c;

    while ((c = fgetc(arquivo)) != EOF) {
        if (c == '\n') {
            linhas++;
        }
    }

    fclose(arquivo);
    return linhas + 1;
}

void pausaSist() {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();

}

void clearPrompt()
{
    system("cls");
}

#endif
