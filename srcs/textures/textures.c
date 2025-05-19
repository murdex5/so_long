/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:02:19 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:02:21 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_texture	*init_txt(void)
{
	t_texture	*txt;

	txt = ft_calloc(sizeof(t_texture), 1);
	if (!txt)
		return (err_msg_std("Texture initializing failed"), NULL);
	txt->height = 64;
	txt->widht = 64;
	txt->img = NULL;
	return (txt);
}

void	*load_texture(t_vars *vars, char *path, int h, int w)
{
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	if (!img)
		return (err_msg_std("Failed to load Textures"), NULL);
	return (img);
}

t_texture	*create_texture(t_vars *vars, char *path)
{
	t_texture	*texture;

	texture = init_txt();
	if (!texture)
		return (NULL);
	texture->img = load_texture(vars, path, texture->height, texture->widht);
	if (!texture->img)
		return (NULL);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (NULL);
	return (texture);
}

int	add_text_to_window(t_vars *vars, char *str, int number, int x)
{
	int		colour;
	char	*s_number;
	int		y;

	y = vars->map->height * 64;
	s_number = ft_itoa(number);
	if (!s_number)
		return (0);
	colour = 0XFFFFFF;
	clear_text_area(vars, x, y - 30);
	mlx_string_put(vars->mlx, vars->win, x - 45, y, colour, str);
	mlx_string_put(vars->mlx, vars->win, x, y, colour, s_number);
	free(s_number);
	return (0);
}
