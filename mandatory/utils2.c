/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:58:15 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/11/19 11:28:59 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_draw_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	all->x = 0;
	while (all->cub->lines[i])
	{
		j = 0;
		while (all->cub->lines[i][j])
		{
			if (all->cub->lines[i][j] == 'E' || all->cub->lines[i][j] == 'N'
				|| all->cub->lines[i][j] == 'W' || all->cub->lines[i][j] == 'S')
			{
				all->player->x = j * Q_SIZE;
				all->player->y = i * Q_SIZE;
				all->player->pl_dir = all->cub->lines[i][j];
				all->cub->lines[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
