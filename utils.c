/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:24:31 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/30 11:09:07 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_white_space(char *c)
{
	if (*c == '\n' || *c == '\t' || *c == '\r'
		|| *c == '\v' || *c == '\f' || *c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		a;
	int		b;
	char	*p;

	a = 1;
	b = 0;
	p = (char *)str;
	while (is_white_space(p))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			a *= -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		b *= 10;
		b += (*p - '0');
		p++;
	}
	return (a * b);
}
