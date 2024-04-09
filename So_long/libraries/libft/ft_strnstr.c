/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:36:32 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:36:34 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenl;

	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	j = 0;
	lenl = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i + j] == little
			[j] && i + j < len && big[i + j] != '\0')
			j++;
		if (j == lenl)
			return ((char *)(big + i));
		j = 0;
		i++;
	}
	return (NULL);
}
