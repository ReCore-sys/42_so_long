/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:34:01 by kshore            #+#    #+#             */
/*   Updated: 2024/04/18 01:27:04 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	get_map_width(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_line(t_complete *game, char *line)
{
	char	**temporary;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->map_height++;
	temporary = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	temporary[game->map_height] = NULL;
	while (i < game->map_height - 1)
	{
		temporary[i] = game->map[i];
		i++;
	}
	temporary[i] = line;
	if (game->map)
		free(game->map);
	game->map = temporary;
	return (1);
}

int	read_map_file(t_complete *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	readmap = get_next_line(game->fd);
	while (add_line(game, readmap))
	{
		readmap = get_next_line(game->fd);
	}
	close (game->fd);
	game->map_width = get_map_width(game->map[0]);
	return (1);
}
