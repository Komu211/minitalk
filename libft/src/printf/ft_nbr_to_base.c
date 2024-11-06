/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_to_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:20:05 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/15 13:22:44 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <unistd.h>

static int	calc_num_digits(unsigned long num, int base_len)
{
	int	digits;

	digits = 0;
	while (num > 0)
	{
		num /= base_len;
		digits++;
	}
	return (digits);
}

static int	print_long_to_base(unsigned long num, char *base, int base_len)
{
	unsigned long	num_digits;
	char			*digits;
	int				p_chars;
	int				i;

	if (num == 0)
		return (write(1, "0", 1));
	num_digits = calc_num_digits(num, base_len);
	digits = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!digits)
		return (-1);
	i = num_digits;
	digits[i--] = '\0';
	while (num > 0)
	{
		digits[i--] = base[num % base_len];
		num /= base_len;
	}
	p_chars = write(1, digits, num_digits);
	free(digits);
	return (p_chars);
}

static int	print_int_to_base(unsigned int nbr, char *base, int base_len)
{
	int				i;
	int				p_chars;
	char			*digits;
	unsigned long	num_digits;

	if (nbr == 0)
		return (write(1, "0", 1));
	num_digits = calc_num_digits(nbr, base_len);
	digits = (char *)malloc((num_digits + 1) * sizeof(char));
	if (!digits)
		return (-1);
	i = num_digits;
	digits[i--] = '\0';
	while (nbr > 0)
	{
		digits[i--] = base[nbr % base_len];
		nbr /= base_len;
	}
	p_chars = write(1, digits, num_digits);
	free(digits);
	return (p_chars);
}

int	ft_put_long_base(unsigned long nbr, char *base)
{
	return (print_long_to_base(nbr, base, ft_strlen(base)));
}

int	ft_put_int_base(unsigned int nbr, char *base)
{
	return (print_int_to_base(nbr, base, ft_strlen(base)));
}
