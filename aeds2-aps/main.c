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
    nodePointer root = NULL;
    addNode(&root, 15.3, "Heitor Passeado", 3055);
    addNode(&root, 14.3, "Gustavo Viegas", 3026);
    addNode(&root, 17.9, "Bruno Marra", 3029);
    addNode(&root, 3.0, "Fulano", 3023);
    addNode(&root, 20.0, "Henrique Deus", 3020);
    addNode(&root, 0.1, "Elite", 3022);
    addNode(&root, 19.0, "Glaucia", 3023);
    addNode(&root, 1.0, "Altasbirra", 3023);


    printLine();
    printf("DescOrder Walking!\n");
    descOrderWalk(&root);
    
    printLine();
    printf("Quantidade de Alunos: %d!\n", treeSize(&root));
    
    printLine();
    Aluno burro = menorNota(&root);
    printf("Menor nota: %.2f do aluno %s!\n", burro.nota, burro.nome);

    printLine();
    Aluno monstro = maiorNota(&root);
    printf("Maior nota: %.2f do aluno %s!\n", monstro.nota, monstro.nome);
    
    printLine();
    printf("Quantidade de alunos com média: %d!\n", alunosComMedia(&root));
    
    printLine();
    return 0;
}
