/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:57:32 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 09:57:46 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_log(double x)
{
	double	result;
	double	term;
	int		n;

	if (x <= 0)
		return (-1);
	x = (x - 1) / (x + 1);
	result = 0.0;
	term = x;
	n = 1;
	while (term > 1e-15 || term < -1e-15)
	{
		result += term / n;
		term *= (x * x);
		n += 2;
	}
	return (2 * result);
}
