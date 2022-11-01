/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:03:30 by lamorim           #+#    #+#             */
/*   Updated: 2022/08/15 16:04:12 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct s_input
{
	int				n_eat;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_philos;
	unsigned int	start;
	char			to_continue;
}	t_input;

t_input	*input_instance(void);
char	is_valid_input(int argc, char **argv);
void	load_input(int argc, char **argv);

#endif
