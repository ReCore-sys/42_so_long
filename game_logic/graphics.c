/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:06:51 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 02:58:01 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * Places the player in the game at the specified height and width coordinates.
 *
 * @param game The gamestate struct representing the current game.
 * @param height The height coordinate where the player should be placed.
 * @param width The width coordinate where the player should be placed.
 */
void	place_player(t_gamestate *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->player, \
		width * TILE_SIZE, height * TILE_SIZE);
	game->player_y = height;
	game->player_x = width;
}

/**
 * Places a collectable in the game at the specified height and width coordinates
 *
 * @param game The gamestate object representing the current state of the game.
 * @param height The height coordinate where the collectable should be placed.
 * @param width The width coordinate where the collectable should be placed.
 */
void	place_collectable(t_gamestate *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx,
		game->win, game->collectable, \
		width * TILE_SIZE, height * TILE_SIZE);
	game->collectables_counter++;
}

/**
 * Loads images for the game.
 *
 * @param game A pointer to the gamestate struct.
 */
void	load_images(t_gamestate *game)
{
	int	x;
	int	y;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &x, &y);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image(game->mlx,
			"assets/gold.xpm", &x, &y);
}

/**
 * Refreshes the graphics of the game.
 *
 * This function updates the game's display based on the current game state.
 * It takes a pointer to a `t_gamestate` structure as a parameter.
 *
 * @param game A pointer to the game state structure.
 */
void	refresh_graphics(t_gamestate *game)
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
