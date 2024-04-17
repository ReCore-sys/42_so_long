/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:34:24 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 02:56:05 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

/**
 * Updates the game map based on the movement of the player.
 *
 * This function is responsible for updating the game map after the player
 * moves to a new position. It takes the current game state, as well as the
 * new x and y coordinates of the player, and updates the map accordingly.
 *
 * @param game The current game state.
 * @param x The new x coordinate of the player.
 * @param y The new y coordinate of the player.
 * @return true if the map was successfully updated, false otherwise.
 */
static bool	move_update_map(t_gamestate *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables_counter != 0)
			return (false);
		printf("\nYou Have Won, Congrats!\n");
		shutdown_game(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->move_counter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->player_x = x;
		game->player_y = y;
		game->collectables_counter--;
		game->move_counter++;
	}
	return (true);
}

/**
 * Handles keyboard input for moving the player character up or down.
 *
 * @param game The game state.
 * @param movement The movement direction (-1 for up, 1 for down).
 * @return true if the movement was successful, false otherwise.
 */
static bool	keyboard_w_s(t_gamestate *game, int movement)
{
	int		temp_x;
	int		temp_y;
	bool	valid_move;

	temp_x = game->player_x;
	temp_y = game->player_y;
	if (movement == 13)
	{
		if (game->map[--temp_y][temp_x] == '1')
			return (false);
		valid_move = move_update_map(game, temp_x, temp_y);
		if (!valid_move)
			return (false);
		game->map[temp_y + 1][temp_x] = '0';
	}
	else if (movement == 1)
	{
		if (game->map[++temp_y][temp_x] == '1')
			return (false);
		valid_move = move_update_map(game, temp_x, temp_y);
		if (!valid_move)
			return (false);
		game->map[temp_y - 1][temp_x] = '0';
	}
	return (true);
}

/**
 * Handles keyboard input for moving the player character left or right.
 *
 * @param game The game state.
 * @param movement The movement direction (-1 for left, 1 for right).
 * @return true if the movement was successful, false otherwise.
 */
static bool	keyboard_a_d(t_gamestate *game, int movement)
{
	int		temp_x;
	int		temp_y;
	bool	valid_move;

	temp_x = game->player_x;
	temp_y = game->player_y;
	if (movement == 0)
	{
		if (game->map[temp_y][--temp_x] == '1')
			return (false);
		valid_move = move_update_map(game, temp_x, temp_y);
		if (!valid_move)
			return (false);
		game->map[temp_y][temp_x + 1] = '0';
	}
	else if (movement == 2)
	{
		if (game->map[temp_y][++temp_x] == '1')
			return (false);
		valid_move = move_update_map(game, temp_x, temp_y);
		if (!valid_move)
			return (false);
		game->map[temp_y][temp_x - 1] = '0';
	}
	return (true);
}

/**
 * Handles the input commands for the game.
 *
 * @param command The input command to be handled.
 * @param game The game state structure.
 * @return An integer representing the status of the input handling.
 */
int	input_handler(int command, t_gamestate *game)
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
