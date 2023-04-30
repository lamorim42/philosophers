/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:58:11 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:49:30 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "philo.h"

typedef struct s_table
{
	t_input	input;
	t_philo	*philo;
}	t_table;

int				ft_atoi(const char *nptr);
char			is_digit(int c);
unsigned int	get_time(unsigned int time);
char			is_valid_input(int argc, char **argv, t_table *table);
void			table_load(t_table *table);
void			philo_load(t_table *table);
void			input_helper(void);

#endif
