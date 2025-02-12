/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:51 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 12:27:38 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "moves.h"
#include <stdlib.h>

#define HEURISTIC 1.065

int		partition(int arr[], int left, int right);
int		quickselect(int arr[], int left, int right, int k);
int		*stack_to_array(t_stack *stack, int *size);
int		find_nth_smallest(t_stack *stack, int n);
int		elements(t_stack **a);
int		check_order(t_stack **a);

void	a_to_b(t_stacks *stacks)
{
	int	n;
	int	i;

	stacks->n[0] = elements(stacks->stack[0]);
	stacks->n[1] = 0;
	while (!check_order(stacks->stack[0]) && stacks->n[0] > 3)
	{
		i = (int)(ft_log(stacks->n[0] + stacks->n[1]) / ft_log(HEURISTIC));
		n = find_nth_smallest(*(stacks->stack[0]), i);
		while (i-- && stacks->n[0] > 3 && !check_order(stacks->stack[0]))
		{
			if ((*stacks->stack[0])->num < n)
				push(stacks, MOVE_PB);
			else
				rotate(stacks, MOVE_RA);
		}
	}
	if (!check_order(stacks->stack[0]))
		swap(stacks, MOVE_SA);
}

int	elements(t_stack **a)
{
	int		n;
	int		first;
	t_stack	*tmp;

	tmp = *a;
	if (tmp == 0x0)
		return (0);
	n = 1;
	first = tmp->num;
	while (first != tmp->next->num)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

int	check_order(t_stack **a)
{
	int		count;
	t_stack	*tmp;

	tmp = *a;
	if (tmp == tmp->next)
		return (1);
	count = 0;
	while (count == 0 || tmp != *a)
	{
		if (tmp->num > tmp->next->num)
			count++;
		tmp = tmp->next;
	}
	return (count < 2);
}

int	partition(int arr[], int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[right];
	i = left;
	j = left;
	while (j < right)
	{
		if (arr[j] <= pivot)
		{
			ft_swap_numbers(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	ft_swap_numbers(&arr[i], &arr[right]);
	return (i);
}

int	quickselect(int arr[], int left, int right, int k)
{
	int	i;

	if (left == right)
		return (arr[left]);
	i = partition(arr, left, right);
	if (k == i)
		return (arr[k]);
	else if (k < i)
		return (quickselect(arr, left, i - 1, k));
	else
		return (quickselect(arr, i + 1, right, k));
}

int	*stack_to_array(t_stack *stack, int *size)
{
	int		*arr;
	int		i;
	t_stack	*tmp;

	*size = elements(&stack);
	if (*size == 0)
		return (NULL);
	arr = (int *)malloc((*size) * sizeof(int));
	if (!arr)
		ft_error();
	tmp = stack;
	i = 0;
	while (i < *size)
	{
		arr[i++] = tmp->num;
		tmp = tmp->next;
	}
	return (arr);
}

int	find_nth_smallest(t_stack *stack, int n)
{
	int	size;
	int	*arr;
	int	result;

	size = 0;
	arr = stack_to_array(stack, &size);
	if (n > size)
		n = size;
	result = quickselect(arr, 0, size - 1, n - 1);
	free(arr);
	return (result);
}
