/*Arquivo cabeçalho para topo 
abstrato de dados (TAD) Aluno*/
typedef struct aluno Aluno;

/*Função que aloca dinamicamente uma
struct aluno na memoria.*/
Aluno*aloca_aluno(void);

/*Função para preenche uma struct Aluno. 
A função recebe um endereço para aluno.*/
void preenche (Aluno*aluno);

/*Função para imprimir uma
struct Aluno. A função recebe um
enderço para aluno e imprime os dados.*/
void imprime(Aluno*aluno);