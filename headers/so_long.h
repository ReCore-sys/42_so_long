/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:15:54 by kshore            #+#    #+#             */
/*   Updated: 2024/04/22 14:48:06 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

# define TILE_SIZE 32

typedef struct s_gamestate
{
	// File descriptor for map file
	int		fd;

	// Map dimensions
	int		map_height;
	int		map_width;

	// Counters needed for setup
	int		playercounter;
	int		columncounter;
	int		exitcounter;

	// Player coordinates
	int		player_x;
	int		player_y;

	// Move counter
	int		move_counter;

	// Collectables counter
	int		collectables_counter;

	// The map
	char	**map;

	// Images
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectable;

	// MLX pointers
	void	*mlx;
	void	*win;

}	t_gamestate;

void	shutdown_game(t_gamestate *game);
bool	read_map_file(t_gamestate *game, char **argv);
int		input_handler(int command, t_gamestate *game);
void	refresh_graphics(t_gamestate *game);
void	load_images(t_gamestate *game);
void	walls_check(t_gamestate *game);
void	character_valid(t_gamestate *game);
bool	floodfill_check(t_gamestate *game, int x, int y);
void	reset_map(t_gamestate *game);
void	find_player(t_gamestate *game);

#endif
