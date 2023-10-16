#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "quick_tools.h"
#include "structs_hotel.h"

#include "reservas_hotel.h"

int main()
{
    str_reservas reservaDados[15], reserva;
    int ret, choice;
    while (1)
    {
        clearPrompt();
        printf("=> RESERVAS:\n");
        printf("Selecione uma op‡Æo: \n");
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
        case 1: // Verificar disponibilidade das acomoda‡äes

            printf("Como deseja verificar a disponibilidade das acomoda‡äes?\n");
            printf("1 - Pesquisa por Data.\n");
            printf("2 - Pesquisa por Categoria.\n");
            printf("3 - Pesquisa por Quantidade de Pessoas.\n");
            printf("4 - Tipo de Facilidade.\n");
            printf("5 - Combina‡Æo.\n");
            printf("=> \n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Indique o dia e o mˆs de in¡cio (DD/MM):");
                scanf("%d/%d", &reserva.dia_iniReserva, &reserva.mes_iniReserva);
                printf("Indique a dura‡Æo da estadia: %d %d", reserva.dia_iniReserva, reserva.mes_iniReserva);
                scanf("%d", &reserva.tempo_Reserva);

                ret = pesquisarDisp_porDia(reserva, &reservaDados);
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
                printf("Indique o c¢digo da categoria que deseja reservar:");
                scanf("%d", &choice);
                break;

            default:
                break;
            }

            /*
                Reserva: este m¢dulo deve permitir que o operador verifique a disponibilidade de uma
                acomoda‡Æo por data, categoria de acomoda‡Æo, quantidade de pessoas, tipo de
                facilidade, ou por uma combina‡Æo destes crit‚rios. Por exemplo, o sistema deve
                permitir que o operador localize um quarto da categoria luxo, do dia 01 a 10 desse mˆs,
                que tenha banheira de hidromassagem e que comporte 2 adultos e 2 crian‡as. Em
                hip¢tese alguma deve haver sombreamento de datas para uma mesma acomoda‡Æo.
            */

            break;
        case 2: // Reservar

            break;
        case 3: // Cancelamento

            break;
        default:
            printf("\n[X] ERRO - Insira um valor v lido!");
            pausaSist();
            break;
        }
    }
    return 0;
}