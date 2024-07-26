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

int	check_order(t_stack **a)
{
	t_stack *tmp;


	tmp = *a;
	while(tmp && tmp->next)
	{
		if( tmp->num > tmp->next->num)
			return (0);
		else
			tmp = tmp->next;
	}
	return (1);
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
