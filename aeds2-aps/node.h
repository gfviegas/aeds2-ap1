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

typedef struct node* nodePointer;
typedef struct node {
    int value;
    nodePointer left;
    nodePointer right;
} node;

int initNode(nodePointer* node);
int addNode(nodePointer* node, int value);
void printNode(nodePointer* node);
void orderWalk(nodePointer* node);
void preorderWalk(nodePointer* node);
void postorderWalk(nodePointer* node);

int treeSize(nodePointer* node);
int treeHeight(nodePointer* node);

#endif /* node_h */
