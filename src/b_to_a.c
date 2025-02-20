/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:21:19 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:21:31 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_insert_index(t_list *a, int n)
{
	int		i;
	int		min;
	int		min_idx;
	t_list	*curr;
	int		prev;

	i = 0;
	curr = a;
	min = *(int *)(curr->content);
	min_idx = 0;
	prev = *(int *)(ft_lstlast(a)->content);
	while (curr)
	{
		if (n < *(int *)(curr->content) && n > prev)
			return (i);
		if (*(int *)(curr->content) < min)
		{
			min = *(int *)(curr->content);
			min_idx = i;
		}
		prev = *(int *)(curr->content);
		curr = curr->next;
		i++;
	}
	return (min_idx);
}

static void	calc_moves(t_stacks *s, int *ra, int *rb, int *cost)
{
	int	abs_ra;
	int	abs_rb;

	if (*ra > s->n_a / 2)
		*ra -= s->n_a;
	if (*rb > s->n_b / 2)
		*rb -= s->n_b;
	abs_ra = ft_abs(*ra);
	abs_rb = ft_abs(*rb);
	if (*ra * *rb > 0)
		*cost = ft_max(abs_ra, abs_rb);
	else
		*cost = abs_ra + abs_rb;
}

static void	calc_best_move(t_stacks *s, int *best_ra, int *best_rb, int *best_n)
{
	int		i;
	int		ra;
	int		rb;
	t_list	*bnode;
	int		cost;

	i = 0;
	bnode = s->b;
	*best_n = INT_MAX;
	while (bnode)
	{
		ra = find_insert_index(s->a, *(int *)(bnode->content));
		rb = i;
		calc_moves(s, &ra, &rb, &cost);
		if (cost < *best_n)
		{
			*best_n = cost;
			*best_ra = ra;
			*best_rb = rb;
		}
		bnode = bnode->next;
		i++;
	}
}

static void	execute_rotations(t_stacks *s, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		rotate(s, MOVE_RR);
		ra--;
		rb--;
	}
	while (ra < 0 && rb < 0)
	{
		reverse_rotate(s, MOVE_RRR);
		ra++;
		rb++;
	}
	while (ra-- > 0)
		rotate(s, MOVE_RA);
	while (++ra < 0)
		reverse_rotate(s, MOVE_RRA);
	while (rb-- > 0)
		rotate(s, MOVE_RB);
	while (++rb < 0)
		reverse_rotate(s, MOVE_RRB);
}

void	b_to_a(t_stacks *s)
{
	int	best_ra;
	int	best_rb;
	int	best_total;

	while (s->n_b > 0)
	{
		best_total = INT_MAX;
		calc_best_move(s, &best_ra, &best_rb, &best_total);
		execute_rotations(s, best_ra, best_rb);
		push(s, MOVE_PA);
	}
}
