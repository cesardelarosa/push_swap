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
	while (!((n <= tmp->num && n >= tmp->prev->num && id == 1) || (n >= tmp->num && n <= tmp->prev->num && id == 0)) && tmp->num != (*s)->prev->num)
	{
		tmp = tmp->next;
		i++;
		if ((tmp->num < ext && id == 1) || (tmp->num > ext && id == 0))
		{
			ext = tmp->num;
			ext_pos = i;
		}
	}
	if (!((n <= tmp->num && n >= tmp->prev->num && id == 1) || (n >= tmp->num && n <= tmp->prev->num && id == 0)))
		i = ext_pos;
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

int	cum_abs_sum(int *r, int n)
{
	int	sum;
	int	i;
	
	i = 0;
	sum = 0;
	while(i < n)
	{
		if (r[i] > 0)
			sum += r[i];
		else
			sum -= r[i];
		i++;
	}
	return (sum);
}

void optimize(int (*r)[3], int n[2])
{
	int	p[3][3];

	p[0][0] = (*r)[0];
	p[0][1] = (*r)[1];
	p[0][2] = 0;
	p[1][2] = min(abs(p[0][0]), abs(p[0][1]));
	p[1][0] = p[0][0] - p[1][2];
	p[1][1] = p[0][1] - p[1][2];
	p[2][2] = max(p[0][0] - n[0], p[0][1] - n[1]);
	p[2][0] = p[0][0] - p[2][2] - n[0];
	p[2][1] = p[0][1] - p[2][2] - n[1];
	if (p[0][0] > n[0] / 2)
		p[0][0] -= n[0];
	if (p[0][1] > n[1] / 2)
		p[0][1] -= n[1];
	ft_memcpy(*r, p[0], 3 * sizeof(int));
	if (cum_abs_sum(p[1], 3) < cum_abs_sum(p[0], 3))
		ft_memcpy(*r, p[1], 3 * sizeof(int));
	if (cum_abs_sum(p[2], 3) < cum_abs_sum(p[1], 3) && cum_abs_sum(p[2], 3) < cum_abs_sum(p[0], 3))
		ft_memcpy(*r, p[2], 3 * sizeof(int));
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

void	rotations(int (*r)[3], t_stack **s1, t_stack **s2, int n[2], int id)
{
	int	m[3];
	int	i;
	t_stack	*tmp;

	i = 0;
	tmp = *s1;
	while (i < n[id])
	{
		m[0] = i * !id + location(tmp->num, s2, id) * id;
		m[1] = location(tmp->num, s2, id) * !id + i * id;
		m[2] = 0;
		optimize(&m, n);
		if (i++ == 0 || cum_abs_sum(m, 3) < cum_abs_sum(*r, 3))
			ft_memcpy(*r, m, 3 * sizeof(int));
		tmp = tmp->next;
	}
}

void	order(t_stack **a, t_stack **b)
{
	int	n[2];
	int	r[3];
	t_stack	*tmp;

	n[0] = elements(a);
	n[1] = 0;
	while (!check_order(a) && n[0] > 3)
	{
		rotations(&r, a, b, n, 0);
		print(r, a, b);
		push(a, b, MOVE_PB);
		n[0]--;
		n[1]++;
	}
	if (!check_order(a))
		swap(a, b, MOVE_SA);
	while (n[1] > 0)
	{
		rotations(&r, b, a, n, 1);
		print(r, a, b);
		push(a, b, MOVE_PA);
		n[0]++;
		n[1]--;
	}
	r[0] = 0;
	r[1] = 0;
	r[2] = 0;
	tmp = *a;
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num) && r[0]++ != n[0] - 1)
		tmp = tmp->next;
	optimize(&r, n);
	print(r, a, b);
	//print_stack(*a);
}
