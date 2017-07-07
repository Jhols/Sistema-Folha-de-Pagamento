#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Constantes
#define MAX_FUNCS 20
#define TAM_MATRICULA 10
#define TAM_NOME 20
#define TAM_DNASC 10

//Registro de funcionarios
typedef struct Funcionario {
  char matricula[TAM_MATRICULA];
  float salBruto;
  char nome[TAM_NOME], dataNascimento[TAM_DNASC];
  int preenchido;
} Funcionario;

//Assinatura das funções
//Função que inclui um funcionário ao vetor de funcionários
void incluirFuncionario(Funcionario *vetor) {
  //Declaração de um funcionário auxiliar
  Funcionario func;

  //system("cls");
  printf("\nInsira um número de Matrícula:\n> ");
  gets(func.matricula); //Captura a string digitada pelo usuário e atribui à matricula do funcionario auxiliar
  setbuf(stdin, NULL); //Limpa o Buffer do Teclado de forma segura
  //Busca no vetor de funcionários se já existe algum registro com o número de matrícula inserido pelo usuário
  for (int i = 0; i < MAX_FUNCS ; i++) {
    if (!strcmp(vetor[i].matricula, func.matricula)) {
      puts("ERRO!!! Já existe um registro de funcionário com este número de matrícula!");
      getchar();
      return;
    }
  }

  //Inicio - Coleta dos dados do novo funcionário
  puts("\nDigite o Nome do Funcionário:");
  do {
    printf("> ");
    gets(func.nome);
    setbuf(stdin, NULL);
    if (!strcmp(func.nome, "")) { //Se o usuário não digitar um nome, o programa solicitará para pôr novamente
      puts("Campo Obrigatório! Por favor, digite um nome:");
    }
  }while (!strcmp(func.nome, ""));

  puts("\nDigite a Data de Nascimento: Formato[dd/mm/aaaa]");
  do {
    printf("> ");
    gets(func.dataNascimento);
    setbuf(stdin, NULL);
    if (!strcmp(func.dataNascimento, "")) {
      puts("Campo Obrigatório! Por favor, digite uma Data de Nascimento:");
    }
  }while (!strcmp(func.dataNascimento, ""));

  puts("\nDigite o valor do Salário Bruto:");
  do {
    printf("> ");
    scanf("%f", &func.salBruto);
    setbuf(stdin, NULL);
    if (func.salBruto < 0) {
      puts("ERRO!!! Valor do Salário Bruto inválido! Por favor, insira um valor positivo.");
    }
  }while(func.salBruto < 0);
  //Fim - Coleta dos dados do novo funcionário

  //Busca o último elemento preenchido do vetor
  int i=0;
  for (int j = 0; j < MAX_FUNCS; j++)
    if (vetor[i].preenchido != 0)
      i++;

  //Inserção dos dados coletados no vetor de funcionários
  strcpy(vetor[i].matricula, func.matricula);
  strcpy(vetor[i].nome, func.nome);
  strcpy(vetor[i].dataNascimento, func.dataNascimento);
  vetor[i].salBruto = func.salBruto;
  vetor[i].preenchido = 1;

  //Conclusão da inserção
  puts("\nNovo funcionário adicionado!");
  getchar();

}

//Função que remove um funcionário do vetor de funcionários
void excluirFuncionario(Funcionario *vetor) {
  Funcionario funcs[MAX_FUNCS];
  char opcao;
  int flag;

  //system("cls");
  do {
    puts("Digite a matrícula do Funcionário a ser removido:");
    flag = 0;
    printf("> ");
    setbuf(stdin, NULL);
    scanf("%s", funcs[0].matricula);
    setbuf(stdin, NULL);

    //Percorre o vetor à procura do funcionário com a matricula digitada acima
    for (int i = 0; i < MAX_FUNCS; i++) {
      if (!strcmp(funcs[0].matricula, vetor[i].matricula)) {
        printf("\nFuncionário %s removido!", vetor[i].nome);
        vetor[i].preenchido = 0; //Exclusão do funcionário
        flag = 1;
      }
    }

    if (flag) {
      /*Se encontrar, os dados do vetor de funcionários serão alocados num vetor auxiliar.
      Essa estratégia serve para tirar quaisquer buracos que fiquem no vetor de funcionarios*/
      int k=0;
      for (int j = 0; j < MAX_FUNCS; j++) {
        if (vetor[j].preenchido == 1) {
          strcpy(funcs[k].matricula, vetor[j].matricula);
          strcpy(funcs[k].nome, vetor[j].nome);
          strcpy(funcs[k].dataNascimento, vetor[j].dataNascimento);
          funcs[k].salBruto = vetor[j].salBruto;
          funcs[k].preenchido = vetor[j].preenchido;
          k++;
        }
      }

      /*Reinserção dos elementos do vetor de funcionários. Dessa vez sem o buraco causado pela exclusão
      do elemento no "For" anterior.*/
      for (int j = 0; j <= k; j++) {
        strcpy(vetor[j].matricula, funcs[j].matricula);
        strcpy(vetor[j].nome, funcs[j].nome);
        strcpy(vetor[j].dataNascimento, funcs[j].dataNascimento);
        vetor[j].salBruto = funcs[j].salBruto;
        vetor[j].preenchido = funcs[j].preenchido;
      }

      //Remoção concluída
      getchar();
      return;
    }

    printf("\nFuncionário não encontrado! Deseja procurar novamente? (S/N)\n> ");
    scanf("%c", &opcao);
    setbuf(stdin, NULL);
    toupper(opcao);

  } while(opcao == 'S');
}

//Função que realiza consulta de um funcionário no vetor de funcionários
void consultarFuncionario(Funcionario *vetor) {
  Funcionario func;
  char opcao;

  //system("cls");
  puts("Digite a matrícula do Funcionário a ser consultado:");
  do {
    printf(">");
    gets(func.matricula);
    setbuf(stdin, NULL);

    for (int i = 0; i < MAX_FUNCS; i++) {
      if (!strcmp(func.matricula, vetor[i].matricula)) {
        printf("\n--- Dados do Funcionário ---\n");
        printf("Funcionário: %d\n", i+1);
        printf("Matrícula: %s\n", vetor[i].matricula);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Data de Nascimento: %s\n", vetor[i].dataNascimento);
        printf("Salário Bruto: %.2f\n", vetor[i].salBruto);

        getchar();
        return;
      }
    }

    printf("\nFuncionário não encontrado! Deseja procurar novamente? (S/N)\n> ");
    scanf("%c", &opcao);
    setbuf(stdin, NULL);
    toupper(opcao);

  } while(opcao == 'S');


}

//Função que aumenta o valor do salário bruto dos funcionários de acordo com um percentual
void processarAumento(Funcionario *vetor, int percentual) {
  int i=0;
  while (vetor[i].preenchido) {
    vetor[i].salBruto += (vetor[i].salBruto * percentual)/100;
    i++;
  }
}

//Função de Ordenamento dos Registros dos Funcionários
void ordenarRegistros(){
//qualquer coisa
}


//Função que imprime todos os registros de funcionários do vetor
void imprimirRegistros(Funcionario *vetor) {
  int i = 0;
  while (i < MAX_FUNCS) {
    if (vetor[i].preenchido == 1)
      printf("pos: %d Nome: %s\n", i, vetor[i].nome);
    i++;
  }
  printf("\n\n");
}

//Função Principal
int main() {

  //Declaração de Variáveis
  Funcionario funcionarios[MAX_FUNCS];
  int opcao;

  for (int i = 0; i < MAX_FUNCS; i++) {
    funcionarios[i].preenchido = 0;
  }

  strcpy(funcionarios[2].matricula, "123");
  strcpy(funcionarios[2].nome, "João Pedro");
  strcpy(funcionarios[2].dataNascimento, "25/01/1997");
  funcionarios[2].salBruto = 50;
  funcionarios[2].preenchido = 1;

  strcpy(funcionarios[0].matricula, "111");
  strcpy(funcionarios[0].nome, "Pedro");
  strcpy(funcionarios[0].dataNascimento, "25/01/1997");
  funcionarios[0].salBruto = 50;
  funcionarios[0].preenchido = 1;

  strcpy(funcionarios[1].matricula, "222");
  strcpy(funcionarios[1].nome, "Jorge");
  strcpy(funcionarios[1].dataNascimento, "25/01/1997");
  funcionarios[1].salBruto = 50;
  funcionarios[1].preenchido = 1;

  strcpy(funcionarios[3].matricula, "333");
  strcpy(funcionarios[3].nome, "Marcos");
  strcpy(funcionarios[3].dataNascimento, "25/01/1997");
  funcionarios[3].salBruto = 50;
  funcionarios[3].preenchido = 1;

  strcpy(funcionarios[4].matricula, "444");
  strcpy(funcionarios[4].nome, "Carlos");
  strcpy(funcionarios[4].dataNascimento, "25/01/1997");
  funcionarios[4].salBruto = 50;
  funcionarios[4].preenchido = 1;

  //Menu Inicial
  while (1) {
    puts("------------ Sistema de Folha sadasdde Pagamento ------------\n");
    printf("1 - Incluir Funcionário   ");  printf("4 - Processar Aumento     ");
    printf("2 - Excluir Funcionário   ");  printf("5 - Ordenar Registros\n");
    printf("3 - Consultar Funcionário\n"); printf("6 - Imprimir Registros\n\n");

    do {
      printf("> ");
      scanf("%d", &opcao);
      setbuf(stdin, NULL); //Limpa o Buffer do teclado de forma segura

      switch (opcao) {
        case 1:
          incluirFuncionario(funcionarios);
          break;
        case 2:
          excluirFuncionario(funcionarios);
          break;
        case 3:
          consultarFuncionario(funcionarios);
          break;
        case 4:
          processarAumento(funcionarios, 20);
          break;
        case 5:
          //ordernarRegistros();
          break;
        case 6:
          imprimirRegistros(funcionarios);
          break;
        default:
          puts("Opção Inválida. Por favor, tente novamente!\n");
      }
    } while(opcao < 1 || opcao > 6);

  }

  return 0;
}
