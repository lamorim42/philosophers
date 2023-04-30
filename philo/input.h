/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:02:47 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 00:06:24 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

typedef struct s_input
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				n_eat;
	unsigned int	start;
	char			to_continue;
}	t_input;

t_input	*input_instance(void);
char	input_validation(int argc, char **argv);
void	input_load(int argc, char **argv);

#endif
