#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void	*roll_dice(void *v)
{
	// tester de malloc dice, et de remplir en le dereferencer
	int dice = (rand() % 6) +1; //genere un nb aleatoire, type int
	int	*res = malloc(sizeof(int)); 
	// on a besoin de renvoyer un pointeur
	// car la variable propre a la fonction vas disparaitre
	// sauf si c'est un pointeur qui a ete malloc

	*res = dice; // mettre le int dans le pointeur

	return ((void *) res); // caster le retour 
}

int	main(void)
{
	pthread_t	threads[4];
	int			i = 0;
	int			*result[4]; // tableaux de pointeur de int pour recup le resultat

	while (i < 4)
	{
		if (pthread_create(&threads[i], NULL, &roll_dice, NULL) != 0)
		{
			printf("fail creat thread\n");
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(threads[i], (void *)&result[i]) != 0) 
			// envoyer l'adrs du pointeur pour recup le resultat 
			// + caster pour eviter les flag
			return 1;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		printf("result[%d] = %d\n", i, *result[i]);
		free(result[i]); // free car le pointeur a ete malloc dans roll_dice
		i++;
	}
	return (0);
}
