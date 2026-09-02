
/*						 === PSEUDO CODE === 
 *
 * JE LANCE MON PROG 
 * ./philo nb_philo time_die time_eat time_sleep nb_meal_per_philo
 *
 * ac = min 5, max 6
 *
 * av = [./philo], [nb_philo], [time_die], [time_eat], [time_sleep], [nb_meal_per_philo]
 * tous en char, il faut le transformer en long au moment de l'assignation dans la struc data
 *
 * j'ai [nb_philo] de philosopher, mes philo sont des thread.
 * 
 *
 *						 === DANS MON MAIN ===
 * {
 * ---------- INITIALISATION ET PARSING -----------------
 *
 *	 je creer ma structure data (variable simple contient qu'une seule struct)
 *	 et ma structure *philo (tableau contient plrs struct philo)
 *
 *
 *	 verifier min et max de ac soit respecter (sinon pas d'interet de continuer le prog)
 *
 *
 *	 dans data : je transforme, j'assigne et je valide les valeurs lu dans av, grace a la fontion init_valid_data()
 *
 *
 *	 j'ai des mutex dans ma structure data, ils sont deja creer, il faut juste les initialiser
 * soit init_mutex_data() ==> initialistion de tout le mutex avec pthread_mutex_init()
 *
 *
 *	 dans le pointeur : *les_philos
 *	 on stocke chaque structure t_philo dans un meme tableau
 *	 le tableau *les_philo sera malloc pour le conserver toutes les struct et leurs champ dans la heap
 *	 (l'interet, la heap garantit un seul espace memoir, commun a tout les threads, donc modifications effectuee dans un thread, 
 *	 sera present dans tout les autres threads)
 *	 soit :
 *	 *les_philo = init_les_philos()
 * 
 *		== DANS INIT_LES_PHILOS ==
 *		{
 *			on malloc pointeur pour qu'ils contienne [nb_philos] de t_philo
 *			les thread philo sont contenue dans les struct t_philo
 *			et on initialise en boucle chaque t_philo
 *			tout les param init a 0
 *			sauf :
 *			data = data
 *			id = i + 1
 *			right fork = data.fork[i]
 *			left fork = data.fork[(i + 1) % nb_philo]
 *				or nb_philo = 1 donc left fork = NULL
 *			return (*les_philos)
 *		}
 *
 *	 j'ai egalement des mutex dans mes philos, ils sont creer, a initialiser donc :
 *	 init_mutex_philos() ==> init tout les mutex avec pthread_mutex_init()
 *
 *
 * ------------- EXECUTION DES ROUTINES ---------------
 *
 *	threads have been created but not started
 *	you want to get the time right before beginning to start the threads
 *
 *	== DANS START PHILO THREAD ==
 *	{
 *		create a pointer to the pointer of data, found in philo[i]
 *		assign get_time in data->start_time
 *		(so we know at what time we begun to start all the philos)
 *
 *		in a while loop
 *		{
 *			start every thread of every philo[i] with the fonction routine() and as arguments philo[i]
 *			don't forget to verify that it does not return 0
 *		}
 *	}
*	(verify return value)

*	==DANS START MONITOR THREAD ==
*	{
*		pthread_create(routine_monitor())
*		pthread_join the monitor thread found in data
*	}
*	(verify return value)

*	finish by clearing everything
*	}
*
*					=== DANS LES ROUTINES ===
*
*	les philos routines ont lieu en paralleles les une des autre
*	idem pour monitor routine
*
*	== PHILOS ROUTINE ==
*	{
*		la structure recu en arg est caster void : faut la recaster en struct philo
*		
*		si l'id du philo est impaire : on veut qu'il attende avant de manger 
*		
*
*	}
*
*	== MONITOR ROUTINE ==
*

 */

