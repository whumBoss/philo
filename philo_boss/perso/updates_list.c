// === 12 aout mardi ===
//
// etape init and valid values de data : FINI
// compilee et fonctionnel
//
// prochaines etapes :
// - makefile
// - init les mutex de data
//
//
// === 15 aout sam ===
//
// makefile fonctionnel 
// ft_strlen ajouter
// macros msg d'erreurs
//
//
// === 16 aout dim ===
//
// initialisation des mutex de data
// initialisation des philos
// et des mutex de philo
// lancement des threads philos
// 
// prochaines etapes :
// - fonction utils pour recuperer l'heure et le transformer
// - comprendre les routines
// - reorga des fonctions/ du main
// - testssss
//
// === 19 aout mer ===
// 
// fontion heure
// reorga main et parsing
//
// === 20 aout jeu ===
//
//	testssss
//
//	=== 29 aout sam ===
//
//	pseudo code et comprehension routines
//
//	=== 31 aout lun ===
//
//	
//	TO DO :
//	- partir du lancement des philos, passer a la fonction routine et avancer sur sur toutes fonctions qui suivent pour que l'exec des philos soit complete (en psuedo code deja)
//	- revenir sur begin monitor et la routine monitor, verif ce qui manque et pseudo coder.
//	- verif les fichier init pour initialiser les param ajouter en dernier
//
//	=== 02 sept mer ===
//
//	avancement sur eating, print actions et clear un peu
//	prochaine etapes : tester make
//
//	=== 03 sept jeu ===
//
//	fini clear, makefile doesn't work, taking fork done.
//	
//	prochaine etape : regler le pb du makefile et faire update_value
//
//	=== 04 sept ven ===
//
//	makefile working, update value et last meal
//
//	prochaine etape : tester eating, mettre le monitor en marche
//	 pour voir comment ca se passe avec juste eating et monitor
//
//	 === 07 sept lun ===
//
//	fonctions du monitor casi fini avec les utils du monitor aussi 
//	prochaine etape : thinking et sleeping, verif toutes les fonctions dans lesquels j'ai des qst ou de commentaires et tester le prog
//
//	=== 08 sept mar ===
//
//	thinking et sleeping pseudo puis vrai code
//	prochaine etape : tester, verif les sleep que je comprends pas, les leaks, les destroy et les joins,
//	les msg a ecrire et le comportement du prog
//
// === mer et jeu ==
// fin du code debut des testssss
// reste a faire : la norme
//
// === lun 14 sept ===
// 
// fait aujd: norme + verif int max + clear manquant
// 
// reste a faire : 
// - debuger le segfault
// - separer le main en plusieur fonction
// - verif norme
// - re faire touttt les test 
//
// liste de test : 
// - peu d'arg
// - trop d'arg
// - arg lettre
// - arg negatif
// - arg < int max
// - nb_philo > 200
// 
// tout les test de la correction avec valgrind puis helgrind 
//
//  === mar 15 sept ===
//
//  fait : norm, debug segfault et leak mutex
//
//  a faire :
//  debug test ./philo 7 400 200 200 10
//  le prog ne dois plus rien ecrire si un philo est die
//	
//	=== ven 18 sept ===
//
//	fait :
//
//	liste de test :
//	valgrind --tool=helgrind --tool=drd ./philo
//	eat and die : 1 800 200 200
//	not die : 5 800 200 200
//	not die, eat 7 : 5 800 200 200 7
//	not die : 4 410 200 200
//	die : 4 310 200 100
//	die, time of death -10ms : 2 200 200 200
//	other : 7 400 200 200 7
//	other : 3 400 200 200 10
//	other : 50 400 200 199
//
//
//
//	a faire :
//
//

