/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/11 19:55:33 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	elements(t_stack **a)
{
	int		n;
	int		first;
	t_stack	*tmp;

	tmp = *a;
	if (tmp == 0x0)
		return (0);
	n = 1;
	first = tmp->num;
	while (first != tmp->next->num)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

int	check_order(t_stack **a)
{
	int		count;
	t_stack	*tmp;

	tmp = *a;
	if (tmp == tmp->next)
		return (1);
	count = 0;
	while (count == 0 || tmp != *a)
	{
		if (tmp->num > tmp->next->num)
			count++;
		tmp = tmp->next;
	}
	return (count < 2);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

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
