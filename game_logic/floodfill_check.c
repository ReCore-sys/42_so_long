/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 02:24:00 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 02:57:10 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * Performs a flood fill check on the game board starting from the specified 
 * coordinates (x, y).
 * 
 * @param game The gamestate object representing the current state of the game.
 * @param x The x-coordinate of the starting point for the flood fill check.
 * @param y The y-coordinate of the starting point for the flood fill check.
 * @return true if the flood fill check is successful, indicating that the area 
 * is fully connected; false otherwise.
 */
bool	floodfill_check(t_gamestate *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_width || y >= game->map_height)
		return (false);
	if (game->map[y][x] == '1' || game->map[y][x] == 'V' \
		|| game->map[y][x] == 'I')
		return (false);
	if (game->map[y][x] == 'E')
		return (true);
	if (game->map[y][x] == 'C')
		game->map[y][x] = 'I';
	else
		game->map[y][x] = 'V';
	if (floodfill_check(game, x + 1, y) || floodfill_check(game, x - 1, y)
		|| floodfill_check(game, x, y + 1) || floodfill_check(game, x, y - 1))
		return (true);
	return (false);
}

/**
 * Resets the game map.
 *
 * This function resets the game map by clearing all the special tiles used for 
 * floodfill and resetting the player's position and score.
 *
 * @param game A pointer to the gamestate struct.
 */
void	reset_map(t_gamestate *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'V')
				game->map[i][j] = '0';
			if (game->map[i][j] == 'I')
				game->map[i][j] = 'C';
			j++;
		}
		i++;
	}
	game->map[game->player_y][game->player_x] = 'P';
}

/**
 * Finds the player in the game state.
 *
 * @param game The game state.
 */
void	find_player(t_gamestate *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
