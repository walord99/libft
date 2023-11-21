# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bplante <bplante@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:49:55 by Ben               #+#    #+#              #
#    Updated: 2023/11/21 08:19:06 by bplante          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
FT				=	ft_bzero.c \
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
					ft_strcmp.c \
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
					ft_gonextword.c 

LST				=	ft_lstnew_bonus.c \
					ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c \
					ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
					ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c \
					ft_lstiter_bonus.c \
					ft_lstmap_bonus.c \
					ft_lstfind_one.c \
					ft_lstdel_element.c \
					ft_lst_to_tab.c \
					ft_lst_destory_nodes.c

PRINT			=	ft_printf.c \
					ft_printf_utils.c \
					ft_printf_options.c \
					ft_printf_convertion.c 

GET_NEXT		=	get_next_line.c \
					get_next_line_utils.c

LIB				= 	tab_len.c \
					free_tab.c \
					get_env.c

OBJ_FT			=	$(addprefix libft/, $(FT:.c=.o))
OBJ_LST			=	$(addprefix lst/, $(LST:.c=.o))
OBJ_PRINT		=	$(addprefix printf/, $(PRINT:.c=.o))
OBJ_GET_NEXT	=	$(addprefix get_next_line/, $(GET_NEXT:.c=.o))
OBJ_LIB			=	$(addprefix lib/, $(LIB:.c=.o))

OBJS_NO_DIR = $(OBJ_FT) $(OBJ_LST) $(OBJ_PRINT) $(OBJ_GET_NEXT) $(OBJ_LIB)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJS_NO_DIR))
NAME			=	libft.a
CFLAGS			=	-Wall -Werror -Wextra
LIBC			=	ar rcs
OBJ_DIR			=	obj

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	$(LIBC) $@ $(OBJS)

$(OBJ_DIR)/%.o : src/%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@ -g

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/libft
	mkdir -p $(OBJ_DIR)/lst
	mkdir -p $(OBJ_DIR)/printf
	mkdir -p $(OBJ_DIR)/get_next_line
	mkdir -p $(OBJ_DIR)/lib
	

clean:
	rm -rf $(OBJ_DIR)
	
fclean : clean
	rm -f $(NAME)

re: fclean all

test:
	echo $(OBJS)