*This project has been created as part of the 42 curriculum by wihumeau*.

# Philosophers

## Description

The **Philosophers** project is a mandatory project of the 42 curriculum.
It is an introduction to threads, multithreading, and management of shared memory within a program using mutex.

The goal is to simulate a scenario where one or multiple philosophers (not more than 200) sit around a table, wanting to eat spaghetti, but the tricky thing here is that each one of them has one fork, but they need two forks to eat the spaghetti. So they have to share forks with their neighbour and eat at different timeframes. Other condition: they should all eat before a certain amount of time; if they don't, they die... and they should avoid dying. After eating, philosophers should think and sleep before they eat again.

Final course of action is determined by the values you give the program.

## Instructions

### Compilation

The project is written in C and compiled using `cc` with standard flags: `-Wall -Wextra -Werror -g3`.

To compile the executable, you can use the `make` command at the root of the repository. The other make commands available are: `make clean`, `make fclean`, `make re`.

The executable will be named `./philo`.

### Arguments

The arguments are fundamentally necessary, they determine the number of philosophers, the timeframes, and other limits. Without arguments the program is unable to proceed with any routine.

Here are the values you need to give to the program:

```
./philo nb_philo timeframe_dying timeframe_eating timeframe_sleeping nb_of_meal_per_philo
```

- `nb_philo` should not be over 200
- timeframes should not be under 60 (ms)
- `nb_of_meal_per_philo` is optional

### Tests

This program should be tested first without Valgrind to see the proper actions and timeframe management. And then with Valgrind to check for leaks, race conditions and data races.

Here are tests and Valgrind flags that should be tested during the project evaluation (and more):

**Should eat and die:**
```
valgrind --tool=helgrind --tool=drd ./philo 1 800 200 200
```

**Should not die:**
```
valgrind --tool=helgrind --tool=drd ./philo 5 800 200 200
valgrind --tool=helgrind --tool=drd ./philo 5 800 200 200 7
valgrind --tool=helgrind --tool=drd ./philo 4 410 200 200
```

**Should die:**
```
valgrind --tool=helgrind --tool=drd ./philo 4 310 200 100
valgrind --tool=helgrind --tool=drd ./philo 2 200 200 200
```

**More:**
```
valgrind --tool=helgrind --tool=drd ./philo 7 400 200 200 7
valgrind --tool=helgrind --tool=drd ./philo 3 400 200 200 10
valgrind --tool=helgrind --tool=drd ./philo 50 400 200 199
```

## Resources

For each of my projects I relied on my peers who have done the project already or who are doing it, to exchange on our comprehension and approach of the concepts, the subject and the code development.

The only other resource I used was a YouTube playlist of videos explaining the concepts of threads and mutex, and showing their implementation.

[Threads & Mutex Playlist](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
