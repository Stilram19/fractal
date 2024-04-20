/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:14 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 11:23:24 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	check_digits(char *s1, char *s2)
{
	int	con1;
	int	con2;

	con1 = 0;
	con2 = 0;
	if (*s1 == '-' || *s1 == '+')
		s1++;
	if (*s2 == '-' || *s2 == '+')
		s2++;
	while (*s1 || *s2)
	{
		if (*s1 && *s1 >= '0' && *s1 <= '9')
			con1 = 1;
		else if (*s1 && *s1 != '.')
			julia_constants_help();
		if (*s2 && *s2 >= 48 && *s2 <= 57)
			con2 = 1;
		else if (*s2 && *s2 != '.')
			julia_constants_help();
		if (*s1 != '\0')
			s1++;
		if (*s2 != '\0')
			s2++;
	}
	if (!(con1 && con2))
		julia_constants_help();
}

void	check_point(char *s1, char *s2)
{
	int	count1;
	int	count2;

	count1 = 0;
	count2 = 0;
	if (*s1 == '-' || *s1 == '+')
		s1++;
	if (*s2 == '-' || *s2 == '+')
		s2++;
	if (*s1 == '.' || *s2 == '.')
		julia_constants_help();
	while (*s1 || *s2)
	{
		if (*s1 == '.')
			count1++;
		if (*s2 == '.')
			count2++;
		if (*s1 != '\0')
			s1++;
		if (*s2)
			s2++;
	}
	if (*(s1 - 1) == '.' || count1 > 1
		|| *(s2 - 1) == '.' || count2 > 1)
		julia_constants_help();
}

t_floating_point	get_mantissa(char *s)
{	
	int					index;
	t_floating_point	ret;

	ret = 0;
	index = 0;
	while (*(s + index))
		index++;
	while (index--)
	{
		ret /= 10.0;
		ret += (*(s + index) - 48) / 10.0;
	}
	return (ret);
}

/**
 * @param ft_atold (ascii to long double)
 * gets a string of ascii as input and converts it to long double.
*/
t_floating_point	ft_atold(char *s)
{
	int					index;
	t_floating_point	floor;
	t_floating_point	mantissa;

	index = 0;
	mantissa = 0;
	floor = ft_atoi(s);
	while (*(s + index) && *(s + index) != '.')
		index++;
	if ((*(s + index)))
		mantissa = get_mantissa(s + index + 1);
	if (*s == '-')
		mantissa *= -1;
	return (mantissa + floor);
}

void	julia_constant_parsing(t_global *g, char *a1, char *a2)
{
	check_digits(a1, a2);
	check_point(a1, a2);
	g->fractal.c[0] = ft_atold(a1);
	g->fractal.c[1] = ft_atold(a2);
}
