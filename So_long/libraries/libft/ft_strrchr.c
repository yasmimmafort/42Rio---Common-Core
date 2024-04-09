/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:36:39 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:36:41 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len_s;

	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len_s >= 0)
	{
		if (s[len_s] == c)
			return ((char *)(s + len_s));
		len_s--;
	}
	return (NULL);
}
