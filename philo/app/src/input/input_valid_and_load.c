/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_and_load.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:15:25 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 14:27:14 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "utils.h"
#include "input.h"

static void	set_input(char *str, int index)
{
	t_input	*input;

	input = input_instance();
	if (index == 1)
		input->n_philos = ph_atoi(str);
	if (index == 2)
		input->t_die = ph_atoi(str);
	if (index == 3)
		input->t_eat = ph_atoi(str);
	if (index == 4)
		input->t_sleep = ph_atoi(str);
	if (index == 5)
		input->n_eat = ph_atoi(str);
}

static char	valid_string(char *str)
{
	while (*str)
	{
		if (!ph_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

char	input_valid_and_load(int argc, char **argv)
{
	int		i;
	t_input	*input;

	i = 1;
	input = input_instance();
	input->n_eat = -1;
	input->start = 0;
	input->to_continue = 1;
	if (argc < 5 || argc > 6)
	{
		print_input_error();
		return (0);
	}
	while (i < argc)
	{
		if (!valid_string(argv[i]))
		{
			print_input_error();
			return (0);
		}
		set_input(argv[i], i);
		i++;
	}
	return (1);
}
