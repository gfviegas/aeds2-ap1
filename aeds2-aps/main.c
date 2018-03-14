
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "alumn.h"

/**
 * Imprime um cabeçalho com instruções e descrição do programa
 */
void printHeader () {
    printf("|| ||\n");
    printf("|| ||\t\tGradezator 1.0\n");
    printf("|| ||\t\tAtividade Prática 1 de \"Algoritmos e Estruturas de Dados\" II \n");
    printf("|| ||\t\tMarço de 2018 - UFV Campus Florestal\n");
    printf("|| ||\t\tBruno Marra (3029), Gustavo Viegas (3026) e Heitor Passeado (3055)\n");
    printf("|| ||\n");
    printf("\nO programa irá pedir pra que você digite um código após cada operação executada. Basta digitar o código requisitado pra a operação ser executada. \n\n");
}

/**
 * Imprime uma linha para dividir o conteúdo no buffer
 */
void printLine () {
    int i;
    printf("\n");
    for (i = 0; i < 50; i++) {
        printf("-");
    }
    printf("\n\n");
}

/**
 * Imprime instruções de códigos a serem inseridos para o programa executar
 */
void printInstructions () {
    printf("Os códigos e operações disponíveis são: \n\n");
    printf("Insira 0 \t->\t Interromper execução\n");
    printf("Insira 1 \t->\t Ler arquivo e preencher Árvore\n");
    printf("Insira 2 \t->\t Imprimir todos os dados da Árvore em ordem decrescente de nota\n");
    printf("Insira 3 \t->\t Imprimir quantidade de registros da Árvore\n");
    printf("Insira 4 \t->\t Imprimir qual a maior nota entre os registros\n");
    printf("Insira 5 \t->\t Imprimir qual a menor nota entre os registros\n");
    printf("Insira 6 \t->\t Imprimir quantos alunos pegaram média na prova\n");
}

/**
 * Lê o arquivo que contêm as entradas e preenche a árvore com os dados lidos
 *
 * @param  no                  Ponteiro para o apontador da raiz da árvore que será manipulada.
 */
void readFile(nodePointer* no){
    int matricula;
    char nome[MAX_NAME_LENGTH];
    float nota;
    
    FILE *fp;
    fp = fopen("/Users/Gustavo/Documents/UFV/aeds2-aps/aeds2-aps/files/alunos.txt", "r");
    
    if (fp != NULL){
        while (1) {
            fscanf(fp, "%d - %s - %f", &matricula, nome, &nota);
            if (fgetc(fp) == EOF)
                break;
            addNode(no, matricula, nome, nota);
        }
        fclose(fp);
    } else {
        printf("Erro na leitura do arquivo: ");
        perror("fopen");
    }
}

/**
 * Lê um código e executa a ação a ela vinculada
 *
 * @param  root                Ponteiro para o apontador da raiz da árvore que será manipulada.
 * @return                     Inteiro representando se o programa deve continuar executando (1) ou não (0)
 */
int readOperation (nodePointer* root) {
    int code, returnValue = 1;
    
    printLine();
    printInstructions();
    
    printf("\nInsira o código da operação que deseja executar: ");
    scanf("%d", &code);
    
    switch (code) {
        case 0:
            returnValue = 0;
            break;
        case 1:
            readFile(root);
            break;
        case 2:
            printLine();
            printf("Imprimindo árvore em ordem decrescente!\n");
            descOrderWalk(*root);
            break;
        case 3:
            printLine();
            printf("Quantidade de Alunos: %d!\n", treeSize(root));
            break;
        case 4:
            printLine();
            Alumn monster = highestGrade(root);
            printf("Maior nota: %.2f do aluno %s!\n", monster.grade, monster.name);
            break;
        case 5:
            printLine();
            Alumn unlucky = lowestGrade(root);
            printf("Menor nota: %.2f do aluno %s!\n", unlucky.grade, unlucky.name);
            break;
        case 6:
            printLine();
            printf("Quantidade de alunos com média: %d!\n", averageStudents(root));
            break;
        default:
            printf("Código inválido!! \n");
            readOperation(root);
            break;
    }
    
    return returnValue;
}


int main() {
    nodePointer root = NULL;
    initNode(&root);    
    
    printHeader(); // Imprime cabeçalho ao executar o script.
    
    while (readOperation(&root) == 1) {
        printf("\n\n Operação executada! \n\n");
    }
    
    printf("\n\n Execução Interrompida! (usuário inseriu o código 0).\n");
    return 0;
}
