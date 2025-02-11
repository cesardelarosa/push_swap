/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:51 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/11 19:54:52 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_numbers(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
		error();
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
