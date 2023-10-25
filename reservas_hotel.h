#ifndef reservas_hotel_h
#define reservas_hotel_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "quick_tools.h"
#include "structs_hotel.h"
#include "cadastro_acomodacoes.h"

int realizarReserva(str_reservas reserva)
{
    FILE *pF_reservas;
    pF_reservas = fopen("..\\data\\reservas_hotel.txt", "a");

    if (pF_reservas == NULL)
    {
        exit(1);
    }

    fprintf(pF_reservas, "%d|", reserva.codigo);
    fprintf(pF_reservas, "%d|", reserva.acomod.codigo);
    fprintf(pF_reservas, "%d|", reserva.acomod.catec_acomod.codigo);
    fprintf(pF_reservas, "%.2f|", reserva.acomod.catec_acomod.valor_diaria);
    fprintf(pF_reservas, "%d/%d/%d|", reserva.dia_iniReserva, reserva.mes_iniReserva, reserva.ano_iniReserva);
    fprintf(pF_reservas, "%d/%d/%d|", reserva.dia_fimReserva, reserva.mes_fimReserva, reserva.ano_fimReserva);
    fprintf(pF_reservas, "%d\n", reserva.tempo_Reserva);

    fclose(pF_reservas);

    return 0;
}

int pesquisarDisp_porDia(str_reservas resPesq, str_reservas *pReserva1, str_reservas *pReserva2,
                         str_reservas *pReserva3, str_reservas *pReserva4, str_reservas *pReserva5)
{
    str_reservas resRead;
    str_reservas acomodRead;
    int cont = 0;

    FILE *pF_reservas, *pF_acomod;

    pF_reservas = fopen("..\\data\\reservas_hotel.txt");
    pF_acomod = fopen("acomodacoes.txt");

    // LEITURA INDIVIDUAL DE CADA LINHA DAS ACOMODA��ES
    while (fscanf(pF_acomod, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodRead.acomod.codigo, reacomodReadsRead.acomod.descricao,
                  acomodRead.acomod.facilidades, &acomodRead.acomod.catec_acomod.codigo,
                  acomodRead.acomod.catec_acomod.descricao, &acomodRead.acomod.catec_acomod.valor_diaria,
                  &acomodRead.acomod.catec_acomod.qtd_pessoas) != EOF)
    {
        // LEITURA DE TODAS AS RESERVAS AP�S CADA ACOMODA��O
        while ((fscanf(pF_reservas, "%d|%d|%d|%f|%d/%d|%d/%d|%d\n", &resRead.codigo, &resRead.acomod.codigo, &resRead.acomod.catec_acomod.codigo,
                       &resRead.acomod.catec_acomod.valor_diaria, &resRead.dia_iniReserva, &resRead.mes_iniReserva, &resRead.dia_fimReserva,
                       &resRead.mes_fimReserva, &resRead.tempo_Reserva) != EOF) ||
               (cont < 5))
        {

            // dado: dia e um mes 22/10
            // siste 20/10 - 3 dia ini < 22 dia fin > 22
            if (acomodRead.codigo == resRead.codigo &&
                ((resPesq.dia_iniReserva > resRead.dia_fimReserva && resPesq.mes_iniReserva >= resRead.mes_fimReserva && resPesq.ano_iniReserva >= resRead.ano_fimReserva) ||
                 (resPesq.dia_iniReserva < resRead.dia_fimReserva && resPesq.mes_iniReserva > resRead.mes_fimReserva && resPesq.ano_iniReserva >= resRead.ano_fimReserva) ||
                 (resPesq.dia_iniReserva < resRead.dia_fimReserva && resPesq.mes_iniReserva < resRead.mes_fimReserva && resPesq.ano_iniReserva > resRead.ano_fimReserva)))
            {
                if (cont == 0)
                {
                    pReserva1->acomod.codigo = acomodRead.acomod.codigo;
                    strcpy(pReserva1->acomod.descricao, acomodRead.acomod.descricao);
                    strcpy(pReserva1->acomod.facilidades, acomodRead.acomod.facilidades);
                    pReserva1->acomod.catec_acomod.codigo = acomodRead.acomod.catec_acomod.codigo;
                    strcpy(pReserva1->acomod.catec_acomod.descricao, acomodRead.acomod.catec_acomod.descricao);
                    pReserva1->acomod.catec_acomod.valor_diaria = acomodRead.acomod.catec_acomod.valor_diaria;
                    pReserva1->acomod.catec_acomod.qtd_pessoas = acomodRead.acomod.catec_acomod.qtd_pessoas;

                    cont++
                }
                else if (cont == 1)
                {
                    pReserva2->acomod.codigo = acomodRead.acomod.codigo;
                    strcpy(pReserva2->acomod.descricao, acomodRead.acomod.descricao);
                    strcpy(pReserva2->acomod.facilidades, acomodRead.acomod.facilidades);
                    pReserva2->acomod.catec_acomod.codigo = acomodRead.acomod.catec_acomod.codigo;
                    strcpy(pReserva2->acomod.catec_acomod.descricao, acomodRead.acomod.catec_acomod.descricao);
                    pReserva2->acomod.catec_acomod.valor_diaria = acomodRead.acomod.catec_acomod.valor_diaria;
                    pReserva2->acomod.catec_acomod.qtd_pessoas = acomodRead.acomod.catec_acomod.qtd_pessoas;

                    cont++
                }
                else if (cont == 2)
                {
                    pReserva3->acomod.codigo = acomodRead.acomod.codigo;
                    strcpy(pReserva3->acomod.descricao, acomodRead.acomod.descricao);
                    strcpy(pReserva3->acomod.facilidades, acomodRead.acomod.facilidades);
                    pReserva3->acomod.catec_acomod.codigo = acomodRead.acomod.catec_acomod.codigo;
                    strcpy(pReserva3->acomod.catec_acomod.descricao, acomodRead.acomod.catec_acomod.descricao);
                    pReserva3->acomod.catec_acomod.valor_diaria = acomodRead.acomod.catec_acomod.valor_diaria;
                    pReserva3->acomod.catec_acomod.qtd_pessoas = acomodRead.acomod.catec_acomod.qtd_pessoas;

                    cont++
                }
                else if (cont == 3)
                {
                    pReserva4->acomod.codigo = acomodRead.acomod.codigo;
                    strcpy(pReserva4->acomod.descricao, acomodRead.acomod.descricao);
                    strcpy(pReserva4->acomod.facilidades, acomodRead.acomod.facilidades);
                    pReserva4->acomod.catec_acomod.codigo = acomodRead.acomod.catec_acomod.codigo;
                    strcpy(pReserva4->acomod.catec_acomod.descricao, acomodRead.acomod.catec_acomod.descricao);
                    pReserva4->acomod.catec_acomod.valor_diaria = acomodRead.acomod.catec_acomod.valor_diaria;
                    pReserva4->acomod.catec_acomod.qtd_pessoas = acomodRead.acomod.catec_acomod.qtd_pessoas;

                    cont++
                }
                else if (cont == 4)
                {
                    pReserva5->acomod.codigo = acomodRead.acomod.codigo;
                    strcpy(pReserva5->acomod.descricao, acomodRead.acomod.descricao);
                    strcpy(pReserva5->acomod.facilidades, acomodRead.acomod.facilidades);
                    pReserva5->acomod.catec_acomod.codigo = acomodRead.acomod.catec_acomod.codigo;
                    strcpy(pReserva5->acomod.catec_acomod.descricao, acomodRead.acomod.catec_acomod.descricao);
                    pReserva5->acomod.catec_acomod.valor_diaria = acomodRead.acomod.catec_acomod.valor_diaria;
                    pReserva5->acomod.catec_acomod.qtd_pessoas = acomodRead.acomod.catec_acomod.qtd_pessoas;

                    cont++
                }
            }
        }
    }

<<<<<<< HEAD

=======
    fclose(pF_acomod);
>>>>>>> 650b4ba619c416095231fcda9b33b1b2c7ad7399
    fclose(pF_reservas);

    return 0;
}

<<<<<<< HEAD
int pesquisarDisp_porCateg(str_acomodacoes acomod[], int num_acomod, const char* categDesejada ){
   
   str_acomodacoes numReservas;
    for (int i = 0; i < nu_categ; i++)
    {
        if (strcmp(acomod->catec_acomod.descricao, categDesejada) == 0)
        {
            for (int j = 0; j < acomod[i].numReservas; i++)
            {
                /* code */
            }
            
        }
        
    }
    
}
=======
int pesquisarDisp_porCateg(){

    
}

>>>>>>> 650b4ba619c416095231fcda9b33b1b2c7ad7399
#endif