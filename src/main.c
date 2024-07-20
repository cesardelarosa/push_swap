/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:31:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/07/13 12:31:27 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	read_args(t_list **a, char **numbers)
{
	int	*content;

	while (*numbers)
	{
		content = (int *)malloc(sizeof(int));
		if (!content)
			ft_error();
		*content = ft_atoi(*numbers);
		ft_lstadd_back(a, ft_lstnew(content));
		numbers++;
	}
}

void	check(t_list *current)
{
	t_list	*compare;

	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (*(int *)current->content == *(int *)compare->content)
				ft_error();
			compare = compare->next;
		}
		current = current->next;
	}
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
	order(stacks);
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	free(stacks);
	return (0);
}
