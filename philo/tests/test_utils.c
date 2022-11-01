
#include "test.h"

void	mock_input(t_input *input)
{
	input->n_philos = 5;
	input->t_die = 800;
	input->t_eat = 200;
	input->t_sleep = 200;
	input->n_eat = 7;
}

t_philo	*philo_creat(void)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	new->id = 0;
	new->n_eat = 0;
	new->last_eat = 0;
	new->checked = 0;
	new->prev = new;
	new->next = new;
	pthread_mutex_init(&new->fork, NULL);
	return (new);
}

void	philo_add_back(t_philo *_new)
{
	t_philo	*prev;

	if (!(*philo_instance()))
	{
		(*philo_instance()) = _new;
		(*philo_instance())->id = 0;
	}
	else
	{
		prev = (*philo_instance())->prev;
		(*philo_instance())->prev = _new;
		_new->next = prev->next;
		prev->next = _new;
		_new->prev = prev;
		_new->id = prev->id + 1;
	}
	pthread_create(&_new->thread, NULL, &philo_life_cycle, _new);
}
