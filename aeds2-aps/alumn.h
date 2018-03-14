
#ifndef aluno_h
#define aluno_h
#define MAX_NAME_LENGTH 50

#include <stdio.h>

typedef struct Alumn* alumnPointer;
typedef struct Alumn {
    float grade; // Chave
    char name[MAX_NAME_LENGTH];
    int registration;
} Alumn;


/**
 *  Inicializa os valores de um aluno, atribuindo os valores do parâmetro ao aluno referenciado
 *
 *  @param  aluno               Ponteiro para o aluno que será manipulado
 *  @param  registration        Valor inteiro da matricula do aluno
 *  @param  name                String com o nome do aluno
 *  @param  grade               Float que representa a nota do aluno
 */
void initAlumn(Alumn* aluno, int registration, char* name, float grade);


#endif /* aluno_h */
