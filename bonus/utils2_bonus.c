/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:29 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:51:30 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

float	radian_to_degree(float corner)
{
	return (corner * (180 / PI));
}

t_texture	get_right_texture(t_cub *cub, t_point endPoint)
{
	if (endPoint.is_door)
		return (cub->doors[0]);
	if (endPoint.ver_inter)
	{
		if (cub->player.current_ray_angle > 3 * PI / 2
			|| cub->player.current_ray_angle < PI / 2)
			return (cub->textures[EAST]);
		else
			return (cub->textures[WEST]);
	}
	else
	{
		if (cub->player.current_ray_angle > 0
			&& cub->player.current_ray_angle < PI)
			return (cub->textures[SOUTH]);
		else
			return (cub->textures[NORTH]);
	}
}
