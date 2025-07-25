NAME = philo
CC = cc
#CFLAGS = -Wall -Wextra -Werror -pthread #-fsanitize=thread
SRCS = philo.c Src/parsing.c \
	Src/utils.c Src/init.c \
	Src/routine.c

OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all