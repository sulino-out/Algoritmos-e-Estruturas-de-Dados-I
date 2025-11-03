// Inclusao de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

// Convencoes de retorno
#define FALSE 0
#define TRUE 1
#define ERROR -1
#define INVALID 0
#define SUCCESS 1
#define LOWER 2
#define EQUAL 3
#define HIGHER 4
// Pseudo-variáveis
#define MAX_DIGITS 256

// Protótipo de funcoes


int main()
{
	// Lê a quantidade de operacoes
	int n;
	scanf("%d", &n);

	// Realiza 'n' operacoes
	while(n--) 
	{
		// Recebe a operacao desejada
		char* operacao = malloc(sizeof(char) * 6); // 6 bytes; 5 para o nome da operacao e 1 para o '\0'
		scanf("%s", operacao);

		// Cria duas listas encadeadas e lê o número a ser inserido nelas
		LinkedList *number1 = create_linked_list();
		if(read_number(number1) != SUCCESS)
		{
			printf("Falha ao ler o numero.\n");
			return 1;
		}

		LinkedList *number2 = create_linked_list();
		if(read_number(number2) != SUCCESS)
		{
			printf("Falha ao ler o numero.\n")
			return 1;
		}

		// Executa a operacao desejada
		if(!strcmp(operacao, "soma")) // Soma os dois números
		{
			LinkedList *soma = create_linked_list();
			
			if(sum_numbers(number1, number2, soma) != SUCCESS)	
			{
				printf("Erro ao somar os numeros.\n");
				return 2;
			}

			free_linked_list(&soma);
		}
		else if(!strcmp(operacao, "menor")) // Diz se o primeiro número é menor
		{
			printf("Resultado :: ");

			if(compare_numbers(number1, number2) == LOWER)
			{
				printf("True\n");
			}
			else
			{
				printf("False\n");
			}
		}
		else if(!strcmp(operacao, "igual")) // Diz se os números sao iguais
		{
			printf("Resultado :: ");

			if(compare_numbers(number1, number2) == EQUAL)
			{
				printf("True\n");
			}
			else
			{
				printf("False\n");
			}
		}
		else if(!strcmp(operacao, "maior")) // Diz se o primeiro número é maior
		{
			printf("Resultado :: ");

			if(compare_numbers(number1, number2) == HIGHER)
			{
				printf("True\n");
			}
			else
			{
				printf("False\n");
			}
		}
		else // Operacao inválida
		{
			printf("Operacao invalida.\n");
		}

		free(operacao);
		free_linked_list(&number1);
		free_linked_list(&number2);
	}

	return 0;
}

// Funcoes principais

// Lê o número do stdin e converte para lista encadeada
int read_number(LinkedList *list)
{
	// Verifica se a lista foi inicializada
	
	// Recebe o número como uma string de MAX_DIGITS caracteres, alocada dinamicamente
	
	// Verifica se todos os caracteres sao digitos

	// Converte a string para uma lista encadeada com blocos de 4 digitos

	// Libera a memória alocada para a string
}

// Soma dois números
int sum_numbers(const LinkedList *number1, const LinkedList *number2, LinkedList *sum)
{
	// Verifica se todas as listas foram inicializadas
	
}

// Compara o primeiro número com o segundo e retorna LOWER, EQUAL ou HIGHER
int compare_numbers(const LinkedList *number1, const LinkedList *number2)
{
	// Verifica se todas as listas foram inicializadas

}

// Funcoes auxiliares
