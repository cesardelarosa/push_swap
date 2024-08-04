/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:51:01 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/05 00:48:38 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_increasing(t_list *a)
{
	int	count;
	t_list	*tmp;	

	if (!a)
		return (1);
	tmp = a;
	count = 0;
	while (tmp->next)
	{
		count += (*(int *)(tmp->content) > *(int *)(tmp->next->content));
		tmp = tmp->next;
	}
	count += *(int *)(tmp->content) > *(int *)(a->content);
	return (count < 2);
}

void	print_moves(int r[3], t_stacks *stacks)
{
	while (r[0]-- > 0)
		rotate(stacks, 'a');
	while (r[1]-- > 0)
		rotate(stacks, 'b');
	while (r[2]-- > 0)
		rotate(stacks, 'r');
	while (++r[0] < 0)
		reverse_rotate(stacks, 'a');
	while (++r[1] < 0)
		reverse_rotate(stacks, 'b');
	while (++r[2] < 0)
		reverse_rotate(stacks, 'r');
}

/*
 *  NO NECESITAMOS UN ESPACIO PARA RR, SINO MODIFICAR OPTIMIZE CONVENIENTEMENTE
void	print_moves(int r[2], t_stacks *stacks)
{
	while (r[0] > 0 && r[1] > 0)
	{
		rotate(stacks, 'r');
		r[0]--;
		r[1]--;
	}
	while (r[0] < 0 && r[1] > 0)
	{
		reverse_rotate(stacks, 'r');
		r[0]++;
		r[1]++;
	}
	while (r[0]-- > 0)
		rotate(stacks, 'a');
	while (r[1]-- > 0)
		rotate(stacks, 'b');
	while (++r[0] < 0)
		reverse_rotate(stacks, 'a');
	while (++r[1] < 0)
		reverse_rotate(stacks, 'b');
}
*/

void	rotations(int (*r)[3], t_stacks *stacks, int n[2], int  id)
{
	
}

void	order(t_stacks *stacks)
{
	int	n[2];
	int	r[3];

	n[0] = ft_lstsize(stacks->a);
	n[1] = 0;
	while (!is_increasing(a) && n[0] - 3)
	{	
		rotations(&r, stacks, n, 0);
		print_moves(r, stacks);
		push(stacks, 'b');
		n[0]--;
		n[1]++;
	}
	if (!is_increasing(a))
		swap(stacks, 'a');
	while (n[1])
	{
		rotations(&r, stacks, n, 1);
		print_moves(r, stacks);
		push(stacks, 'a');
		n[0]++;
		n[1]--;
	}
	r[1] = 0;
	r[2] = 0;
	// r[0] para rotar finalmente stack
	optimize(&r, n);
	print(r, stacks);
}
