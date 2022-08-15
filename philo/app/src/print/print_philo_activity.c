/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_activity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:40:57 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 15:42:31 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "philo.h"
#include "input.h"
#include "utils.h"

void	print_philo_activity(t_philo *philo, char *activity)
{
	t_input			*input;
	unsigned int	start_time;

	input = input_instance();
	start_time = ph_get_time(input->start);
	if (input->to_continue)
		printf("%u %u %s\n", start_time, philo->id + 1, activity);
}