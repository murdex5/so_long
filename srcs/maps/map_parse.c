/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:37:03 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 11:37:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(sizeof(t_map), 1);
	if (!map)
		return (NULL);
	map->collectibles = 0;
	map->content = NULL;
	map->exits = 0;
	map->height = 0;
	map->width = 0;
	map->map_changed = 0;
	map->enemy_present = 0;
	return (map);
}

int	read_map_files(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("So long");
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->content[i] = ft_strdup(line);
		free(line);
		if (!map->content[i])
			return (free_n_returnt(map->content, NULL, NULL), 0);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

t_map	*map_pop(t_map *map, char *path)
{
	map->content = ft_calloc(sizeof(char *), (count_lines(path) + 1));
	map->content[count_lines(path)] = NULL;
	if (!map->content)
		return (free_error("Memory allocation for content is failed", map),
			NULL);
	if (!read_map_files(map, path))
		return (free_error("Failed to read the map file", map), NULL);
	return (map);
}
