/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:43:54 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:43:55 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_texture(t_vars *vars, t_texture *texture)
{
	if (!texture)
		return ;
	if (texture->img)
		mlx_destroy_image(vars->mlx, texture->img);
	free(texture);
}
