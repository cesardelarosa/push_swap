/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:45:03 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 18:45:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"

void	rotate_node(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
}

void	rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RA == type_move)
	{
		rotate_node(&stacks->a);
		ft_putstr(RA);
	}
	else if (MOVE_RB == type_move)
	{
		rotate_node(&stacks->b);
		ft_putstr(RB);
	}
	else if (MOVE_RR == type_move)
	{
		rotate_node(&stacks->a);
		rotate_node(&stacks->b);
		ft_putstr(RR);
	}
}

void	silent_rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RA == type_move)
		rotate_node(&stacks->a);
	else if (MOVE_RB == type_move)
		rotate_node(&stacks->b);
	else if (MOVE_RR == type_move)
	{
		rotate_node(&stacks->a);
		rotate_node(&stacks->b);
	}
}
