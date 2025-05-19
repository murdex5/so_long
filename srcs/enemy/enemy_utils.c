/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:45:51 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/22 17:45:54 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_background_tile(t_vars *vars, int tile_x, int tile_y)
{
	t_texture	*floor_texture;
	int			tile_size;

	tile_size = 64;
	if (!vars || tile_x < 0 || tile_y < 0 || tile_y >= vars->map->height
		|| tile_x >= vars->map->width)
		return ;
	floor_texture = get_texture_for_tile(vars, '0');
	if (vars->mlx && vars->win && floor_texture && floor_texture->img)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, floor_texture->img, tile_x
			* tile_size, tile_y * tile_size);
	}
}
