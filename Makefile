NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC =  main.c philo_utils.c philo.c dinner.c philo_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)  philo.h

	$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)

clean:
	rm -rf $(OBJ) 

fclean: clean
	rm -rf $(NAME)

re: fclean all