/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 12:56:47 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/29 20:06:46 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	main(int argc, char **argv)
{
	t_global	g;

	check_args(argc, argv, &g);
	global_init(&g);
	while (1) {
        event_handling(&g);
        rendering(&g);
    }
	return (0);
}
