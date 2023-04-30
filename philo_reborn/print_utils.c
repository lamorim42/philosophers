/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 23:31:51 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:49:19 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	input_helper(void)
{
	printf("input Error!\n\tPlease use: ");
	printf("number_of_philosophers ");
	printf("time_to_die ");
	printf("time_to_eat ");
	printf("time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

void	ft_putnbr_fd(unsigned int n, int fd)
{
	unsigned long int	n_long;
	char				digit;

	n_long = n;
	if (n_long < 0)
	{
		n_long = -n_long;
		write(fd, "-", 1);
	}
	if (n_long > 9)
		ft_putnbr_fd(n_long / 10, fd);
	digit = '0' + (n_long % 10);
	write(fd, &digit, 1);
}

void	print_action(t_philo *philo, char *str)
{
	ft_putnbr_fd(get_time(philo->input->start_time), 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd((philo->id + 1), 1);
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd("\n", 1);
}
