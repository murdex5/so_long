/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 13:57:48 by kadferna          #+#    #+#             */
/*   Updated: 2025/04/12 13:57:51 by kadferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_animation	*create_node(void *img)
{
	t_animation	*new_node;

	if (!img)
		return (NULL);
	new_node = malloc(sizeof(t_animation));
	if (!new_node)
		return (NULL);
	new_node->img = img;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_animation **head, t_animation *new_node)
{
	t_animation	*current;

	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

int	render_player(t_vars *vars)
{
	t_player	*player;

	player = vars->player;
	if (!player->idle_left || !player->idle_right || !player->runing_left
		|| !player->runing_right)
		return (0);
	if (player->player_state == 0)
	{
		if (player->player_dir == 0)
			run_ani(vars, player->idle_right);
		else
			run_ani(vars, player->idle_left);
	}
	else
	{
		if (player->player_dir == 0)
			run_ani(vars, player->runing_right);
		else
			run_ani(vars, player->runing_left);
	}
	return (0);
}

t_animation	*load_animation(t_vars *vars, char *path, int h, int w)
{
	int			i;
	void		*img;
	t_animation	*head;
	t_animation	*new_node;
	char		*filename;

	head = NULL;
	i = 0;
	while (i < 4)
	{
		filename = get_img(path, 0, i);
		img = mlx_xpm_file_to_image(vars->mlx, filename, &h, &w);
		new_node = create_node(img);
		if (!new_node)
		{
			ft_printf("Error: \nFailed to load the %s to the node.\n", path);
			free(filename);
			i++;
			continue ;
		}
		add_node(&head, new_node);
		free(filename);
		i++;
	}
	return (head);
}
