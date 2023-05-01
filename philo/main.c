/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:32:51 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 21:32:53 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	main_verify_death(t_table *table)
{
	pthread_mutex_lock(&table->input.mutex_dead);
	if (table->input.to_stop)
	{
		pthread_mutex_unlock(&table->input.mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&table->input.mutex_dead);
	return (0);
}

static void	stop(t_table *table)
{
	unsigned int	i;

	i = -1;
	while (!main_verify_death(table))
		ft_sleep(1);
	while (++i < table->input.n_philo)
		pthread_join(table->philos[i].main_thread, NULL);
	pthread_mutex_destroy(&table->input.mutex_print);
	i = -1;
	while (++i < table->input.n_philo)
		pthread_mutex_destroy(&table->philos[i].fork);
	free(table->philos);
}

static void	input_load(t_table *table, int argc, char **argv)
{
	table->input.n_philo = ft_atoi(argv[1]);
	table->input.t_die = ft_atoi(argv[2]);
	table->input.t_eat = ft_atoi(argv[3]);
	table->input.t_sleep = ft_atoi(argv[4]);
	table->input.max_eat = -1;
	if (argc == 6)
		table->input.max_eat = ft_atoi(argv[5]);
}

static int	is_valid_input(int argc, char **argv, t_table *table)
{
	if ((argc == 5 || argc == 6) && is_number(argv, 0, 1))
	{
		input_load(table, argc, argv);
		if (table->input.n_philo <= 0
			|| table->input.t_die <= 0
			|| table->input.t_eat <= 0
			|| table->input.t_sleep <= 0)
		{
			return (0);
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!is_valid_input(argc, argv, &table))
	{
		input_helper();
		return (1);
	}
	table.philos = malloc(sizeof(t_philo) * table.input.n_philo);
	table_load(&table);
	make_threads(&table);
	stop(&table);
	return (0);
}
