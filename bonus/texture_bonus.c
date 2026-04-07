/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:43:58 by aelbouab          #+#    #+#             */
/*   Updated: 2024/11/19 15:19:26 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	texture_v2(t_all *all, int i)
{
	int	text_of_x;

	text_of_x = 0;
	if (i == 2 || i == 3)
	{
		if (!all->flag_door)
			text_of_x = (((int) all->hor_p_x % Q_SIZE)
					* all->cub->texture[i]->width / Q_SIZE);
		else
			text_of_x = (((int) all->hor_p_x % Q_SIZE)
					* all->cub->texture[4]->width / Q_SIZE);
	}
	else
	{
		if (!all->flag_door)
			text_of_x = (((int) all->ver_p_y % Q_SIZE)
					* all->cub->texture[i]->width / Q_SIZE);
		else
			text_of_x = (((int) all->ver_p_y % Q_SIZE)
					* all->cub->texture[4]->width / Q_SIZE);
	}
	return (text_of_x);
}

void	fill_img1_bonus(t_cub *cub)
{
	mlx_texture_t	*img;

	img = mlx_load_png(cub->paths[3]);
	if (!img)
		ft_error_bonus("error image", cub, 1);
	cub->texture[3] = mlx_texture_to_image(cub->mlx_ptr, img);
	mlx_delete_texture(img);
	img = mlx_load_png(cub->paths[4]);
	if (!img)
		ft_error_bonus("error image", cub, 1);
	cub->texture[4] = mlx_texture_to_image(cub->mlx_ptr, img);
	mlx_delete_texture(img);
	if (!cub->texture[0] || !cub->texture[1] || !cub->texture[2]
		|| !cub->texture[3] || !cub->texture[4])
		ft_error_bonus("error image", cub, 1);
}

void	fill_img_bonus(t_cub *cub)
{
	mlx_texture_t	*img;

	img = mlx_load_png(cub->paths[0]);
	if (!img)
		ft_error_bonus("error image", cub, 1);
	cub->texture[0] = mlx_texture_to_image(cub->mlx_ptr, img);
	mlx_delete_texture(img);
	img = mlx_load_png(cub->paths[1]);
	if (!img)
		ft_error_bonus("error image", cub, 1);
	cub->texture[1] = mlx_texture_to_image(cub->mlx_ptr, img);
	mlx_delete_texture(img);
	img = mlx_load_png(cub->paths[2]);
	if (!img)
		ft_error_bonus("error image", cub, 1);
	cub->texture[2] = mlx_texture_to_image(cub->mlx_ptr, img);
	mlx_delete_texture(img);
	fill_img1_bonus(cub);
}
