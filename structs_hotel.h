#ifndef structs_hotel_h
#define structs_hotel_h

#include <stdio.h>

/*
 * Struct Hotel - Guarda os dados do Hotel em questÆo
 */
typedef struct
{
    char nome_fantasia[50];
    char razao_soc[50];
    int inscricao_estadual;
    int cnpj;
    char end_completo[100];
    int telefone;
    char email[50];
    char nome_responsavel[50];
    int tel_responsavel;
    int horario_checkin;
    int horario_checkout;
    float margem_lucro;
} str_hotel;
/*
 * Struct H¢spedes - Guarda os dados dos H¢spedes do hotel
 */
typedef struct
{
    int codigo;
    char nome[50];
    char end_completo[100];
    char cpf[15];
    char telefone[15];
    char email[50];
    char sexo;
    char estado_civil[15];
    char data_nasc[11];
} str_hospedes;

/*
 * Sub-Struct de 'Acomodacoes' - Guarda as caracter¡sticas das acomoda‡äes e ‚ acessada atrav‚s da struct Acomodacoes
 */
typedef struct
{
    int codigo;
    char descricao[140];
    float valor_diaria;
    int qtd_pessoas;
} str_categ_acomodacoes;

/*
 * Struct Acomodacoes - Guarda as informa‡äes das acomoda‡äes
 */
typedef struct
{
    str_categ_acomodacoes catec_acomod;
    int codigo;
    char descricao[140];
    char facilidades[100];
    char categoria[30];
} str_acomodacoes;

/*
 * Struct Produtos - Guarda as informa‡äes dos produtos
 */
typedef struct
{
    int codigo;
    char descricao[30];
    int estoque;
    int estoque_min;
    float preco_custo;
    float preco_venda;
} str_produtos;

/*
 * Struct Fornecedores - Guarda os dados dos fornecedores do hotel
 */
typedef struct
{
    int codigo;
    char nome[50];
    char razao_social[50];
    int inscricao_estadual;
    int cnpj;
    char end_completo[100];
    int telefone;
    char email[50];
} str_fornecedores;

/*
 * Struct Operadores do Sistema - Guarda os logins dos operadores do sistema
 */
typedef struct
{
    int codigo;
    char nome[50];
    char usuario[20];
    int senha;
    /*? Permissäes;*/
} str_op_sistemas;

#endif