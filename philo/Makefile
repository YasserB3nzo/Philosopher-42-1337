NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread
SRCS = philo.c Src/CheckArg.c \
	Src/Error.c Src/ft_atoi.c
OBJS = $(SRCS:.c=.o)

LIB_PATH = ./printf

LIB_NAME = libftprintf.a



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_PATH) -lftprintf

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all