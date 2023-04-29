/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:11:09 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/29 19:15:24by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static char	argv_validation(char *argv)
{
	while (*argv)
	{
		if (is_digit(*argv) == 0)
			return (0);
		argv++;
	}
	return (1);
}

char	input_validation(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	argv++;
	while (*argv)
	{
		if (argv_validation(*argv) == 0)
			return (0);
		argv++;
	}
	return (1);
}
