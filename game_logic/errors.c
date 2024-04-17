/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:33:01 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 01:12:40 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	horizontalwall(t_complete *game)
{
	int	i;
	int	j;

	i = game->map_width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] == '1' && game->map[game->map_height - 1][j] == '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_complete *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}

void	if_walls(t_complete *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nThis map is missing the walls\n");
		shutdown_game(game);
	}
}

static void	count_checker(t_complete *game, int height, int width)
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
		game->playercounter++;
	if (game->map[height][width] == 'E')
		game->exitcounter++;
}

void	character_valid(t_complete *game)
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
