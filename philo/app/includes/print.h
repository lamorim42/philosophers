/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:11:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 15:45:05 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "philo.h"
# include <stdio.h>

void	print_input_error(void);

void	print_philo_activity(t_philo *philo, char *activity);
void	print_philo_die(t_philo *philo);

#endif