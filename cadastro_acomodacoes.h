#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quick_tools.h"
#include "structs_hotel.h"

//fun��o que mostra as categorias cadastradas 
void listarCategorias() {

    FILE *arquivo;
    arquivo = fopen("categorias_acomodacoes.txt", "r"); 
    //abri o arquivo no modo de leitura

    if (arquivo == NULL) { //se o arquivo nao abrir, mostra essa mensagem de erro
        printf("Erro ao abrir o arquivo de categorias de acomoda��es.\n");
        return;
    }

    str_categ_acomodacoes categoria;

    printf("Categorias de Acomoda��es Cadastradas:\n");
    //o fscanf l� os dados e armazena na variavel categorias ate chegar no fim do arquivo (EOF)
    while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoria.codigo, categoria.descricao, &categoria.valor_diaria, &categoria.qtd_pessoas) != EOF) {
        printf("C�digo: %d\n", categoria.codigo);
        printf("Descri��o: %s\n", categoria.descricao);
        printf("Valor da Di�ria: %.2f\n", categoria.valor_diaria);
        printf("Quantidade de Pessoas: %d\n", categoria.qtd_pessoas);
        printf("-------------------------------\n");
    }

    //assim q terminar a leitura, fecha o arquivo
    fclose(arquivo);
}

int cadastrarCategoria(str_categ_acomodacoes categoria) {
    FILE *arquivo;
    //abrir em modo "a" p anexar as novas infos no fim do arquivo
    arquivo = fopen("categorias_acomodacoes.txt", "a");

    if (arquivo == NULL) {
        exit(1);
    }

    //fun��o contadorLinhas define qual o proximo codigo 
    categoria.codigo = contadorLinhas("categorias_acomodacoes.txt");
    fprintf(arquivo, "%d|", categoria.codigo);
    fprintf(arquivo, "%s|", categoria.descricao);
    fprintf(arquivo, "%.2f|", categoria.valor_diaria);
    fprintf(arquivo, "%d\n", categoria.qtd_pessoas);

    fclose(arquivo);
}

int pesquisarCategoria(int codigo, str_categ_acomodacoes *categoria)
{
    FILE *arquivo;
    //abre no modo de leitura
    arquivo = fopen("categorias_acomodacoes.txt", "r");

    if (arquivo == NULL) { //mensagem caso d� erro 
        exit(1);
    }

    str_categ_acomodacoes categoriaTemp;
    //variavel que vai armazenar temporariamente os dados das categorias
    int encontrado = 1;

    //loop vai ler os dados com a categoriaTemp ate chegar no fim do arquvio
    while (fscanf(arquivo, "%d|%[^|]|%f|%d\n", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF) {
        if (categoriaTemp.codigo == codigo) {
            //se o codigo for igual o informado, entao passa os dados desse codigo pra categoria
            *categoria = categoriaTemp;
            encontrado = 0;
            break;
        }
    }

    fclose(arquivo)
  
    return encontardo;
}

int editarCategoria(int codigo, str_categ_acomodacoes categoria) {
    FILE *arquivo, *arquivoTemp;
    arquivo = fopen("categorias_acomodacoes.txt", "r");
    arquivoTemp = fopen("categorias_acomodacoes_temp.txt", "w");

    if (arquivo == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivos de categorias de acomoda��es.\n");
        exit(1);
    }

    str_categ_acomodacoes categoriaTemp;
    int encontrado = 0;

    while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF) {
        if (categoriaTemp.codigo == codigo) {
            fprintf(arquivoTemp, "%d|", categoria.codigo);
            fprintf(arquivoTemp, "%s|", categoria.descricao);
            fprintf(arquivoTemp, "%.2f|", categoria.valor_diaria);
            fprintf(arquivoTemp, "%d\n", categoria.qtd_pessoas);
            encontrado = 1;
        } else {
            fprintf(arquivoTemp, "%d|", categoriaTemp.codigo);
            fprintf(arquivoTemp, "%s|", categoriaTemp.descricao);
            fprintf(arquivoTemp, "%.2f|", categoriaTemp.valor_diaria);
            fprintf(arquivoTemp, "%d\n", categoriaTemp.qtd_pessoas);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        if (remove("categorias_acomodacoes.txt") == 0 && rename("categorias_acomodacoes_temp.txt", "categorias_acomodacoes.txt") == 0) {
            printf("Categoria de acomoda��o editada com sucesso!\n");
        } else {
            printf("Erro ao editar categoria de acomoda��o.\n");
        }
    }

    return encontrado;
}

int excluirCategoria(int codigo) {
    FILE *arquivo, *arquivoTemp;
    arquivo = fopen("categorias_acomodacoes.txt", "r");
    arquivoTemp = fopen("categorias_acomodacoes_temp.txt", "w");

    if (arquivo == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivos de categorias de acomoda��es.\n");
        exit(1);
    }

    str_categ_acomodacoes categoriaTemp;
    int encontrado = 0;

    while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF) {
        if (categoriaTemp.codigo == codigo) {
            encontrado = 1;
        } else {
            fprintf(arquivoTemp, "%d|", categoriaTemp.codigo);
            fprintf(arquivoTemp, "%s|", categoriaTemp.descricao);
            fprintf(arquivoTemp, "%.2f|", categoriaTemp.valor_diaria);
            fprintf(arquivoTemp, "%d\n", categoriaTemp.qtd_pessoas);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        if (remove("categorias_acomodacoes.txt") == 0 && rename("categorias_acomodacoes_temp.txt", "categorias_acomodacoes.txt") == 0) {
            printf("Categoria de acomoda��o exclu�da com sucesso!\n");
            return 1;
        } else {
            printf("Erro ao excluir categoria de acomoda��o.\n");
        }
    }

    return encontrado;
}
               
void listarAcomodacoes() {
    FILE *arquivo;
    // Abre o arquivo "acomodacoes.txt" no modo de leitura
    arquivo = fopen("acomodacoes.txt", "r");

    if (arquivo == NULL) {// mensagemd de erro
        printf("Erro ao abrir o arquivo de acomoda��es.\n");
        return;
    }

    str_acomodacoes acomodacao;

    // L� os dados das acomoda��es do arquivo enquanto n�o atingir o final do arquivo EOF
    printf("Acomoda��es Cadastradas:\n");
    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.catec_acomod.codigo, acomodacao.catec_acomod.descricao, &acomodacao.catec_acomod.valor_diaria, &acomodacao.catec_acomod.qtd_pessoas) != EOF) {
        printf("C�digo: %d\n", acomodacao.codigo);
        printf("Descri��o: %s\n", acomodacao.descricao);
        printf("Facilidades: %s\n", acomodacao.facilidades);
        printf("Categoria de Acomoda��o:\n");
        printf(" - C�digo: %d\n", acomodacao.catec_acomod.codigo);
        printf(" - Descri��o: %s\n", acomodacao.catec_acomod.descricao);
        printf(" - Valor da Di�ria: %.2f\n", acomodacao.catec_acomod.valor_diaria);
        printf(" - Quantidade de Pessoas: %d\n", acomodacao.catec_acomod.qtd_pessoas);
        printf("-------------------------------\n");
    }

    //fechamento do arquivo 
    fclose(arquivo);
}

void cadastrarAcomodacao(str_acomodacoes acomodacao) {
    FILE *arquivo;
    // Abre o arquivo "acomodacoes.txt" no modo de ap�ndice (para adicionar novos dados ao final)
    arquivo = fopen("acomodacoes.txt", "a");

    if (arquivo == NULL) { //mensagem c
        printf("Erro ao abrir o arquivo de acomoda��es.\n");
        exit(1);
    }

    acomodacao.codigo = contadorLinhas("acomodacoes.txt");
    fprintf(arquivo, "%d|", acomodacao.codigo);
    fprintf(arquivo, "%s|", acomodacao.descricao);
    fprintf(arquivo, "%s|", acomodacao.facilidades);
    fprintf(arquivo, "%d|", acomodacao.catec_acomod.codigo);
    fprintf(arquivo, "%s|", acomodacao.catec_acomod.descricao);
    fprintf(arquivo, "%.2f|", acomodacao.catec_acomod.valor_diaria);
    fprintf(arquivo, "%d\n", acomodacao.catec_acomod.qtd_pessoas);

    fclose(arquivo);

    printf("Acomoda��o cadastrada com sucesso!\n");
}


int pesquisarAcomodacao(int codigo, str_acomodacoes *acomodacao) {
    FILE *arquivo;
    arquivo = fopen("acomodacoes.txt", "r");

    if (arquivo == NULL) {// mensagem de erro 
        printf("Erro ao abrir o arquivo de acomoda��es.\n");
        exit(1);
    }

    str_acomodacoes acomodacaoTemp;
    int encontrado = 0;

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                   acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo,
                   acomodacaoTemp.catec_acomod.descricao, &acomodacaoTemp.catec_acomod.valor_diaria,
                   &acomodacaoTemp.catec_acomod.qtd_pessoas) != EOF) {
        if (acomodacaoTemp.codigo == codigo) {
            *acomodacao = acomodacaoTemp;
            encontrado = 1;
            break;
        }
    }

    fclose(arquivo);

    if (encontrado) {
        printf("Acomoda��o encontrada!\n");
        printf("C�digo: %d\n", acomodacao->codigo);
        printf("Descri��o: %s\n", acomodacao->descricao);
        printf("Facilidades: %s\n", acomodacao->facilidades);
        printf("Categoria de Acomoda��o:\n");
        printf(" - C�digo: %d\n", acomodacao->catec_acomod.codigo);
        printf(" - Descri��o: %s\n", acomodacao->catec_acomod.descricao);
        printf(" - Valor da Di�ria: %.2f\n", acomodacao->catec_acomod.valor_diaria);
        printf(" - Quantidade de Pessoas: %d\n", acomodacao->catec_acomod.qtd_pessoas);
    } else {
        printf("Acomoda��o n�o encontrada.\n");
    }

    return encontrado;
}

int editarAcomodacao(int codigo, str_acomodacoes acomodacao) {
    FILE *arquivo, *arquivoTemp;
    arquivo = fopen("acomodacoes.txt", "r");
    arquivoTemp = fopen("acomodacoes_temp.txt", "w");

    if (arquivo == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivos de acomoda��es.\n");
        exit(1);
    }

    str_acomodacoes acomodacaoTemp;
    int encontrado = 0;

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                   acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo,
                   acomodacaoTemp.catec_acomod.descricao, &acomodacaoTemp.catec_acomod.valor_diaria,
                   &acomodacaoTemp.catec_acomod.qtd_pessoas) != EOF) {
        if (acomodacaoTemp.codigo == codigo) {
            fprintf(arquivoTemp, "%d|", acomodacao.codigo);
            fprintf(arquivoTemp, "%s|", acomodacao.descricao);
            fprintf(arquivoTemp, "%s|", acomodacao.facilidades);
            fprintf(arquivoTemp, "%d|", acomodacao.catec_acomod.codigo);
            fprintf(arquivoTemp, "%s|", acomodacao.catec_acomod.descricao);
            fprintf(arquivoTemp, "%.2f|", acomodacao.catec_acomod.valor_diaria);
            fprintf(arquivoTemp, "%d\n", acomodacao.catec_acomod.qtd_pessoas);
            encontrado = 1;
        } else {
            fprintf(arquivoTemp, "%d|", acomodacaoTemp.codigo);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.descricao);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.facilidades);
            fprintf(arquivoTemp, "%d|", acomodacaoTemp.catec_acomod.codigo);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.catec_acomod.descricao);
            fprintf(arquivoTemp, "%.2f|", acomodacaoTemp.catec_acomod.valor_diaria);
            fprintf(arquivoTemp, "%d\n", acomodacaoTemp.catec_acomod.qtd_pessoas);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        if (remove("acomodacoes.txt") == 0 && rename("acomodacoes_temp.txt", "acomodacoes.txt") == 0) {
            printf("Acomoda��o editada com sucesso!\n");
        } else {
            printf("Erro ao editar acomoda��o.\n");
        }
    }

    return encontrado;
}

int excluirAcomodacao(int codigo) {
    FILE *arquivo, *arquivoTemp;
    arquivo = fopen("acomodacoes.txt", "r");
    arquivoTemp = fopen("acomodacoes_temp.txt", "w");

    if (arquivo == NULL || arquivoTemp == NULL) {
        printf("Erro ao abrir arquivos de acomoda��es.\n");
        exit(1);
    }

    str_acomodacoes acomodacaoTemp;
    int encontrado = 0;

    while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                   acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo,
                   acomodacaoTemp.catec_acomod.descricao, &acomodacaoTemp.catec_acomod.valor_diaria,
                   &acomodacaoTemp.catec_acomod.qtd_pessoas) != EOF) {
        if (acomodacaoTemp.codigo == codigo) {
            encontrado = 1;
        } else {
            fprintf(arquivoTemp, "%d|", acomodacaoTemp.codigo);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.descricao);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.facilidades);
            fprintf(arquivoTemp, "%d|", acomodacaoTemp.catec_acomod.codigo);
            fprintf(arquivoTemp, "%s|", acomodacaoTemp.catec_acomod.descricao);
            fprintf(arquivoTemp, "%.2f|", acomodacaoTemp.catec_acomod.valor_diaria);
            fprintf(arquivoTemp, "%d\n", acomodacaoTemp.catec_acomod.qtd_pessoas);
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);

    if (encontrado) {
        if (remove("acomodacoes.txt") == 0 && rename("acomodacoes_temp.txt", "acomodacoes.txt") == 0) {
            printf("Acomoda��o exclu�da com sucesso!\n");
            return 1;
        } else {
            printf("Erro ao excluir acomoda��o.\n");
        }
    }

    return encontrado;
}