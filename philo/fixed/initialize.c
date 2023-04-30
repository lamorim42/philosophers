#include "philo.h"

static void init_mutex(t_table *table)
{
	pthread_mutex_init(&table->input.mutex_print, NULL);
	pthread_mutex_init(&table->input.mutex_dead, NULL);
	pthread_mutex_init(&table->input.mutex_control_eat, NULL);
	pthread_mutex_init(&table->input.mutex_control, NULL);
}

int table_load(t_table *table)
{
	unsigned int i;

	i = 0;
	table->input.start = get_time();
	table->input.to_stop = 0;
	table->input.count_max_eat = 0;
	init_mutex(table);
	while (i < table->input.n_philo)
	{
		table->philos[i].id = i + 1;
		table->philos[i].time_last_eat = table->input.start;
		table->philos[i].count_eat = 0;
		table->philos[i].end = 0;
		table->philos[i].next_fork = NULL;
		pthread_mutex_init(&table->philos[i].fork, NULL);
		if (table->input.n_philo == 1)
			return (1);
		if (i == table->input.n_philo - 1)
			table->philos[i].next_fork = &table->philos[0].fork;
		else
			table->philos[i].next_fork = &table->philos[i + 1].fork;
		i++;
	}
	return (1);
}
