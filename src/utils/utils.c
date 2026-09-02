#include "../../header/header.h"


// On veut faire dormir le thread pdt un temps donne, tout en verifiant que le thread soit pas dead.
void	custom_sleep(t_data *data, size_t sleep_time)
{
	size_t	time;
	time = get_time_of_day();

	while ((get_time_of_day() - time) < sleep_time && !read_value(&data->lock_end_prog, &data->end_prog)) // arg de read value ???
		usleep(100); // milliseconds aussi?
	return ;
}


long	get_time_of_day(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); // resultat en milliseconds
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

