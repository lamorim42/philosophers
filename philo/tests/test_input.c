
#include <criterion/criterion.h>
#include "input.h"

Test(test_input, input_instance)
{
	t_input	*input;

	input = input_instance();
	input->n_philos = 5;
	cr_assert(input->n_philos == 5);
}
