/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_instance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:08:38 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 14:09:32 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

t_input	*input_instance(void)
{
	static t_input	__instance;

	return (&__instance);
}