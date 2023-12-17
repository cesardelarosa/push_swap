/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:35:10 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/12/17 16:00:09 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // read, write
#include <stdlib.h> // malloc, free, exit

int		ft_atoi(const char *nptr);
void	ft_putnbr(int n);

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	read_args(int *stack, int n, char **numbers)
{
	if (n < 1)
		error();
	while (n--)
		stack[n] = ft_atoi(numbers[n + 1]);
}

void	check(int *list, int n)
{
	int	i;

	while (n--)
	{
		i = n;
		while (i--)
		{
			if (list[n] == list[i])
				error();
		}
	}
}

void	print_stack(int *stack, int n)
{
	while (n--)
	{
		ft_putnbr(stack[n]);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	int	*stack[2];

	stack[0] = (int *)malloc(argc * sizeof(int));
	stack[1] = (int *)malloc(argc * sizeof(int));
	read_args(stack[0], argc - 1, argv);
	check(stack[0], argc - 1);
	print_stack(stack[0], argc - 1);
	free(stack[0]);
	free(stack[1]);
	return (0);
}
