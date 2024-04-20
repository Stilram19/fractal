/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:06:56 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 12:39:09 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TYPES_H
# define MY_TYPES_H

# define LONG_LONG_MAX_STR "9223372036854775807"

# define WIDTH 1000
# define HEIGHT 1000

# define MANDELBROT 1
# define JULIA 2


#define KEY_UP SDLK_UP
#define KEY_DOWN SDLK_DOWN
#define KEY_LEFT SDLK_LEFT
#define KEY_RIGHT SDLK_RIGHT
#define SPACE SDLK_SPACE
#define PLUS SDLK_PLUS
#define MINUS SDLK_MINUS
#define ESC SDLK_ESCAPE

# define SCROL_UP 5
# define SCROL_DOWN 4
# define ZOOM 0.5
# define BLACK 0x00000000
# define DONE 1

# define RED 0xff0000
# define ORANGE 0xffa500
# define YELLOW 0xffff00
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define INDIGO 0x4b0082
# define VIOLET 0x9400d3
# define PINK 0xffc0cb
# define BROWN 0xa52a2a
# define BEIGE 0xf5f5dc
# define TAN 0xd2b48c
# define GOLD 0xffd700
# define SILVER 0xc0c0c0
# define MAROON 0x800000
# define OLIVE 0x808000
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080
# define CORAL 0xff7f50
# define LAVENDER 0xe6e6fa

typedef struct s_img_data
{
	int		bpp;
	int		stride;
	int		endian;
	void	*ptr;
	char	*base_add;
}t_img_data;

typedef long double	t_floating_point;

typedef struct s_cplane
{
	t_floating_point	x[2];
	t_floating_point	y[2];
}t_cplane;

typedef struct s_fractal
{
	int					type;
	int					mouse_vis;
	t_floating_point	c[2];
}t_fractal;

typedef struct s_global {
    int keys[2];
    int key_zoom[2];
    int mouse_pos[2];
    int mouse_zoom;
    SDL_Window* window;
    SDL_Renderer* renderer;
	SDL_Surface* surface;
	t_fractal	fractal;
	t_cplane	c_plane;
} t_global;

#endif