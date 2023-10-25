#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "quick_tools.h"
#include "structs_hotel.h"
#include "cadastro_acomodacoes.h"

#include "reservas_hotel.h"

int main()
{
    str_reservas reservaDados[5], reserva;
    int ret, choice;
    while (1)
    {
        clearPrompt();
        printf("=> RESERVAS:\n");
        printf("Selecione uma opï¿½ï¿½o: \n");
        printf("1 - Verificar disponibilidades\n");
        printf("2 - Fazer Reserva\n");
        printf("3 - Cancelamento\n");
        printf("4 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);
        if (choice == 4)
        {
            break;
        }
        switch (choice)
        {
        case 1: // Verificar disponibilidade das acomodaï¿½ï¿½es

            printf("Como deseja verificar a disponibilidade das acomodaï¿½ï¿½es?\n");
            printf("1 - Pesquisa por Data.\n");
            printf("2 - Pesquisa por Categoria.\n");
            printf("3 - Pesquisa por Quantidade de Pessoas.\n");
            printf("4 - Tipo de Facilidade.\n");
            printf("5 - Combinaï¿½ï¿½o.\n");
            printf("=> \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
<<<<<<< HEAD
                printf("Indique o dia e o mï¿½s de inï¿½cio (DD MM):");
                scanf("%d/%d", &reserva.dia_iniReserva, &reserva.mes_iniReserva);
                printf("Indique a duraï¿½ï¿½o da estadia: %d/%d", reserva.dia_iniReserva, reserva.mes_iniReserva);
=======
                printf("Indique o dia e o mˆs de in¡cio (DD/MM):");
                scanf("%d/%d", &reserva.dia_iniReserva, &reserva.mes_iniReserva);
                printf("Indique a dura‡Æo da estadia: %d %d", reserva.dia_iniReserva, reserva.mes_iniReserva);
>>>>>>> 650b4ba619c416095231fcda9b33b1b2c7ad7399
                scanf("%d", &reserva.tempo_Reserva);

                ret = pesquisarDisp_porDia(reserva, &reservaDados[0], &reservaDados[1], &reservaDados[2], &reservaDados[3], &reservaDados[4]);
                if (ret == 0)
                {
                    printf("Nenhuma acomoda‡Æo dispon¡vel nesta data");
                }
                else
                {
                    printf("RESULTADOS: ---------------\n");
                    for (int i = 0; i < ret; i++)
                    {
                        printf("Op‡Æo: %d =================\n", i);
                        printf("C¢digo      : %d\n", reservaDados[i].acomod.codigo);
                        printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
                        printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
                        printf("Categoria desta Acomoda‡Æo --------------\n");
                        printf(" - C¢digo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
                        printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
                        printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
                        printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
                    }
                }
                break;
            case 2:
                printf("Indique o cï¿½digo da categoria que deseja reservar:");
                scanf("%d", &choice);
                break;

            default:
                break;
            }

            /*
                Reserva: este mï¿½dulo deve permitir que o operador verifique a disponibilidade de uma
                acomodaï¿½ï¿½o por data, categoria de acomodaï¿½ï¿½o, quantidade de pessoas, tipo de
                facilidade, ou por uma combinaï¿½ï¿½o destes critï¿½rios. Por exemplo, o sistema deve
                permitir que o operador localize um quarto da categoria luxo, do dia 01 a 10 desse mï¿½s,
                que tenha banheira de hidromassagem e que comporte 2 adultos e 2 crianï¿½as. Em
                hipï¿½tese alguma deve haver sombreamento de datas para uma mesma acomodaï¿½ï¿½o.
            */

            break;
        case 2: // Reservar

            break;
        case 3: // Cancelamento

            break;
        default:
            printf("\n[X] ERRO - Insira um valor vï¿½lido!");
            pausaSist();
            break;
        }
    }
    return 0;
}