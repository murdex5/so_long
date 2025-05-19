/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:56:03 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 14:56:04 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	on_key_press_exit(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->player)
	{
		free_player(vars, vars->player);
		vars->player = NULL;
	}
	if (vars->enemy)
		free_enemy(vars, vars->enemy);
	free_textures(vars);
	if (vars->mlx)
	{
		if (vars->buffer_map)
			mlx_destroy_image(vars->mlx, vars->buffer_map);
		vars->buffer_map = NULL;
		if (vars->win)
			mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		vars->mlx = NULL;
	}
	free_vars(vars);
}

void	exceeds_limits(int min, int max_width, int max_height, t_vars *vars)
{
	if (vars->map->width >= max_width)
		vars->map->width = max_width - 1;
	if (vars->map->width <= min)
		vars->map->width = min + 1;
	if (vars->map->height >= max_height)
		vars->map->height = max_height - 1;
	if (vars->map->height <= min)
		vars->map->height = min + 1;
}

void	player_move(int keysym, t_vars *vars)
{
	int	new_x;
	int	new_y;

	new_x = vars->map->player_x;
	new_y = vars->map->player_y;
	if (keysym == W)
		new_y -= 1;
	else if (keysym == A)
		new_x -= 1;
	else if (keysym == S)
		new_y += 1;
	else if (keysym == D)
		new_x += 1;
	replace_tile(vars, new_x, new_y);
	exited(vars, new_x, new_y);
	if (vars->map->content[new_y][new_x] != '1')
	{
		vars->map->player_x = new_x;
		vars->map->player_y = new_y;
		vars->player->player_state = 1;
		vars->moves++;
	}
	if (vars->map->content[new_y][new_x] == 'C')
		vars->map->collectibles -= 1;
	vars->map->map_changed = 1;
}

int	on_keypress(int keysym, t_vars *vars)
{
	if (keysym == ESC)
	{
		on_key_press_exit(vars);
		exit(0);
	}
	diter_dir(keysym, vars);
	if (keysym == W || keysym == A || keysym == S || keysym == D)
	{
		player_move(keysym, vars);
	}
	return (0);
}
