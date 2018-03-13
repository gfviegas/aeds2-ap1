//
//  main.c
//  aeds2-aps
//
//  Created by Gustavo Viegas on 06/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#include <stdio.h>
#include "node.h"

void printLine() {
    int i;
    printf("\n");
    for (i = 0; i < 80; i++) {
        printf("*");
    }

    printf("\n");
}

int main(int argc, const char * argv[]) {
    node *root = NULL;
    addNode(&root, 4);

    addNode(&root, 2);
    addNode(&root, 6);
    addNode(&root, 1);
    addNode(&root, 3);
    addNode(&root, 5);
    addNode(&root, 7);
    
    printLine();
    printf("Order Walking!\n");
    orderWalk(&root);
    
    printLine();
    printf("Preorder Walking!\n");
    preorderWalk(&root);
    
    printLine();
    printf("Postorder Walking!\n");
    postorderWalk(&root);
    
    printLine();
    printf("Tree size: %d\n", treeSize(&root));
    
    printLine();
    printf("Tree height: %d\n", treeHeight(&root));
    return 0;
}
