NAME = philo
CC = cc
#CFLAGS = -Wall -Wextra -Werror -pthread

valgrind = -fsanitize=thread

SRCS = philo.c Src/parsing.c \
	Src/utils.c Src/init.c \
	Src/routine.c

OBJS = $(SRCS:.c=.o)

# -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all