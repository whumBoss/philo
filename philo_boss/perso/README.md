*This project has been created as part of the 42 curriculum by wihumeau*.

# Philosophers

## Description
The **Philosophers** project is a mandatory project of 42 curriculum. 
It is an introduction to threads, multithreading, management of shared memory within a program using mutex.

THe goal is to simulate a scenario where where one or multipuls philosopher (not more than 200) sits around a table, wanting to eat spaghetti but the triky thing here is that each one of them have one fork, but the need two forks to eat the spaghetti. So they have tto share forks with their neighbour and eat at different timeframe. Other condition they should all eat beafore a certain amout of time, if they don't they die... and they should avoid dying. After eating philosophers should think and sleep before they eat again.

Final course of action, is determined by the values you give the program. 


## Instructions

### Compilation
The project is written in C and compiled using `cc` with standard flags: `-Wall -Wextra -Werror -g3`.

To compile the executable, you can use the make command at the root of the repository. The other make command available are: make clean, make fclean, make re.

The executable will be named ./philo

### Arguments
The argument are fondamentely necesserary, they determine the number of philosophers, the timeframes, and other limits. Without argument the program is anable to procede with any routine.

Here are the values you need to give to the program:

```
./philo nb_philo timeframe_dying timeframe_eating timeframe_sleeping nb_of_meal_per_philo
```
nb_philo should not be over 200
timeframes should not be under 60 (ms)
nb_of_meal_per_philo is optionnal

### Tests
This program should be tested first withou valgrind to see the proper actions and timeframe management. And the with Valgrind to check for leaks, race condition and data race.

Here are tests and valgrind flags that should be tested during the project evaluation (and more):

Sould eat and die : 
```
valgrind --tool=helgrind --tool=drd ./philo 1 800 200 200
```

Should not die :
``` 
valgrind --tool=helgrind --tool=drd ./philo 5 800 200 200
valgrind --tool=helgrind --tool=drd ./philo 5 800 200 200 7
valgrind --tool=helgrind --tool=drd ./philo 4 410 200 200
```

Should die :
```
valgrind --tool=helgrind --tool=drd ./philo 4 310 200 100
valgrind --tool=helgrind --tool=drd ./philo 2 200 200 200

```
More :
```
valgrind --tool=helgrind --tool=drd ./philo 7 400 200 200 7
valgrind --tool=helgrind --tool=drd ./philo 3 400 200 200 10
valgrind --tool=helgrind --tool=drd ./philo 50 400 200 199
```


## Ressources
For each of my project i realated on my peers who have done the project already or who are doign it to extchange on our comprehension and aprrehantion of the concepts, the subject and the code developpement.

Only other ressource i used was a Youtube playlist of videos explaning the concepts of threads and mutex, and showing their implemantation.


https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2


