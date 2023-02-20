CC		= 	gcc
SRC		= 	ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
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
			ft_substr.c
OBJS	= 	$(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
NAME	= 	libft.a
CFLAGS	= 	-Wall -Werror -Wextra
LIBC	= 	ar rc
LIBR	= 	ranlib
RM		= 	rm -f
RM_DIR	=	rm -rf
BIN_DIR	= 	bin
VPATH	=	.

all : $(NAME)

$(BIN_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(BIN_DIR) $(OBJS)
	$(LIBC) $@ $(OBJS)
	$(LIBR) $(NAME)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	$(RM_DIR) $(BIN_DIR)
	

fclean : clean
	$(RM) $(NAME)

re: fclean all

	