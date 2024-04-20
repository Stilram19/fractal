/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:34:59 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 13:50:21 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	get_color(int option, int c)
{
	if (!option)
		return (first_strategy(c));
	return (second_strategy(c));
}

void	draw_to_surface(t_global *g)
{
	int					x;
	int					y;
	int					c;
	t_floating_point	coords[2];

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		coords[0] = ((g->c_plane.x[1] - g->c_plane.x[0])
				* x) / WIDTH + g->c_plane.x[0];
		while (++y < HEIGHT)
		{
			coords[1] = ((g->c_plane.y[0] - g->c_plane.y[1])
					* y) / HEIGHT + g->c_plane.y[1];
			if (g->fractal.type / 10 == 1)
				c = mandelbrot(coords[1], coords[0]);
			else
				c = julia(coords);
			if (c > 100)
				ft_put_pixel(g->surface, x, y, BLACK);
			else
				ft_put_pixel(g->surface, x, y, get_color(g->fractal.type % 10, c));
		}
	}
}

void render_to_screen(t_global *g) {
    SDL_Texture* texture = SDL_CreateTextureFromSurface(g->renderer, g->surface);
    SDL_RenderCopy(g->renderer, texture, NULL, NULL);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(g->renderer);
}

int rendering(t_global* g) {
    // Create a new surface
    if (g->surface) {
        SDL_FreeSurface(g->surface);
    }
    g->surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
    if (!g->surface) {
        // Handle error
        exit(EXIT_FAILURE);
    }

    react_to_event_if_any();
    draw_to_surface(g);
    render_to_screen(g);

    return (DONE);
}
