# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:50:03 by rmoutaou          #+#    #+#              #
#    Updated: 2023/11/13 23:46:20 by rmoutaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=		libft.a

MAN_SOURCE_FILES	=		ft_atoi.c ft_putendl_fd.c ft_strncmp.c \
							ft_bzero.c ft_putnbr_fd.c ft_strnstr.c \
							ft_calloc.c ft_putstr_fd.c ft_strrchr.c \
							ft_isalnum.c ft_split.c ft_strtrim.c \
							ft_isalpha.c ft_strchr.c ft_substr.c \
							ft_isascii.c ft_strdup.c ft_tolower.c \
							ft_isdigit.c ft_memchr.c ft_toupper.c \
							ft_isprint.c ft_memcmp.c ft_strjoin.c \
							ft_itoa.c ft_memcpy.c ft_strlcat.c \
							ft_memmove.c ft_strlcpy.c \
							ft_memset.c ft_strlen.c \
							ft_putchar_fd.c ft_strmapi.c ft_striteri.c \

BON_SOURCE_FILES	=		ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
							ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
							ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
							ft_lstmap_bonus.c

MAN_OBJECT_FILES	=		$(MAN_SOURCE_FILES:.c=.o)
BON_OBJECT_FILES	=		$(BON_SOURCE_FILES:.c=.o)

COMPILER 			= 		cc
FLAGS				=		-Wall -Wextra -Werror
LIBRARY_AR			=		ar rc

%.o	:		%.c 
			$(COMPILER) $(FLAGS) -c -o $@ $<

$(NAME):	$(MAN_OBJECT_FILES)
			$(LIBRARY_AR) $@ $^

all:		$(NAME)

bonus:		$(BON_OBJECT_FILES)
			$(LIBRARY_AR) $(NAME) $^

clean:
			rm -f $(MAN_OBJECT_FILES) $(BON_OBJECT_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus