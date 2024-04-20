/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obednaou <obednaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:02:13 by obednaou          #+#    #+#             */
/*   Updated: 2022/12/30 11:07:45 by obednaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractal.h"

void	julia_constants_help(void)
{
	ft_putendl_fd("Julia constant input help:", 1);
	ft_putendl_fd("	(*) Only one point is allowed or none.", 1);
	ft_putendl_fd("	(*) No points at the beginning and at the end.", 1);
	ft_putendl_fd("	(*) Each input must include at least one digit.", 1);
	ft_putendl_fd("	(*) You can refer to wikipidea to get a constant", 1);
	ft_putendl_fd("		of a famous julia set.", 1);
	exit(EXIT_SUCCESS);
}

static const char	*ft_skip_spaces(const char *str)
{
	while ((*str <= 13 && *str >= 9)
		|| *str == 32)
		str++;
	return (str);
}

static size_t	ft_digits_count(const char *str)
{
	size_t	count;

	count = 0;
	while (*str == 48)
		str++;
	while (*str <= 57 && *str >= 48)
	{
		count++;
		str++;
	}
	return (count);
}

static int	handling_big_numbers(int sign)
{
	if (sign + 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		ret;
	int		sign;

	ret = 0;
	sign = 1;
	str = ft_skip_spaces(str);
	if (*str == 43 || *str == 45)
	{
		if (*str++ == 45)
			sign = -1;
	}
	if (ft_digits_count(str) > 19)
		return (handling_big_numbers(sign));
	if (ft_digits_count(str) == 19
		&& ft_strncmp(LONG_LONG_MAX_STR, str, 19) < 0)
		return (handling_big_numbers(sign));
	while (*str >= 48 && *str <= 57)
	{
		ret *= 10;
		ret += *str - 48;
		str++;
	}
	return (sign * ret);
}
