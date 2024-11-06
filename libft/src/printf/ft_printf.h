/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:20:50 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/15 13:10:29 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstrn_fd(char *s, int n, int fd);
int		str_fd(char *str);
int		ft_put_long_base(unsigned long nbr, char *base);
int		ft_printf_ptr(void *ptr, char *base);
int		ft_printf_digit(int num);
int		ft_printf_unsigned_digit(unsigned int num);
char	*ft_uitoa(unsigned int n);
int		ft_put_int_base(unsigned int nbr, char *base);

#endif