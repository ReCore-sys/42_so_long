/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:06:51 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 01:26:23 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->player, \
		width * TILE_SIZE, height * TILE_SIZE);
	game->player_y = height;
	game->player_x = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->collectable, \
		width * TILE_SIZE, height * TILE_SIZE);
	game->collectables_counter++;
}

void	place_image(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"assets/gold.xpm", &i, &j);
}

void	refresh_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables_counter = 0;
	height = -1;
	while (++height < game->map_height)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
			game->wall, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
			game->exit, width * TILE_SIZE, height * TILE_SIZE);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx, game->win, \
			game->floor, width * TILE_SIZE, height * TILE_SIZE);
		}
	}
}
