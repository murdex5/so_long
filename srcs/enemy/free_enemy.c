/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:17:12 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/22 12:17:13 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_enemy(t_vars *vars, t_enemy *enemy)
{
	if (!enemy)
		return ;
	if (enemy->right)
	{
		free_animation(vars, enemy->right);
		enemy->right = NULL;
	}
	free(enemy);
	enemy = NULL;
}
