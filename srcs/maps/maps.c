/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:34:40 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 13:34:42 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_surrounded(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i])
	{
		if (map->content[i][0] != '1')
			return (0);
		if (map->content[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	if (!check_one(map->content[0], '0'))
		return (0);
	else if (!check_one(map->content[map->height - 1], '0'))
		return (0);
	return (1);
}

int	check_path(t_map *map)
{
	char	**map_copy;
	int		results;

	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	results = flood_filling(map, map_copy, map->player_x, map->player_y);
	free_ifnot_null(map_copy);
	return (results);
}

t_map	*parse_map(char *path)
{
	t_map	*map;

	if (!check_file_type(path))
		return (NULL);
	map = init_map();
	if (!map)
		return (free_error("Couldn't initialize the map", map), NULL);
	map = map_pop(map, path);
	if (!map)
		return (NULL);
	if (!check_map(map))
		return (free_error(NULL, map), NULL);
	if (check_path(map) <= 0)
		return (free_error("Path is not valid", map), NULL);
	return (map);
}
