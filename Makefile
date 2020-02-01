NAME		= ft_ssl
COMP		= gcc
FLAGS		= #-Wall -Wextra -Werror -O3
SRC			= main.c
SRC_DIR		= src/
OBJ_DIR		= obj/
OBJ			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
INC_DIR		= includes/ 
LIBFT_DIR	= libftprintf/
LIBFT		= $(LIBFT_DIR)libftprintf.a


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(COMP) -o $(NAME) $(OBJ) $(LIBFT)
	@printf "\033[1;32m$(NAME) created \033[0m\n"

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(OBJ): $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(COMP) -c $< -o $@ $(FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@printf "\033[1;33mobject deleted \033[0m\n"

fclean: clean
	@rm -rf $(NAME) $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@printf "\033[1;31m$(NAME) deleted \033[0m\n"

re: fclean all

.PHONY: all clean fclean re
