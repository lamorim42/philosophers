NAME = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread -g3
SRC = main.c
SRC += input_instance.c
SRC += is_digit.c
SRC += input_validation.c
SRC += input_load.c
SRC += ft_sleep.c
SRC += philo_instance.c
SRC += philo_load.c
SRC += philo_loop.c
SRC += print_utils.c
SRC += get_time.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
