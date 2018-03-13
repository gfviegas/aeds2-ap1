//
//  aluno.c
//  aeds2-aps
//
//  Created by Gustavo Viegas on 13/03/18.
//  Copyright © 2018 Gustavo Viegas. All rights reserved.
//

#include "aluno.h"
#include <string.h>

void inicializaAluno(Aluno* aluno, float nota, char* nome, int matricula) {
    aluno->nota = nota;
    strcpy(aluno->nome, nome);
    aluno->matricula = matricula;
}
