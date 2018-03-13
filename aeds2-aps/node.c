//
//  node.c
//  aeds2-aps
//
//  Created by Gustavo Viegas on 06/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#include <stdlib.h>
#include "node.h"
#include "aluno.h"

int initNode(nodePointer* node) {
    *node = NULL;
    return 0;
}

int addNode(nodePointer* no, Aluno aluno) {
    if ((*no) == NULL) {
        (*no) = (nodePointer) malloc(sizeof(node));
        (*no)->aluno = aluno;
        (*no)->right = NULL;
        (*no)->left = NULL;
    }
    else if (aluno.nota <= (*no)->aluno.nota) addNode(&(*no)->left, aluno);
    else if (aluno.nota > (*no)->aluno.nota) addNode(&(*no)->right, aluno);
    
    return 1;
}

void printNode(nodePointer node) {
    printf("Aluno: %s \t Matrícula: %d \t - Nota: %.2f \n", node->aluno.nome, node->aluno.matricula, node->aluno.nota);
}

int descOrderWalk(nodePointer node) {
    if (node == NULL) return 1;
    
    descOrderWalk(node->right);
    printNode(node);
    descOrderWalk(node->left);
    
    return 0;
}

int treeSize(nodePointer* node) {
    if (*node == NULL) return 0;
    return 1 + treeSize(&(*node)->left) + treeSize(&(*node)->right);
}

int treeHeight(nodePointer* node) {
    int leftSizeHeight, rightSizeHeight, tallerSize;
    if (*node == NULL) return 0;
    
    leftSizeHeight = treeHeight(&(*node)->left);
    rightSizeHeight = treeHeight(&(*node)->right);
    tallerSize = (leftSizeHeight > rightSizeHeight) ? leftSizeHeight : rightSizeHeight;
    
    return 1 + tallerSize;
}

Aluno menorNota(nodePointer* node) {
    if ((*node)->left != NULL)
        return menorNota(&(*node)->left);
    return (*node)->aluno;
}

Aluno maiorNota(nodePointer* node) {
    if ((*node)->right != NULL)
        return maiorNota(&(*node)->right);
    return (*node)->aluno;
}

int alunosComMedia(nodePointer* node) {
    if (*node == NULL) return 0;
    else if ((*node)->aluno.nota >= 12.0)
        return 1 + alunosComMedia(&(*node)->left) + alunosComMedia(&(*node)->right);
    else
        return alunosComMedia(&(*node)->right);
}
