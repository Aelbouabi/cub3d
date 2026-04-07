/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouab <aelbouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:52:18 by mkaoukin          #+#    #+#             */
/*   Updated: 2024/11/16 17:19:16 by aelbouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	key_rotation_bonus(t_all *all)
{
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_LEFT))
	{
		all->player->angle -= 0.1;
		if (all->player->angle < 0)
			all->player->angle += M_PI * 2;
	}
	if (mlx_is_key_down(all->cub->mlx_ptr, MLX_KEY_RIGHT))
	{
		all->player->angle += 0.1;
		if (all->player->angle >= M_PI * 2)
			all->player->angle -= (M_PI * 2);
	}
}

int	ft_color_bonus(unsigned char r, unsigned char g
		, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

size_t	long_line_bonus(t_cub *cub)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (cub->lines[i])
	{
		if (j < ft_strlen(cub->lines[i], 1))
			j = ft_strlen(cub->lines[i], 1);
		i++;
	}
	return (j);
}

int	h_map_bonus(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->lines[i])
		i++;
	return (i);
}

double	deg_to_rad_bonus(double an)
{
	return (an * (M_PI / 180));
}
