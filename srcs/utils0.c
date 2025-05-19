/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:38:46 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 13:38:48 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_file_type(char *str)
{
	char	**str2;
	int		i;
	char	*temp;

	str2 = ft_split(str, '.');
	if (!str2)
		return (err_msg_std("Ft_split faield"), 0);
	i = 0;
	while (str2[i])
		i++;
	temp = ft_strdup(str2[i - 1]);
	if (!temp)
		return (err_msg_std("Memory allocation failed for temo"), 0);
	if (ft_strncmp(temp, "ber", ft_strlen("ber") + 1) == 0)
		return (free_n_returnt(str2, temp, NULL), 1);
	return (free_n_returnt(str2, temp, "This type of file is not supported!"),
		0);
}

char	*int_to_str(int len, int num)
{
	char	*str;
	int		temp;

	len = 0;
	temp = len;
	if (temp == 0)
		len = 1;
	else
	{
		while (temp != 0)
		{
			len++;
			temp /= 10;
		}
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void	replace_tile(t_vars *vars, int new_x, int new_y)
{
	int			x;
	int			y;
	t_map		*map;
	t_texture	*texture;

	map = vars->map;
	x = map->player_x;
	y = map->player_y;
	if (new_x != x || new_y != y)
	{
		if (map->content[y][x] == 'C')
		{
			map->content[y][x] = '0';
			texture = get_texture_for_tile(vars, '0');
		}
		else
			texture = get_texture_for_tile(vars, map->content[y][x]);
		if (texture && texture->img)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, texture->img, x * 64,
				y * 64);
		}
	}
}

void	diter_dir(int keysym, t_vars *vars)
{
	if (keysym == D)
		vars->player->player_dir = 0;
	else if (keysym == A)
		vars->player->player_dir = 1;
}
