/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:49:02 by kshore            #+#    #+#             */
/*   Updated: 2024/04/22 14:49:23 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * Shuts down the game and frees the allocated memory.
 *
 * @param game The gamestate structure containing the game data.
 */
void	shutdown_game(t_gamestate *game)
{
	int	line;

	line = 0;
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	while (line < game->map_height - 1)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_gamestate	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_gamestate));
	if (!read_map_file(&game, argv))
		return (ft_printf("Could not load map file, does it exist?\n"), 0);
	(walls_check(&game), character_valid(&game));
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, (game.map_width * TILE_SIZE),
			(game.map_height * TILE_SIZE), "so_long");
	load_images(&game);
	refresh_graphics(&game);
	mlx_key_hook(game.win, input_handler, &game);
	mlx_hook(game.win, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlx);
}
