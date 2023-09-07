#include <stdio.h>

// Struct Hotel
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

// Struct Hóspedes
typedef struct
{
    int codigo;
    char nome[50];
    char end_completo[100];
    int cpf;
    int telefone;
    char email[50];
    char sexo;
    char estado_civil[15];
    int data_nasc;
} str_hospedes;

// Sub-Struct de 'Acomodacoes'
typedef struct
{
    int codigo;
    char descricao[140];
    float valor_diaria;
    int qtd_pessoas;
} str_categ_acomodacoes;

// Struct Acomodacoes
typedef struct
{
    str_categ_acomodacoes catec_acomod;
    int codigo;
    char descricao[140];
    char facilidades[100];
    char categoria[30];   
} str_acomodacoes;

// Struct Produtos
typedef struct
{
    int codigo;
    char descricao[30];
    int estoque;
    int estoque_min;
    float preco_custo;
    float preco_venda;
} str_produtos;

// Struct Fornecedores
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

// Struct Operadores do Sistema
typedef struct
{
    int codigo;
    char nome[50];
    char usuario[20];
    int senha;
    /*? Permissões;*/ 
} str_op_sistemas;