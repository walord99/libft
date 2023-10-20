# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bplante <bplante@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:49:55 by Ben               #+#    #+#              #
#    Updated: 2023/10/19 15:46:49 by bplante          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
SRC			=	ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c	\
				ft_substr.c	\
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_gonextword.c \
				ft_lstnew_bonus.c \
				\
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				\
				ft_printf.c \
				ft_printf_utils.c \
				ft_printf_options.c \
				ft_printf_convertion.c \
				\
				get_next_line.c \
				get_next_line_utils.c

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
NAME		=	libft.a
CFLAGS		=	-Wall -Werror -Wextra
LIBC		=	ar rcs
OBJ_DIR		=	obj

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(LIBC) $@ $(OBJS)

$(OBJ_DIR)/%.o : src/%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	
fclean : clean
	rm -f $(NAME)

re: fclean all
