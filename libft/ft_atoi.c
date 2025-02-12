/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:01:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 00:37:50 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				sgn;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	sgn = (*nptr != '-') - (*nptr == '-');
	nptr += (*nptr == '-' || *nptr == '+');
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > (INT_MAX / 10)
			|| (n == INT_MAX / 10 && (*nptr - '0') > (INT_MAX % 10)))
		{
			if (sgn == 1)
				return (INT_MAX);
			return (INT_MIN);
		}
		n = n * 10 + (*nptr++ - '0');
	}
	return (sgn * n);
}
