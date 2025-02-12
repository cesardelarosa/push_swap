/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:55:13 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 11:40:21 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "moves.h"
#include "libft.h"

int		location(int n, t_stack **s);
int		operations(t_operations *op);
void	optimize(t_operations *op, int n[2]);
void	print(t_operations op, t_stacks *stacks);
void	rotations(t_operations *op, t_stacks *stacks);

void	b_to_a(t_stacks *stacks)
{
	t_operations	op;
	t_stack			*tmp;

	while (stacks->n[1])
	{
		rotations(&op, stacks);
		print(op, stacks);
		push(stacks, MOVE_PA);
	}
	op = (t_operations){0, 0, 0};
	tmp = *(stacks->stack[0]);
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num)
		&& op.ra++ != stacks->n[0] - 1)
		tmp = tmp->next;
	operations(&op);
	optimize(&op, stacks->n);
	print(op, stacks);
}

int	location(int n, t_stack **s)
{
	t_stack	*tmp;
	int		i;
	int		ext;
	int		ext_pos;

	tmp = *s;
	if (tmp == NULL)
		return (0);
	i = 0;
	ext = tmp->num;
	ext_pos = 0;
	while (!(n <= tmp->num && n >= tmp->prev->num)
		&& tmp->num != (*s)->prev->num)
	{
		tmp = tmp->next;
		i++;
		if (tmp->num < ext)
		{
			ext = tmp->num;
			ext_pos = i;
		}
	}
	if (!(n <= tmp->num && n >= tmp->prev->num))
		i = ext_pos;
	return (i);
}

int	operations(t_operations *op)
{
	if (op->ra * op->rb > 0)
		op->n = ft_max(abs(op->ra), ft_abs(op->rb));
	else
		op->n = ft_abs(op->ra) + ft_abs(op->rb);
	return (op->n);
}

void	optimize(t_operations *op, int n[2])
{
	t_operations	var[3];
	int				i;

	var[0].ra = op->ra - n[0];
	var[0].rb = op->rb;
	var[1].ra = op->ra;
	var[1].rb = op->rb - n[1];
	var[2].ra = op->ra - n[0];
	var[2].rb = op->rb - n[1];
	i = 0;
	while (i < 3)
	{
		if (operations(&var[i]) < operations(op))
			*op = var[i];
		i++;
	}
}

void	print(t_operations op, t_stacks *stacks)
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

void	rotations(t_operations *op, t_stacks *stacks)
{
	t_operations	m;
	int				i;
	t_stack			*tmp;

	i = 0;
	tmp = *(stacks->stack[1]);
	while (i < stacks->n[1])
	{
		m.ra = location(tmp->num, stacks->stack[0]);
		m.rb = i;
		optimize(&m, stacks->n);
		if (i++ == 0 || operations(&m) < operations(op))
			*op = m;
		tmp = tmp->next;
	}
}
