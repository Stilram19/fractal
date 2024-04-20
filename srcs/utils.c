/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:57:38 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 13:15:20 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

/**
 * @brief the program exits with the given exit status if the first parameter
 * is a NULL pointer.
*/
void	exit_if(void *ptr, int status)
{
	if (!ptr)
		exit(status);
}

/**
 * @brief very important function:
 * this function is called the first time
 * with the address of the t_global struct
 * in the stack frame of the main function,
 * in its first call, we declare the static variable
 * pointer in the bss segment and initialize it
 * for the first and the last time.
 * once we need to access a field in the t_global
 * g struct, we call this function which 
 * will return the address (which sleeps for
 * the program's life time in the static variable).
 * The magic of this function is that it'll make
 * a lot of stack frames smaller (especially those
 * pushed and poped while rendering) --> minimize the
 * overhead
*/
t_global	*get_global(t_global *initializer)
{
	static t_global	*g;

	if (!g)
		g = initializer;
	return (g);
}

/**
 * @brief calculates the address of the pixel we want to color
 * and writes the chosen color to the the memory location.
 * @param x{int} the offset by which we jump from a pixel to 
 * the next ont in the same row.
 * @param y{int} the offset by which we jump from a pixel to
 * the one in the same position in the next row in the image.
 * @param color{int} the amount of red, green, blue (rgb).
*/
void    ft_put_pixel(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color)
{
    if (y >= (unsigned int)surface->h || x >= (unsigned int)surface->w)
        return ;
    *((Uint32*)((Uint8*)surface->pixels + y * surface->pitch + x * surface->format->BytesPerPixel)) = color;
}
