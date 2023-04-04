# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ben <benplante99@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:49:55 by Ben               #+#    #+#              #
#    Updated: 2023/04/04 13:06:13 by Ben              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	gcc
SRC			= 	ft_bzero.c \
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
				ft_gonextword.c

BONUS_SRC	= 	ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c
			
OBJS		= 	$(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
BONUS_OBJS	= 	$(addprefix $(BIN_DIR)/, $(BONUS_SRC:.c=.o))
DEBUG_OBJS	= 	$(addprefix debug_dir/, $(SRC:.c=.o))
NAME		= 	libft.a
CFLAGS		= 	-Wall -Werror -Wextra
LIBC		= 	ar rcs
RM			= 	rm -f
RM_DIR		=	rm -rf
BIN_DIR		= 	bin
VPATH		=	.

all : $(NAME)

$(BIN_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(BIN_DIR) $(OBJS)
	$(LIBC) $@ $(OBJS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	$(RM_DIR) $(BIN_DIR)
	
fclean : clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME) $(BIN_DIR) $(BONUS_OBJS)
	$(LIBC) libft.a $(BONUS_OBJS)

debug_dir/%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ -g

debug_dir:
	mkdir -p debug_dir

debug: debug_dir $(DEBUG_OBJS) $(NAME)
	$(LIBC) debug_dir/libft.a $(DEBUG_OBJS)
	gcc -g testmain.c debug_dir/libft.a
	lldb a.out
