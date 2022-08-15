NAME = philo
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I ./app/includes/

SRC = main.c
SRC += input_instance.c
SRC += input_valid_and_load.c
SRC += philo_instance.c
SRC += philo_join.c
SRC += philo_life_cycle.c
SRC += philo_load.c
SRC += print_input_error.c
SRC += print_philo_activity.c
SRC += print_philo_die.c
SRC += ph_atoi.c
SRC += ph_consume_time.c
SRC += ph_get_time.c
SRC += ph_isdigit.c
SRC += ph_sleep.c

OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./app/obj/, $(OBJS))
OBJ_DIR = ./app/obj

RM = rm -rf

VPATH = ./app/src ./app/src/input ./app/src/philo\
		./app/src/print ./app/src/utils

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: obj_dir $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re: fclean all

obj_dir:
	@if [ ! -d "$(OBJ_DIR)" ]; then\
		mkdir $(OBJ_DIR);\
	else\
		echo "make: Nothing to be done for 'all'.";\
	fi

.PHONY= all clean fclean re $(NAME)