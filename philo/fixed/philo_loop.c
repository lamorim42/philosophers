/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 21:34:14 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 21:34:16 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	to_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_print);
	print_action("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->input->mutex_print);
	ft_sleep(philo->input->t_sleep);
}

static void	to_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->input->mutex_print);
	print_action("is thinking\n", philo);
	pthread_mutex_unlock(&philo->input->mutex_print);
}

void	philo_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&philo->input->mutex_print);
	print_action("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->input->mutex_print);
	if (!philo->next_fork)
	{
		ft_sleep(philo->input->t_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->next_fork);
	pthread_mutex_lock(&philo->input->mutex_print);
	print_action("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->input->mutex_print);
	pthread_mutex_lock(&philo->input->mutex_print);
	print_action("is eating\n", philo);
	pthread_mutex_lock(&philo->input->mutex_control_eat);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->input->mutex_control_eat);
	pthread_mutex_unlock(&philo->input->mutex_print);
	ft_sleep(philo->input->t_eat);
	pthread_mutex_unlock(philo->next_fork);
	pthread_mutex_unlock(&philo->fork);
	to_sleep(philo);
	to_think(philo);
}
