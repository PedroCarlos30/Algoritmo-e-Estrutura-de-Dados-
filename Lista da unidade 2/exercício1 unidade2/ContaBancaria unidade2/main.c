#include <stdio.h>
#include "contabancaria.h"

int main() {
    ContaBancaria* conta1 = criaConta("João", 12345, 1000.0);
    ContaBancaria* conta2 = criaConta("Maria", 67890, 500.0);

    deposita(conta1, 500.0);
    saca(conta2, 200.0);
    transfere(conta1, conta2, 300.0);

    printf("Saldo da conta 1: %.2lf\n", saldo(conta1));
    printf("Saldo da conta 2: %.2lf\n", saldo(conta2));

    excluiConta(conta1);
    excluiConta(conta2);

    return 0;
}
