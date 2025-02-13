/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:44:35 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 18:44:56 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"

void	swap_node(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap(t_stacks *stacks, int type_move)
{
	if (MOVE_SA == type_move)
	{
		swap_node(&stacks->a);
		ft_putstr(SA);
	}
	else if (MOVE_SB == type_move)
	{
		swap_node(&stacks->b);
		ft_putstr(SB);
	}
	else if (MOVE_SS == type_move)
	{
		swap_node(&stacks->a);
		swap_node(&stacks->b);
		ft_putstr(SS);
	}
}

void	silent_swap(t_stacks *stacks, int type_move)
{
	if (MOVE_SA == type_move)
		swap_node(&stacks->a);
	else if (MOVE_SB == type_move)
		swap_node(&stacks->b);
	else if (MOVE_SS == type_move)
	{
		swap_node(&stacks->a);
		swap_node(&stacks->b);
	}
}
