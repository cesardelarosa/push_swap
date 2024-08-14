/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:36:40 by adpedrer          #+#    #+#             */
/*   Updated: 2024/08/04 18:34:26 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	elements(t_stack **a)
{
	int	n;
	int	first;
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
	int	count;
	t_stack *tmp;

	tmp = *a;
	if (tmp == tmp->next)
		return (1);
	count = 0;
	while(count == 0 || tmp != *a)
	{
		if (tmp->num > tmp->next->num)
			count++;
		tmp = tmp->next;
	}
	return (count < 2);
}


void stacks_initiator(t_stack ***a, t_stack ***b)
{
	*a = (t_stack **)malloc(sizeof(t_stack *));
	*b = (t_stack **)malloc(sizeof(t_stack *));
	if (!*a || !*b)
		error(2);
	**a = NULL;
	**b = NULL;
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
