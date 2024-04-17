/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:34:24 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 02:00:19 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	move_update_map(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables_counter != 0)
			return (0);
		printf("\nYou Have Won, Congrats!\n");
		shutdown_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->move_counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->player_x = i;
		game->player_y = j;
		game->collectables_counter--;
		game->move_counter++;
	}
	return (1);
}

static int	keyboard_w_s(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 13)
	{
		if (game->map[--j][i] == '1')
			return (0);
		k = move_update_map(game, i, j);
		if (!k)
			return (0);
		game->map[j + 1][i] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++j][i] == '1')
			return (0);
		k = move_update_map(game, i, j);
		if (!k)
			return (0);
		game->map[j - 1][i] = '0';
	}
	return (1);
}

static int	keyboard_a_d(t_complete *game, int movement)
{
	int	i;
	int	j;
	int	k;

	i = game->player_x;
	j = game->player_y;
	if (movement == 0)
	{
		if (game->map[j][--i] == '1')
			return (0);
		k = move_update_map(game, i, j);
		if (!k)
			return (0);
		game->map[j][i + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[j][++i] == '1')
			return (0);
		k = move_update_map(game, i, j);
		if (!k)
			return (0);
		game->map[j][i - 1] = '0';
	}
	return (1);
}

int	input_handler(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		shutdown_game(game);
	if (command == 13)
		works = keyboard_w_s(game, command);
	if (command == 1)
		works = keyboard_w_s(game, command);
	if (command == 0)
		works = keyboard_a_d(game, command);
	if (command == 2)
		works = keyboard_a_d(game, command);
	if (works)
	{
		refresh_graphics(game);
		printf("Steps Taken: %i\n", game->move_counter);
		printf("Collectables Remaining: %i\n", game->collectables_counter);
	}
	return (1);
}
