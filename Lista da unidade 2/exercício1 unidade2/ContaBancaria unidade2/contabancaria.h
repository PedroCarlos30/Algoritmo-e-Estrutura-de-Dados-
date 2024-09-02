#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

typedef struct ContaBancaria ContaBancaria;

ContaBancaria* criaConta(char* titular, int numero, double saldo);
void deposita(ContaBancaria* conta, double valor);
int saca(ContaBancaria* conta, double valor);
int transfere(ContaBancaria* origem, ContaBancaria* destino, double valor);
double saldo(ContaBancaria* conta);
void excluiConta(ContaBancaria* conta);

#endif
