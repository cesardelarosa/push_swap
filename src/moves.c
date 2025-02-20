/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:20:34 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stacks *stacks, int type_move)
{
	if (type_move == MOVE_PA)
	{
		push_node(&stacks->b, &stacks->a);
		stacks->n_a++;
		stacks->n_b--;
		ft_putstr(PA);
	}
	else if (type_move == MOVE_PB)
	{
		push_node(&stacks->a, &stacks->b);
		stacks->n_a--;
		stacks->n_b++;
		ft_putstr(PB);
	}
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
