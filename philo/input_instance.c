/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_instance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:07:15 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/29 19:08:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_input	*input_instance(void)
{
	static t_input	input;

	return (&input);
}
