/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:47:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/16 23:05:06 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "moves.h"
#include "libft.h"
#include <limits.h>

static t_list	*get_node_at(t_list *lst, int index)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current && i++ < index)
		current = current->next;
	return (current);
}

static int	get_prev_val(t_list *a, int index, int n_a)
{
	t_list	*prev;

	prev = get_node_at(a, (index - 1 + n_a) % n_a);
	return (*(int *)(prev->content));
}

static int	location(int n, t_list *a, int n_a)
{
	int		i;
	int		ext;
	int		ext_pos;
	t_list	*current;

	if (!a)
		return (0);
	i = 0;
	current = a;
	ext = *(int *)(current->content);
	ext_pos = 0;
	while (i < n_a)
	{
		if (n <= *(int *)(current->content) && n >= get_prev_val(a, i, n_a))
			return (i);
		if (*(int *)(current->content) < ext)
		{
			ext = *(int *)(current->content);
			ext_pos = i;
		}
		i++;
		current = current->next;
	}
	return (ext_pos);
}

static int	operations(t_operations *op)
{
	int	abs_ra;
	int	abs_rb;

	abs_ra = ft_abs(op->ra);
	abs_rb = ft_abs(op->rb);
	if (op->ra * op->rb > 0)
		op->n = ft_max(abs_ra, abs_rb);
	else
		op->n = abs_ra + abs_rb;
	return (op->n);
}

static void	optimize(t_operations *op, int n_a, int n_b)
{
	t_operations	var[3];
	int				i;

	var[0].ra = op->ra - n_a;
	var[0].rb = op->rb;
	operations(&var[0]);
	var[1].ra = op->ra;
	var[1].rb = op->rb - n_b;
	operations(&var[1]);
	var[2].ra = op->ra - n_a;
	var[2].rb = op->rb - n_b;
	operations(&var[2]);
	i = 0;
	while (i < 3)
	{
		if (operations(&var[i]) < operations(op))
			*op = var[i];
		i++;
	}
}

static void	print_operations(t_operations op, t_stacks *stacks)
{
	while (op.ra > 0 && op.rb > 0)
	{
		rotate(stacks, MOVE_RR);
		op.ra--;
		op.rb--;
	}
	while (op.ra < 0 && op.rb < 0)
	{
		reverse_rotate(stacks, MOVE_RRR);
		op.ra++;
		op.rb++;
	}
	while (op.ra-- > 0)
		rotate(stacks, MOVE_RA);
	while (op.rb-- > 0)
		rotate(stacks, MOVE_RB);
	while (++op.ra < 0)
		reverse_rotate(stacks, MOVE_RRA);
	while (++op.rb < 0)
		reverse_rotate(stacks, MOVE_RRB);
}

static t_operations	rotations(t_stacks *stacks)
{
	t_operations	best_op;
	t_operations	current_op;
	t_list			*current;
	int				i;

	best_op.n = INT_MAX;
	i = 0;
	current = stacks->b;
	while (i < stacks->n_b)
	{
		current_op.ra = location(*(int *)current->content, stacks->a, stacks->n_a);
		current_op.rb = i;
		optimize(&current_op, stacks->n_a, stacks->n_b);
		if (i++ == 0 || operations(&current_op) < operations(&best_op))
			best_op = current_op;
		current = current->next;
	}
	return (best_op);
}

void	b_to_a(t_stacks *stacks)
{
	while (stacks->n_b > 0)
	{
		print_operations(rotations(stacks), stacks);
		push(stacks, MOVE_PA);
	}
}
