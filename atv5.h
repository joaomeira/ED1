/* Nome João Victor Meira Barros
** Conjunto de numeros inteiros */

#ifndef __CONJUNT_NUM_INT__
#define __CONJUNT_NUM_INT__

/* Definindo Chamadas */
typedef struct node Node;

/* Insere Elemento
 * A função insere elemento, pega o endereço de um ponteiro
 * já existente para poder manipula-lo nem necessidade de
 * retorno. Caso a lista esteja vazia ou seja NULA, o mesmo
 * ira alocar espaço para o ponteiro e inserir o elemento
 * desejado, Caso Contrario irá percorrer até o ultimo
 * elemento e alocar um expaço no apontamento para o proximo
 * inserir o elemento e finalizar a função*/
void insereElemento(Node ** Lista,int Elemento);

/* Remove Elemento
 * A função remove elemento funciona semelhante a insere
 * diferencia-se em que há mais casos e liberação de memoria.
 * Caso a lista tenha sido inserida seja VAZIA retorna a
 * mensagem informando que não é possivel apagar um elemento
 * dado que não existe elementos a serem apagados. Caso Contrario
 * se o proximo da lista for vazio, ou seja, nao tendo um proximo
 * no primeiro elemento quer dizer que só há 1 elemento, irá checar
 * esse unico elemento para ver se é o elemento pedido para remover
 * caso seja, ira armazenar o endereço do nó apontar a lista para NULO
 * deixando ela VAZIA, e liberar a memoria do endereço armazenado,
 * ele não sendo o mesmo pedido para remover retorna a mensagem
 * que nao tem o elemento pedido logo então não há como ser removido.
 * Caso Contrario para garantir o percorrer com dois ponteiros
 * iremos andar de dois em dois, logo o primeiro tem que ser checado
 * pois nao ira passar na verificação de todo resto da lista
 * Garantindo que o primeiro não é o elemento que deverá ser removido
 * prosseguiremos para o caso geral. Ou se for para removelo, a função
 * armazena o endereço dele aponta o inicio da lista para o segundo nó
 * e libera o espaço armazenado. Irá percorrer toda a lista
 * sempre armazenando o ponteiro anterior e o atual, caso encontre
 * para remover o anterior e apontado para o proximo do atual e
 * o atual é liberado. Se não encontrar o elemento novamente retorna
 * a mensagem dizendo que não é possivel apagar um elemento
 * inexistente */
void removeElemento(Node ** Lista,int Elemento);

/* Imprime Elementos
 * Percorre toda a lista, imprimindo os elementos nela presente.
 * Não há retorno, caso a lista seja vazia ira retornar uma impressao
 * VAZIA! */
void imprimeElementos(Node * Lista);

/* Esvazia Conjuntos
 * Semelhante a remoção de elementos, só que a liberação é feita em todos
 * elemento, do INICIO até o FINAL da lista. Não há retorno é necessario
 * passar o endereço do ponteiro da LISTA. */
void esvaziaConjunto(Node ** Lista);

/* É Vazio 
 * Verifica se uma lista é vazia, retornando 1 para vazia e 0 para não vazia
 * sendo assim pode ser usada para checagem em ifs e while*/
int eVazio(Node * Lista);

/* Pertence Conjunto
 * A função trabalha da mesma forma da remove elemnto, com uma diferença
 * ela vai até o elemento e quando chega lá retorna 1 e se chegar ao final da lista
 * retorna 0 caso não tenha encontrado o elemento */
int pertenceConjunto(Node * Lista,int Elemento);

/* É Igual
 * Esta função checa se duas listas são iguais, sendo assim
 * irá andar no a no comparando se os dados são os mesmos, caso
 * chegue ao final com exito sem nenhum convergir irá retornar 1
 * do contrario 0 */
int eIgual(Node * Lista_A,Node * Lista_B);

/* Unir Conjunto
 * Ira pegar dois conjuntos e soma-los não deixando um numero se repetir
 * ou seja 1,2,3 e 2,3,4 = 1,2,3,4 sera retornado uma nova lista com os 
 * conjuntos unidos */
Node * unirConjunto(Node * Lista_A, Node * Lista_B);

/* Intercerção Conjunto
 * Esta função ira fazer uma intercerção entre dois conjuntos
 * sendo eles 2,3,4 e 1,2,3 o resultado sera 2,3 ou seja os
 * numeros que tiver no primeiro e no segundo aparecerão na
 * nova lista os demais serão descartados. Retorno com a nova lista. */
Node * interConjunto(Node * Lista_A, Node * Lista_B);

/* Menos Conjunto
 * Um complemento relativo entre o conjunto A e B ou seja
 * A - B sendo 1,2,3 e 1,2 o resultado seria 3 mantendo somente
 * o elemento que não há em B em A. Retorno com a nova lista. */
Node * menosConjunto(Node * Lista_A, Node * Lista_B);



#endif