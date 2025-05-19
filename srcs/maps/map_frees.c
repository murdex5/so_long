/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_frees.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:04:47 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 11:04:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_content(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_ifnot_null(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] != NULL)
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->content)
		free_content(map->content);
	map->collectibles = 0;
	map->width = 0;
	map->height = 0;
	map->exits = 0;
	map->player_x = 0;
	map->player_y = 0;
	free(map);
	map = NULL;
}

int	free_error(char *msg, t_map *map)
{
	if (msg)
		err_msg_std(msg);
	free_map(map);
	return (1);
}
