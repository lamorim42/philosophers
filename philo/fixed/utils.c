#include "philo.h"

int is_number(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int ft_atoi(const char *str)
{
	int i;
	long sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long int get_time(void)
{
	long int time;
	struct timeval current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	input_helper(void)
{
	printf("input Error!\n\tPlease use: ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

void print_action(char *str, t_philo *philo)
{
	long int time;

	time = -1;
	time = get_time() - philo->input->start;
	if (time >= 0 && time <= 2147483647 && !verify_death(philo, 0))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
}
