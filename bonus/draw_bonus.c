/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:03:18 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/11/19 16:31:34 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	rotation_bonus(t_all *all)
{
	int		m_x;
	int		m_y;

	mlx_get_mouse_pos(all->cub->mlx_ptr, &m_x, &m_y);
	if (m_x < all->mouse->x)
		all->player->angle -= 0.001 * (all->mouse->x - m_x);
	if (m_x > all->mouse->x)
		all->player->angle += 0.001 * (m_x - all->mouse->x);
	if (all->player->angle >= M_PI * 2)
		all->player->angle -= (M_PI * 2);
	if (all->player->angle < 0)
		all->player->angle += M_PI * 2;
	mlx_set_mouse_pos(all->cub->mlx_ptr, all->res_w / 2, all->res_h / 2);
	all->mouse->x = all->res_w / 2;
	all->mouse->y = all->res_h / 2;
}

void	moves_bonus(t_all *all, float x, float y)
{
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_W))
	{
		y = sin(all->player->angle) * P_S;
		x = cos(all->player->angle) * P_S;
		slide_in_bonus(all, y, x);
	}
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_S))
	{
		y = -sin(all->player->angle) * P_S;
		x = -cos(all->player->angle) * P_S;
		slide_in_bonus(all, y, x);
	}
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_D))
	{
		y = sin(all->player->angle + (M_PI / 2)) * P_S;
		x = cos(all->player->angle + (M_PI / 2)) * P_S;
		slide_in_bonus(all, y, x);
	}
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_A))
	{
		y = sin(all->player->angle - (M_PI / 2)) * P_S;
		x = cos(all->player->angle - (M_PI / 2)) * P_S;
		slide_in_bonus(all, y, x);
	}
}

void	ft_catch_bonus(void *d)
{
	t_all	*all;
	float	dpp;

	all = d;
	rotation_bonus(all);
	key_rotation_bonus(all);
	moves_bonus(all, 0, 0);
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_ESCAPE))
		exit (0);
	check_door_bonus(all);
	ft_draw_map_bonus(all);
	draw_fc_bonus(all);
	all->ray_angle = all->player->angle - deg_to_rad_bonus(30);
	if (all->ray_angle < 0)
		all->ray_angle += 2 * M_PI;
	else if (all->ray_angle >= 2 * M_PI)
		all->ray_angle -= 2 * M_PI;
	dpp = (all->res_w / 2) / tan(deg_to_rad_bonus(30));
	draw_3d_bonus(all, -1, dpp);
	draw_minimap_bonus(all);
	close_door_bonus(all);
}

void	ft_draw_bonus(t_all *all)
{
	all->cub->width = long_line_bonus(all->cub) * Q_SIZE;
	all->cub->height = h_map_bonus(all->cub) * Q_SIZE;
	all->x = 0;
	all->res_w = 900;
	all->res_h = 780;
	all->cub->mlx_ptr = mlx_init(all->res_w, all->res_h, "cub3D_bonus", false);
	if (!all->cub->mlx_ptr)
		ft_error_bonus("error mlx_unit", all->cub, 1);
	all->cub->img = mlx_new_image(all->cub->mlx_ptr, all->res_w, all->res_h);
	if (!all->cub->img)
	{
		mlx_close_window(all->cub->mlx_ptr);
		ft_error_bonus("error mlx_new_image", all->cub, 1);
	}
	fill_img_bonus(all->cub);
	if (mlx_image_to_window(all->cub->mlx_ptr, all->cub->img, 0, 0))
	{
		mlx_close_window(all->cub->mlx_ptr);
		ft_error_bonus("mlx_image_to_window", all->cub, 1);
	}
	ft_draw_map_bonus(all);
	draw_fc_bonus(all);
	ft_do_bonus(all);
	mlx_loop_hook(all->cub->mlx_ptr, ft_catch_bonus, all);
	mlx_loop(all->cub->mlx_ptr);
}
