/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:52:10 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/12 13:52:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
		return (NULL);
	player->idle_right = NULL;
	player->idle_left = NULL;
	player->runing_right = NULL;
	player->runing_left = NULL;
	player->player_state = 0;
	player->player_dir = 0;
	return (player);
}

t_player	*player_pop(t_vars *vars)
{
	t_player	*player;

	player = init_player();
	if (!player)
		return (NULL);
	player->heigth = vars->map->player_y;
	player->width = vars->map->player_x;
	player->idle_right = load_animation(vars,
			"assets/player/player_idle/right/", 64, 64);
	player->idle_left = load_animation(vars, "assets/player/player_idle/left/",
			64, 64);
	player->runing_right = load_animation(vars,
			"assets/player/player_run/right/", 64, 64);
	player->runing_left = load_animation(vars, "assets/player/player_run/left/",
			64, 64);
	if (!player->idle_right || !player->runing_right)
		return (free_player(vars, player), NULL);
	return (player);
}
