// Nome dos integrantes e número USP

// -
// -
// -

// Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definição de constantes

// Protótipo de funções
void inverter_ordem(int vetor[], int n);
void busca_sequencial(int vetor[], int n);
void busca_binaria_iterativa(int vetor[], int n);
void busca_binaria_recursiva(int vetor[], int elemento, int l, int r);

// Função main
int main()
{
	int opcao; // Cria a variável para armazenar a opção do menu
	int num_elementos; // Cria a variável para armazenar o número de elementos do vetor
	int elemento;
	int left;
	int right;
	
	// Pede o tamanho do vetor
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &num_elementos);

	int *vetor = (int *) malloc(sizeof(int) * num_elementos); // Aloca memória dinâmicamente com tamanho 'num_elementos'
	
	// Pede por cada um dos elementos do vetor
	for(int i = 0; i < num_elementos; i++)
	{
		printf("Digite o elemento %d: ", i);
		scanf("%d", &vetor[i]);
	}

	// Intera até que a opção saída seja escolhida
	do
	{	
		// Imprime as opções
		printf("=-=-=-=-= Inversão e Busca =-=-=-=-=\n");
		printf("1. Inversão da ordem do vetor de entrada\n");
		printf("2. Busca Sequencial no vetor de entrada\n");
		printf("3. Busca Binária Iterativa no vetor de entrada\n");
		printf("4. Busca Binária Recursiva no vetor de entrada\n");
		printf("5. Encerrar programa.\n");

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
				busca_binaria_iterativa(vetor, num_elementos);
				break;
			case 4:
				// Busca binária recursive no vetor
				scanf("%d", &elemento);
				left = 0;
				right = num_elementos - 1;

				busca_binaria_recursiva(vetor, elemento, left, right);
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

	free(vetor);
	vetor = NULL;

	return 0;
}

// Outras funções
void inverter_ordem(int vetor[], int n)
{
	// Imprime o vetor na ordem inversa
	for (int i = n-1; i >= 0; i--)
	{
		printf ("%d", vetor[i]);
		if (i > 0)
		{
			printf (" "); // Imprime espaço entre os números, mas nao depois do ultimo
		}
	}

	printf("\n"); // Imprime uma quebra de linha ao final
}

void busca_sequencial(int vetor[], int n)
{
	int elementos;

	scanf ("%d", &elementos);

	for(int i = 0; i < n; i++){ // Percorre todos os elementos do vetor
		if (vetor[i] == elementos){
			printf ("SIM\n"); // Se tiver um elemento no vetor igual ao elemento que queremos procurar, imprime "SIM"
			return;
		} 	
	} 
	printf ("NAO\n");

}

void busca_binaria_iterativa(int vetor[], int n)
{
	
}

void busca_binaria_recursiva(int vetor[], int elemento, int l, int r)
{
	/* Casos base */

	if(r < l) // Caso 1: Left é maior que right (elemento nao encontrado)
	{
		printf("NAO\n");
		return;
	}

	int middle = l + ((r - l) / 2); // Define a posicao intermediária do vetor
	
	if(vetor[middle] == elemento) // Caso 2: Elemento encontrado
	{
		printf("SIM\n");
		return;
	}

	/* Caso recursivo */

	// Declara as variaveis para os novos left e right
	int left = l;
	int right = r;

	if(vetor[middle] < elemento) // Se o elemento central do vetor for menor que o elemento, corta a metade da esquerda
	{
		left = middle + 1;
	}
	else if(vetor[middle] > elemento) // Se o elemento central do vetor for maior que o elemento, corta a metade da direita
	{
		right = middle - 1;
	}

	busca_binaria_recursiva(vetor, elemento, left, right); // Chama recursivamente a funcao
}
