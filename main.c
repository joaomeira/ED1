/* Nome João Victor Meira Barros
** Conjunto de numeros inteiros */

#include <stdio.h>
#include <stdlib.h>
#include "atv5.h"

int main()
{
    Node * Conjunto_A = NULL,
    * Conjunto_B = NULL,
    * AUX = NULL;
    int respostas = 0,
    conjunto = 0,
    op = 0,
    elemento = 0;
    
    while(respostas != -50)
    {
        printf("\n\nOla usuario,\n Voce tem 2 conjuntos:\nConjunto A:");
        imprimeElementos(Conjunto_A);
        printf("Conjunto B:");
        imprimeElementos(Conjunto_B);

        printf("Em qual conjunto voce deseja mexer?\n1- Conjunto A\n2- Conjunto B\n3- Operacoes com 2 conjuntos\n4- SAIR\nR= ");
        scanf("%i",&respostas);

        switch (respostas)
        {
        case 1:
            conjunto = 1;
            break;

        case 2:
            conjunto = 2;
            break;
        case 3:
            conjunto = 3;
            break;
        case 4:
            exit(1);
            break;
        default:
            continue;
            break;
        }

        if(conjunto == 3)
        {
            printf("\n1- Verificar se as listas sao iguais");
            printf("\n2- Unir os conjuntos");
            printf("\n3- Intercesao entre os conjuntos");
            printf("\n4- Complemento relativo de B em A");
            printf("\n5- Complemento relativo de A em B");
            printf("\n6- Voltar");
            printf("\n7- Sair\n\n R: ");
        }else
        {
            printf("\n1- Inserir um elemento");
            printf("\n2- Remover um elemento");
            printf("\n3- Esvaziar esta lista");
            printf("\n4- Verificar se o elemento existe nesta lista");
            printf("\n5- Voltar");
            printf("\n6- Sair\n\n R: ");
        }
        
        scanf("%i",&op);

        if(conjunto == 3)
        {
            switch (op)
            {
            case 1:
                if(eIgual(Conjunto_A,Conjunto_B)) printf("\nE IGUAL\n");
                else printf("\nNAO E IGUAL\n");
                break;
            case 2:
                AUX = unirConjunto(Conjunto_A,Conjunto_B);
                printf("\nRESULTADO");
                imprimeElementos(AUX);
                printf("\n\n");
                esvaziaConjunto(&AUX);
                break;
            case 3:
                AUX = interConjunto(Conjunto_A,Conjunto_B);
                printf("RESULTADO");
                imprimeElementos(AUX);
                printf("\n\n");
                esvaziaConjunto(&AUX);
                break;
            case 4:
                AUX = menosConjunto(Conjunto_A,Conjunto_B);
                printf("RESULTADO");
                imprimeElementos(AUX);
                printf("\n\n");
                esvaziaConjunto(&AUX);
                break;
            case 5:
                AUX = menosConjunto(Conjunto_B,Conjunto_A);
                printf("RESULTADO");
                imprimeElementos(AUX);
                printf("\n\n");
                esvaziaConjunto(&AUX);
                break;
            case 6:
                continue;
                break;
            case 7:
                exit(1);
                break;
            
            default:
                continue;
                break;
            }
        }
        else if (conjunto == 1)
        {
            switch (op)
            {
            case 1:
                printf("Insira o valor desejado inserir: ");
                scanf("%i",&elemento);
                insereElemento(&Conjunto_A,elemento);
                break;
            case 2:
                printf("Insira o valor desejado remover: ");
                scanf("%i",&elemento);
                removeElemento(&Conjunto_A,elemento);
                break;
            case 3:
                esvaziaConjunto(&Conjunto_A);
                break;
            case 4:
                printf("Insira o valor desejado procurar: ");
                scanf("%i",&elemento);
                if(pertenceConjunto(Conjunto_A,elemento)) printf("\nPertence sim\n");
                else printf("\nPertence nao\n");
                break;
            case 5:
                continue;
                break;
            case 6:
                exit(1);
                break;
            default:
                continue;
                break;
            }
        }
        else if (conjunto == 2)
        {
            switch (op)
            {
            case 1:
                printf("Insira o valor desejado inserir: ");
                scanf("%i",&elemento);
                insereElemento(&Conjunto_B,elemento);
                break;
            case 2:
                printf("Insira o valor desejado remover: ");
                scanf("%i",&elemento);
                removeElemento(&Conjunto_B,elemento);
                break;
            case 3:
                esvaziaConjunto(&Conjunto_B);
                break;
            case 4:
                printf("Insira o valor desejado procurar: ");
                scanf("%i",&elemento);
                if(pertenceConjunto(Conjunto_B,elemento)) printf("\nPertence sim\n");
                else printf("\nPertence nao\n");
                break;
            case 5:
                continue;
                break;
            case 6:
                exit(1);
                break;
            default:
                continue;
                break;
            }
        }
        
    }

    return 1;
}
