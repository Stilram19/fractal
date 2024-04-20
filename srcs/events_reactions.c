/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_reactions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:49:51 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/29 14:45:42 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	keyboard_translate(t_global *g)
{
	t_floating_point	d;
	t_floating_point	trans;

	trans = 0;
	d = g->c_plane.x[1] - g->c_plane.x[0];
	if (g->keys[0] == KEY_DOWN)
		trans = -(d / 10.0);
	else if (g->keys[0] == KEY_UP)
		trans = d / 10.0;
	if (trans)
	{
		g->c_plane.y[0] += trans;
		g->c_plane.y[1] += trans;
		trans = 0;
	}
	if (g->keys[1] == KEY_LEFT)
		trans = -(d / 10.0);
	else if (g->keys[1] == KEY_RIGHT)
		trans = d / 10.0;
	if (trans)
	{
		g->c_plane.x[0] += trans;
		g->c_plane.x[1] += trans;
	}
}

void	mouse_zoom(t_global *g)
{
	t_floating_point	d;
	t_floating_point	zoom;
	t_floating_point	plane_mouse_pos[2];

	zoom = ZOOM;
	d = g->c_plane.x[1] - g->c_plane.x[0];
	if (g->mouse_zoom == SCROL_UP)
		zoom = 1 / ZOOM;
	plane_mouse_pos[0] = g->mouse_pos[0] * d / WIDTH + g->c_plane.x[0];
	plane_mouse_pos[1] = -(g->mouse_pos[1] * d / HEIGHT) + g->c_plane.y[1];
	g->c_plane.x[1] = (g->c_plane.x[1] - plane_mouse_pos[0])
		* zoom + plane_mouse_pos[0];
	g->c_plane.y[1] = (g->c_plane.y[1] - plane_mouse_pos[1])
		* zoom + plane_mouse_pos[1];
	g->c_plane.y[0] = g->c_plane.y[1] - d * zoom;
	g->c_plane.x[0] = g->c_plane.x[1] - d * zoom;
	g->mouse_zoom = 0;
}

void	keyboard_zoom(t_global *g)
{
	t_floating_point	d;
	t_floating_point	zoom;
	t_floating_point	plane_mouse_pos[2];

	zoom = ZOOM;
	d = g->c_plane.x[1] - g->c_plane.x[0];
	if (g->key_zoom[0] && g->key_zoom[1] == MINUS)
		zoom = 1 / ZOOM;
	plane_mouse_pos[0] = g->mouse_pos[0] * d / WIDTH + g->c_plane.x[0];
	plane_mouse_pos[1] = -(g->mouse_pos[1] * d / HEIGHT) + g->c_plane.y[1];
	g->c_plane.x[1] = (g->c_plane.x[1] - plane_mouse_pos[0])
		* zoom + plane_mouse_pos[0];
	g->c_plane.y[1] = (g->c_plane.y[1] - plane_mouse_pos[1])
		* zoom + plane_mouse_pos[1];
	g->c_plane.y[0] = g->c_plane.y[1] - d * zoom;
	g->c_plane.x[0] = g->c_plane.x[1] - d * zoom;
}

void	react_to_event_if_any(void)
{
	static t_global	*g;

	if (!g)
		g = get_global(NULL);
	if (g->keys[0] == KEY_DOWN || g->keys[0] == KEY_UP
		|| g->keys[1] == KEY_LEFT || g->keys[1] == KEY_RIGHT)
		keyboard_translate(g);
	else if (g->mouse_zoom == SCROL_UP
		|| g->mouse_zoom == SCROL_DOWN)
		mouse_zoom(g);
	else if (g->key_zoom[0] && g->key_zoom[1])
		keyboard_zoom(g);
}
