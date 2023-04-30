NAME = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror -pthread -g3
SRC = main.c
SRC += get_time.c
SRC += is_digit.c
SRC += ft_atoi.c
SRC += is_valid_input.c
SRC += philo_load.c
SRC += table_load.c
SRC += print_utils.c
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
