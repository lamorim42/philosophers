/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:32:59 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 13:52:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ph_is_space(int c);
static int	ph_is_signal(int c);

int	ph_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	nptr_int;

	i = 0;
	signal = 1;
	nptr_int = 0;
	while (ph_is_space(nptr[i]))
		i++;
	if (ph_is_signal(nptr[i]))
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while (ph_isdigit(nptr[i]))
	{
		nptr_int = (nptr_int * 10) + (nptr[i] - '0');
		i++;
	}
	return (nptr_int * signal);
}

static int	ph_is_space(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

static int	ph_is_signal(int c)
{
	return (c == '-' || c == '+');
}
