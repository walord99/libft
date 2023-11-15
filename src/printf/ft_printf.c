/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bplante <bplante@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:16:27 by bplante           #+#    #+#             */
/*   Updated: 2023/11/10 06:19:01 by bplante          ###   ########.fr       */
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

int	print(const char *str, int fd, va_list args)
{
	int	char_amount;

	char_amount = 0;
	while (*str)
	{
		if (*str != '%')
		{
			if (write(fd, str, 1) == -1)
				return (-1);
			char_amount++;
		}
		else
		{
			str++;
			char_amount = format(args, (char **)&str, char_amount, fd);
			if (char_amount == -1)
				return (-1);
		}
		str++;
	}
	return (char_amount);
}

int	format(va_list args, char **str, int char_amount, int fd)
{
	char		*output;
	int			i;
	t_options	*options;

	options = ft_calloc(sizeof(t_options), 1);
	if (!options)
		return (-1);
	if (get_options(*str, options) == -1)
		return (-1);
	*str = ft_strchr(*str, options->specifier);
	output = specifier_selector(args, options->specifier);
	if (!output)
	{
		free(options);
		return (-1);
	}
	i = ft_putstr_e(output, options, fd);
	free(options);
	free(output);
	if (i == -1)
		return (-1);
	return (char_amount + i);
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
