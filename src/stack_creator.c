/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpedrer <adpedrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:32:36 by adpedrer          #+#    #+#             */
/*   Updated: 2024/08/15 03:01:48 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void stacks_initiator(t_stack ***a, t_stack ***b)
{
	*a = (t_stack **)malloc(sizeof(t_stack *));
	*b = (t_stack **)malloc(sizeof(t_stack *));
	if (!*a || !*b)
		error(2);
	**a = NULL;
	**b = NULL;
}

int count_numbers(int argc, char **argv)
{
	int i;
	int j;
	int count;
	char **result;
	
	i = 1;
	count = 0;
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (!result)
		{
			//fprintf(stderr, "Error: fallo en ft_split durante count_numbers\n");
			error(2);
		}
		j = 0;
		while (result[j])
		{
			count++;
			j++;
		}
		free_split(result);
		i++;
	}
	if (count == 0)
		error(2);
	return count;
}

void allocate_combined_args(char ***combined_args, int num_numbers)
{
	int k;

	*combined_args = (char **)malloc((num_numbers + 1) * sizeof(char *));
	if (!(*combined_args))
	{
		//fprintf(stderr, "Error: fallo en la asignación de memoria para combined_args\n");
		error(2);
	}

	k = 0;
	while (k < num_numbers + 1)
	{
		(*combined_args)[k] = NULL;
		k++;
	}
}

void handle_split_result(char **combined_args, char **result, int *index)
{
	int j;

	j = 0;
	while (result[j])
	{
		combined_args[*index] = ft_strdup(result[j]);
		if (!combined_args[*index])
		{
			free_split(result);
			free_split(combined_args);
			//fprintf(stderr, "Error: fallo en strdup\n");
			error(2);
		}
		(*index)++;
		j++;
	}
}

void fill_combined_args(char **combined_args, int argc, char **argv)
{
	char **result;
	int i;
	int index;

	i = 1;
	index = 0;
	while (i < argc)
	{
		result = ft_split(argv[i], ' ');
		if (!result)
		{
			free_split(combined_args);
			//fprintf(stderr, "Error: fallo en ft_split\n");
			error(2); 
		}
		handle_split_result(combined_args, result, &index);
		free_split(result);
		i++;
	}
}

void stack_creator(t_stack **a, int argc, char **argv)
{
	int num_numbers;
	char **combined_args;

	if (argc < 2 || !argv[1])
		error(7);
	num_numbers = count_numbers(argc, argv);
	allocate_combined_args(&combined_args, num_numbers);
	fill_combined_args(combined_args, argc, argv);
	combined_args[num_numbers] = NULL;
	//print_result(combined_args);
	check_duplicates(combined_args);
	stack_creator_add(a, combined_args);
	free_split(combined_args);
}

void free_split(char **split)
{
	int i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void check_duplicates(char **nums)
{
	int i;
	int j;
	long num;

	i = 0;
	while (nums[i])
	{
		num = atoi_psw(nums[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			//fprintf(stderr, "Error: valor fuera del rango INT_MAX o INT_MIN en check_duplicates\n");
			error(1);
		}
		j = i + 1;
		while (nums[j])
		{
			if (num == atoi_psw(nums[j]))
			{
				//fprintf(stderr, "Error: duplicado encontrado en check_duplicates\n");
				error(3);
			}
			j++;
		}
		i++;
	}
}

void stack_creator_add(t_stack **a, char **nums)
{
	t_stack *temp;
	int i;

	i = 0;
	while (nums[i])
	{
		temp = ft_lstnew_psw(atoi_psw(nums[i]));
		if (!temp)
		{
			//fprintf(stderr, "Error: fallo en ft_lstnew_psw en stack_creator_add\n");
			error(2);
		}
		ft_lstadd_back_psw(a, temp);
		i++;
	}
}

long atoi_psw(char *str)
{
	long num;
	int sign;

	num = 0;
	sign = 1;
	if (!(*str))
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		error(1);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		error(1);
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		error(1);
	return (num * sign);
}
