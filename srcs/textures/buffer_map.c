/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:57:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/16 13:57:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_texture	*get_texture_for_tile(t_vars *vars, char tile_char)
{
	if (tile_char == '1')
		return (vars->water);
	else if (tile_char == '0')
		return (vars->floor);
	else if (tile_char == 'C')
		return (vars->collectibles);
	else if (tile_char == 'E')
		return (vars->exit);
	return (NULL);
}

void	copy_texture_to_buffer(t_texture *tex, t_vars *vars, int map_x,
		int map_y)
{
	int	x;
	int	y;
	int	buffer_pos;
	int	tex_pos;

	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			buffer_pos = ((map_y * 64) + y) * vars->buffer_line_len + ((map_x
						* 64) + x) * (vars->buffer_bpp / 8);
			tex_pos = y * tex->line_len + x * (tex->bpp / 8);
			*(unsigned int *)(vars->buffer_addr
					+ buffer_pos) = *(unsigned int *)(tex->addr + tex_pos);
			x++;
		}
		y++;
	}
}

void	init_buffer(t_vars *vars)
{
	if (vars->buffer_map)
		mlx_destroy_image(vars->mlx, vars->buffer_map);
	vars->buffer_map = mlx_new_image(vars->mlx, vars->map->width * 64,
			vars->map->height * 64);
	vars->buffer_addr = mlx_get_data_addr(vars->buffer_map, &vars->buffer_bpp,
			&vars->buffer_line_len, &vars->buffer_endian);
}

void	draw_map(t_vars *vars)
{
	int			x;
	int			y;
	t_texture	*current;

	if (!vars->buffer_map)
		init_buffer(vars);
	ft_memset(vars->buffer_addr, 0, vars->map->height * 64
		* vars->buffer_line_len);
	y = 0;
	while (y < vars->map->height)
	{
		x = 0;
		while (x < vars->map->width)
		{
			current = get_texture_for_tile(vars, vars->map->content[y][x]);
			if (current)
				copy_texture_to_buffer(current, vars, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->buffer_map, 0, 0);
}
