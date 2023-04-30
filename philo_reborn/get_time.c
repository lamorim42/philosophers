/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:01:09 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:30:43 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

unsigned int	get_time(unsigned int time)
{
	struct timeval	date;
	unsigned int	_time;

	gettimeofday(&date, NULL);
	_time = (((date.tv_sec * 1000) + (date.tv_usec / 1000)) - time);
	return (_time);
}
