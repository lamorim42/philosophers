
#include <criterion/criterion.h>
#include "test.h"

Test(test_input, input_instance)
{
	t_input	*input;

	input = input_instance();
	mock_input(input);
	cr_assert_eq(input->n_philos, 5);
}

Test(test_input, input_instance_memmory_is_always_the_same)
{
	t_input	*input;
	t_input	*input2;

	input = input_instance();
	input2 = input_instance();
	cr_assert_eq(input, input2);
}

Test(test_input, input_instance_read_and_write)
{
	t_input	*input;
	t_input	input2;

	input = input_instance();
	mock_input(input);
	input2 = *input_instance();
	input2.n_philos = 8;
	cr_assert_eq(input->n_philos, 5);
	cr_assert_eq(input2.n_philos, 8);
}
