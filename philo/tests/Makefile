NAME = test_suite
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
INCLUDE = -I ../app/includes/

SRC += input_instance.c
SRC += test_utils.c
SRC += test_input.c


OBJS = $(SRC:.c=.o)
OBJ = $(addprefix ./obj/, $(OBJS))
OBJ_DIR = ./obj

RM = rm -rf

VPATH = ../app/src ../app/src/input ../app/src/philo\
		../app/src/print ../app/src/utils

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: obj_dir $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread -lcriterion

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

test: fclean all
	@printf "\e[1;95m\n############## TEST ##############\n\n\e[0m"
	./test_suite

.PHONY= all clean fclean re $(NAME)