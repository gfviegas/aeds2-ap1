
#include <stdlib.h>
#include "node.h"
#include "alumn.h"

// Inicializa os valores de um nó, atribuindo o seu valor do ponteiro para null
void initNode(nodePointer* node) {
    *node = NULL;
}

// Adiciona um novo nó na árvore, alocando-o na posição correta ordenada por nota do aluno
int addNode(nodePointer* node, int registration, char* name, float grade) {
    if ((*node) == NULL) {
        (*node) = (nodePointer) malloc(sizeof(Node));
        initAlumn(&(*node)->alumn, registration, name, grade);
        initNode(&(*node)->right);
        initNode(&(*node)->left);
    }
    else if (grade <= (*node)->alumn.grade) addNode(&(*node)->left, registration, name, grade);
    else if (grade > (*node)->alumn.grade) addNode(&(*node)->right, registration, name, grade);
    
    return 1;
}

// Imprime os dados de um nó
void printNode(nodePointer node) {
    printf("Aluno: %15s \t | Matrícula: %5d \t | Nota: %.2f \n", node->alumn.name, node->alumn.registration, node->alumn.grade);
}

// Percorre a árvore imprimindo seus valores de forma ordenada decrescente pela nota
int descOrderWalk(nodePointer node) {
    if (node == NULL) return 1;
    
    descOrderWalk(node->right);
    printNode(node);
    descOrderWalk(node->left);
    
    return 0;
}

// Conta a quantidade de alunos/nós que a árvore possui
int treeSize(nodePointer* node) {
    if (*node == NULL) return 0;
    return 1 + treeSize(&(*node)->left) + treeSize(&(*node)->right);
}

// Busca o aluno que possui a menor nota na árvore
Alumn lowestGrade(nodePointer* node) {
    if ((*node)->left != NULL)
        return lowestGrade(&(*node)->left);
    return (*node)->alumn;
}

// Busca o aluno que possui a maior nota na árvore
Alumn highestGrade(nodePointer* node) {
    if ((*node)->right != NULL)
        return highestGrade(&(*node)->right);
    return (*node)->alumn;
}

// Conta a quantidade de alunos/nós que a árvore possui que tem nota >= 12
int averageStudents(nodePointer* node) {
    if (*node == NULL) return 0;
    else if ((*node)->alumn.grade >= 12.0)
        return 1 + averageStudents(&(*node)->left) + averageStudents(&(*node)->right);
    else
        return averageStudents(&(*node)->right);
}
