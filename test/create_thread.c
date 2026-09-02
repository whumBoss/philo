#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*say_hello(void *v)
{
	printf("pid : %d\n", getpid());
	return (NULL);
}

int	main(void)
{
	pthread_t	thread1; // crea struc
	pthread_t	thread2;

	// TO DO ==> creer des mutex
	pthread_create(&thread1, NULL, &say_hello, NULL); // init struct, lancement thread
	pthread_create(&thread2, NULL, &say_hello, NULL);
	pthread_join(thread1, NULL); // wait pour la fin d'execution du thread
	pthread_join(thread2, NULL);
	return (0);
}

