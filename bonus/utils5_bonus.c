/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:08:23 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/11/18 17:53:40 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	draw_fc_bonus(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < all->res_h)
	{
		j = 0;
		while (j < all->res_w)
		{
			if (i < all->res_h / 2)
			{
				mlx_put_pixel(all->cub->img, j, i, ft_color_bonus(
						all->cub->c[0], all->cub->c[1], all->cub->c[2], 255));
			}
			else
			{
				mlx_put_pixel(all->cub->img, j, i, ft_color_bonus(
						all->cub->ff[0], all->cub->ff[1], all->cub->ff[2], -1));
			}
			j++;
		}
		i++;
	}
}

void	draw_texture1_bonus(t_all *all, float wall_h, int text_of_x, int i)
{
	int	y;
	int	text_of_y;
	int	wall_bottom_px;
	int	wall_top_px;
	int	index;

	y = 0;
	wall_top_px = (all->res_h / 2) - ((int) wall_h / 2);
	wall_bottom_px = (all->res_h / 2) + ((int) wall_h / 2);
	if (y < wall_top_px)
		y = wall_top_px;
	while (y < wall_bottom_px && y < all->res_h)
	{
		text_of_y = (y - wall_top_px)
			* ((float) all->cub->texture[i]->height) / ((float)(wall_h));
		index = ((all->cub->texture[i]->width * text_of_y) + text_of_x) * 4;
		all->cub->pixel = all->cub->texture[i]->pixels[index];
		all->cub->pixel1 = all->cub->texture[i]->pixels[index + 1];
		all->cub->pixel2 = all->cub->texture[i]->pixels[index + 2];
		all->cub->pixel3 = all->cub->texture[i]->pixels[index + 3];
		mlx_put_pixel(all->cub->img, all->x, y++,
			ft_color_bonus(all->cub->pixel, all->cub->pixel1,
				all->cub->pixel2, all->cub->pixel3));
	}
}

void	draw_texture_bonus(t_all *all, float wall_h, int i)
{
	int	text_of_x;

	if (dest_vita1_bonus(all))
		i = 1;
	if (i && !(all->ray_angle > 0 && all->ray_angle < M_PI))
		i = 2;
	else if (i && (all->ray_angle > 0 && all->ray_angle < M_PI))
		i = 3;
	else if (!i && (all->ray_angle >= M_PI_2 && all->ray_angle < 3 * M_PI_2))
		i = 1;
	text_of_x = texture_v2(all, i);
	if (!all->flag_door)
		draw_texture1_bonus(all, wall_h, text_of_x, i);
	else
		draw_texture1_bonus(all, wall_h, text_of_x, 4);
	if (all->x < all->res_w)
		all->x++;
	else
		all->x = 0;
}

void	ray_pp(t_all *all)
{
	all->ray_angle += deg_to_rad_bonus(60) / all->res_w;
	if (all->ray_angle < 0)
		all->ray_angle += 2 * M_PI;
	else if (all->ray_angle >= 2 * M_PI)
		all->ray_angle -= 2 * M_PI;
}

void	draw_3d_bonus(t_all *all, int numray, float dpp)
{
	float	wall_h;

	while (++numray <= all->res_w)
	{
		hor_point_bonus(all, all->ray_angle);
		ver_point_bonus(all, all->ray_angle);
		all->ray_dist = dest_vita2_bonus(all);
		wall_h = (Q_SIZE / all->ray_dist) * dpp;
		if (dest_vita1_bonus(all)
			&& ((int)all->hor_p_x / Q_SIZE)
			< (int)ft_strlen(all->cub->lines[(int)all->hor_p_y / Q_SIZE], 0)
			&& all->cub->lines[(int)all->hor_p_y / Q_SIZE]
			[(int)all->hor_p_x / Q_SIZE] == 'D')
			all->flag_door = 1;
		else if (!dest_vita1_bonus(all) && ((int)all->ver_p_x / Q_SIZE)
			< (int)ft_strlen(all->cub->lines[(int)all->ver_p_y / Q_SIZE], 0)
			&& all->cub->lines[(int)all->ver_p_y / Q_SIZE]
			[(int)all->ver_p_x / Q_SIZE] == 'D')
			all->flag_door = 1;
		else
			all->flag_door = 0;
		draw_texture_bonus(all, wall_h, 0);
		ray_pp(all);
	}
}
