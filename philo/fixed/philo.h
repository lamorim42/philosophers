/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 19:53:20 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 19:56:55 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define TRUE 1
# define FALSE 0

typedef struct s_input
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	max_eat;
	long int		start;
	int				count_max_eat;
	int				to_stop;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_dead;
	pthread_mutex_t	mutex_control_eat;
	pthread_mutex_t	mutex_control;
}	t_input;

typedef struct s_philo
{
	unsigned int	count_eat;
	long int		time_last_eat;
	int				id;
	int				end;
	pthread_t		main_thread;
	pthread_t		death_thread;
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	fork;
	t_input			*input;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_input	input;
}	t_table;

long int	get_time(void);
void		ft_sleep(long int time);
int			is_number(char **argv, int i, int j);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);
int			table_load(t_table *table);
int			threading(t_table *table);
void		print_action(char *str, t_philo *philo);
void		input_helper(void);
void		philo_loop(t_philo *philo);
int			verify_death(t_philo *philo, int i);

#endif
