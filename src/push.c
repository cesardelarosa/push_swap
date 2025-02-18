/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:21:42 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:21:53 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"

void	push_node(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (src && *src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dest;
		*dest = tmp;
	}
}

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
