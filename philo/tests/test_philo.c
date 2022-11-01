
#include <criterion/criterion.h>
#include "test.h"

Test(test_philo, philo_create_instace_point_to_null)
{
	t_philo	**philo;

	philo = philo_instance();
	cr_assert_eq(*philo, NULL);
}

Test(test_philo, philo_instance_memmory_is_always_the_same)
{
	t_philo	**philo;
	t_philo	**philo2;

	philo = philo_instance();
	philo2 = philo_instance();
	cr_assert_eq(philo, philo2);
}


Test(test_philo, philo_creat)
{
	t_philo	**philo;

	philo = philo_instance();
	*philo = philo_creat();
	cr_assert_neq(*philo, NULL);
	free(*philo);
}

Test(test_philo, philo_add_back)
{
	t_philo	**philo;
	t_philo	*philo2;

	philo = philo_instance();
	*philo = philo_creat();
	philo2 = philo_creat();
	philo_add_back(philo2);
	cr_assert_eq((*philo)->prev, philo2);
	pthread_mutex_destroy(&(*philo)->fork);
	pthread_mutex_destroy(&philo2->fork);
	free(*philo);
	free(philo2);
}
