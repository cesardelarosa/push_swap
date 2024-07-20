/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 09:38:31 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/07/13 12:23:33 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stacks *stacks, char c)
{
	void	*mem;

	if ((c == 'a' || c == 's') && stacks->a && stacks->a->next)
	{
		mem = stacks->a->content;
		stacks->a->content = stacks->a->next->content;
		stacks->a->next->content = mem;
	}
	if ((c == 'b' || c == 's') && stacks->b && stacks->b->next)
	{
		mem = stacks->b->content;
		stacks->b->content = stacks->b->next->content;
		stacks->b->next->content = mem;
	}
	ft_printf("s%c\n", c);
}

void	push(t_stacks *stacks, char c)
{
	t_list	*temp;

	if (c == 'a' && stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = stacks->a;
		stacks->a = temp;
	}
	if (c == 'b' && stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = stacks->b;
		stacks->b = temp;
	}
	ft_printf("p%c\n", c);
}

void	rotate(t_stacks *stacks, char c)
{
	t_list	*temp;

	if ((c == 'a' || c == 'r') && stacks->a && stacks->a->next)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_back(&(stacks->a), temp);
	}
	if ((c == 'b' || c == 'r') && stacks->b && stacks->b->next)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_back(&(stacks->b), temp);
	}
	ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stacks *stacks, char c)
{
	t_list	*second_last;

	if ((c == 'a' || c == 'r') && stacks->a && stacks->a->next)
	{
		second_last = stacks->a;
		while (second_last->next->next)
			second_last = second_last->next;
		(second_last->next)->next = stacks->a;
		stacks->a = (second_last->next);
		second_last->next = NULL;
	}
	if ((c == 'b' || c == 'r') && stacks->b && stacks->b->next)
	{
		second_last = stacks->b;
		while (second_last->next->next)
			second_last = second_last->next;
		(second_last->next)->next = stacks->b;
		stacks->b = (second_last->next);
		second_last->next = NULL;
	}
	ft_printf("rr%c\n", c);
}
