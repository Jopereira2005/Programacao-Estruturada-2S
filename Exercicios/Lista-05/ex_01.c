// Fazer um programa para Sistema de Conta Bancária – este programa se destina a controlar 
// as contas de 10 clientes. 
 
// [1] Cadastro - receber os valores digitados pelo usuário. Apenas um registro é cadastrado por vez. 
// [2]  Depósito  -  o  acesso  deve  ser  feito  através  do  nº  de  conta  corrente.  Buscar  o  registro, 
// mostrar o nome do cliente e o saldo para simples conferência, pedir o valor do depósito, fazer 
// as alterações e apresentar na tela o saldo atualizado. 
// [3] Retirada - o acesso deve ser feito através do nº de conta corrente. Buscar o registro, mostrar 
// o  nome  do  cliente  e  o  saldo  para  simples  conferência,  pedir  o  valor  da  retirada,  fazer  as 
// alterações se possível (a retirada só será permitida, se houver saldo suficiente) e apresentar na 
// tela o saldo atualizado. 
 
// struct cliente{ 
// char nome[30]; 
// int conta; 
//  float saldo; 
// };

#include <stdio.h>
#include <stdlib.h>

typedef struct client {
  char nome[30];
  int conta;
  float saldo;
} client;

client cadastro();
void deposito(client conta[], int num_conta);
void retirada(client conta[], int num_conta);

int main() {
  int tam = 10, num_conta;
  client contas[tam];
  char op = 'S', op2;


  for (int i = 0; i < tam; i++) {
    contas[i] = cadastro();
  }
  
  printf("Digite um numero de conta: ");
  scanf("%i", &num_conta);


  while(op != 'N' && op != 'n') {
    fflush(stdin);
    printf("\nEscolha uma das opcoes abaixo: \n 1 - Deposito. \n 2 - Retirada. \n 3 - Alterar conta.\n");
    scanf("%c", &op2);

    if(op2 == '1') {
      deposito(contas, num_conta);
    } else if(op2 == '2') {
      retirada(contas, num_conta);
    } else if(op2 == '3') {
      scanf("%i", &num_conta);
    }

    fflush(stdin);
    printf("\nDeseja continuar (S/N): ");
    scanf("%c", &op);
  }
}

client cadastro() {
  client conta;
  printf("Nome: ");
  fgets(conta.nome, 30, stdin);

  fflush(stdin);

  printf("Numero da conta: ");
  scanf("%i", &conta.conta);

  printf("Saldo: ");
  scanf("%f", &conta.saldo);

  fflush(stdin);

  return conta;
}

void deposito(client conta[], int num_conta) {
  int i = 0, enc;
  float valor;
  for (; i < 10; i++) {
    if(conta[i].conta == num_conta) {
      printf("\nNome: %sSaldo: %2.f.\n", conta[i].nome, conta[i].saldo);
      printf("Valor do deposito: ");
      scanf("%f", &valor);

      conta[i].saldo = conta[i].saldo + valor;

      printf("Saldo atualizado: %2.f \n ", conta[i].saldo);
    
      enc = 1;
      break;
    }
  }
  
  if(!enc) {
    printf("Conta não encontrada");
  }
  
}

void retirada(client conta[], int num_conta) {
  int i = 0, enc;
  float valor;
  for (; i < 10; i++) {
    if(conta[i].conta == num_conta) {
      printf("\nNome: %sSaldo: %2.f.\n", conta[i].nome, conta[i].saldo);
      printf("Valor da retirada: ");
      scanf("%f", &valor);

      if(conta[i].saldo < valor) {
        printf("Saldo insuficiente");
      } else {
        conta[i].saldo = conta[i].saldo - valor;
        printf("Saldo atualizado: %2.f ", conta[i].saldo);
      }
      enc = 1;
      break;
    }
  }
  
  if(!enc) {
    printf("Conta não encontrada");
  }
}