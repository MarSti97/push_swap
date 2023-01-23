SRCS = push_swap.c moves.c checkers.c list_func.c writing.c algo.c algo_tools.c \
ft_atoi.c ft_printf.c ft_put.c algo_two.c
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
NAME = push_swap
RM = rm -f

#Colors
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

all : $(NAME)
	@echo "$(GREEN)---- Successful Compile ----$(END)"

$(NAME) : $(SRCS)
	@cc $(FLAGS) $(SRCS) -o $(NAME) 

clean :
	@$(RM)
	@echo "$(RED)---- Cleaned ----$(END)"

fclean : clean 
	@$(RM) $(NAME)
	@echo "$(RED)---- All ----$(END)"

re : fclean all

.PHONY : all fclean clean re