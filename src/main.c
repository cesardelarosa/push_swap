/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:31:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/15 15:50:57 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "stacks.h"
#include "operations.h"
#include "turkish.h"
#include "libft.h"
#include "ft_printf.h"

#define HEURISTIC 1.065

void	quick_to_b(t_stacks *stacks)
{
	int				n;
	int				i;

	stacks->n_a = elements(stacks->a);
	stacks->n_b = 0;
	while (!check_order(stacks->a) && stacks->n_a > 3)
	{
		i = (int)(ft_log(stacks->n_a + stacks->n_b) / ft_log(HEURISTIC));
		n = find_nth_smallest(*(stacks->a), i);
		while (i && stacks->n_a > 3 && !check_order(stacks->a))
		{
			if (stacks->a->num < n)
			{
				push(stacks, 'b');
				stacks->n_a--;
				stacks->n_b++;
			}
			else
				rotate(stacks, 'a');
			i--;
		}
	}
	if (!check_order(stacks->a))
		swap(stacks, 'a');
}

void	turkish_to_a(t_stacks *stacks)
{
	t_operations	op;
	t_stack			*tmp;

	while (stacks->n_a)
	{
		rotations(&op, stacks);
		print(op, stacks);
		push(stacks, 'a');
		stacks->n_a++;
		stacks->n_b--;
	}
	op = (t_operations){0, 0, 0};
	tmp = stacks->a;
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num) \
		&& op.ra++ != stacks->n_a - 1)
		tmp = tmp->next;
	operations(&op);
	optimize(&op, stacks->n_a + stacks->n_b);
	print(op, stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error();
	stacks->a = NULL;
	stacks->b = NULL;
	if (argc == 2)
		read_args(&(stacks->a), ft_split(argv[1], ' '));
	else if (argc > 2)
		read_args(&(stacks->a), ++argv);
	check(stacks->a);
	quick_to_b(stacks);
	turkish_to_a(stacks);
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	free(stacks);
	return (0);
}
