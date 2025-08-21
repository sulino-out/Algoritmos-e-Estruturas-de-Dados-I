// Nome dos integrantes e número USP

// -
// -
// -

// Inclusão de bibliotecas
#include <stdio.h>

// Definição de constantes

// Protótipo de funções
void inverter_ordem(int vetor[], int n);
void busca_sequencial(int vetor[], int n);
void busca_binaria_iterativa(int vetor[], int n);
void busca_binaria_recursiva(int vetor[], int n);

// Função main
int main()
{
	int opcao; // Cria a variável para armazenar a opção do menu
	int num_elementos; // Cria a variável para armazenar o número de elementos do vetor
	
	scanf("%d", &num_elementos);

	int *vetor = (int *) malloc(sizeof(int) * num_elementos); // Aloca memória dinâmicamente com tamanho 'num_elementos'

	// Intera até que a opção saída seja escolhida
	do
	{	
		// Imprime as opções
		printf("=-=-=-=-= Inversão e Busca =-=-=-=-=\n");
		printf("1. Inversão da ordem do vetor de entrada\n");
		printf("2. Busca Sequencial no vetor de entrada\n");
		printf("3. Busca Binária Iterativa no vetor de entrada\n");
		printf("4. Busca Binária Recursiva no vetor de entrada\n");

		scanf("%d", &opcao); // Pede a opção a usuário

		// Executa a operação selecionada
		switch(opcao)
		{
			case 1: 
				// Inverter a ordem do vetor
				inverter_ordem(vetor, num_elementos);
				break;
			case 2:
				// Busca sequencial no vetor
				busca_sequencial(vetor, num_elementos);
				break;
			case 3:
				// Busca binária iterativa no vetor
				busca_binaria_iterativa();
				break;
			case 4:
				// Busca binária recursive no vetor
				busca_binaria_recursiva();
				break;
			case 5:
				// Encerrar programa
				printf("Saindo...\n");
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}

	}while(opcao != 5);

	return 0;
}

// Outras funções
void inverter_ordem(int vetor[], int n)
{

}

void busca_sequencial(int vetor[], int n)
{

}

void busca_binaria_iterativa(int vetor[], int n)
{

}

void busca_binaria_recursiva(int vetor[], int n)
{

}
