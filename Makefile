NAME		=		push_swap

BONUS_NAME	=		checker

CC			=		cc

CFLAGS		=		-Wall -Wextra -Werror

SRC			=		src/push_swap.c src/utils.c src/operations.c src/operations_two.c src/operations_three.c\
					src/sort.c src/free_all.c src/utils_two.c src/norm_helper.c src/norm_helper_two.c

SRC_BONUS	=		src/utils.c src/sort.c src/free_all.c src/utils_two.c src/norm_helper.c src/norm_helper_two.c\
					src_bonus/push_swap_bonus.c src_bonus/operations_bonus.c src_bonus/operations_two_bonus.c src_bonus/operations_three_bonus.c\
					gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ			=		$(SRC:.c=.o)

OBJ_BONUS	=		$(SRC_BONUS:.c=.o)

all			:		$(NAME)

bonus		:		$(OBJ_BONUS)
					make -s -C libft
					$(CC) $(CFLAGS) $(OBJ_BONUS) libft/libft.a -o $(BONUS_NAME)

$(NAME)		:		$(OBJ)
					make -s -C libft
					$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean		:
					make -s clean -C libft
					rm -rf $(OBJ)
					rm -rf $(OBJ_BONUS)

fclean		:		clean
					rm -rf $(NAME)
					rm -rf $(BONUS_NAME)
					make -s fclean -C libft

re			:		fclean all

.PHONY		:		all clean fclean re bonus
