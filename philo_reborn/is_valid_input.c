/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:39:22 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:39:50 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

static void	set_input(char *argv, int i, t_input *input)
{
	if (i == 1)
		input->n_philo = ft_atoi(argv);
	else if (i == 2)
		input->t_die = ft_atoi(argv);
	else if (i == 3)
		input->t_eat = ft_atoi(argv);
	else if (i == 4)
		input->t_sleep = ft_atoi(argv);
	else if (i == 5)
		input->max_eat = ft_atoi(argv);
}

static char	argv_validation(char *argv)
{
	while (*argv)
	{
		if (is_digit(*argv) == 0)
			return (0);
		argv++;
	}
	return (1);
}

char	is_valid_input(int argc, char **argv, t_table *table)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (i < argc)
	{
		if (argv_validation(argv[i]) == 0)
			return (0);
		set_input(argv[i], i, &table->input);
		i++;
	}
	table_load(table);
	return (1);
}
