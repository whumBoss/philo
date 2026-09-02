#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int primes[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
// tableau de int differentes valeurs

void* routine(void* arg)
{
    int index = *(int*)arg;
	// l'arg est utilise comme un index
	// la fonction a recus l'arg sous forme void pointeur
	// il faut caster le void* en int* soit: (int*)arg
	// et il faut dereferencer le int* pour assigner la valeur int
	// soit *arg
    printf("%d ", primes[index]); 
	// comment ca ce fait que les appelle de printf sont pas intremeler, 
	// chaque printf se deroule l'un apres l'autre alors que les threads 
	// se deroule en meme temps
    free(arg); // free le malloc des qu'on a fini de l'utiliser
	return (NULL);
}

int main(int argc, char* argv[]) {
    pthread_t th[10]; // 10 threads
    int i;
    for (i = 0; i < 10; i++) 
	{
        int* a = malloc(sizeof(int)); 
		// si j'envoie l'adresse de i, i vas etre incrementer, 
		// donc la valeur de i ne sera plus la meme lors de 
		// l'utilisation de la variable par le thread

        *a = i;
		// donc dans mon pointeur de int qui a ete malloc
		// je met la valeur de i;
		// et j'envoie ce pointeur qui renvoie vers la bonne valeur
		// (c'est bien la valeur du int et pas l'adrs de la variable
		
        if (pthread_create(&th[i], NULL, &routine, a) != 0) // envoie a
		{
            perror("Failed to created thread");
        }
    }
	// comment ca se passe le fait que on fait malloc sur malloc
	// avec des variable qui ont le meme nom??
	// ca en creer des differentes visiblement, a differentes adrs, pas d'ecrasement
	// mais thecniquement quand tu fait ca, tu ne peux plus avoir acces a ta variable
	// a la limite tu peux appeler les variable en boucle puis les free
	// pour consulter chaqu'une d'entre elles 
	// mais complique de les utiliser librement 
	// vu que tu les appeles avec le meme nom

    for (i = 0; i < 10; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    } 
    return 0;
}
