#include "philo.h"

int verify_death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->input->mutex_dead);
	if (i)
		philo->input->to_stop = i;
	if (philo->input->to_stop)
	{
		pthread_mutex_unlock(&philo->input->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->input->mutex_dead);
	return (0);
}
