/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shalfbea <shalfbea@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:25:38 by shalfbea          #+#    #+#             */
/*   Updated: 2022/01/27 08:53:13 by shalfbea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] == s2[i]) && s1[i] && s2[i])
		++i;
	if (i == n)
		return ((int) 0);
	return ((unsigned char)s1[i] - s2[i]);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	return (0);
}

static int	ft_atoi_helper(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-')
	{
		*sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	return (i);
}

int	ft_atoi(const char *str)
{
	size_t	res;
	int		i;
	int		sign;

	sign = 1;
	res = 0;
	i = ft_atoi_helper(str, &sign);
	while ((str[i]) >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		++i;
		if ((sign > 0) && (res > 2147483647))
			return (-1);
		if ((sign < 0) && (res > 2147483648))
			return (0);
	}
	return ((int) res * sign);
}

double	simple_atof(const char *str)
{
	double	res;
	int		i;
	int		k;
	double	mantissa;

	i = 0;
	res = fabs((double)atoi(str));
	while (str[i] && str[i] != '.')
		++i;
	if (str[i] != '.')
		return (res);
	mantissa = 0.0;
	if (str[++i])
	{
		k = 0;
		while (str[i] && k < 17)
			mantissa += (str[i++] - '0') / pow(10, ++k);
		res += mantissa;
		ft_atoi_helper(str, &i);
		if (i < 0)
			res = -res;
	}
	return (res);
}
