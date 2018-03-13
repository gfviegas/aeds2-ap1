//
//  node.c
//  aeds2-aps
//
//  Created by Gustavo Viegas on 06/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#include <stdlib.h>
#include "node.h"

int initNode(nodePointer* node) {
    *node = NULL;
    return 0;
}

int addNode(nodePointer* node, int value) {
    if (*node == NULL) {
        *node = (nodePointer) malloc(sizeof(node));
        initNode(&(*node)->left);
        initNode(&(*node)->right);
        (*node)->value = value;
        return 0;
    }
    
    if (value > (*node)->value) return addNode(&(*node)->right, value);
    else return addNode(&(*node)->left, value);
}

void printNode(nodePointer* node) {
    printf("Node value: \t %d \n", (*node)->value);
}

void orderWalk(nodePointer* node) {
    if ((*node)->left != NULL) orderWalk(&(*node)->left);
    printNode(node);
    if ((*node)->right != NULL) orderWalk(&(*node)->right);
}

void preorderWalk(nodePointer* node) {
    printNode(node);
    if ((*node)->left != NULL) preorderWalk(&(*node)->left);
    if ((*node)->right != NULL) preorderWalk(&(*node)->right);
}

void postorderWalk(nodePointer* node) {
    if ((*node)->left != NULL) postorderWalk(&(*node)->left);
    if ((*node)->right != NULL) postorderWalk(&(*node)->right);
    printNode(node);
}

int treeSize(nodePointer* node) {
    if (*node == NULL) return 0;
    int size = 1 + treeSize(&(*node)->left) +  treeSize(&(*node)->right);
    
    return size;
}

int treeHeight(nodePointer* node) {
    int leftSizeHeight, rightSizeHeight, tallerSize;
    if (*node == NULL) return 0;
    
    leftSizeHeight = treeHeight(&(*node)->left);
    rightSizeHeight = treeHeight(&(*node)->right);
    tallerSize = (leftSizeHeight > rightSizeHeight) ? leftSizeHeight : rightSizeHeight;
    
    return 1 + tallerSize;
}
