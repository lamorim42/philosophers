#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

typedef struct s_input
{
	unsigned int	n_philos;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				n_eat;
	unsigned int	start;
	char			to_continue;
}	t_input;

t_input	*input_mem(void)
{
	static t_input	__instance;

	return (&__instance);
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

int	ph_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static char	is_valid_digit(char *str)
{
	while (*str)
	{
		if (!ph_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	is_valid_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		return (0);
	}
	else
	{
		while (i < argc)
		{
			if (!is_valid_digit(argv[i]))
				return (0);
			i++;
		}
	}
	return (1);
}

static int	ph_is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	ph_is_signal(int c)
{
	return (c == '-' || c == '+');
}

int	ph_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	nptr_int;

	i = 0;
	signal = 1;
	nptr_int = 0;
	while (ph_is_space(nptr[i]))
		i++;
	if (ph_is_signal(nptr[i]))
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (ph_isdigit(nptr[i]))
	{
		nptr_int = (nptr_int * 10) + (nptr[i] - '0');
		i++;
	}
	return (nptr_int * signal);
}

void	load_input(char **argv)
{
	t_input	*input;

	input = input_mem();
	input->n_philos = ph_atoi(argv[1]);
	input->t_die = ph_atoi(argv[2]);
	input->t_eat = ph_atoi(argv[3]);
	input->t_sleep = ph_atoi(argv[4]);
	if (argv[5])
		input->n_eat = ph_atoi(argv[5]);
}

int	main(int argc, char **argv)
{
	if (is_valid_input(argc, argv))
		load_input(argv);
	else
	{
		input_helper();
		return (1);
	}
	return (0);
}