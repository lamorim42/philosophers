/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:33:43 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 14:40:32 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	print_input_error(void)
{
	printf("input Error!\n\tPlease use: ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}
