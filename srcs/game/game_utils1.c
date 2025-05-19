/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:57:05 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/22 17:57:10 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_vars	*init_vars(void)
{
	t_vars	*vars;

	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		return (NULL);
	vars->mlx = NULL;
	vars->win = NULL;
	vars->map = NULL;
	vars->floor = NULL;
	vars->water = NULL;
	vars->player = NULL;
	vars->frames = 0;
	return (vars);
}

int	init_mlx(t_vars *vars)
{
	if (!vars)
	{
		err_msg_std("Vars does no exist");
		return (0);
	}
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_putstr_fd("So long: ", 1);
		ft_putstr_fd("Failed to initialize mlx\n", 1);
		return (0);
	}
	return (1);
}
