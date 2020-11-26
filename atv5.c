/* Nome João Victor Meira Barros
** Conjunto de numeros inteiros */

#include <stdio.h>
#include <stdlib.h>
#include "atv5.h"

/* Declarando Estruturas */
struct node
{
    int dado;
    struct node * prox;
};

void insereElemento(Node ** Lista,int Elemento)
{
    int e = Elemento;
    Node * aux = NULL;

    if(*Lista == NULL)
    {
        *Lista = (Node *) malloc (sizeof(Node));
        (*Lista)->dado = e;
        (*Lista)->prox = NULL;
    }else if(pertenceConjunto(*Lista,e) == 0)
    {
        aux = *Lista;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = (Node *) malloc (sizeof(Node));
        aux = aux->prox;
        aux->dado = e;
        aux->prox = NULL;
    }else
    {
        printf("Este elemento ja existe neste conjunto");
    }
    
}

void removeElemento(Node ** Lista,int Elemento)
{
    int e = Elemento;
    Node * aux = NULL,* aux2 = NULL;

    if (*Lista == NULL)
    {
        printf("Nao tem como apagar um elemento que nao existe");
        return;
    }else if ((*Lista)->prox == NULL)
    {
        if ((*Lista)->dado == e)
        {
            aux = *Lista;
            *Lista = NULL;
            free(aux);
        }else{
            printf("Nao tem como apagar um elemento que nao existe");
            return;
        }
    }else if ((*Lista)->dado == e)
    {
        aux = *Lista;
        *Lista = aux->prox;
        free(aux);
    }else
    {
        aux = *Lista;
        aux2 = aux -> prox;
        while(aux2->prox != NULL && aux2->dado != e)
        {
            aux = aux->prox;
            aux2 = aux2->prox;
        }
        if (aux2->dado == e)
        {
            aux->prox = aux2->prox;
            free(aux2);
            return;
        }else
        {
            printf("Nao tem como apagar um elemento que nao existe");
            return;
        }
    }
}

void imprimeElementos(Node * Lista)
{
    Node * aux = Lista;

    printf("\nLista\n [ ");
    while (aux != NULL)
    {
        printf("%d ",aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}

void esvaziaConjunto(Node ** Lista)
{
    Node * aux,* aux2;

    if(*Lista == NULL)
    {
        printf("Nao tem como esvaziar o que ja esta vazio");
        return;
    }
    else if ((*Lista)->prox == NULL)
    {
        aux = *Lista;
        *Lista = NULL;
        free(aux);
    }
    else
    {
        aux = *Lista;
        aux2 = aux->prox;

        while(aux2 != NULL){
            free(aux);
            aux = aux2;
            aux2 = aux2->prox;
        }
        
        if (aux != NULL)
        {
            free(aux);
        }

        *Lista = NULL; 
    }
}

int eVazio(Node * Lista)
{
    if(Lista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}

int pertenceConjunto(Node * Lista,int Elemento)
{
    int e = Elemento;
    Node * aux = NULL,* aux2 = NULL;

    if (Lista == NULL)
    {
        printf("Nao tem como procurar um elemento em um conjunto vazio");
        return 0;
    }else if (Lista->prox == NULL)
    {
        if (Lista->dado == e)
        {
            return 1;
        }else{
            return 0;
        }
    }else if (Lista->dado == e)
    {
        return 1;
    }else
    {
        aux = Lista;
        aux2 = aux -> prox;
        while(aux2->prox != NULL && aux2->dado != e)
        {
            aux = aux->prox;
            aux2 = aux2->prox;
        }
        if (aux2->dado == e)
        {
            return 1;
        }else
        {
            return 0;
        }
    }
}

int eIgual(Node * Lista_A,Node * Lista_B)
{
    Node * A = Lista_A;
    Node * B = Lista_B;
    int rt = 0, rt2 = 0;

    if(A == NULL || B == NULL)
    {
        if(A == B)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }else
    {
        while(A != NULL && B != NULL)
        {
            if(A->dado == B->dado)
            {
                rt += 1;
            }
            
            rt2 += 1;
            A = A->prox;
            B = B->prox;
        }

        if (rt == rt2 && A == B)
        {
            return 1;
        }else
        {
            return 0;
        }      
    }
    
}

Node * unirConjunto(Node * Lista_A, Node * Lista_B)
{
    Node * aux = NULL,
    * aux2 = NULL;

    if(Lista_A == NULL || Lista_B == NULL)
    {
        if(Lista_A != NULL)
        {
            return Lista_A;
        }
        else
        { 
            return Lista_B;
        }
    }
    else
    {
        aux2 = Lista_A;
        while(aux2 != NULL)
        {
            insereElemento(&aux,aux2->dado);
            aux2 = aux2->prox;
        }
        aux2 = Lista_B;
        while(aux2 != NULL)
        {
            if(pertenceConjunto(aux,aux2->dado) == 0)
            {
                insereElemento(&aux,aux2->dado);
            }
            aux2 = aux2 -> prox;
        }

        return aux;
    }
}

Node * interConjunto(Node * Lista_A, Node * Lista_B)
{
    Node * aux = NULL,
    * aux2 = NULL;

    if(Lista_A == NULL || Lista_B == NULL)
    {
        return NULL;
    }
    else
    {
        aux2 = Lista_B;
        while(aux2 != NULL)
        {
            if(pertenceConjunto(Lista_A,aux2->dado))
            {
                insereElemento(&aux,aux2->dado);
            }
            aux2 = aux2 -> prox;
        }

        return aux;
    }
}

Node * menosConjunto(Node * Lista_A, Node * Lista_B)
{
    Node * aux = NULL,
    * aux2 = NULL;

    if(Lista_B == NULL)
    {
        return Lista_A;
    }
    else
    {
        aux2 = Lista_A;
        while(aux2 != NULL)
        {   
            if(pertenceConjunto(Lista_B,aux2->dado) == 0)
            {
                insereElemento(&aux,aux2->dado);
            }
            aux2 = aux2->prox;
        }

        return aux;
    }
}


