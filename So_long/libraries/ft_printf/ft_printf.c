/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:22:13 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:22:16 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(va_list args, const char type)
{
	int	len_print;

	len_print = 0;
	if (type == 'c')
		len_print += ft_printchar(va_arg(args, int));
	else if (type == 's')
		len_print += ft_printstr(va_arg(args, char *));
	else if (type == 'p')
		len_print += ft_printptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len_print += ft_printnbr(va_arg(args, int));
	else if (type == 'u')
		len_print += ft_print_unsint(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		len_print += ft_printhex(va_arg(args, unsigned int), type);
	else if (type == '%')
		len_print += ft_printchar('%');
	return (len_print);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len_printf;
	va_list	args;

	i = 0;
	len_printf = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			len_printf += ft_formats(args, s[i + 1]);
			i++;
		}
		else
			len_printf += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (len_printf);
}
