/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:31:27 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/08/15 04:50:44 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
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
