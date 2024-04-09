/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:42:56 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:42:58 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_ber(char *file)
{
	int	i;
	int	j;

	i = ft_strlen(file);
	j = 1;
	while (j < 5)
	{
		if (file[i - j] != 'r' && file[i - j] != 'e'
			&& file[i - j] != 'b' && file[i - j] != '.')
		{
			ft_printf("Error: This file is not .ber\n");
			exit(1);
		}
		j++;
	}
}

void	check_file(char *file)
{
	int		fd;

	check_file_ber(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Unable to find this map\n");
		exit(1);
	}
	close(fd);
}
