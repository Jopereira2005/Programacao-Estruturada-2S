// Fazer um programa para Diário Eletrônico – este programa se destina a controlar as notas e a 
// média de 10 alunos. 
 
// [1] Cadastro - receber os valores digitados pelo usuário, inicialmente notas e média=0. Apenas um 
// registro é cadastrado por vez. 
// [2]  Controle  de  Notas  -  o  acesso  deve  ser  feito  através  do  RA.  Buscar  o  registro,  mostrar  o 
// nome  do  aluno  para  simples  conferência,  fazer  as  alterações  das  notas,  calcular  a  média  e 
// apresentar na tela as notas e a média. 
 
// struct aluno{ 
// char nome[80]; 
// char RA[7]; 
// float nota[2]; -> notas de provas – considerar 2 provas 
// float media; -> média aritmética das provas 
// };

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{ 
  char nome[80]; 
  char RA[7]; 
  float nota[2]; 
  float media;
} aluno;

aluno cadastro();
void notas_media(aluno alunos[], char RA[7]);
#define tam 2


int main() {
  char RA[7];
  aluno alunos[tam];
  char op = 'S';


  for (int i = 0; i < tam; i++) {
    alunos[i] = cadastro();
  }

  while(op != 'N' && op != 'n') {
    fflush(stdin);
    printf("\nDigite o RA do aluno para atribuir as notas: ");
    fgets(RA, 7 , stdin);
    
    notas_media(alunos, RA);

    fflush(stdin);
    printf("\nDeseja continuar (S/N): ");
    scanf("%c", &op);
  }
}

aluno cadastro() {
  aluno aluno;
  printf("Nome: ");
  fgets(aluno.nome, 80, stdin);

  fflush(stdin);

  printf("RA: ");
  fgets(aluno.RA, 7, stdin);

  fflush(stdin);


  aluno.nota[0] = 0;
  aluno.nota[1] = 0; 
  aluno.media = 0;

  return aluno;
}

void notas_media(aluno alunos[], char RA[7]) {
  int enc = 0;
  for(int i = 0; i < tam; i++) {
    if(strcmp(alunos[i].RA, RA) == 0) {
      printf("Nome: %s", alunos[i].nome);

      do {
        fflush(stdin);
        printf("Digite a nota da primeira prova (0 a 10): ");
        scanf("%f", &alunos[i].nota[0]);
        
        if(alunos[i].nota[0] < 0 || alunos[i].nota[0] > 10) {
          printf("\nNota invalida\n");
        }

      } while (alunos[i].nota[0] < 0 || alunos[i].nota[0] > 10);

      do {
        fflush(stdin);
        printf("Digite a nota da segunda prova (0 a 10): ");
        scanf("%f", &alunos[i].nota[1]);
        
        if(alunos[i].nota[1] < 0 || alunos[i].nota[1] > 10) {
          printf("\nNota invalida\n");
        }

      } while (alunos[i].nota[1] < 0 || alunos[i].nota[1] > 10);


      alunos[i].media = (alunos[i].nota[0] + alunos[i].nota[1]) / 2;

      printf("\nNota 1: %.1f | Nota 2: %.1f\n", alunos[i].nota[0], alunos[i].nota[1]);
      printf("\nMedia: %.1f\n", alunos[i].media);

      enc = 1;
      break;
    }
  }

  if(!enc) {
    printf("\nAluno nao encontrado");
  }
}