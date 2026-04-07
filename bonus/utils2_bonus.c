/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:58:15 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/11/19 15:27:27 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_do_bonus(t_all *all)
{
	player_angle_bonus(all);
	all->mouse->x = all->res_w / 2;
	all->mouse->y = all->res_h / 2;
	mlx_set_mouse_pos(all->cub->mlx_ptr, all->mouse->x, all->mouse->y);
	mlx_set_cursor_mode(all->cub->mlx_ptr, MLX_MOUSE_HIDDEN);
	draw_line_bonus(all);
}

void	check_door_bonus(t_all *all)
{
	int	y;
	int	x;

	y = (int)all->player->y / Q_SIZE;
	x = (int)all->player->x / Q_SIZE;
	if (all->cub->lines[y][x] == 'D')
		all->cub->lines[y][x] = 'd';
	if (all->cub->lines[y][x + 1] == 'D')
		all->cub->lines[y][x + 1] = 'd';
	if (all->cub->lines[y - 1][x + 1] == 'D')
		all->cub->lines[y - 1][x + 1] = 'd';
	if (all->cub->lines[y + 1][x + 1] == 'D')
		all->cub->lines[y + 1][x + 1] = 'd';
	if (all->cub->lines[y][x - 1] == 'D')
		all->cub->lines[y][x - 1] = 'd';
	if (all->cub->lines[y + 1][x] == 'D')
		all->cub->lines[y + 1][x] = 'd';
	if (all->cub->lines[y + 1][x - 1] == 'D')
		all->cub->lines[y + 1][x - 1] = 'd';
	if (all->cub->lines[y - 1][x] == 'D')
		all->cub->lines[y - 1][x] = 'd';
	if (all->cub->lines[y - 1][x - 1] == 'D')
		all->cub->lines[y - 1][x - 1] = 'd';
}

void	close_door_bonus(t_all *all)
{
	int		i;
	int		j;

	j = -1;
	while (all->cub->lines[++j])
	{
		i = -1;
		while (all->cub->lines[j][++i])
			if (all->cub->lines[j][i] == 'd')
				all->cub->lines[j][i] = 'D';
	}
}

void	draw_player_bonus(t_all *all, int color)
{
	int	i;
	int	j;

	i = 100;
	while (i <= 104)
	{
		j = 100;
		while (j <= 104)
		{
			mlx_put_pixel(all->cub->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	ft_draw_map_bonus(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->cub->lines[i])
	{
		j = 0;
		while (all->cub->lines[i][j])
		{
			all->cub->x = j * Q_SIZE;
			all->cub->y = i * Q_SIZE;
			if (all->cub->lines[i][j] == 'E' || all->cub->lines[i][j] == 'N'
				|| all->cub->lines[i][j] == 'W' || all->cub->lines[i][j] == 'S')
			{
				all->player->x = j * Q_SIZE;
				all->player->y = i * Q_SIZE;
				all->player->x_mini = j * 10;
				all->player->y_mini = i * 10;
				all->player->pl_dir = all->cub->lines[i][j];
				all->cub->lines[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
