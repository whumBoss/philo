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
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_mutex_init(&mutex, NULL); 
	// initialisation de la structure mutex ==> creation du mutex 
	// avant l'initialisation et le lancement du thread
	if (pthread_create(&thread1, NULL, &say_hello, NULL) != 0)
		return 1;
	if (pthread_create(&thread2, NULL, &say_hello, NULL) != 0)
		return 2;
	if (pthread_join(thread1, NULL) != 0)
		return 3;
	if (pthread_join(thread2, NULL) != 0)
		return 4;
	pthread_mutex_destroy(&mutex);
	// close le mutex
	printf("mails: %d\n", mails);
	return (0);
}
