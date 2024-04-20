/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring_strategies.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:42:01 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/29 14:37:09 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

int	first_strategy(int c)
{
	int	arr[20];

	arr[0] = RED;
	arr[1] = ORANGE;
	arr[2] = YELLOW;
	arr[3] = GREEN;
	arr[4] = BLUE;
	arr[5] = INDIGO;
	arr[6] = VIOLET;
	arr[7] = PINK;
	arr[8] = BROWN;
	arr[9] = BEIGE;
	arr[10] = TAN;
	arr[11] = GOLD;
	arr[12] = SILVER;
	arr[13] = MAROON;
	arr[14] = OLIVE;
	arr[15] = PURPLE;
	arr[16] = TEAL;
	arr[17] = NAVY;
	arr[18] = CORAL;
	arr[19] = LAVENDER;
	return (arr[c % 20]);
}

int	second_strategy(int c)
{
	int	arr[16];

	arr[0] = 4335120;
	arr[1] = 1641242;
	arr[2] = 590127;
	arr[3] = 263241;
	arr[4] = 1892;
	arr[5] = 797834;
	arr[6] = 1594033;
	arr[7] = 3763665;
	arr[8] = 8828389;
	arr[9] = 13888760;
	arr[10] = 15854015;
	arr[11] = 16304479;
	arr[12] = 16755200;
	arr[13] = 13402112;
	arr[14] = 10048000;
	arr[15] = 6960131;
	return (arr[c % 16]);
}
