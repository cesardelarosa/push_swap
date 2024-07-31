#include "push_swap.h"
#include "ft_printf/ft_printf.h"

int	order_b(int n, t_stack **b)
{
	t_stack	*tmp;
	int	i;
	int	max;
	int	max_pos;

	tmp = *b;
	i = 0;
	max = tmp->num;
	max_pos = 0;
	while (!(n > tmp->num && n < tmp->prev->num) && tmp->num != (*b)->next->num)
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

void	optimize(int **r, int n_a, int n_b)
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

void	find_best(t_stack **a, t_stack **b, int n_a, int n_b)
{
	t_stack	*tmp;
	int	i;
	int	r[3];
	int	*ptr;
	int	best[3];

	tmp = *a;
	i = 0;
	best[0] = 0;
	best[1] = order_b(tmp->num, b);
	best[2] = 0;
	while (i < n_a)
	{
		r[0] = i;
		r[1] = order_b(tmp->num, b);
		r[2] = 0;
		ptr = r;
		optimize(&ptr, n_a, n_b);
		if (r[0] + r[1] + r[2] < best[0] + best[1] + best[2])
		{
			best[0] = r[0];
			best[1] = r[1];
			best[2] = r[2];
		}	
		tmp = tmp->next;
		i++;
	}
	while (best[0]-- > 0)
		rotate(a, b, MOVE_RA);
	while (best[1]-- > 0)
		rotate(a, b, MOVE_RB);
	while (best[2]-- > 0)
		rotate(a, b, MOVE_RR);
	while (best[0]++ < 0)
		reverse_rotate(a, b, MOVE_RRA);
	while (best[1]++ < 0)
		reverse_rotate(a, b, MOVE_RRB);
	while (best[2]++ < 0)
		reverse_rotate(a, b, MOVE_RRR);
		
}

void	order(t_stack **a, t_stack **b)
{
	int	n_a;
	int	n_b;

	n_a = elements(a);
	n_b = 0;
	while (!check_order(a) && n_a > 3)
	{
		push(a, b, MOVE_PB);
		find_best(a, b, n_a, n_b);	
		n_a--;
		n_b++;
	}
	if (!check_order(a))
		swap(a, b, MOVE_SA);
}
