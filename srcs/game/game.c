/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:17:48 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/10 14:17:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	make_window(t_vars *vars)
{
	if (!vars || !vars->mlx)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->win = mlx_new_window(vars->mlx, vars->map->width * 64,
			vars->map->height * 64, "Knight game");
	if (!vars->win)
	{
		err_msg_std("Failed to create a Window");
		mlx_destroy_display(vars->mlx);
		return (0);
	}
	return (1);
}

int	get_map(t_vars *vars, char *path)
{
	if (!vars || !vars->mlx)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->map = parse_map(path);
	if (!vars->map)
	{
		free_map(vars->map);
		err_msg_std("Parsing map failed");
		return (0);
	}
	return (1);
}

int	get_textures(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->win)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->floor = create_texture(vars,
			"assets/textures/background/shadows.xpm");
	vars->water = create_texture(vars, "assets/textures/path/briks_floor.xpm");
	vars->collectibles = create_texture(vars,
			"assets/textures/collectibles/collectible.xpm");
	vars->exit = create_texture(vars, "assets/textures/exit/Exit.xpm");
	if (vars->floor && vars->water && vars->collectibles && vars->exit)
		return (1);
	return (0);
}

int	get_player(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->win)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->player = player_pop(vars);
	if (!vars->player)
		return (0);
	return (1);
}

int	set_enemy(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->win)
	{
		err_msg_std("Error");
		return (0);
	}
	vars->enemy = pop_enemy(vars);
	if (!vars->enemy)
		return (0);
	return (1);
}
