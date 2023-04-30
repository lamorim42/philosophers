/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:55:28 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 00:21:51 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

char			is_digit(int c);
void			ft_sleep(unsigned int time);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(unsigned int n, int fd);
void			input_helper(void);
unsigned int	get_time(unsigned int time);
void			print_action(t_philo *philo, char *str);

#endif
