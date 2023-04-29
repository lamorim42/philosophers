/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:23:53 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/29 19:40:06 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "input.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	if (input_validation(argc, argv) == 0)
	{
		printf("invalido!\n");
		return (1);
	}
	printf("Valido!\n");
	input_load(argc, argv);
	printf("%d, %d, %d, %d, %d\n", input_instance()->n_philo,
	input_instance()->t_die, input_instance()->t_eat,
	input_instance()->t_sleep, input_instance()->n_eat);
	return (0);
}
