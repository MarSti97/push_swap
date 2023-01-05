SRCS = push_swap.c altering.c checker.c list_func.c rotating.c algo.c ./libft/libft.a
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
	@cc $(FLAGS) $(SRCS) -I libft -o $(NAME) 

clean :
	@$(RM)
	@echo "$(RED)---- Cleaned ----$(END)"

fclean : clean 
	@$(RM) $(NAME)
	@echo "$(RED)---- All ----$(END)"

re : fclean all

.PHONY : all fclean clean re