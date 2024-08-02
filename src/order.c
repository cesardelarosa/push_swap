#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	order_b(int n, t_stack **b)
{
	t_stack	*tmp;
	int	i;
	int	max;
	int	max_pos;

	if (elements(b) < 3)
		return (0);
	tmp = *b;
	i = 0;
	max = tmp->num;
	max_pos = 0;
	while (!(n > tmp->num && n < tmp->prev->num) && tmp->num != (*b)->prev->num)
	{
		tmp = tmp->next;
		i++;
		if (tmp->num > max)
		{
			max = tmp->num;
			max_pos = i;
		}
	}
	if (!(n > tmp->num && n < tmp->prev->num))
		i = max_pos;
	return (i);
}

int	order_a(int n, t_stack **a)
{
	t_stack	*tmp;
	int	i;
	int	min;
	int	min_pos;

	tmp = *a;
	i = 0;
	min = tmp->num;
	min_pos = 0;
	while (!(n < tmp->num && n > tmp->prev->num) && tmp->num != (*a)->prev->num)
	{
		tmp = tmp->next;
		i++;
		if (tmp->num < min)
		{
			min = tmp->num;
			min_pos = i;
		}
	}
	if (!(n < tmp->num && n > tmp->prev->num))
		i = min_pos;
	return (i);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (b > a)
		return (b);
	return (a);
}

void	optimize(int (*r)[3], int n_a, int n_b)
{
	if ((*r)[0] > n_a / 2)
		(*r)[0] -= n_a;
	if ((*r)[1] > n_b / 2)
		(*r)[1] -= n_b;
	if ((*r)[0] > 0 && (*r)[1] > 0)
	{
		(*r)[2] = min((*r)[0], (*r)[1]);
		(*r)[0] -= (*r)[2];
		(*r)[1] -= (*r)[2];
	}
	else if ((*r)[0] < 0 && (*r)[1] < 0)
	{
		(*r)[2] = max((*r)[0], (*r)[1]);
		(*r)[0] -= (*r)[2];
		(*r)[1] -= (*r)[2];
	}
	else
		(*r)[2] = 0;
}

void	print(int *r, t_stack **a, t_stack **b)
{
	while (r[0]-- > 0)
		rotate(a, b, MOVE_RA);
	while (r[1]-- > 0)
		rotate(a, b, MOVE_RB);
	while (r[2]-- > 0)
		rotate(a, b, MOVE_RR);
	while (++r[0] < 0)
		reverse_rotate(a, b, MOVE_RRA);
	while (++r[1] < 0)
		reverse_rotate(a, b, MOVE_RRB);
	while (++r[2] < 0)
		reverse_rotate(a, b, MOVE_RRR);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	rotations_a(int (*r)[3], t_stack **a, t_stack **b, int n_a, int n_b)
{
	int	m[3];
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (i < n_a)
	{
		m[0] = i;
		m[1] = order_b(tmp->num, b);
		m[2] = 0;
		optimize(&m, n_a, n_b);
		if (i++ == 0 || abs(m[0]) + abs(m[1]) + abs(m[2]) < abs((*r)[0]) \
				+ abs((*r)[1]) + abs((*r)[2]))
		{
			(*r)[0] = m[0];
			(*r)[1] = m[1];
			(*r)[2] = m[2];
		}
		tmp = tmp->next;
	}
}

void	rotations_b(int (*r)[3], t_stack **a, t_stack **b, int n_a, int n_b)
{
	int	m[3];
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	while (i < n_b)
	{
		m[0] = order_a(tmp->num, a);
		m[1] = i;
		m[2] = 0;
		optimize(&m, n_a, n_b);
		if (i++ == 0 || abs(m[0]) + abs(m[1]) + abs(m[2]) < abs((*r)[0]) \
				+ abs((*r)[1]) + abs((*r)[2]))
		{
			(*r)[0] = m[0];
			(*r)[1] = m[1];
			(*r)[2] = m[2];
		}
		tmp = tmp->next;
	}
}

void	order(t_stack **a, t_stack **b)
{
	int	n_a;
	int	n_b;
	int	r[3];
	t_stack	*tmp;

	n_a = elements(a);
	if (n_a < 2)
		return ;
	n_b = 0;
	while (!check_order(a) && n_a > 3)
	{
		rotations_a(&r, a, b, n_a, n_b);
		print(r, a, b);
		push(a, b, MOVE_PB);
		n_a--;
		n_b++;
	}
	if (!check_order(a))
		swap(a, b, MOVE_SA);
	while (n_b > 0)
	{
		rotations_b(&r, a, b, n_a, n_b);
		print(r, a, b);
		push(a, b, MOVE_PA);
		n_b--;
		n_a++;
	}
	r[0] = 0;
	r[1] = 0;
	r[2] = 0;
	tmp = *a;
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num))
	{
		r[0]++;
		tmp = tmp->next;
	}
	optimize(&r, n_a, n_b);
	print(r, a, b);
	print_stack(*a);
}
