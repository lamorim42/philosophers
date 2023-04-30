/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:24:31 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/29 20:30:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "input.h"
#include <stdio.h>

void	*philo_loop(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *) ptr;
	printf("%d\n", philo->id);
	return (NULL);
}
