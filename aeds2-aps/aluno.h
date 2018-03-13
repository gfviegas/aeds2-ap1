//
//  aluno.h
//  aeds2-aps
//
//  Created by Gustavo Viegas on 13/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#ifndef aluno_h
#define aluno_h
#define MAX_NAME_LENGTH 100

#include <stdio.h>

typedef struct Aluno* alunoPointer;
typedef struct Aluno {
    float nota; // Chave
    char nome[MAX_NAME_LENGTH];
    int matricula;
} Aluno;


void inicializaAluno(Aluno* aluno, float nota, char* nome, int matricula);


#endif /* aluno_h */
