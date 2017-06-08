#include <stdio.h>
#include <stdlib.h>

#define MAX_FUNCS 20
#define TAM_NOME 20
#define TAM_DNASC 10

//Registro de funcionarios
typedef struct Funcionario {
  char matricula[9];
  float salBruto;
  char nome[TAM_NOME], dataNascimento[TAM_DNASC];
}Funcionario;

//Assinatura das funções
void incluirFuncionario(Funcionario *vetor) {
  int matricula, salBruto;
  char nome[TAM_NOME], dataNascimento[TAM_DNASC];

  //system("cls");
  puts("Insira um número de Matrícula:");
  scanf("%d", &matricula);
  fflush(stdin);

  //Busca no vetor de funcionários se já existe algum registro com o número de matrícula inserido pelo usuário
  for (int i = 0; i < MAX_FUNCS; i++) {
    if (vetor[i].matricula == matricula) {
      puts("ERRO!!! Já existe um registro de funcionário com este num de matrícula!");
      getchar();
      return;
    }
  }
  puts("que que isso"); getchar(); return;
}

//Função Principal
int main() {

  //Declaração de Variáveis
  Funcionario funcionarios[MAX_FUNCS];
  funcionarios[3].matricula = 123456789;
  int opcao;

  //Menu Inicial
  while (1) {
    puts("------------ Sistema de Folha sadasdde Pagamento ------------\n");
    printf("1 - Incluir Funcionário   ");  printf("3 - Consultar Funcionário\n");
    printf("2 - Excluir Funcionário   ");  printf("5 - Ordenar Registros\n");
    printf("4 - Processar Aumento     ");  printf("6 - Imprimir Registros\n\n");

    do {
      printf("> ");
      scanf("%d", &opcao);
      fflush(stdin);

      switch (opcao) {
        case 1:
          incluirFuncionario(funcionarios);
          break;
        case 2:
          //excluirFuncionario();
          break;
        case 3:
          //consultarFuncionario();
          break;
        case 4:
          //processarAumento();
          break;
        case 5:
          //ordernarRegistros();
          break;
        case 6:
          //imprimirRegistros();
          break;
        default:
          puts("Opção Inválida. Por favor, tente novamente!\n");
      }
    } while(opcao < 1 || opcao > 6);

    break;
  }

  return 0;
}
