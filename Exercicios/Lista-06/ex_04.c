// Fazer  um  programa  para  Controle  de  Hotel  -  este  programa  se  destina  a  controlar  o 
// check-in  (cadastro  de  hóspedes)  de  um  hotel.  O  hotel  possui  15  quartos. Utilizar 
// alocação dinâmica e ponteiros para a estrutura. 
 
// [1]  Check-in  -  alocar  dinamicamente  espaço,  receber  os  valores  digitados  pelo  usuário,  se  o 
// hóspede  não  tiver  acompanhantes  atribuir  categoria  Solteiro,  caso  contrário  Familiar,  buscar  o 
// número do quarto disponível, de acordo com a categoria na estrutura quartos. Apenas um hóspede 
// é cadastrado por vez. Não esquecer de atualizar o quarto da estrutura quartos para Ocupado. 
 
// [2] Check-out – encerra a estadia e apresenta o relatório, de acordo com o quarto. Apenas 
// um registro é acessado por vez, buscar e mostrar o número do quarto, o nome do hóspede, 
// quantidade  de  acompanhantes,  a  categoria  (Solteiro  ou  Familiar, o  tempo  de  permanência 
// em dias e o valor a ser pago.  
 
// [3] Fim 
 
// Dica: 
// • No check-in - não esquecer de verificar se na estrutura hospede há um espaço vago 
// (cujo  quarto  =  -1),  se  houver  o  novo  hóspede  deverá  ser  ali  armazenado,  caso 
// contrário, acrescentar no final da estrutura. 
 
 
// struct hospede{ 
//  int quarto;   // número do quarto 
//  char nome[80]; 
// int acompanhante;  // quantidade de acompanhantes 
// char categoria;  // [S]olteiro / [F]amiliar 
// int dias;   // tempo de permanência – em dias 
// }; 
 
//  struct quarto{ 
//  int num;   // número do quarto 
//  char categoria  // [S]olteiro / [F]amiliar 
//  char status   // [L]ivre / [O]cupado 
// }; 
 
// Categoria de quarto: 
// [S]olteiro – diária R$ 85,00 por pessoa 
// [F]amiliar – diária R$ 45,00 por pessoa 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede{ 
  int quarto;   // número do quarto 
  char nome[80]; 
  int acompanhante;  // quantidade de acompanhantes 
  char categoria;  // [S]olteiro / [F]amiliar 
  int dias;   // tempo de permanência – em dias 
} hospede; 
 
typedef struct quarto{ 
  int num;   // número do quarto 
  char categoria;  // [S]olteiro / [F]amiliar 
  char status;   // [L]ivre / [O]cupado 
} quarto; 

void aloca_quarto(quarto **p_quarto, int qtdd_quarto);
void aloca_hospede(hospede **p_hospede, int qtdd_hospede);

void cadastro_quarto(quarto *p_quarto, char categoria);
void cadastro_hospede(hospede *p_hospede, quarto *p_quarto, int qtdd_quarto);

void mostra_quartos(quarto *p_quarto, int qtdd_quarto);
void mostra_hospedes(hospede *p_hospede, int qtdd_hospede);

int busca_quarto(quarto *p_quarto, int qtdd_quarto, char categoria, char status);
int busca_hospede(hospede *p_hospede, int qtdd_hospede);

void checkout(hospede *p_hospede, quarto *p_quarto,int qtdd_hospede, int qtdd_quarto);



int main() {
  quarto *p_quarto = NULL;
  hospede *p_hospede = NULL;
  int qtdd_quarto = 0, qtdd_hospede = 0, op;
  char categoria;

  for(int i = 0; i < 5; i++) {
    if(i < 2) {
      categoria = 'F';
    } else {
      categoria = 'S';
    }

    aloca_quarto(&p_quarto, qtdd_quarto+1);
    cadastro_quarto(p_quarto+qtdd_quarto, categoria);
    qtdd_quarto++;
  }

  do {
    printf("Check-In  [1]\n");
    printf("Check-Out [2]\n");
    printf("Hospedes  [3]\n");
    printf("Quartos   [4]\n");
    printf("Sair      [5]\n");
    printf("Escolha uma das opcoes acima: ");
    scanf("%i", &op);
    printf("\n");


    fflush(stdin);
    
    switch (op) {
      case 1:
        aloca_hospede(&p_hospede, qtdd_hospede+1);
        cadastro_hospede(p_hospede+qtdd_hospede, p_quarto, qtdd_quarto);
        qtdd_hospede++;
        break;
      case 2:
        checkout(p_hospede, p_quarto, qtdd_hospede, qtdd_quarto);
        break;
      case 3:
        mostra_hospedes(p_hospede, qtdd_hospede);
        break;
      case 4:
        mostra_quartos(p_quarto, qtdd_quarto);
        break;
      default:
        printf("Opção invalida\n");
        break;
    }
  } while (op != 5);
  
  return 0;
}

void aloca_quarto(quarto **p_quarto, int qtdd_quarto) {
  if((*p_quarto = (quarto*) realloc(*p_quarto, qtdd_quarto * sizeof(quarto))) == NULL) {
    printf("Erro de Alocacao");
    exit(1);
  }
}

void aloca_hospede(hospede **p_hospede, int qtdd_hospede) {
  if((*p_hospede = (hospede*) realloc(*p_hospede, qtdd_hospede * sizeof(hospede))) == NULL) {
    printf("Erro de Alocacao");
    exit(1);
  }
}

void cadastro_quarto(quarto *p_quarto, char categoria) {
  static int num = 1;
  p_quarto->num = num++;
  p_quarto->categoria = categoria;
  p_quarto->status = 'L';
}

void cadastro_hospede(hospede *p_hospede, quarto *p_quarto, int qtdd_quarto) {
  int acompanhantes, dias, quarto;
  printf("Digite o nome: ");
  fgets(p_hospede->nome, 80, stdin);
  fflush(stdin);
  
  do {
    printf("Digite a quantidade de acompanhantes (max: 3): ");
    scanf("%i",  &acompanhantes);

    if(acompanhantes < 0 || acompanhantes > 3) {
      printf("Quantidade invalida.\n");
    }
  } while(acompanhantes < 0 || acompanhantes > 3);
  p_hospede->acompanhante = acompanhantes;
  fflush(stdin);

  if(acompanhantes == 0) {
    quarto = busca_quarto(p_quarto, qtdd_quarto, 'S', 'L');
    p_hospede->categoria = 'S';
  
    if(quarto < 0) {
      quarto = busca_quarto(p_quarto, qtdd_quarto, 'F', 'L');
      p_hospede->categoria = 'F';

    }

    (p_quarto+quarto)->status = 'O';
    p_hospede->quarto = (p_quarto+quarto)->num;
  } else {
    quarto = busca_quarto(p_quarto, qtdd_quarto, 'F', 'L');
    p_hospede->categoria = 'F';
    (p_quarto+quarto)->status = 'O';
    p_hospede->quarto = (p_quarto+quarto)->num;
  }

  do {
    printf("Digite o tempo de estadia (dias): ");
    scanf("%i", &dias);

    if(dias <= 0) {
      printf("Quantidade invalida.\n");
    }
  } while (dias <= 0);  
  p_hospede->dias = dias;
  fflush(stdin);
}

void mostra_quartos(quarto *p_quarto, int qtdd_quarto) {
  system("cls");
  for(int i = 0; i < qtdd_quarto; i++) {
    printf("Quarto - [%i]\n", (p_quarto+i)->num);
    printf("Categoria: %s\n", ((p_quarto+i)->categoria) == 'F' ? "Familiar" : "Solteiro");
    printf("Status: %s\n", ((p_quarto+i)->status) == 'L' ? "Livre" : "Ocupado");
    printf("--------------------\n");
  }
  
}

void mostra_hospedes(hospede *p_hospede, int qtdd_hospede) {
  system("cls");
  for(int i = 0; i < qtdd_hospede; i++) {
    printf("Hospede: %s", (p_hospede+i)->nome);
    printf("Acompanhantes: %i\n", (p_hospede+i)->acompanhante);
    printf("Categoria: %s\n", ((p_hospede+i)->categoria) == 'F' ? "Familiar" : "Solteiro");
    printf("Quarto: %i\n", (p_hospede+i)->quarto);
    printf("Tempo de permanencia: %i dias\n", (p_hospede+i)->dias);
    printf("--------------------\n");
  }
}

int busca_quarto(quarto *p_quarto, int qtdd_quarto, char categoria, char status) {
  for(int i = 0; i < qtdd_quarto; i++) {
    if((p_quarto+i)->categoria == categoria) {
      if((p_quarto+i)->status == status) {
        return i;
      }
    }
  }

  return -1;
}

int busca_hospede(hospede *p_hospede, int qtdd_hospede) {
  for(int i = 0; i < qtdd_hospede; i++) {
    if((p_hospede+i)->quarto == -1) {
      return i;
    }
  }

  return -1;
}

void checkout(hospede *p_hospede, quarto *p_quarto, int qtdd_hospede, int qtdd_quarto) {
  int num_quarto, pos_quarto;
  char op;

  do {
    printf("Digite o numero do quarto que voce deseja: ");
    scanf("%i", &num_quarto);
    fflush(stdin);

    for(int i = 0; i < qtdd_quarto; i++) {
      if((p_quarto+i)->num == num_quarto) {
        if((p_quarto+i)->status == 'O') {
          (p_quarto+i)->status = 'L';
          pos_quarto = num_quarto;
        } else {
          pos_quarto = -1;
        }
      }
    }

    if(pos_quarto < 0) {
      printf("O quarto indicado está Livre\n");
      printf("Deseja tentar novamente (S/N): ");
      scanf("%c", &op);
      fflush(stdin);
    } 
    
    if(op != 'N' && op != 'n') {
      break;
    }
  } while(pos_quarto < 0);

  for(int i = 0; i < qtdd_hospede; i++) {
    if((p_hospede+i)->quarto == num_quarto) {
      printf("Quarto: %i\n", num_quarto);
      printf("Nome: %s", (p_hospede+i)->nome);
      printf("Categoria: %s\n", ((p_hospede+i)->categoria) == 'F' ? "Familiar" : "Solteiro");
      printf("Acompanhantes: %i\n", (p_hospede+i)->acompanhante);
      printf("Dias: %i\n", (p_hospede+i)->dias);
      printf("Total Pago: R$%i\n", ((((p_hospede+i)->categoria) == 'F') ? (((p_hospede+i)->acompanhante + 1) * 45) : 85) * (p_hospede+i)->dias);
    }
  }
}