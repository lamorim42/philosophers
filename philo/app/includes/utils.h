/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:47:24 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:10:55 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				ph_isdigit(int c);
int				ph_atoi(const char *nptr);
void			ph_sleep(unsigned int time);
unsigned int	ph_get_time(unsigned int time);
char			ph_consume_time(unsigned int time, long *life);

#endif
