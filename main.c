#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 1000
#define MAX_LINHA 200

typedef struct {
    int semestre;
    char turma;
    char periodo;
    char nome[100];
    char disciplina[50];
    float media;
} Aluno;

void ler_csv(const char *arquivo, Aluno lista_alunos[], int *quantidade_alunos) {
    FILE *fp = fopen(arquivo, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        exit(1);
    }
    char linha[MAX_LINHA];
    while (fgets(linha, sizeof(linha), fp) && *quantidade_alunos < MAX_ALUNOS) {
        sscanf(linha, "%d,%c,%c,%99[^,],%49[^,],%f", &lista_alunos[*quantidade_alunos].semestre, &lista_alunos[*quantidade_alunos].turma, 
               &lista_alunos[*quantidade_alunos].periodo, lista_alunos[*quantidade_alunos].nome, lista_alunos[*quantidade_alunos].disciplina, 
               &lista_alunos[*quantidade_alunos].media);
        (*quantidade_alunos)++;
    }
    fclose(fp);
}

void salvar_csv(const char *arquivo, Aluno lista_alunos[], int quantidade_alunos) {
    FILE *fp = fopen(arquivo, "w");
    if (!fp) {
        printf("Erro ao criar o arquivo %s\n", arquivo);
        exit(1);
    }
    for (int i = 0; i < quantidade_alunos; i++) {
        fprintf(fp, "%d,%c,%c,%s,%s,%.2f\n", lista_alunos[i].semestre, lista_alunos[i].turma, lista_alunos[i].periodo,
                lista_alunos[i].nome, lista_alunos[i].disciplina, lista_alunos[i].media);
    }
    fclose(fp);
    printf("Arquivo saida.csv gerado com sucesso!\n");
}

void trocar(Aluno *a, Aluno *b) {
    Aluno temp = *a;
    *a = *b;
    *b = temp;
}

void ordenar_por_nome(Aluno lista_alunos[], int quantidade_alunos) {
    for (int i = 0; i < quantidade_alunos - 1; i++) {
        for (int j = 0; j < quantidade_alunos - i - 1; j++) {
            if (strcmp(lista_alunos[j].nome, lista_alunos[j + 1].nome) > 0) {
                trocar(&lista_alunos[j], &lista_alunos[j + 1]);
            }
        }
    }
}

void ordenar_por_semestre(Aluno lista_alunos[], int quantidade_alunos) {
    for (int i = 0; i < quantidade_alunos - 1; i++) {
        for (int j = 0; j < quantidade_alunos - i - 1; j++) {
            if (lista_alunos[j].semestre > lista_alunos[j + 1].semestre) {
                trocar(&lista_alunos[j], &lista_alunos[j + 1]);
            }
        }
    }
}

void ordenar_completo(Aluno lista_alunos[], int quantidade_alunos) {
    for (int i = 0; i < quantidade_alunos - 1; i++) {
        for (int j = 0; j < quantidade_alunos - i - 1; j++) {
            if (lista_alunos[j].semestre > lista_alunos[j + 1].semestre ||
                (lista_alunos[j].semestre == lista_alunos[j + 1].semestre && lista_alunos[j].turma > lista_alunos[j + 1].turma) ||
                (lista_alunos[j].semestre == lista_alunos[j + 1].semestre && lista_alunos[j].turma == lista_alunos[j + 1].turma && lista_alunos[j].periodo > lista_alunos[j + 1].periodo) ||
                (lista_alunos[j].semestre == lista_alunos[j + 1].semestre && lista_alunos[j].turma == lista_alunos[j + 1].turma && lista_alunos[j].periodo == lista_alunos[j + 1].periodo && strcmp(lista_alunos[j].disciplina, lista_alunos[j + 1].disciplina) > 0) ||
                (lista_alunos[j].semestre == lista_alunos[j + 1].semestre && lista_alunos[j].turma == lista_alunos[j + 1].turma && lista_alunos[j].periodo == lista_alunos[j + 1].periodo && strcmp(lista_alunos[j].disciplina, lista_alunos[j + 1].disciplina) == 0 && strcmp(lista_alunos[j].nome, lista_alunos[j + 1].nome) > 0)) {
                trocar(&lista_alunos[j], &lista_alunos[j + 1]);
            }
        }
    }
}

void ordenar_por_disciplina_media(Aluno lista_alunos[], int quantidade_alunos) {
    for (int i = 0; i < quantidade_alunos - 1; i++) {
        for (int j = 0; j < quantidade_alunos - i - 1; j++) {
            if (strcmp(lista_alunos[j].disciplina, lista_alunos[j + 1].disciplina) > 0 ||
                (strcmp(lista_alunos[j].disciplina, lista_alunos[j + 1].disciplina) == 0 && lista_alunos[j].media < lista_alunos[j + 1].media)) {
                trocar(&lista_alunos[j], &lista_alunos[j + 1]);
            }
        }
    }
}

void menu(Aluno lista_alunos[], int quantidade_alunos) {
    int opcao;
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Ordenar por nome\n");
        printf("2. Ordenar por semestre\n");
        printf("3. Ordenar por semestre, turma, periodo, disciplina e nome\n");
        printf("4. Ordenar por disciplina e media final (decrescente)\n");
        printf("5. Ordenar por periodo, semestre, turma, disciplina e nome\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                ordenar_por_nome(lista_alunos, quantidade_alunos);
                break;
            case 2:
                ordenar_por_semestre(lista_alunos, quantidade_alunos);
                break;
            case 3:
                ordenar_completo(lista_alunos, quantidade_alunos);
                break;
            case 4:
                ordenar_por_disciplina_media(lista_alunos, quantidade_alunos);
                break;
            case 5:
                ordenar_completo(lista_alunos, quantidade_alunos);
                break;
            case 0:
                printf("Voce escolheu sair! Ate logo.\n");
                return;
            default:
                printf("Opcao invalida!\n");
        }
        salvar_csv("saida.csv", lista_alunos, quantidade_alunos);
    } while (opcao != 0);
}

int main() {
    Aluno lista_alunos[MAX_ALUNOS];
    int quantidade_alunos = 0;
    
    ler_csv("entrada.csv", lista_alunos, &quantidade_alunos);
    menu(lista_alunos, quantidade_alunos);
    
    return 0;
}
