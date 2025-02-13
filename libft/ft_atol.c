/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:01:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 18:25:24 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long	ft_atol(const char *nptr)
{
	unsigned long	n;
	long			sgn;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	sgn = (*nptr != '-') - (*nptr == '-');
	nptr += (*nptr == '-' || *nptr == '+');
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > (LONG_MAX / 10)
			|| (n == LONG_MAX / 10 && (*nptr - '0') > (LONG_MAX % 10)))
		{
			if (sgn == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		n = n * 10 + (*nptr++ - '0');
	}
	return (sgn * n);
}
