#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	mails = 0;
pthread_mutex_t	mutex; // creation de la structure mutex

void	*say_hello(void *v)
{
	int i = 0;
	while (i < 1000000)
	{
		pthread_mutex_lock(&mutex); 
		// check si le mutex est verouiller
		// wait jusqu'a ce que le mutex soit verouiller
		// verouiller le mutex
		mails++;
		i++;
		pthread_mutex_unlock(&mutex);
		// deverouiller le mutex
	}
	return (NULL);
}

int	main(void)
{
	pthread_t	threads[4];
	int			i = 0;

	pthread_mutex_init(&mutex, NULL); 
	while (i < 4) // une boucle pour creer tout les mutex
	{
		if (pthread_create(&threads[i], NULL, &say_hello, NULL) != 0) // or threads + i
		{
			printf("fail creat thread\n");
			return 1;
		}
		i++;
	}
	i = 0;
	while (i < 4) // une boucle pour wait tout les mutex
	{
		if (pthread_join(threads[i], NULL) != 0)
			return 1;
		i++;
	}
	// !! Attention : pas creat et join dans la meme boucle
	// sinon ==> exectution en sequenciel
	// interet des threads : exectution en paralleles, m timeline
	// si threads sequenciel ==> aucun interet
	pthread_mutex_destroy(&mutex);
	printf("mails: %d\n", mails);
	return (0);
}
