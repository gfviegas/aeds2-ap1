
#ifndef node_h
#define node_h

#include <stdio.h>
#include "alumn.h"

typedef struct Node* nodePointer;
typedef struct Node {
    Alumn alumn;
    nodePointer left;
    nodePointer right;
} Node;

/**
 *  Inicializa os valores de um nó, atribuindo o seu valor do ponteiro para null
 *
 *  @param  node           Ponteiro para o ponteiro do nó que será manipulado
 */
void initNode(nodePointer* node);

/**
 *  Adiciona um novo nó na árvore, alocando-o na posição correta ordenada por nota do aluno
 *
 *  @param  node           Ponteiro para o ponteiro do nó que será manipulado
 *  @param  registration       Valor inteiro da matricula do aluno
 *  @param  name            String com o nome do aluno
 *  @param  grade            Float que representa a nota do aluno
 */
int addNode(nodePointer* node, int registration, char* name, float grade);

/**
 *  Imprime os dados de um nó
 *
 *  @param  node           Ponteiro para o nó que será impresso
 */
void printNode(nodePointer node);

/**
 *  Percorre a árvore imprimindo seus valores de forma ordenada decrescente pela nota
 *
 *  @param  node           Ponteiro para o nó raiz da árvore que será impressa
 */
int descOrderWalk(nodePointer node);

/**
 *  Conta a quantidade de alunos/nós que a árvore possui
 *
 *  @param  node           Ponteiro para o nó raiz da árvore que será manipulada
 *  @return Inteiro representando a quantidade de nós (ou a quantidade de alunos) que a árvore possui
 */
int treeSize(nodePointer* node);

/**
 *  Busca o aluno que possui a menor nota na árvore
 *
 *  @param  node           Ponteiro para o nó raiz da árvore que será manipulada
 *  @return Os dados de um Aluno que possui a menor grade da árvore
 */
Alumn lowestGrade(nodePointer* node);

/**
 *  Busca o aluno que possui a maior nota na árvore
 *
 *  @param  node           Ponteiro para o nó raiz da árvore que será manipulada
 *  @return Os dados de um Aluno que possui a maior grade da árvore
 */
Alumn highestGrade(nodePointer* node);

/**
 *  Conta a quantidade de alunos/nós que a árvore possui que tem nota >= 12
 *
 *  @param  node           Ponteiro para o nó raiz da árvore que será manipulada
 *  @return Inteiro representando a quantidade de nós (ou a quantidade de alunos) que pegaram média
 */
int averageStudents(nodePointer* node);

#endif /* node_h */
