#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>


int	location(int n, t_stack **s, int id)
{
	t_stack	*tmp;
	int	i;
	int	ext;
	int	ext_pos;

	tmp = *s;
	if (tmp == NULL)
		return (0);
	i = 0;
	ext = tmp->num;
	ext_pos = 0;
	while (!((n <= tmp->num && n >= tmp->prev->num && id == 1) \
		|| (n >= tmp->num && n <= tmp->prev->num && id == 0)) \
		&& tmp->num != (*s)->prev->num)
	{
		tmp = tmp->next;
		i++;
		if ((tmp->num < ext && id == 1) || (tmp->num > ext && id == 0))
		{
			ext = tmp->num;
			ext_pos = i;
		}
	}
	if (!((n <= tmp->num && n >= tmp->prev->num && id == 1) \
		|| (n >= tmp->num && n <= tmp->prev->num && id == 0)))
		i = ext_pos;
	return (i);
}


int	operations(t_operations *op)
{
	if (op->ra * op->rb > 0)
		op->n = max(abs(op->ra), abs(op->rb));
	else
		op->n = abs(op->ra) + abs(op->rb);
	return (op->n);
}

void	optimize(t_operations *op, int n[2])
{
	t_operations	var[3];
	int		i;

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
		rotate(stacks->stack[0], stacks->stack[1], MOVE_RR);
		op.ra--;
		op.rb--;
	}
	while (op.ra < 0 && op.rb < 0)
	{
		reverse_rotate(stacks->stack[0], stacks->stack[1], MOVE_RRR);
		op.ra++;
		op.rb++;
	}
	while (op.ra-- > 0)
		rotate(stacks->stack[0], stacks->stack[1], MOVE_RA);
	while (op.rb-- > 0)
		rotate(stacks->stack[0], stacks->stack[1], MOVE_RB);
	while (++op.ra < 0)
		reverse_rotate(stacks->stack[0], stacks->stack[1], MOVE_RRA);
	while (++op.rb < 0)
		reverse_rotate(stacks->stack[0], stacks->stack[1], MOVE_RRB);
}

void	rotations(t_operations *op, t_stacks *stacks, int id)
{
	t_operations	m;
	int		i;
	t_stack		*tmp;

	i = 0;
	tmp = *(stacks->stack[id]);
	while (i < stacks->n[id])
	{
		m.ra = i * !id + location(tmp->num, stacks->stack[!id], id) * id;
		m.rb = location(tmp->num, stacks->stack[!id], id) * !id + i * id;
		optimize(&m, stacks->n);
		if (i++ == 0 || operations(&m) < operations(op))
			*op = m;
		tmp = tmp->next;
	}
}

void	order(t_stacks *stacks)
{
	t_operations	op;
	t_stack		*tmp;

	stacks->n[0] = elements(stacks->stack[0]);
	stacks->n[1]= 0;
	while (!check_order(stacks->stack[0]) && stacks->n[0] > 3)
	{
		rotations(&op, stacks, 0);
		print(op, stacks);
		push(stacks->stack[0], stacks->stack[1], MOVE_PB);
		stacks->n[0]--;
		stacks->n[1]++;
	}
	if (!check_order(stacks->stack[0]))
		swap(stacks->stack[0], stacks->stack[1], MOVE_SA);
	while (stacks->n[1])
	{
		rotations(&op, stacks, 1);
		print(op, stacks);
		push(stacks->stack[0], stacks->stack[1], MOVE_PA);
		stacks->n[0]++;
		stacks->n[1]--;
	}
	op = (t_operations){0,0,0};
	tmp = *(stacks->stack[0]);
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num) && op.ra++ != stacks->n[0] - 1)
		tmp = tmp->next;
	operations(&op);
	optimize(&op, stacks->n);
	print(op, stacks);
	//print_stack(*(stacks->stack[0]));
}
