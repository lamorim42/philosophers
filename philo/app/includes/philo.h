/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:42:53 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/10 17:41:20 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	unsigned int	id;
	pthread_t		thread;
	pthread_mutex_t	fork;
	int				n_eat;
	char			checked;
	unsigned int	last_eat;
	struct s_philo	*prev;
	struct s_philo	*next;
}	t_philo;

void	philo_load(void);
void	philo_join(void);
void	*philo_life_cycle(void *arg);
t_philo	**philo_instance(void);

#endif
