/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:23:37 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/06 13:04:01 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_char(char c)
{
	return (write(1, &c, 1));
}

static int	ft_handle_arg(va_list *args, char type)
{
	if (type == '%')
		return (print_char('%'));
	else if (type == 'c')
		return (print_char(va_arg(*args, int)));
	else if (type == 's')
		return (str_fd(va_arg(*args, char *)));
	else if (type == 'p')
		return (ft_printf_ptr(va_arg(*args, void *), "0123456789abcdef"));
	else if (type == 'i' || type == 'd')
		return (ft_printf_digit(va_arg(*args, int)));
	else if (type == 'u')
		return (ft_printf_unsigned_digit(va_arg(*args, unsigned int)));
	else if (type == 'x')
		return (ft_put_int_base((unsigned long)va_arg(*args, int),
				"0123456789abcdef"));
	else if (type == 'X')
		return (ft_put_int_base((unsigned long)va_arg(*args, int),
				"0123456789ABCDEF"));
	return (-1);
}

static int	next_special(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '%')
		i++;
	if (s[i] == '%')
		return (i);
	return (i);
}

static int	ft_printf_process_format(const char *format, va_list *args)
{
	int	p_len;
	int	i;
	int	tmp;
	int	arg_res;

	p_len = 0;
	i = 0;
	while (format[i])
	{
		tmp = ft_putstrn_fd((char *)format + i, next_special(format + i), 1);
		if (tmp == -1)
			return (-1);
		p_len += tmp;
		i += tmp;
		if (format[i] == '%')
		{
			arg_res = ft_handle_arg(args, format[i + 1]);
			if (arg_res == -1)
				return (-1);
			p_len += arg_res;
			i += 2;
		}
	}
	return (p_len);
}

int	ft_printf(const char *format, ...)
{
	int		p_len;
	va_list	args;

	va_start(args, format);
	p_len = ft_printf_process_format(format, &args);
	va_end(args);
	return (p_len);
}
