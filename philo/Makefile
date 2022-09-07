SRC = philo_main.c\
create_var.c\
create_threads.c\
exit.c\
timing_utils.c\
routine.c\
actions.c\
monitor_thread.c\
cycle_check_thread.c\
unlock_mutexes.c\
print.c\

SDIR = sources

ODIR = objects

OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = philo

FLAGS = -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@cc -Ipthread $(OBJ) $(FLAGS) -g -o $(NAME)
	@echo $(NAME)" made"

$(ODIR)/%.o	:	$(SDIR)/%.c
	@mkdir -p objects
	@cc $(FLAGS) -g -c $< -o $@
	@echo "Compiling "$<

clean	:
	@rm -f $(OBJ)
	@rm -rf $(ODIR)
	@echo $(NAME)" cleaned"

fclean	:	clean
	@rm -f $(NAME)
	@echo $(NAME)" fcleaned"

re		:	fclean all

.PHONY	:	all clean fclean re