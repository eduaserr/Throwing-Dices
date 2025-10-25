#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static void clear_stdin(void)
{
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

static void	loading_bar()				// animación de carga
{
	int i = 0;

	while (i++ < 15)
	{
		int random = 1 + rand() % 6;
		printf("\r%d", random);
		fflush(stdout);
		usleep(50000 + (i * 5000));
	}
	printf("\r");
}

static void	dice()						// generador de numero
{
	int random = 1 + rand() % 6;
	printf(" %d\n", random);
}

static void	throws(int dices)			// numero de tiradas
{
	int i = 0;
	while (i < dices)
	{
		printf("El %dº dado es: ", i + 1);
		dice();
		i++;
	}
}

static bool	rerun()						// repetir programa
{
	char c;
	while (1)
	{
		printf("Quieres tirar de nuevo? Y/N\n");
		if (scanf(" %c", &c) != 1)
		{
			clear_stdin();
			return false;
		}
		clear_stdin();
		if (c == 'Y' || c == 'y')
			return true;
		else if (c == 'N' || c == 'n')
			return false;
		else
			printf("Comando desconocido. Por favor ingresa Y o N.\n");
	}
}

static void	validate_input(int *dices)	// parseo de input
{
	while (1)
	{
		printf("Cuantos dados vas a tirar? (1-99)\n");
		int ret = scanf("%d", dices);
		clear_stdin();
		if (ret != 1)
		{
			printf("Entrada inválida. Introduce un número.\n\n");
			continue;
		}
		if (*dices >= 1 && *dices < 100)
			break;
		
		if (*dices >= 100)
			printf("No hay suficientes dados en la mesa! (máximo 99)\n\n");
		else
			printf("Introduce un número válido mayor a 0.\n\n");
	}
}

int main()
{
	int	dices = 0;
	srand(time(NULL));
	do
	{
		validate_input(&dices);
		loading_bar();
		throws(dices);
	} while (rerun());
	return (0);
}