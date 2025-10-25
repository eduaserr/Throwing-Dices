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

static void	loading_bar(int faces, int dices)
{
	int steps = 15;
	int display = (dices > 10) ? 10 : dices;
	for (int i = 0; i < steps; i++)
	{
		printf("\r\033[K");
		for (int j = 0; j < display; j++)
		{
			int random = 1 + rand() % faces;
			printf("%d ", random);
		}
		if (dices > display)
			printf("...");
		fflush(stdout);
		usleep(50000 + (i * 5000));
	}
	printf("\r\033[K\n");
	fflush(stdout);
}

static void	dice(int faces)
{
	int random = 1 + rand() % faces;
	printf(" %d\n", random);
}

static void	throws(int faces, int dices)
{
	for (int i = 0; i < dices; i++)
	{
		printf("El %dº dado es: ", i + 1);
		dice(faces);
	}
}

static bool	rerun(void)
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

static void	validate_input(int *faces, int *dices)
{
	while (1)
	{
		printf("De cuantas caras va a ser el dado? (3-999)\n");
		int ret = scanf("%d", faces);
		clear_stdin();
		if (ret != 1)
		{
			printf("Entrada inválida. Introduce un número.\n\n");
			continue;
		}
		if (*faces >= 3 && *faces <= 999)
			break;
		printf("Número fuera de rango. Introduce entre 3 y 999.\n\n");
	}
	while (1)
	{
		printf("Cuantos dados vas a tirar? (1-99)\n");
		int ret = scanf("%d", dices);
		clear_stdin();
		if (ret != 1)
		{
			printf("Entrada inválida. Introduce un número.\n\n");
			continue ;
		}
		if (*dices >= 1 && *dices <= 99)
			break ;
		printf("Número fuera de rango. Introduce entre 1 y 99.\n\n");
	}
}

int main(void)
{
	int	dices = 0;
	int faces = 0;
	srand(time(NULL));
	do
	{
		validate_input(&faces, &dices);
		loading_bar(faces, dices);
		throws(faces, dices);
	} while (rerun());
	return 0;
}
