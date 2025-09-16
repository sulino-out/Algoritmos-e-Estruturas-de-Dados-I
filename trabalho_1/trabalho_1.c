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
void busca_binaria_recursiva(int vetor[], int elemento, int inicio, int fim);

// Função main
int main()
{
	// Declara as variáveis
	int opcao; 
	int num_elementos; 
	int elemento;
	int inicio;
	int fim;
	
	// Pede o tamanho do vetor
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &num_elementos);

	int *vetor = (int *) malloc(sizeof(int) * num_elementos); // Aloca memória dinâmicamente com tamanho 'num_elementos'
	
	printf("Digite os elementos do vetor: ");
	// Pede por cada um dos elementos do vetor
	for(int i = 0; i < num_elementos; i++)
	{
		scanf("%d", &vetor[i]);
	}

	// Itera até que a opção saída seja escolhida
	do
	{	
		// Imprime as opções
		printf("=-=-=-=-= Inversão e Busca =-=-=-=-=\n");
		printf("1. Inversão da ordem do vetor de entrada\n");
		printf("2. Busca Sequencial no vetor de entrada\n");
		printf("3. Busca Binária Iterativa no vetor de entrada\n");
		printf("4. Busca Binária Recursiva no vetor de entrada\n");
		printf("5. Encerrar programa.\n");
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

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
				inicio = 0;
				fim = num_elementos - 1;

				busca_binaria_recursiva(vetor, elemento, inicio, fim);
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

	// Libera a memória alocada
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

void busca_binaria_recursiva(int vetor[], int elemento, int inicio, int fim)
{
	/* Casos base */

	if(fim < inicio) // Caso 1: Posicao final é menor que a posicao inicial (Elemento nao encontrado)
	{
		printf("NAO\n");
		return;
	}

	int meio = inicio + ((fim - inicio) / 2); // Define a posicao intermediária do vetor
	
	if(vetor[meio] == elemento) // Caso 2: Elemento central do vetor é igual ao desejado (Elemento encontrado)
	{
		printf("SIM\n");
		return;
	}

	/* Caso recursivo */

	// Declara as variaveis para os novos novo_inicio e novo_fim
	int novo_inicio = inicio;
	int novo_fim = fim;

	if(vetor[meio] < elemento) // Se o elemento central do vetor for menor que o elemento, corta a metade da esquerda
	{
		novo_inicio = meio + 1;
	}
	else if(vetor[meio] > elemento) // Se o elemento central do vetor for maior que o elemento, corta a metade da direita
	{
		novo_fim = meio - 1;
	}

	busca_binaria_recursiva(vetor, elemento, novo_inicio, novo_fim); // Chama recursivamente a funcao
}
