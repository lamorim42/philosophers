/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:42:09 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 10:48:56 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_input
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				max_eat;
	int				count_max_eat;
	char			to_continue;
	pthread_mutex_t	print;
	pthread_mutex_t	m_control;
	pthread_mutex_t	death;
	pthread_mutex_t	eat_control;
}	t_input;

#endif
