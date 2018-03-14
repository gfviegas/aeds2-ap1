
#include "alumn.h"
#include <string.h>

// Inicializa os valores de um aluno, atribuindo os valores do parâmetro ao aluno referenciado
void initAlumn(Alumn* alumn, int registration, char* name, float grade) {
    alumn->registration = registration;
    strcpy(alumn->name, name);
    alumn->grade = grade;
}
