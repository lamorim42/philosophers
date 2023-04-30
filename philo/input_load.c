/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:27:46 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 01:16:10 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "utils.h"

static int	ft_is_space(int c);
static int	ft_signal(int c);

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	nptr_int;

	i = 0;
	signal = 1;
	nptr_int = 0;
	while (ft_is_space(nptr[i]))
		i++;
	if (ft_signal(nptr[i]))
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (is_digit(nptr[i]))
	{
		nptr_int = (nptr_int * 10) + (nptr[i] - '0');
		i++;
	}
	return (nptr_int * signal);
}

static int	ft_is_space(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_signal(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

static void	set_input(char *argv, int i)
{
	if (i == 1)
		input_instance()->n_philo = ft_atoi(argv);
	else if (i == 2)
		input_instance()->t_die = ft_atoi(argv);
	else if (i == 3)
		input_instance()->t_eat = ft_atoi(argv);
	else if (i == 4)
		input_instance()->t_sleep = ft_atoi(argv);
	else if (i == 5)
		input_instance()->n_eat = ft_atoi(argv);
}

void	input_load(int argc, char **argv)
{
	int	i;

	i = 1;
	input_instance()->n_eat = -1;
	input_instance()->to_continue = 1;
	pthread_mutex_init(&input_instance()->print, NULL);
	pthread_mutex_init(&input_instance()->m_continue, NULL);
	while (i < argc)
	{
		set_input(argv[i], i);
		i++;
	}

}
