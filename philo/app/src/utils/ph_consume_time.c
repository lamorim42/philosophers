/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_consume_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:04:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 14:07:21 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	ph_consume_time(unsigned int time, long *life)
{
	while (time > 0)
	{
		ph_sleep(1);
		if (*life == 0)
			return (0);
		(*life)--;
		time--;
	}
	return (1);
}
