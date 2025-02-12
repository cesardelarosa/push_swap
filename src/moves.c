/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 12:26:19 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"

void	push_node(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (src && *src)
	{
		tmp = *src;
		if (tmp->next == tmp)
			*src = NULL;
		else
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			*src = tmp->next;
		}
		if (*dest == NULL)
		{
			tmp->next = tmp;
			tmp->prev = tmp;
		}
		else
		{
			tmp->next = *dest;
			tmp->prev = (*dest)->prev;
			(*dest)->prev->next = tmp;
			(*dest)->prev = tmp;
		}
		*dest = tmp;
	}
}

void	push(t_stacks *stacks, int type_move)
{
	if (MOVE_PA == type_move)
	{
		push_node(stacks->stack[1], stacks->stack[0]);
		stacks->n[0]++;
		stacks->n[1]--;
		ft_putstr(PA);
	}
	else if (MOVE_PB == type_move)
	{
		push_node(stacks->stack[0], stacks->stack[1]);
		stacks->n[0]--;
		stacks->n[1]++;
		ft_putstr(PB);
	}
}

void	reverse_rotate_node(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->prev;
	}
}

void	reverse_rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RRA == type_move)
	{
		reverse_rotate_node(stacks->stack[0]);
		ft_putstr(RRA);
	}
	else if (MOVE_RRB == type_move)
	{
		reverse_rotate_node(stacks->stack[1]);
		ft_putstr(RRB);
	}
	else if (MOVE_RRR == type_move)
	{
		reverse_rotate_node(stacks->stack[0]);
		reverse_rotate_node(stacks->stack[1]);
		ft_putstr(RRR);
	}
}

void	rotate_node(t_stack **stack)
{
	if (stack && *stack && (*stack)->next != *stack)
	{
		*stack = (*stack)->next;
	}
}

void	rotate(t_stacks *stacks, int type_move)
{
	if (MOVE_RA == type_move)
	{
		rotate_node(stacks->stack[0]);
		ft_putstr(RA);
	}
	else if (MOVE_RB == type_move)
	{
		rotate_node(stacks->stack[1]);
		ft_putstr(RB);
	}
	else if (MOVE_RR == type_move)
	{
		rotate_node(stacks->stack[0]);
		rotate_node(stacks->stack[1]);
		ft_putstr(RR);
	}
}

void	swap_node(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack && *stack && (*stack)->next && (*stack)->next != *stack)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		second->next = first;
		second->prev = first->prev;
		if (first->prev)
			first->prev->next = second;
		first->prev = second;
		*stack = second;
	}
}

void	swap(t_stacks *stacks, int type_move)
{
	if (MOVE_SA == type_move)
	{
		swap_node(stacks->stack[0]);
		ft_putstr(SA);
	}
	else if (MOVE_SB == type_move)
	{
		swap_node(stacks->stack[1]);
		ft_putstr(SB);
	}
	else if (MOVE_SS == type_move)
	{
		swap_node(stacks->stack[0]);
		swap_node(stacks->stack[1]);
		ft_putstr(SS);
	}
}
