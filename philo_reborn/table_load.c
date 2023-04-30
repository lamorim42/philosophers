/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 11:36:05 by lamorim           #+#    #+#             */
/*   Updated: 2023/04/30 11:36:16 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

void	table_load(t_table *table)
{
	table->input.start_time = get_time(0);
	table->input.to_continue = 1;
	table->input.count_max_eat = 0;
	pthread_mutex_init(&table->input.death, NULL);
	pthread_mutex_init(&table->input.print, NULL);
	pthread_mutex_init(&table->input.m_control, NULL);
	pthread_mutex_init(&table->input.eat_control, NULL);
}
