SRC = philo_main.c\
create_var.c\
create_threads.c\
exit.c\
timing_utils.c\
routine.c\
actions.c\
monitor_thread.c\

SDIR = sources

ODIR = objects

OBJ = $(addprefix $(ODIR)/,$(SRC:.c=.o))

NAME = philo

FLAGS = -Wall -Wextra -Werror

CHECKDATARACES =

ifdef FSANITIZE_THREADS
CHECKDATARACES = -fsanitize=thread
endif

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	@cc -Ipthread $(OBJ) $(FLAGS) -g -o $(NAME) $(CHECKDATARACES)
	@echo $(NAME)" made"

$(ODIR)/%.o	:	$(SDIR)/%.c
	@mkdir -p objects
	@cc $(FLAGS) -g -c $< -o $@ $(CHECKDATARACES)
	@echo "Compiling "$<

clean	:
	@rm -f $(OBJ)
	@rm -rf $(ODIR)
	@echo $(NAME)" cleaned"

fclean	:	clean
	@rm -f $(NAME)
	@echo $(NAME)" fcleaned"

re		:	fclean all

fsanitize	:
	@make FSANITIZE_THREADS=1

.PHONY	:	all clean fclean re