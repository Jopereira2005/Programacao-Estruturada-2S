#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dance {
  int regaula;
  int qaluno;
  char modalidade;
  char turno;
  float valor;
} dance;

typedef struct aluno {
  char CPF[13];
  char nome[80];
  int numaula;
} aluno;

void aloca_dance(dance **p_dance, int qdance);
void aloca_aluno(aluno **p_aluno, int qaluno);

void cadastra_dance(dance *p_dance, char modalidade, char turno);
void cadastra_aluno(aluno *p_aluno, dance *p_dance, int qdance);

void mostra_dance(dance *p_dance, int qdance);
void mostra_aluno(aluno *p_aluno, int qaluno);

int busca_dance(dance *p_dance, char modalidade, char turno, int qdance);

int main() {
  dance *p_dance = NULL;
  aluno *p_aluno = NULL;
  int qdance = 6, qaluno = 0, op;

  aloca_dance(&p_dance, qdance);
  cadastra_dance(p_dance+0, 'B', 'M');
  cadastra_dance(p_dance+1, 'B', 'T');
  cadastra_dance(p_dance+2, 'B', 'N');
  cadastra_dance(p_dance+3, 'S', 'M');
  cadastra_dance(p_dance+4, 'S', 'T');
  cadastra_dance(p_dance+5, 'S', 'N');

  do {
    printf("[1] Matricula\n[2] Mostra Alunos\n[3] Mostra Turmas\n[4] Sair\nDigite uma opcao: ");
    scanf("%i", &op);
    fflush(stdin);

    switch(op) {
      case 1:
        aloca_aluno(&p_aluno, qaluno+1);
        cadastra_aluno(p_aluno+qaluno, p_dance, qdance);
        qaluno++;
        break;
      case 2:
        mostra_aluno(p_aluno, qaluno);
        break;
      case 3:
        mostra_dance(p_dance, qdance);
        break;
      default:
        printf("\nOpcao invalida\n");
        break;
    }
  } while(op != 4);
}

void aloca_dance(dance **p_dance, int qdance) {
  if((*p_dance = (dance*) realloc(*p_dance, qdance * sizeof(dance))) == NULL) {
    printf("Erro de alocacao");
    exit(1);
  }
}

void aloca_aluno(aluno **p_aluno, int qaluno) {
  if((*p_aluno = (aluno*) realloc(*p_aluno, qaluno * sizeof(aluno))) == NULL) {
    printf("Erro de alocacao");
    exit(1);
  }
}

void cadastra_dance(dance *p_dance, char modalidade, char turno) {
  float valor;
  static int reg_aula = 1;
  p_dance->regaula = reg_aula++;
  p_dance->qaluno = 0;
  p_dance->modalidade = modalidade;
  p_dance->turno = turno;

  if(turno == 'M') {
    valor = 300.00;
  } else if(turno == 'T') {
    valor = 250.00;
  } else {
    valor = 350.00;
  }

  p_dance->valor = valor;
}

void cadastra_aluno(aluno *p_aluno, dance *p_dance, int qdance) {
  int numaula;
  char modalidade, turno;
  mostra_dance(p_dance, qdance);

  printf("\n\nCPF: ");
  gets(p_aluno->CPF);
  fflush(stdin);

  printf("Nome: ");
  gets(p_aluno->nome);
  fflush(stdin);

  do {
    printf("Modalidade: ");
    scanf("%c", &modalidade);
    fflush(stdin);
    
    printf("Turno: ");
    scanf("%c", &turno);
    fflush(stdin);

    if((numaula = busca_dance(p_dance, modalidade, turno, qdance)) < 0) {
      printf("\nTurma nao exitente.\n");
    } else {
      p_aluno->numaula = numaula;
      (p_dance+numaula-1)->qaluno = (p_dance+numaula-1)->qaluno + 1;
      printf("\nValor: %.2f\n\n", (p_dance+numaula-1)->valor);
    }
  } while(numaula < 0);
}

void mostra_dance(dance *p_dance, int qdance) {
  printf("\n\n----------------------\n");
  for(int i = 0; i < qdance; i++) {
    printf("Registro Aula: %i\n", (p_dance+i)->regaula);
    printf("Quantidade Aluno: %i\n", (p_dance+i)->qaluno);
    printf("Modalidade: %c\n", (p_dance+i)->modalidade);
    printf("Turno: %c\n", (p_dance+i)->turno);
    printf("Valor: %.2f\n", (p_dance+i)->valor);
    printf("----------------------\n");
  }
}
void mostra_aluno(aluno *p_aluno, int qaluno) {
  printf("\n\n----------------------\n");
  for(int i = 0; i < qaluno; i++) {
    printf("CPF: %s\n", (p_aluno+i)->CPF);
    printf("Nome: %s\n", (p_aluno+i)->nome);
    printf("Numero Aula: %.i\n", (p_aluno+i)->numaula);
    printf("----------------------\n");
  }
}

int busca_dance(dance *p_dance, char modalidade, char turno, int qdance) {
  for(int i = 0; i < qdance; i++) {
    if((p_dance+i)->modalidade == modalidade) {
      if((p_dance+i)->turno == turno) {
        return (p_dance+i)->regaula;
      }
    }
  }
  return -1;
}

