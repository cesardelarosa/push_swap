/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:51:01 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/07/13 12:23:33 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order(t_stacks *stacks)
{
	if (is_sorted(stacks->a))
		return ;
	else if (ft_lstsize(stacks->a) <= 3)
		sort_three(stacks);
	else if (ft_lstsize(stacks->a) <= 5)
		sort_five(stacks);
	else
		sort_large(stacks);
}

int	is_sorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (*(int *)(lst->content) > *(int *)(lst->next->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(stacks->a->content);
	b = *(int *)(stacks->a->next->content);
	c = 0;
	if (stacks->a->next->next != NULL)
		c = *(int *)(stacks->a->next->next->content);
	if (!c || (a > b && b < c && a < c))
		swap(stacks, 'a');
	else if (a > b && b > c)
	{
		swap(stacks, 'a');
		reverse_rotate(stacks, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(stacks, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(stacks, 'a');
		rotate(stacks, 'a');
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(stacks, 'a');
}

void	sort_five(t_stacks *stacks)
{
	int	min;

	while (ft_lstsize(stacks->a) > 3)
	{
		min = find_min(stacks->a);
		if (*(int *)(stacks->a->content) == min)
			push(stacks, 'b');
		else
			rotate(stacks, 'a');
	}
	sort_three(stacks);
	while (stacks->b)
	{
		push(stacks, 'a');
		if (*(int *)(stacks->a->content) > *(int *)(stacks->a->next->content))
			swap(stacks, 'a');
		if (*(int *)(stacks->a->next->content) \
			> *(int *)(stacks->a->next->next->content))
		{
			rotate(stacks, 'a');
			swap(stacks, 'a');
			reverse_rotate(stacks, 'a');
		}
	}
}

void	sort_large(t_stacks *stacks)
{
	int	max_bits;
	int	size;
	int	max_num;
	int	i;
	int	j;

	max_bits = 0;
	max_num = find_max(stacks->a);
	while ((max_num >> max_bits) != 0)
		max_bits++;
	size = ft_lstsize(stacks->a);
	i = 0;
	while (i++ < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*(int *)(stacks->a->content) >> (i -1)) & 1) == 1)
				rotate(stacks, 'a');
			else
				push(stacks, 'b');
		}
		while (stacks->b)
			push(stacks, 'a');
	}
}
