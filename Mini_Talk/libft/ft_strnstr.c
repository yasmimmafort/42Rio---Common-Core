/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:18:04 by yathayde          #+#    #+#             */
/*   Updated: 2023/10/19 17:26:42 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (lil[0] == '\0')
		return ((char *) big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == lil[j] && (i + j) < len)
		{
			if (big[i + j] == '\0' && lil[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (lil[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
