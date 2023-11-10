/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:51:05 by bplante           #+#    #+#             */
/*   Updated: 2023/11/10 03:10:30 by bplante          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *dest, int c, size_t len);
void				ft_bzero(void *dest, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t				ft_strlcat(char *dest, const char *src, size_t destsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(char *s1, char *s2);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *heystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t n, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				*ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				ft_num_to_char(int n);
int					ft_go_next_word(const char *str, char delemiter);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstadd_front(t_list *list, void *content);
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstadd_back(t_list *lst, void *content);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
t_list				*ft_lstclear(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *));
t_list				*ft_lstfind_one(t_list *list, bool (*equal)(void *, void *),
						void *data);
t_list				*ft_lstdel_element(t_list *list, t_list *node,
						void (*del)(void *));

typedef struct s_options
{
	char			flag;
	int				width;
	int				precision;
	char			specifier;
}					t_options;

int					ft_printf(const char *str, ...);
int					ft_printf_fd(const char *str, int fd, ...);
int					get_flag(char *str, t_options *options);
int					get_width(char *str, t_options *options);
int					get_precision(char *str, t_options *options);
int					get_specifier(char *str, t_options *options);
int					get_options(char *str, t_options *options);
int					number_char_amount(int n);
char				*char_to_str(char c);
char				*arg_to_int(int i);
char				*arg_to_str(char *str);
char				*arg_to_uint_hex(unsigned long num, int is_caps);
char				num_to_hex(int num, int is_caps);
char				*arg_to_uint(unsigned int num);
char				*arg_to_ptr(void *ptr);
int					ft_putstr_e(char *str, t_options *options);
int					format(va_list args, char **str, int char_amount);
char				*specifier_selector(va_list args, char c);

# define BUFFER_SIZE 20

char				*get_next_line(int fd, bool include_NL);
char				*ft_strjoin_free(char *s1, char *s2);

int					tab_len(void **arr);
void				free_tab(void **arr, void *(del)(void *));
char				*get_env(char **env, char *key);
#endif
