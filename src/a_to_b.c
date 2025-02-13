/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:04:29 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 18:59:48 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"
#include <stdlib.h>

#define HEURISTIC 1.065

int		find_nth_smallest(t_list *stack, int n);
int		check_order(t_list *a);

void	a_to_b(t_stacks *stacks)
{
	int	i;
	int	n;

	while (!check_order(stacks->a) && stacks->n_a > 3)
	{
		i = (int)(ft_log(stacks->n) / ft_log(HEURISTIC));
		n = find_nth_smallest(stacks->a, i);
		while (i - 1 && stacks->n_a > 3 && !check_order(stacks->a))
		{
			if (*(int *)(stacks->a->content) < n)
			{
				push(stacks, MOVE_PB);
				i--;
			}
			else
				rotate(stacks, MOVE_RA);
		}
	}
	if (!check_order(stacks->a))
		swap(stacks, MOVE_SA);
}

t_list	*find_min_node(t_list *list)
{
	t_list	*min;

	min = list;
	while (list)
	{
		if (*(int *)list->content < *(int *)min->content)
			min = list;
		list = list->next;
	}
	return (min);
}

int	find_nth_smallest(t_list *stack, int n)
{
	t_list	*copy;
	t_list	*min_node;
	int		size;
	int		result;

	copy = ft_lstcpy(stack);
	size = ft_lstsize(copy);
	if (n > size)
		n = size;
	while (--n > 0)
	{
		min_node = find_min_node(copy);
		ft_lstrm_node(&copy, min_node);
	}
	min_node = find_min_node(copy);
	result = *(int *)min_node->content;
	ft_lstclear(&copy, free);
	return (result);
}
