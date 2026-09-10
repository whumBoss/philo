 6959  valgrind ./philo 1 800 200 200
 6960  valgrind ./philo 4 310 200 100
 6961  ./philo 4 310 200 100
 6962  valgrind ./philo 5 410 200 200
 6963  valgrind --tool=helgrind ./philo 5 410 200 200
 6964  ./philo 5 410 200 200
 6965  valgrind --tool=helgrind ./philo 5 410 200 200
 6967  valgrind --tool=helgrind ./philo 5 800 200 200 5
 6968  valgrind --tool=helgrind ./philo 5 900 200 200 5
 6969  ./philo 5 900 200 200 5
 6970  valgrind --tool=helgrind ./philo 5 900 200 200 5
 6973  valgrind --tool=helgrind ./philo 5 800 200 200 
 6975  valgrind --tool=helgrind ./philo 5 800 200 200 
 6976  valgrind --tool=helgrind ./philo 5 410 200 200 
 6984* cd Documents/code/03_milestone/philo
 6989  ./philo 1 800 200 200
 6990  ./philo 5 800 200 200
 6991  ./philo 5 800 200 200 7
 6992  ./philo 4 410 200 200
 6993  ./philo 3 310 200 200
 6994  ./philo 2 310 200 200
 6995  valgrind ./philo 1 800 200 200
 6996  valgrind ./philo 5 800 200 200
 6997  valgrind ./philo 5 800 200 200 7
 6998  valgrind ./philo 4 410 200 200
 6999  valgrind ./philo 3 310 200 200
 7000  valgrind ./philo 2 310 200 200
 7001  valgrind --tool=helgrind ./philo 1 800 200 200
 7003  valgrind --tool=helgrind ./philo 1 800 200 200
 7004  valgrind --tool=helgrind ./philo 5 800 200 200
 7005  valgrind --tool=helgrind ./philo 5 800 200 200 7
 7006  valgrind --tool=helgrind ./philo 4 410 200 200
 7007  valgrind --tool=helgrind ./philo 3 310 200 200
 7008  valgrind --tool=helgrind ./philo 2 310 200 200
 7009  ./philo 2 310 200 200
 7010  ./philo "" 310 200 200
 7011  ./philo " " 310 200 200
 7012  ./philo " " "" 200 200
 7013  ./philo " " " " 200 200
 7014  ./philo " " " " "" 200
 7015  ./philo " " " " "" ""
 7016  ./philo " " " " " " " "
 7017  ./philo 1 " " " " " "
 7018  ./philo 1a " " " " " "
 7019  ./philo 1a 12 12 12
 7020  ./philo 1a 12as 12 12
 7021  ./philo 1a 12as 12df 12er
 7022  ./philo
 7023  ./philo 1 2 3 4 5 6 
 7024  ./philo 1 2 3 4 5
 7025  ./philo 1 2 3 4
 7026  ./philo 1 2 3
 7028  ./philo 1a 12as 12df 12er
 7029  ./philo 1a 12as 12df 
 7031  ./philo 1a 12as 12df 
 7032  ./philo 1a 12as 12df 12er
 7033  ./philo 200 500 12 12
 7034  ./philo 200 500 100 100
 7035  ./philo 199 800 100 100
 7036  ./philo 200 800 100 100
 7037  ./philo 1 800 100 100
 7039  ./philo 1 800 100 100
 7040  ./philo 200 500 100 100
 7041  ./philo 200 500 100 100 5 | grep eating | wc -l
 7042  ./philo 5 500 100 100 5 | grep eating | wc -l
 7043  ./philo 5 500 100 100 10 | grep eating | wc -l
 7044  ./philo 5 200 100 100 10 | grep eating | wc -l
 7045  ./philo 5 300 100 100 10 | grep eating | wc -l
 7046  ./philo 5 400 100 100 10 | grep eating | wc -l
 7047  ./philo 8 500 100 100 10 | grep eating | wc -l
 7054  history | tail -100 | grep ./philo
