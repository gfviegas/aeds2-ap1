//
//  main.c
//  aeds2-aps
//
//  Created by Gustavo Viegas on 06/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void printLine();
void readFile(char *file, nodePointer *no);

int main() {
    node *root = NULL;
    initNode(&root);    
    readFile("./files/alunos", &root);

    printLine();
    printf("DescOrder Walking!\n");
    descOrderWalk(root);
    
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

void printLine() {
    int i;
    printf("\n");
    for (i = 0; i < 80; i++) {
        printf("*");
    }

    printf("\n");
}

void readFile(char *file, nodePointer* no){
    FILE *fp;
    fp = fopen(file, "r");

    if(fp != NULL){
        while(1){
            Aluno aluno;
            fscanf(fp, "%d - %s - %f", &aluno.matricula, aluno.nome, &aluno.nota);
            if(fgetc(fp) == EOF)
                break;
            addNode(no, aluno);
        }
        fclose(fp);
    }
}