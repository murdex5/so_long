/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:40:30 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 11:40:31 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	get_hw(map);
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
			j++;
		if (j != map->width)
			return (0);
		i++;
	}
	if (i != map->height)
		return (0);
	return (1);
}

int	check_collectibles(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'C')
				map->collectibles++;
			j++;
		}
		i++;
	}
	if (map->collectibles == 0)
		return (0);
	return (1);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'P')
			{
				map->player_y = i;
				map->player_x = j;
				map->content[i][j] = '0';
				map->player_count++;
			}
			j++;
		}
		i++;
	}
	if (map->player_count != 1)
		return (0);
	return (1);
}

int	check_exits(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->content[i])
	{
		j = 0;
		while (map->content[i][j])
		{
			if (map->content[i][j] == 'E')
				map->exits++;
			j++;
		}
		i++;
	}
	if (map->exits != 1)
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	if (!check_rectangular(map))
		return (err_msg_std("The map should be rectangular"), 0);
	if (!check_surrounded(map))
		return (err_msg_std("The map is not surrounded"), 0);
	if (!check_forbidden_chars(map))
		return (0);
	if (!check_exits(map))
		return (err_msg_std("Ther are no or one too many exits"), 0);
	if (!check_collectibles(map))
		return (err_msg_std("There should be atleast One collectible"), 0);
	if (!check_player(map))
		return (err_msg_std("There are no or too many players"), 0);
	if (!check_enemy(map))
		return (ft_printf("Couldn't find the Enemy in the map (optional)\n"),
			1);
	return (1);
}
