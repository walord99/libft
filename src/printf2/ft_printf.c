/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante/Walord <benplante99@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:16:27 by bplante           #+#    #+#             */
/*   Updated: 2023/12/12 02:11:41 by bplante/Wal      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print(const char *str, int fd, va_list args);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = print(str, 1, args);
	va_end(args);
	return (ret);
}

int	ft_printf_fd(const char *str, int fd, ...)
{
	va_list	args;
	int		ret;

	va_start(args, fd);
	ret = print(str, fd, args);
	va_end(args);
	return (ret);
}

int	write_segments(t_list *segments, int fd)
{
	int		len;
	char	*joined;
	int		i;
	t_list	*tmp;

	tmp = segments;
	len = 0;
	while (segments)
	{
		len += ft_strlen((char *)segments->content);
		segments = segments->next;
	}
	joined = ft_calloc(len + 1, sizeof(char));
	i = 0;
	while (tmp)
	{
		ft_strcpy(&joined[i], (char *)tmp->content);
		i += ft_strlen((char *)tmp->content);
		tmp = tmp->next;
	}
	write(fd, joined, len);
	return (len);
}

int	print(const char *str, int fd, va_list args)
{
	t_list	*segments;
	int		i;

	segments = NULL;
	i = 0;
	while (str[i] != 0)
	{
		while (str[i] != '%' && str[i] != 0)
			i++;
		ft_lstadd_back(segments, ft_strndup(str, i - 1));
		ft_lstadd_back(segments, specifier_selector(args, str[i + 1]));
		i += 2;
	}
	ft_lstclear(segments, &free);
}

char	*specifier_selector(va_list args, char c)
{
	if (c == 'c')
		return (char_to_str(va_arg(args, unsigned int)));
	else if (c == 's')
		return (arg_to_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'x')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (arg_to_uint_hex(va_arg(args, unsigned int), 1));
	else if (c == '%')
		return (ft_strdup("%"));
	else if (c == 'u')
		return (arg_to_uint(va_arg(args, unsigned int)));
	else
		return (arg_to_ptr(va_arg(args, void *)));
}

// char	*apply_options(char *str, t_options options)
// {
// 	if(options.width != 0)
// 	{

// 	}
// }
