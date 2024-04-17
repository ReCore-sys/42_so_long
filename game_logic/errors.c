/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:33:01 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 02:56:39 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * Checks if the top and bottom of the map have solid walls.
 *
 * @param game The game state.
 * @return true if the map has walls on the top and bottom, false otherwise.
 */
static bool	horizontal_walls_check(t_gamestate *game)
{
	int	i;
	int	j;

	i = game->map_width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->map_height - 1][j] == '1')
			return (false);
		j++;
	}
	return (true);
}

/**
 * Checks if the left and right of the map have solid walls.
 *
 * @param game The game state.
 * @return true if the map has walls on the left and right, false otherwise.
 */
static bool	vertical_walls_check(t_gamestate *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
			return (false);
		height++;
	}
	return (true);
}

/**
 * Checks if the map has walls on all sides.
 *
 * @param game The game state.
 */
void	walls_check(t_gamestate *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!vertical_walls_check(game) || !horizontal_walls_check(game))
	{
		printf("\nThis map is missing the walls\n");
		shutdown_game(game);
	}
	find_player(game);
	if (!floodfill_check(game, game->player_x, game->player_y))
	{
		printf("\nThis map is not solvable\n");
		shutdown_game(game);
	}
	reset_map(game);
}

/**
 * Is run on every tile of the map to check if the characters are valid.
 *
 * @param game The game state.
 */
static void	count_checker(t_gamestate *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
		game->map[height][width] != '0' &&
		game->map[height][width] != 'P' &&
		game->map[height][width] != 'E' &&
		game->map[height][width] != 'C' &&
		game->map[height][width] != '\n')
	{
		printf("\nError Here!%c\n", game->map[height][width]);
		shutdown_game(game);
	}
	if (game->map[height][width] == 'C')
		game->columncounter++;
	if (game->map[height][width] == 'P')
	{
		game->playercounter++;
	}
	if (game->map[height][width] == 'E')
		game->exitcounter++;
}

/**
 * Checks if the characters in the map are valid.
 *
 * @param game The game state.
 */
void	character_valid(t_gamestate *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height - 1)
	{
		width = 0;
		while (width <= game->map_width)
		{
			count_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (!(game->playercounter == 1 && game->columncounter > 1
			&& game->exitcounter == 1))
	{
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		shutdown_game(game);
	}
}
