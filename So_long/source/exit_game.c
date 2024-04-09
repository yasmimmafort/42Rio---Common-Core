/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:43:13 by yathayde          #+#    #+#             */
/*   Updated: 2024/04/09 11:43:15 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	throw_error(t_game *data, char e, int img)
{
	if (e == 'M')
	{
		ft_printf("Error: This map is irregular\n");
		free_map(data->map.map);
		exit(1);
	}
	destroy_window(data, img);
	exit(1);
}

int	destroy_window(t_game *data, int img)
{
	free_map(data->map.map);
	if (img)
	{
		mlx_destroy_image(data->ptr_mlx, data->img.img_exit);
		mlx_destroy_image(data->ptr_mlx, data->img.img_gram);
		mlx_destroy_image(data->ptr_mlx, data->img.img_kidb);
		mlx_destroy_image(data->ptr_mlx, data->img.img_kidf);
		mlx_destroy_image(data->ptr_mlx, data->img.img_kidl);
		mlx_destroy_image(data->ptr_mlx, data->img.img_kidr);
		mlx_destroy_image(data->ptr_mlx, data->img.img_pok);
		mlx_destroy_image(data->ptr_mlx, data->img.img_tree);
	}
	mlx_destroy_window(data->ptr_mlx, data->w_mlx);
	mlx_destroy_display(data->ptr_mlx);
	free(data->ptr_mlx);
	exit(0);
	return (0);
}
