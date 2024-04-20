/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:02:50 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 10:57:53 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

#include <SDL2/SDL.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "my_types.h"

void        event_handling(t_global *g);
int			destroy(t_global *g);
int			first_strategy(int c);
int			second_strategy(int c);
int			rendering(t_global *g);
int			mandelbrot(t_floating_point im_c, t_floating_point re_c);
int			julia(t_floating_point coords[2]);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
void		new_img(void);
void		exit_if(void *ptr, int status);
void		julia_constants_help(void);
void		global_init(t_global *g);
void		check_args(int argc, char **argv, t_global *g);
void		react_to_event_if_any(void);
void		julia_constant_parsing(t_global *g, char *a1, char *a2);
void		ft_putendl_fd(char *s, int fd);
t_global	*get_global(t_global *g);
void    ft_put_pixel(SDL_Surface* surface, unsigned int x, unsigned int y, unsigned int color);

#endif
