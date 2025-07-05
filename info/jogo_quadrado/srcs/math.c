/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:45:24 by rafaelfe          #+#    #+#             */
/*   Updated: 2025/05/21 17:14:17 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	ft_abs(int num)
{
	if (num <= -2147483648)
		return (2147483647);
	if (num < 0)
		return (num * -1);
	return (num);
}

float clamp(float value, float min, float max)
{
	if (value < min)
		return min;
	if (value > max)
		return max;
	return value;
}

t_point	normalize(t_point point)
{
	float len = sqrtf(point.x * point.x + point.y * point.y);
	len = sqrtf(len);

	if (len == 0)
		return ((t_point){0, 0});
	point.x /= len;
	point.y /= len;
	return (point);
}
