/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   silent_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:13:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/20 12:16:26 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	silent_push(t_stacks *stacks, int type_move)
{
	if (type_move == MOVE_PA)
	{
		push_node(&stacks->b, &stacks->a);
		stacks->n_a++;
		stacks->n_b--;
	}
	else if (type_move == MOVE_PB)
	{
		push_node(&stacks->a, &stacks->b);
		stacks->n_a--;
		stacks->n_b++;
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
