/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 00:12:26 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 10:41:26 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stacks.h"
#include "libft.h"

static int		count_tokens(int argc, char **argv);
static char		**combine_tokens(int argc, char **argv, int num_tokens);
static void		init_stacks(t_stacks *stacks);
static void		check_duplicates_tokens(char **tokens);
static void		create_stack_from_tokens(t_stack **stack, char **tokens);

t_stacks	*parser(int argc, char **argv)
{
	t_stacks	*stacks;
	int			num_tokens;
	char		**tokens;

	if (argc < 2 || !argv[1] || !*argv[1])
		ft_error();
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		ft_error();
	init_stacks(stacks);
	num_tokens = count_tokens(argc, argv);
	tokens = combine_tokens(argc, argv, num_tokens);
	check_duplicates_tokens(tokens);
	create_stack_from_tokens(stacks->stack[0], tokens);
	ft_free_split(tokens);
	return (stacks);
}

static int	count_tokens(int argc, char **argv)
{
	int		i;
	int		count;
	char	**split;
	int		j;

	i = 1;
	count = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
			ft_error();
		j = 0;
		while (split[j++])
			count++;
		ft_free_split(split);
	}
	if (count == 0)
		ft_error();
	return (count);
}

static char	**combine_tokens(int argc, char **argv, int num_tokens)
{
	char	**tokens;
	char	**split;
	int		i;
	int		index;
	int		j;

	tokens = malloc((num_tokens + 1) * sizeof(char *));
	if (!tokens)
		ft_error();
	i = 1;
	index = 0;
	while (i < argc)
	{
		split = ft_split(argv[i++], ' ');
		if (!split)
		{
			ft_free_split(tokens);
			ft_error();
		}
		j = 0;
		while (split[j])
		{
			tokens[index] = ft_strdup(split[j++]);
			if (!tokens[index++])
			{
				ft_free_split(split);
				ft_free_split(tokens);
				ft_error();
			}
		}
		ft_free_split(split);
	}
	tokens[index] = NULL;
	return (tokens);
}

static void	init_stacks(t_stacks *stacks)
{
	stacks->stack[0] = malloc(sizeof(t_stack *));
	stacks->stack[1] = malloc(sizeof(t_stack *));
	if (!stacks->stack[0] || !stacks->stack[1])
		ft_error();
	*(stacks->stack[0]) = NULL;
	*(stacks->stack[1]) = NULL;
	stacks->n[0] = 0;
	stacks->n[1] = 0;
}

static void	check_duplicates_tokens(char **tokens)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (tokens[i])
	{
		num = ft_atoi(tokens[i]);
		j = ++i;
		while (tokens[j])
		{
			if (num == ft_atoi(tokens[j++]))
				ft_error();
		}
	}
}

static void	create_stack_from_tokens(t_stack **stack, char **tokens)
{
	int		i;
	t_stack	*node;

	i = 0;
	while (tokens[i])
	{
		node = ft_lstnew_psw(ft_atoi(tokens[i++]));
		if (!node)
			ft_error();
		ft_lstadd_back_psw(stack, node);
	}
}
