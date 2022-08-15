/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:41:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 15:41:47 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "philo.h"
#include "input.h"
#include "utils.h"

void	print_philo_die(t_philo *philo)
{
	t_input			*input;
	unsigned int	start_time;

	input = input_instance();
	start_time = ph_get_time(input->start);
	printf("%u %u died\n", start_time, philo->id + 1);
}