/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:55:59 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 14:01:05 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <sys/time.h>
#include <stdlib.h>

unsigned int	ph_get_time(unsigned int time)
{
	struct timeval	date;
	unsigned int	t;

	gettimeofday(&date, NULL);
	t = ((date.tv_sec * 1000) + (date.tv_usec / 1000)) - time;
	return (t);
}
