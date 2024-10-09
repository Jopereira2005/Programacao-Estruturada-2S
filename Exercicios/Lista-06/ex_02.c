// Fazer  um  programa  para  Sistema  de  Conta  Bancária  –  este  programa  se  destina  a 
// controlar  as  contas  de  clientes.  Consultar  o  usuário  para  continuar.  Utilizar  alocação 
// dinâmica e ponteiros para a estrutura. 
 
// [1] Cadastro - receber os valores digitados pelo usuário. Apenas um registro é cadastrado por vez. 
 
// [2]  Depósito  -  o  acesso  deve  ser  feito  através  do  nº  de  conta  corrente.  Buscar  o  registro, 
// mostrar o nome do cliente e o saldo para simples conferência, pedir o valor do depósito, fazer 
// as alterações e apresentar na tela o saldo atualizado. 
 
// [3]  Retirada  -  o  acesso  deve  ser  feito  através  do  nº  de  conta  corrente.  Buscar  o  registro, 
// mostrar o nome do cliente e o saldo para simples conferência, pedir o valor da retirada, fazer 
// as  alterações  se  possível  (a  retirada  só  será  permitida,  se  houver  saldo  suficiente)  e 
// apresentar na tela o saldo atualizado. 
 
// struct cliente{ 
//   char nome[30]; 
//   int conta; 
//   float saldo; 
// };

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct client { 
  char nome[30]; 
  int conta; 
  float saldo; 
} client;

void aloca(client **p_client, int tam);
void cadastro(client *p_client);
int busca(client *p_client, int tam);
void operacao(client *p_client, int op);
void mostra_clientes(client *p_client, int tam);

int main() {
  int tam = 0, indice, op;
  client *p_clients = NULL;

  do {
    printf("\nEscolha umas das opcoes:\n");
    printf("Cadastro [1]\n");
    printf("Deposito [2]\n");
    printf("Retirada [3]\n");
    printf("Contas   [4]\n");
    printf("Sair     [5]\n");
    scanf("%i", &op);
    fflush(stdin);
    
    switch (op) {
      case 1:
        aloca(&p_clients, tam+1);
        cadastro(p_clients+tam);
        tam++;
        break;
      case 2:
      case 3:
        if((indice = busca(p_clients, tam)) >= 0) 
          operacao(p_clients+indice, op);
        break;
      case 4:
        mostra_clientes(p_clients, tam);
      case 5:
        break;
     default:
        printf("Opcao Invalida");
        break;
    }
    
  } while (op != 5);
  
}

void aloca(client **p_client, int tam) {
  if((*p_client = (client*) realloc(*p_client, tam * sizeof(client))) == NULL) {
    printf("Erro de Alocacao");
    exit(1);
  }
}

void cadastro(client *p_client) {
  static int num_conta = 100;
  p_client->conta = num_conta;
  num_conta += 10;
  printf("--------------\n");
  printf("Digite o nome: ");
  fgets(p_client->nome, 30, stdin);

  fflush(stdin);

  printf("Digite o saldo: ");
  scanf("%f", &p_client->saldo);

  printf("--------------\n");
  fflush(stdin);
}


int busca(client *p_client, int tam) {
  int num_conta;
  printf("Digite o numero da conta: ");
  scanf("%i", &num_conta);
  for(int i = 0; i < tam; i++) {
    if((p_client+i)->conta == num_conta) {
      return i;
    }
  }

  printf("Conta nao encontrada");
  return -1;
}

void operacao(client *p_client, int op) {
  float valor;
  printf("Nome: %s", p_client->nome);
  printf("Saldo: %.2f\n------------\n", p_client->saldo);

  if(op == 2) {
    printf("Digite o valor do deposito: ");
  } else {
    printf("Digite o valor da retirada: ");
  }

  scanf("%f", &valor);

  if(op == 2) {
    p_client->saldo = p_client->saldo + valor; 
    printf("Saldo atualizado: %.2f", p_client->saldo);
  } else {
    if(p_client->saldo >= valor) {
      p_client->saldo = p_client->saldo - valor;
      printf("Saldo atualizado: %.2f", p_client->saldo);
    } else {
      printf("\nSaldo Insuficiente\n");
    }
  }
}

void mostra_clientes(client *p_client, int tam) {
  system("cls");
  for (int i = 0; i < tam; i++) {
    printf("Nome: %sSaldo: %.2f \nConta: %i\n", (p_client+i)->nome, (p_client+i)->saldo, (p_client+i)->conta);
  }
}
