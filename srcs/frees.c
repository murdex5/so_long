/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:07:35 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/09 14:07:37 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	free_n_returnt(char **str, char *temp, char *msg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	if (temp)
		free(temp);
	temp = NULL;
	if (msg)
		err_msg_std(msg);
	return (0);
}

void	free_textures(t_vars *vars)
{
	if (vars->floor)
	{
		free_texture(vars, vars->floor);
		vars->floor = NULL;
	}
	if (vars->water)
	{
		free_texture(vars, vars->water);
		vars->water = NULL;
	}
	if (vars->collectibles)
	{
		free_texture(vars, vars->collectibles);
		vars->collectibles = NULL;
	}
	if (vars->exit)
	{
		free_texture(vars, vars->exit);
		vars->exit = NULL;
	}
}
