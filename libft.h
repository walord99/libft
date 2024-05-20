/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <benplante99@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:51:05 by bplante           #+#    #+#             */
/*   Updated: 2024/05/20 13:44:31 by bplante          ###   ########.fr       */
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
char				*ft_strndup(char *str, int len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
int					count_words(const char *str, char delemiter);
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

/**
 * @brief Allocates a new node,
	add's it at the start and return the pointer to the first element
 *
 * @param lst List pointer, NULL if there is no list yet
 * @param content Content to be added
 * @return First element to the list
 */
t_list				*ft_lstadd_front(t_list *list, void *content);

/**
 * @brief Get the last node of the list, NULL if none or an error has occured
 *
 * @param lst List pointer
 * @return Last node
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Get the size of the list, 0 if NULL
 *
 * @param lst List pointer
 * @return Size
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Allocates a new node,
	add's it to the end and return the pointer to the first element
 *
 * @param lst List pointer, NULL if there is no list yet
 * @param content Content to be added
 * @return First element to the list
 */
t_list				*ft_lstadd_back(t_list *lst, void *content);

/**
 * @brief Deletes a node and it's content without relinking
 *
 * @param lst List pointer
 * @param del Function to delete content
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes a list with its content
 *
 * @param lst List Pointer
 * @param del
 * @return t_list*
 */
void				ft_lstclear(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *));

/**
 * @brief Finds a node when the equal returns true.
 * Returns NULL when none is found or an error has occured
 *
 * @param list List pointer
 * @param equal Function to compare contents
 * @param data The content you want it to be equal to
 * @return The node found
 */
t_list				*ft_lstfind_one(t_list *list, bool (*equal)(void *, void *),
						void *data);

/**
 * @brief Remove a node and it's content from the list and return a
 * pointer to the new list start
 *
 * @param list List pointer
 * @param node
 * @param del
 * @return t_list*
 */
t_list				*ft_lstdel_element(t_list *list, t_list *node,
						void (*del)(void *));

/**
 * @brief Return a NULL terminated pointer array to the contents of the list.
 * Returns NULL if an error has occured. Does not copy content.
 *
 * @param list List pointer
 * @return Pointer array
 */
void				*lst_to_tab(t_list *list);

/**
 * @brief Deletes all the nodes and keep content allocated
 *
 * @param list List pointer
 */
void				lst_destroy_nodes(t_list *list);

typedef struct s_options
{
	char			flag;
	int				width;
	int				precision;
	char			specifier;
}					t_options;

/**
 * @brief Prints a formated string to STDOUT
 *
 * @param str Available formats: %cspdiux
 * @param ...
 * @return The ammoount of character printed
 */
int					ft_printf(const char *str, ...);

/**
 * @brief Prints a formated string to the file descriptor
 *
 * @param str Available formats: %cspdiux
 * @param fd File descriptor
 * @param ...
 * @return The ammoount of character written
 */

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
int					ft_putstr_e(char *str, t_options *options, int fd);
int					format(va_list args, char **str, int char_amount, int fd);
char				*specifier_selector(va_list args, char c);

# define BUFFER_SIZE 20

/**
 * @brief Returns an allocated string containing the next line from the fd.
 * Returns NULL if reached EOF or an error has occured
 *
 * @param fd File descriptor
 * @param include_NL If the function should include the NL character if present
 * @return The line
 */
char				*get_next_line(int fd, bool include_NL);

# define FREE_S1 1
# define FREE_S2 2
# define FREE_ALL 3

/**
 * @brief Joins 2 strings with the possibility of automatically freeing.
 * Use ft_strjoin if not freeing anything
 *
 * @param s1 First string
 * @param s2 Second string
 * @param options FREE_S1 FREE_S2 FREE_ALL
 * @return Allocated new string
 */
char				*ft_strjoin_free(char *s1, char *s2, int options);
char				*ft_strjoin_va(int arg_count, ...);

/**
 * @brief Returns the lenght of a NULL terminated pointer array
 *
 * @param arr Array pointer
 * @return Lenght
 */
int					tab_len(void **arr);

/**
 * @brief Free a NULL terminated pointer array
 *
 * @param arr Array pointer
 * @param del Function pointer to delete contained struct
 */
void				free_tab(void **arr, void (*del)(void *));

/**
 * @brief Get a value from the environment according to the key
 *
 * @param env Environment array
 * @param key The key
 * @return String containing the value
 */
const char			*get_env(char **env, char *key);
/**
 * @brief Return the absolute value of an integer
 *
 * @param i Int
 * @return Absolute value
 */
int					abs(int i);


/**
 * @brief Check if string is an int that doesnt overflow
 * 
 * @param str The string
 * @return bool
 */
bool				is_string_valid_int(char *str);

#endif
