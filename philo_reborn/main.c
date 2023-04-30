/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:23:53 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:49:41 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (!is_valid_input(argc, argv, &table))
	{
		input_helper();
		return (1);
	}
	return (0);
}
