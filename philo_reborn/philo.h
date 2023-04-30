/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:42:18 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:43:49 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "input.h"

typedef struct s_philo
{
	int				id;
	unsigned long	time_last_eat;
	unsigned long	eat_count;
	int				eat_end;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	t_input			*input;
	pthread_t		main_thread;
	pthread_t		death_thread;
}	t_philo;


#endif
