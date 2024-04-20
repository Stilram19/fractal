/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:09 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 11:37:39 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (n-- && (*(s1 + i) || *(s2 + i)))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}

void	display_help(void)
{
	ft_putendl_fd("Help:", 1);
	ft_putendl_fd("	Mandelbrot:(One argument!)", 1);
	ft_putendl_fd("		(*) Enter MS0 as the first parameter to display", 1);
	ft_putendl_fd("			the mandelbrot set with coloring strategy 0.", 1);
	ft_putendl_fd("		(*) Enter MS1 as the first parameter to display", 1);
	ft_putendl_fd("			the mandelbrot set with coloring strategy 1.", 1);
	ft_putendl_fd("	Julia: (one or three arguments!)", 1);
	ft_putendl_fd("		(*) Enter JS0 as the first parameter to display", 1);
	ft_putendl_fd("			julia set with coloring strategy 0.", 1);
	ft_putendl_fd("		(*) Enter JS1 as the first parameter to display", 1);
	ft_putendl_fd("			julia set with coloring strategy 1.", 1);
	ft_putendl_fd("		The second and third arguments are optional", 1);
	ft_putendl_fd("		(in case of one argument different julia", 1);
	ft_putendl_fd("		sets are created when moving the mouse around)", 1);
	ft_putendl_fd("		The second and third arguments are the real", 1);
	ft_putendl_fd("		part and the imaginary part of the constant", 1);
	ft_putendl_fd("		of julia set you wish to display.", 1);
	ft_putendl_fd("		Once you entered the second and third arguments", 1);
	ft_putendl_fd("		the mouse visualization is disabled.", 1);
	exit(EXIT_SUCCESS);
}

/**
 * @param argc{int} the number of 
 * arguments (./a.out included)
 * @param argv{char **} pointer to pointer
 *  to the first character of the first argument.
*/
void	check_args(int argc, char **argv, t_global *g)
{
	if (argc == 1 || argc == 3 || argc > 4)
		display_help();
	g->fractal.mouse_vis = -1;
	if (!ft_strncmp(*(argv + 1), "MS0\0", 4))
		g->fractal.type = 10;
	else if (!ft_strncmp(*(argv + 1), "MS1\0", 4))
		g->fractal.type = 11;
	else if (!ft_strncmp(*(argv + 1), "JS0\0", 4))
		g->fractal.type = 20;
	else if (!ft_strncmp(*(argv + 1), "JS1\0", 4))
		g->fractal.type = 21;
	else
		display_help();
	if (argc == 2)
		return ;
	if (argc == 4 && !ft_strncmp(*(argv + 1), "M", 1))
		display_help();
	julia_constant_parsing(g, *(argv + 2), *(argv + 3));
	g->fractal.mouse_vis = 1;
}

/**
 * @brief intializes the fields of the 
 * t_global struct declared in the main function,
 * @param g{t_global *} pointer that contains 
 * the address of the struct in the stack
 * frame of the main function.
*/
void	global_init(t_global *g)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		exit(EXIT_FAILURE);
	}

    // Create a window
    g->window = SDL_CreateWindow("fractal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    exit_if(g->window, EXIT_FAILURE);

	g->renderer = SDL_CreateRenderer(g->window, -1, SDL_RENDERER_ACCELERATED);
	exit_if(g->renderer, EXIT_FAILURE);

	// g->texture = NULL;
	g->surface = NULL;
	g->keys[0] = 0;
	g->keys[1] = 0;
	g->key_zoom[0] = 0;
	g->key_zoom[1] = 0;
	g->mouse_pos[0] = 0;
	g->mouse_pos[1] = 0;
	g->mouse_zoom = 0;
	g->c_plane.x[0] = -2;
	g->c_plane.x[1] = 2;
	g->c_plane.y[0] = -2;
	g->c_plane.y[1] = 2;
	get_global(g);
}
