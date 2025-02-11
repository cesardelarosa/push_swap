/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:54:43 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/11 19:54:44 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks || argc < 2 || !*argv[1])
		error();
	stacks_initiator(&(stacks->stack[0]), &(stacks->stack[1]));
	stack_creator(stacks->stack[0], argc, argv);
	a_to_b(stacks);
	b_to_a(stacks);
	ft_lstclear_psw(stacks->stack[0]);
	ft_lstclear_psw(stacks->stack[1]);
	free(stacks->stack[0]);
	free(stacks->stack[1]);
	free(stacks);
	return (0);
}

void	a_to_b(t_stacks *stacks)
{
	int				n;
	int				i;

	stacks->n[0] = elements(stacks->stack[0]);
	stacks->n[1] = 0;
	while (!check_order(stacks->stack[0]) && stacks->n[0] > 3)
	{
		i = (int)(ft_log(stacks->n[0] + stacks->n[1]) / ft_log(HEURISTIC));
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
}

void	b_to_a(t_stacks *stacks)
{
	t_operations	op;
	t_stack			*tmp;

	while (stacks->n[1])
	{
		rotations(&op, stacks);
		print(op, stacks);
		push(stacks->stack[0], stacks->stack[1], MOVE_PA);
		stacks->n[0]++;
		stacks->n[1]--;
	}
	op = (t_operations){0, 0, 0};
	tmp = *(stacks->stack[0]);
	while (!(tmp->num < tmp->next->num && tmp->num < tmp->prev->num) \
		&& op.ra++ != stacks->n[0] - 1)
		tmp = tmp->next;
	operations(&op);
	optimize(&op, stacks->n);
	print(op, stacks);
}

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
