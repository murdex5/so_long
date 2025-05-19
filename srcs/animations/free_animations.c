/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:47:11 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/14 10:47:12 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_animation(t_vars *vars, t_animation *animation)
{
	t_animation	*current;
	t_animation	*next;

	if (!animation)
		return ;
	current = animation;
	while (current)
	{
		next = current->next;
		if (current->img)
			mlx_destroy_image(vars->mlx, current->img);
		free(current);
		current = next;
	}
}
