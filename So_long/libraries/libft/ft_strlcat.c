/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:36:02 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:36:03 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;
	size_t	sizedest;
	size_t	sizesrc;

	sizesrc = ft_strlen(src);
	if (dst == NULL && size == 0)
		return (sizesrc);
	d = ft_strlen(dst);
	sizedest = d;
	if (size <= sizedest)
		return (size + sizesrc);
	s = 0;
	while (src[s] && d + 1 < size)
	{
		dst[d] = src[s];
		s++;
		d++;
	}
	dst[d] = 0;
	return (sizedest + sizesrc);
}
