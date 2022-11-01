
#ifndef TEST_H
# define TEST_H

# include "input.h"
# include "philo.h"
# include <pthread.h>
# include <stdlib.h>

void	mock_input(t_input *input);
t_philo	*philo_creat(void);
void	philo_add_back(t_philo *_new);

#endif
