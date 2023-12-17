/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:01:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/12/17 15:53:36 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

void	error(void);

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
		if (n > (unsigned int)((INT_MAX - *nptr + '0' + (sgn < 0)) / 10))
			error();
		n = n * 10 + (*nptr++ - '0');
	}
	if (*nptr)
		error();
	return (sgn * n);
}
