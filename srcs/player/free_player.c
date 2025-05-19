/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:49:50 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:49:52 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_player(t_vars *vars, t_player *player)
{
	if (!player)
		return ;
	if (player->idle_left)
	{
		free_animation(vars, player->idle_left);
		player->idle_left = NULL;
	}
	if (player->idle_right)
	{
		free_animation(vars, player->idle_right);
		player->idle_right = NULL;
	}
	if (player->runing_left)
	{
		free_animation(vars, player->runing_left);
		player->runing_left = NULL;
	}
	if (player->runing_right)
	{
		free_animation(vars, player->runing_right);
		player->runing_right = NULL;
	}
	free(player);
	player = NULL;
}
