#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "cadastro_acomodacoes.h"

void cadastrarCategoria(str_categ_acomodacoes categoria);
int pesquisarCategoria(int codigo, str_categ_acomodacoes *categoria);
int editarCategoria(int codigo, str_categ_acomodacoes categoria);
int excluirCategoria(int codigo);

void cadastrarAcomodacao(str_acomodacoes acomodacao);
int pesquisarAcomodacao(int codigo, str_acomodacoes *acomodacao);
int editarAcomodacao(int codigo, str_acomodacoes acomodacao);
int excluirAcomodacao(int codigo);

void listarCategorias();
void listarAcomodacoes();

int main() {
    int escolha;
    str_categ_acomodacoes categoria;
    str_acomodacoes acomodacao;

    while (1) {
        system("clear"); 
        printf("Cadastro e Gestão de Acomodações e Categorias:\n");
        printf("1 - Cadastrar Categoria de Acomodação\n");
        printf("2 - Pesquisar Categoria de Acomodação\n");
        printf("3 - Editar Categoria de Acomodação\n");
        printf("4 - Excluir Categoria de Acomodação\n");
        printf("5 - Cadastrar Acomodação\n");
        printf("6 - Pesquisar Acomodação\n");
        printf("7 - Editar Acomodação\n");
        printf("8 - Excluir Acomodação\n");
        printf("9 - Listar Categorias\n");
        printf("10 - Listar Acomodações\n");
        printf("11 - Sair\n");
        printf("=> ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Informe a descrição da categoria: ");
                scanf(" %[^\n]", categoria.descricao);
                printf("Informe o valor da diária: ");
                scanf("%f", &categoria.valor_diaria);
                printf("Informe a quantidade de pessoas: ");
                scanf("%d", &categoria.qtd_pessoas);
                cadastrarCategoria(categoria);
                pausaSist();
                break;

            case 2: 
            printf("Informe o código da categoria de acomodação: ");
            int codigoCategoria;
            scanf("%d", &codigoCategoria);

            if (pesquisarCategoria(codigoCategoria, &categoria)) {
                printf("Categoria de Acomodação encontrada!\n");
                printf("Código: %d\n", categoria.codigo);
                printf("Descrição: %s\n", categoria.descricao);
                printf("Valor da Diária: %.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas: %d\n", categoria.qtd_pessoas);
            } else {
                printf("Categoria de Acomodação não encontrada.\n");
            }

            pausaSist();
            break;

            case 3:
                printf("Informe o código da categoria a ser editada: ");
                int codigoEditar;
                scanf("%d", &codigoEditar);
                if (pesquisarCategoria(codigoEditar, &categoria)) {
                    printf("Informe a nova descrição da categoria: ");
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
                printf("Informe o código da categoria a ser excluída: ");
                int codigoExcluirCategoria;
                scanf("%d", &codigoExcluirCategoria);
                if (excluirCategoria(codigoExcluirCategoria)) {
                    pausaSist();
                } else {
                    pausaSist();
                }
                break;

            case 5:
                printf("Informe a descrição da acomodação: ");
                scanf(" %[^\n]", acomodacao.descricao);
                printf("Informe as facilidades: ");
                scanf(" %[^\n]", acomodacao.facilidades);
                printf("Informe o código da categoria da acomodação: ");
                scanf("%d", &acomodacao.catec_acomod.codigo);
                if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod)) {
                    cadastrarAcomodacao(acomodacao);
                } else {
                    printf("Categoria de acomodação não encontrada.\n");
                }
                pausaSist();
                break;

            case 6:
                printf("Informe o código da acomodação: ");
                int codigoAcomodacao;
                scanf("%d", &codigoAcomodacao);
                if (pesquisarAcomodacao(codigoAcomodacao, &acomodacao)) {
                    // Acomodação encontrada
                }
                pausaSist();
                break;

            case 7:
                printf("Informe o código da acomodação a ser editada: ");
                int codigoEditarAcomodacao;
                scanf("%d", &codigoEditarAcomodacao);
                if (pesquisarAcomodacao(codigoEditarAcomodacao, &acomodacao)) {
                    printf("Informe a nova descrição da acomodação: ");
                    scanf(" %[^\n]", acomodacao.descricao);
                    printf("Informe as novas facilidades: ");
                    scanf(" %[^\n]", acomodacao.facilidades);
                    printf("Informe o novo código da categoria da acomodação: ");
                    scanf("%d", &acomodacao.catec_acomod.codigo);
                    if (pesquisarCategoria(acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod)) {
                        editarAcomodacao(codigoEditarAcomodacao, acomodacao);
                    } else {
                        printf("Categoria de acomodação não encontrada.\n");
                    }
                }
                pausaSist();
                break;

            case 8:
                printf("Informe o código da acomodação a ser excluída: ");
                int codigoExcluirAcomodacao;
                scanf("%d", &codigoExcluirAcomodacao);
                if (excluirAcomodacao(codigoExcluirAcomodacao)) {
                    pausaSist();
                } else {
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

            case 11:
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
                pausaSist();
                break;
        }
    }

    return 0;
}