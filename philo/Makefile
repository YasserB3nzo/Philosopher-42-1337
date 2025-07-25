NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
SRCS = philo.c Src/CheckArg.c \
	Src/utils.c Src/ft_atoi.c

OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all