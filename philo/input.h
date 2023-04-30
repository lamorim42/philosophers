/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:02:47 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 10:46:21 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

#include <pthread.h>

typedef struct s_input
{
}	t_input;

t_input	*input_instance(void);
char	input_validation(int argc, char **argv);
void	input_load(int argc, char **argv);

#endif
