SRC = philo_main.c\
parse_input.c\
threads.c\
routine.c\

OBJ = $(SRC:.c=.o)

NAME = philo

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	cc -Ipthread $(OBJ) -Wall -Wextra -Werror -o $(NAME)

clean	:
	rm -f $(OBJ)

fclean	:	clean
	rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re