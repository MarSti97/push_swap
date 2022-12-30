SRCS = push_swap.c ./libft/libft.a
FLAGS = -Wall -Werror -Wextra -g -fsanitize=address
NAME = push_swap
RM = rm -f

all : $(NAME)
	@echo successful compile

$(NAME) : $(SRCS)
	@cc $(FLAGS) $(SRCS) -I libft -o $(NAME) 

clean :
	@$(RM)
	@echo cleaned

fclean : clean 
	@$(RM) $(NAME)
	@echo fcleaned

re : fclean all