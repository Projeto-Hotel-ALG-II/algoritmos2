#ifndef reservas_hotel_h
#define reservas_hotel_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "quick_tools.h"
#include "structs_hotel.h"

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
    fprintf(pF_reservas, "%d/%d|", reserva.dia_iniReserva, reserva.mes_iniReserva);
    fprintf(pF_reservas, "%d/%d|", reserva.dia_fimReserva, reserva.mes_fimReserva);
    fprintf(pF_reservas, "%d\n", reserva.tempo_Reserva);

    fclose(pF_reservas);

    return 0;
}

int pesquisarDisp_porDia(FILE *pF_reservas, str_reservas resPesq)
{
    str_reservas resRead;

    if (pF_reservas == NULL)
    {
        exit(1);
    }
    while (fscanf(pF_reservas, "%d|%d|%d|%f|%d/%d|%d/%d|%d\n", &resRead.codigo, &resRead.acomod.codigo, &resRead.acomod.catec_acomod.codigo,
                  &resRead.acomod.catec_acomod.valor_diaria, &resRead.dia_iniReserva, &resRead.mes_iniReserva, &resRead.dia_fimReserva,
                  &resRead.mes_fimReserva, &resRead.tempo_Reserva) != EOF)
    {

        // dado: dia e um mes 22/10
        // siste 20/10 - 3 dia ini < 22 dia fin > 22
        if ((resPesq.dia_iniReserva > resRead.dia_fimReserva && resPesq.mes_iniReserva >= resRead.mes_fimReserva) ||
            (resPesq.dia_iniReserva < resRead.dia_fimReserva && resPesq.mes_iniReserva > resRead.mes_fimReserva))
        {

        }
    }

    fclose(pF_reservas);

    return 0;
}

#endif