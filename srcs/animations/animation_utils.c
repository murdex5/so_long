/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:45:59 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 12:46:02 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*get_img(char *path, int len, int i)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str3 = int_to_str(len, i);
	str2 = ft_strjoin(path, str3);
	str1 = ft_strjoin(str2, ".xpm");
	free(str2);
	free(str3);
	if (access(str1, F_OK) == 0)
		return (str1);
	return (NULL);
}

int	render_player_frame(t_vars *vars, t_animation *anim)
{
	static t_animation	*current_frame = NULL;
	static int			frame_counter = 0;
	int					frame_delay;

	frame_delay = 1000;
	if (!current_frame)
		current_frame = anim;
	render_animation(vars, current_frame);
	frame_counter++;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		current_frame = current_frame->next;
		if (!current_frame)
			current_frame = anim;
	}
	return (0);
}

void	render_animation(t_vars *vars, t_animation *anim)
{
	int	pixel_x;
	int	pixel_y;

	if (!vars || !anim || !anim->img)
		return ;
	if (vars->map->player_x < 0 || vars->map->player_y < 0)
		return ;
	pixel_x = vars->map->player_x * 64;
	pixel_y = vars->map->player_y * 64;
	mlx_put_image_to_window(vars->mlx, vars->win, anim->img, pixel_x, pixel_y);
}

void	run_ani(t_vars *vars, t_animation *animation)
{
	if (animation)
		render_player_frame(vars, animation);
}
