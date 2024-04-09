/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:42:44 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:42:46 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(t_game *data)
{
	if (data->map.rows == data->map.columns)
		throw_error(data, 'M', 0);
	if (data->map.rows <= 2 || data->map.columns <= 2)
		throw_error(data, 'M', 0);
}

void	check_assets(t_game *data)
{
	if (data->map.colection < 1)
		throw_error(data, 'M', 0);
	if (data->map.person != 1)
		throw_error(data, 'M', 0);
	if (data->map.exit != 1)
		throw_error(data, 'M', 0);
}

void	check_caracters(t_game *data)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			c = data->map.map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				throw_error(data, 'M', 0);
			j++;
		}
		i++;
	}
}

void	check_walls(t_game *data)
{
	int	i;
	int	j;
	int	c;

	c = data->map.columns - 1;
	i = 0;
	while (data->map.map[i])
	{
		if (i == 0 || i == (data->map.rows - 1))
		{
			j = 0;
			while (data->map.map[i][j])
			{
				if (data->map.map[i][j] != '1')
					throw_error(data, 'M', 0);
				j++;
			}
		}
		else
		{
			if (data->map.map[i][0] != '1' || data->map.map[i][c] != '1')
				throw_error(data, 'M', 0);
		}
		i++;
	}
}
