/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:55:15 by yathayde          #+#    #+#             */
/*   Updated: 2023/11/06 13:30:39 by yathayde        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printchar(char c);
int	ft_printstr(const char *s);
int	ft_printnbr(int nb);
int	ft_printptr(unsigned long long ptr);
int	ft_print_unsint(unsigned int n);
int	ft_printhex(unsigned int n, const char c);
int	ft_printf(const char *s, ...);

#endif
