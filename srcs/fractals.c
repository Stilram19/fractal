/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:57:38 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/29 20:42:39 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	mandelbrot(t_floating_point im_of_c, t_floating_point re_of_c)
{
	int					c;
	t_floating_point	temp;
	t_floating_point	norm;
	t_floating_point	im_of_out;
	t_floating_point	re_of_out;

	c = 0;
	norm = 0;
	im_of_out = 0;
	re_of_out = 0;
	while (c <= 100 && norm <= 2)
	{
		temp = im_of_out;
		im_of_out = 2 * temp * re_of_out + im_of_c;
		re_of_out = re_of_out * re_of_out - temp * temp + re_of_c;
		norm = sqrt(re_of_out * re_of_out + im_of_out * im_of_out);
		c++;
	}
	return (c);
}

void	get_julia_constant(t_floating_point	constant[2], t_global *g)
{
	if (g->fractal.mouse_vis == 1)
	{
		constant[0] = g->fractal.c[0];
		constant[1] = g->fractal.c[1];
		return ;
	}
	constant[0] = (g->mouse_pos[0] * (g->c_plane.x[1] - g->c_plane.x[0]))
		/ WIDTH + g->c_plane.x[0];
	constant[1] = (g->mouse_pos[1] * (g->c_plane.y[0] - g->c_plane.y[1]))
		/ HEIGHT + g->c_plane.y[1];
}

int	julia(t_floating_point coords[2])
{
	int					c;
	t_floating_point	vars[4];
	t_floating_point	constant[2];
	static t_global		*g;

	if (!g)
		g = get_global(NULL);
	get_julia_constant(constant, g);
	c = 0;
	vars[0] = coords[0];
	vars[1] = coords[1];
	vars[3] = 0;
	while (c <= 100 && vars[3] <= 2)
	{
		vars[2] = vars[1];
		vars[1] = 2 * vars[2] * vars[0] + constant[1];
		vars[0] = vars[0] * vars[0] - vars[2] * vars[2] + constant[0];
		vars[3] = sqrt(vars[0] * vars[0] + vars[1] * vars[1]);
		c++;
	}
	return (c);
}
