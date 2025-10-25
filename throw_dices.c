#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

static void	loading_bar(int dices)				// animación de carga
{
	int steps = 15;
	int display = (dices > 10) ? 10 : dices;

	for (int i = 0; i < steps; i++)
	{
		printf("\r\033[K");
		printf("n ");
		for (int j = 0; j < display; j++)
		{
			int random = 1 + rand() % 6;
			printf("%d ", random);
		}
		if (dices > display)
			printf("...");
		fflush(stdout);
		usleep(50000 + (i * 5000));
	}
	// limpiar la línea final
	printf("\r\033[K\n");
	fflush(stdout);
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
		scanf(" %c", &c);
		while (getchar() != '\n');
		if (c == 'Y' || c == 'y')
			return (true);
		else if (c == 'N' || c == 'n')
			return (false);
		else
			printf("Comando desconocido. Por favor ingresa Y o N.\n");
	}
}

static void	validate_input(int *dices)	// parseo de input
{
	while (1)
		{
			printf("Cuantos dados vas a tirar?\n");
			
			if (scanf("%d", dices) == 1 && *dices > 0)
			{
				if (*dices < 100){
					while (getchar() != '\n');
					break ;
				}
				printf("No hay suficientes dados en la mesa!\n\n");
			}
			else
			{
				printf("Introduce un número válido mayor a 0.\n\n");
				while (getchar() != '\n');
			}
		}
}

int main()
{
	int	dices = 0;
	srand(time(NULL));
	do
	{
		validate_input(&dices);
		loading_bar(dices);
		throws(dices);
	} while (rerun());
	return (0);
}
