//
//  node.h
//  aeds2-aps
//
//  Created by Gustavo Viegas on 06/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>
#include "aluno.h"

typedef struct node* nodePointer;
typedef struct node {
    Aluno aluno;
    nodePointer left;
    nodePointer right;
} node;

int initNode(nodePointer* node);
int addNode(nodePointer* node, Aluno aluno);
void printNode(nodePointer node);
int descOrderWalk(nodePointer node);

int treeSize(nodePointer* node);
int treeHeight(nodePointer* node);

Aluno menorNota(nodePointer* node);
Aluno maiorNota(nodePointer* node);

int alunosComMedia(nodePointer* node);

#endif /* node_h */
