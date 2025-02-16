/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:56:28 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/16 18:57:04 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"
#include "libft.h"
#include <limits.h>

static int	find_min_index(t_list *a)
{
	int		i;
	int		min_index;
	int		min_val;
	t_list	*tmp;

	if (!a)
		return (0);
	i = 0;
	min_index = 0;
	tmp = a;
	min_val = *(int *)(tmp->content);
	while (tmp)
	{
		if (*(int *)(tmp->content) < min_val)
		{
			min_val = *(int *)(tmp->content);
			min_index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_index);
}

void	align_a(t_stacks *stacks)
{
	int	min_index;
	int	i;

	min_index = find_min_index(stacks->a);
	if (min_index <= stacks->n_a / 2)
	{
		while (min_index-- > 0)
			rotate(stacks, MOVE_RA);
	}
	else
	{
		i = stacks->n_a - min_index;
		while (i-- > 0)
			reverse_rotate(stacks, MOVE_RRA);
	}
}
