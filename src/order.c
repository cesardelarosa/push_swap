#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include <limits.h>
#include <math.h>

int	location(int n, t_stack **s)
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
	while (!(n <= tmp->num && n >= tmp->prev->num) && tmp->num != (*s)->prev->num)
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

void	rotations(t_operations *op, t_stacks *stacks)
{
	t_operations	m;
	int		i;
	t_stack		*tmp;

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

void swapp(int *a, int *b) {
    int temp = *a;
    
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swapp(&arr[i], &arr[j]);
            i++;
        }
    }
    swapp(&arr[i], &arr[right]);
    return i;
}

int quickselect(int arr[], int left, int right, int k)
{
	int	i;
    	
	if (left == right)
        		return arr[left];

    	i = partition(arr, left, right);

	if (k == i)
		return arr[k];
	else if (k < i)
		return quickselect(arr, left, i - 1, k);
	else
        	return quickselect(arr, i + 1, right, k);
}

int *stack_to_array(t_stack *stack, int *size) {
    int *arr;
    int i = 0;

    if (!stack) {
        *size = 0;
        return NULL;
    }
    t_stack *tmp = stack;
    do {
        (*size)++;
        tmp = tmp->next;
    } while (tmp != stack);
    arr = (int *)malloc((*size) * sizeof(int));
    if (!arr)
        error(0);
    tmp = stack;
    while (i < *size) {
        arr[i++] = tmp->num;
        tmp = tmp->next;
    }
    return arr;
}

int find_nth_smallest(t_stack *stack, int n) {
    int size = 0;
    int *arr = stack_to_array(stack, &size);

    if (n > size)
        n = size; // Ajustar n al tamaño de la pila
    int result = quickselect(arr, 0, size - 1, n - 1);
    free(arr);
    return result;
}

void	order(t_stacks *stacks)
{
	t_operations	op;
	t_stack		*tmp;
	int		n;
	int		i;

	stacks->n[0] = elements(stacks->stack[0]);
	stacks->n[1]= 0;
	while (!check_order(stacks->stack[0]) && stacks->n[0] > 3)
	{
		i = log(stacks->n[0] + stacks->n[1])/log(1.09);
		n = find_nth_smallest(*(stacks->stack[0]), i);
		while (i && stacks->n[0] > 3 && !check_order(stacks->stack[0]))
		{
			if ((*stacks->stack[0])->num < n)
			{
				push(stacks->stack[0], stacks->stack[1], MOVE_PB);
				stacks->n[0]--;
				stacks->n[1]++;
			}
			else
				rotate(stacks->stack[0], stacks->stack[1], MOVE_RA);
			i--;
		}
	}
	if (!check_order(stacks->stack[0]))
		swap(stacks->stack[0], stacks->stack[1], MOVE_SA);
	while (stacks->n[1])
	{
		rotations(&op, stacks);
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
