#include "philo.h"

static void *is_dead(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	ft_sleep(philo->input->t_die + 1);
	pthread_mutex_lock(&philo->input->mutex_control_eat);
	pthread_mutex_lock(&philo->input->mutex_control);
	if (!verify_death(philo, 0) && !philo->end && ((get_time() - philo->time_last_eat) >= (long)(philo->input->t_die)))
	{
		pthread_mutex_unlock(&philo->input->mutex_control_eat);
		pthread_mutex_unlock(&philo->input->mutex_control);
		pthread_mutex_lock(&philo->input->mutex_print);
		print_action("died\n", philo);
		pthread_mutex_unlock(&philo->input->mutex_print);
		verify_death(philo, 1);
	}
	pthread_mutex_unlock(&philo->input->mutex_control_eat);
	pthread_mutex_unlock(&philo->input->mutex_control);
	return (NULL);
}

static void *thread(void *data)
{
	t_philo *philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_sleep(philo->input->t_eat / 10);
	while (!verify_death(philo, 0))
	{
		pthread_create(&philo->death_thread, NULL, is_dead, data);
		philo_loop(philo);
		pthread_detach(philo->death_thread);
		if (++philo->count_eat == philo->input->max_eat)
		{
			pthread_mutex_lock(&philo->input->mutex_control);
			philo->end = 1;
			philo->input->count_max_eat++;
			if (philo->input->count_max_eat == (int)philo->input->n_philo)
			{
				pthread_mutex_unlock(&philo->input->mutex_control);
				verify_death(philo, 1);
			}
			pthread_mutex_unlock(&philo->input->mutex_control);
			return (NULL);
		}
	}
	return (NULL);
}

int threading(t_table *table)
{
	unsigned int i;

	i = 0;
	while (i < table->input.n_philo)
	{
		table->philos[i].input = &table->input;
		pthread_create(&table->philos[i].main_thread, NULL, thread, &table->philos[i]);
		i++;
	}
	return (1);
}
