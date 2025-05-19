/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:42:57 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/17 14:42:59 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exited(t_vars *vars, int new_x, int new_y)
{
	if (vars->map->content[new_y][new_x] == 'E')
	{
		if (vars->map->collectibles == 0)
		{
			ft_printf("Woohooo!! You win!!\n");
			on_key_press_exit(vars);
			exit(0);
		}
		else
			ft_printf("Collect all the coins to exit!!!\n");
	}
	if ((new_x == vars->map->enemy_x) && (new_y == vars->map->enemy_y))
	{
		ft_printf("You were slain by the Great SKELETORR!\n");
		on_key_press_exit(vars);
		exit(0);
	}
	else if ((vars->map->player_x == vars->map->enemy_x)
		&& (vars->map->player_y == vars->map->enemy_y))
	{
		ft_printf("You were slain by the Great SKELETORR!\n");
		on_key_press_exit(vars);
		exit(0);
	}
}

void	clear_text_area(t_vars *vars, int x, int y)
{
	t_texture	*background;
	int			clear_x;
	int			clear_width;
	int			tile_size;

	clear_x = x - 50;
	clear_width = 100;
	tile_size = 64;
	background = get_texture_for_tile(vars, '1');
	mlx_put_image_to_window(vars->mlx, vars->win, background->img, clear_x, y
		- (y % tile_size));
	if (clear_width > tile_size)
		mlx_put_image_to_window(vars->mlx, vars->win, background->img, clear_x
			+ tile_size, y - (y % tile_size));
}

int	on_destroy(t_vars *vars)
{
	if (vars)
		on_key_press_exit(vars);
	exit(0);
}

int	set_player_to_idle(int keysym, t_vars *vars)
{
	vars->player->player_state = 0;
	return (keysym * 0);
}
