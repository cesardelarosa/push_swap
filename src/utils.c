/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:36:40 by adpedrer          #+#    #+#             */
/*   Updated: 2024/07/26 01:50:54 by cde-la-r         ###   ########.fr       */
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
	int	n;
	int	count;
	t_stack *tmp;
	
	tmp = *a;
	n = elements(&tmp);
	count = 0;
	while(n--)
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
