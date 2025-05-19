/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:28:16 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/24 13:28:18 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_for(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'P'
			&& str[i] != 'E' && str[i] != 'M')
		{
			err_msg_std("Allowed chars:\n0\n1\nC\nP\nE\nM");
			return (0);
		}
		i++;
	}
	return (1);
}
