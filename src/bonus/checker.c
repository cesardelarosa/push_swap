/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:14:10 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/13 19:56:11 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	remove_newline(char *instr)
{
	size_t	len;

	len = ft_strlen(instr);
	if (len > 0 && instr[len - 1] == '\n')
		instr[len - 1] = '\0';
}

void	execute_instruction(t_stacks *stacks, char *instr)
{
	if (!ft_strcmp(instr, "sa"))
		silent_swap(stacks, MOVE_SA);
	else if (!ft_strcmp(instr, "sb"))
		silent_swap(stacks, MOVE_SB);
	else if (!ft_strcmp(instr, "ss"))
		silent_swap(stacks, MOVE_SS);
	else if (!ft_strcmp(instr, "pa"))
		silent_push(stacks, MOVE_PA);
	else if (!ft_strcmp(instr, "pb"))
		silent_push(stacks, MOVE_PB);
	else if (!ft_strcmp(instr, "ra"))
		silent_rotate(stacks, MOVE_RA);
	else if (!ft_strcmp(instr, "rb"))
		silent_rotate(stacks, MOVE_RB);
	else if (!ft_strcmp(instr, "rr"))
		silent_rotate(stacks, MOVE_RR);
	else if (!ft_strcmp(instr, "rra"))
		silent_reverse_rotate(stacks, MOVE_RRA);
	else if (!ft_strcmp(instr, "rrb"))
		silent_reverse_rotate(stacks, MOVE_RRB);
	else if (!ft_strcmp(instr, "rrr"))
		silent_reverse_rotate(stacks, MOVE_RRR);
	else
		ft_error();
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	char		*instr;

	if (argc < 2)
		return (0);
	stacks = parser(argc, argv);
	instr = get_next_line(0);
	while (instr)
	{
		remove_newline(instr);
		if (instr[0] == '\0')
		{
			free(instr);
			break ;
		}
		execute_instruction(stacks, instr);
		free(instr);
		instr = get_next_line(0);
	}
	if (check_order(stacks->a) && !(stacks->b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(stacks);
	return (0);
}
