SRC = philo_main.c\
create_var.c\
create_threads.c\
exit.c\
timing_utils.c\
routine.c\
actions.c\

SDIR = sources

ODIR = objects

OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = philo

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@cc -Ipthread $(OBJ) -Wall -Wextra -Werror -g -o $(NAME)
	@echo $(NAME)" made"

$(ODIR)/%.o	:	$(SDIR)/%.c
	@mkdir -p objects
	@cc -Wall -Werror -Wextra -g -c $< -o $@

clean	:
	@rm -f $(OBJ)
	@rm -rf $(ODIR)
	@echo $(NAME)" cleaned"

fclean	:	clean
	@rm -f $(NAME)
	@echo $(NAME)" fcleaned"

re		:	fclean all

.PHONY	:	all clean fclean re