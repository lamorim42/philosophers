/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:37:17 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 21:37:18 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	input_helper(void)
{
	printf("input Error!\n\tPlease use: ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

void	print_action(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = get_time() - philo->input->start;
	if (time >= 0 && time <= 2147483647 && !is_to_stop(philo))
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
}