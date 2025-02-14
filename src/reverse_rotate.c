/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:43:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 18:44:17 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"

void	reverse_rotate_node(t_list **stack)
{
	t_list	*prev;
	t_list	*curr;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	prev = NULL;
	curr = *stack;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
		prev->next = NULL;
	curr->next = *stack;
	*stack = curr;
}

void	reverse_rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RRA == type_move)
	{
		reverse_rotate_node(&stacks->a);
		ft_putstr(RRA);
	}
	else if (MOVE_RRB == type_move)
	{
		reverse_rotate_node(&stacks->b);
		ft_putstr(RRB);
	}
	else if (MOVE_RRR == type_move)
	{
		reverse_rotate_node(&stacks->a);
		reverse_rotate_node(&stacks->b);
		ft_putstr(RRR);
	}
}

void	silent_reverse_rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RRA == type_move)
		reverse_rotate_node(&stacks->a);
	else if (MOVE_RRB == type_move)
		reverse_rotate_node(&stacks->b);
	else if (MOVE_RRR == type_move)
	{
		reverse_rotate_node(&stacks->a);
		reverse_rotate_node(&stacks->b);
	}
}
