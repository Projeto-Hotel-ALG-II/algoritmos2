#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerencia_operadores.h"

int main() {
    char ntemp[35], noriginal[35];
    int choice, ret;
    str_op_sistemas operador;
    strcpy(ntemp, "temp_operadores.txt");
    strcpy(noriginal, "operadores.txt");

    while (1) {
        printf("Cadastro e Gestão de Operadores do Sistema:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;  // Sai do loop quando a escolha for 5
        }

        switch (choice) {
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
                printf("Indique as permissões (separadas por vírgulas) : ");
                scanf(" %[^\n]", operador.permissoes);

                // Função cadastra o operador
                ret = cadastrarOperador(operador);

                if (ret == 0) {
                    printf("\nOperador cadastrado com sucesso!");
                    pausaSist();
                } else {
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

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    pausaSist();
                } else {
                    printf("=> Operador não encontrado!\n");
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

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    printf("=========================================\n");
                    printf("Deseja alterar este operador?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("=> ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        clearPrompt();
                        fflush(stdin);
                        printf("Indique o novo nome        : ");
                        scanf(" %[^\n]", operador.nome);

                        fflush(stdin);
                        printf("Indique a nova senha       : ");
                        scanf(" %[^\n]", operador.senha);

                        fflush(stdin);
                        printf("Indique as novas permissões (separadas por vírgulas) : ");
                        scanf(" %[^\n]", operador.permissoes);

                        ret = editarOperador(operador.usuario, operador);

                        if (ret == 0) {
                            printf("Operador alterado com sucesso!");
                            pausaSist();
                        } else {
                            printf("=> Falha ao alterar operador.");
                            pausaSist();
                        }
                    }
                } else {
                    printf("=> Operador não encontrado!\n");
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

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    printf("=========================================\n");
                    printf("Deseja excluir este operador?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("=> ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        ret = excluirOperador(operador.usuario);

                        if (ret == 0) {
                            printf("Operador excluído com sucesso!");
                            pausaSist();
                        } else {
                            printf("=> Falha ao excluir operador.");
                            pausaSist();
                        }
                    }
                } else {
                    printf("Operador não encontrado.");
                    pausaSist();
                }
                break;

            default: // EM CASO DE OUTRA OPÇÃO
                printf("\n[X] ERRO - Insira um valor válido!");
                pausaSist();
                break;
        }
    }

    return 0;
}
