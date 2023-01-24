SRCS = push_swap.c moves.c checkers.c list_func.c writing.c algo.c algo_tools.c \
ft_atoi.c algo_two.c
BONUS = ./bonus/checker.c ./bonus/checker_tools.c \
./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \
./bonus/bonus_moves.c checkers.c list_func.c ft_atoi.c
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
NAME = push_swap
BONUS_NAME = checker
RM = rm -f

#Colors
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

all : $(NAME)
	@echo "$(GREEN)---- Successful Compile ----$(END)"

$(NAME) : $(SRCS)
	@cc $(FLAGS) $(SRCS) -o $(NAME) 

bonus : $(BONUS)
	@cc $(FLAGS) $(BONUS) -o $(BONUS_NAME)
	@echo "$(GREEN)---- Checker has been made ----$(END)"

clean :
	@$(RM) $(NAME)
	@echo "$(RED)---- Cleaned ----$(END)"

fclean : clean 
	@$(RM) $(BONUS_NAME)
	@echo "$(RED)---- All ----$(END)"

re : fclean all
