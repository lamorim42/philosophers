/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:57:35 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/29 20:27:20 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_philo	*prev;
	int				n_eat;
	unsigned int	last_eat;
	pthread_t		thread;
	char			is_check;
}	t_philo;

t_philo	**philo_instance(void);
void	philo_load(void);
void	*philo_loop(void *ptr);

#endif
