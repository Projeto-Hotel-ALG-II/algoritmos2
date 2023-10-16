#ifndef structs_hotel_h
#define structs_hotel_h

#include <stdio.h>

/*
 * Struct Hotel - Guarda os dados do Hotel em questÆo
 */
typedef struct
{
    char nome_fantasia[50];
    char razao_soc[100];
    char inscricao_estadual[20]; // Varia dependendo do estado
    char cnpj[19];               // XX.XXX.XXX/YYYY-ZZ
    char end_completo[100];
    char telefone[16]; // (ZZ) YXXXX-XXXX
    char email[50];
    char nome_responsavel[50];
    char tel_responsavel[16]; // (ZZ) YXXXX-XXXX
    char horario_checkin[6];  // XX:XX
    char horario_checkout[6];
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
    char cpf[15];      // XXX.XXX.XXX-YY
    char telefone[16]; // (ZZ) YXXXX-XXXX
    char email[50];
    char sexo; // F, M ou N
    char estado_civil[15];
    char data_nasc[11]; // DD/MM/AAAA
} str_hospedes;

/*
 * Sub-Struct de 'Acomodacoes' - Guarda as caracter¡sticas das acomoda‡äes e ‚ acessada atrav‚s da struct Acomodacoes
 */
typedef struct
{
    int codigo;
    char descricao[300];
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
    char descricao[200];
    char facilidades[200];
} str_acomodacoes;

/*
 * Struct Produtos - Guarda as informa‡äes dos produtos
 */
typedef struct
{
    int codigo;
    char descricao[40];
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
    char razao_social[100];
    char inscricao_estadual[20]; // Varia de estado para estado
    char cnpj[19];               // XX.XXX.XXX/YYYY-ZZ
    char end_completo[100];
    char telefone[16]; // (XX) YZZZZ-ZZZZ
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
    char senha[9]; // 8 caracteres
    char permissoes[200];
} str_op_sistemas;

typedef struct
{
    int codigo;
    int dia_iniReserva;
    int mes_iniReserva;
    int dia_fimReserva;
    int mes_fimReserva;
    int tempo_Reserva; // em dias
    str_acomodacoes acomod;
} str_reservas;

#endif