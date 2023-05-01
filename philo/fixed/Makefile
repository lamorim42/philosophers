NAME		=	philo

CC			=	clang

CFLAGS		=	-Werror -Wall -Wextra -pthread

SRCS		=	main.c
SRCS		+=	utils.c
SRCS		+=	print_utils.c
SRCS		+=	make_threads.c
SRCS		+=	initialize.c
SRCS		+=	ft_sleep.c
SRCS		+=	philo_loop.c
SRCS		+=	to_stop.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY: all clean fclean re
