/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:01:09 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 00:04:21 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdlib.h>

unsigned int	get_time(unsigned int time)
{
	struct timeval	date;
	unsigned int	_time;

	gettimeofday(&date, NULL);
	_time = (((date.tv_sec * 1000) + (date.tv_usec / 1000)) - time);
	return (_time);
}
