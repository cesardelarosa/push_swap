/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:32:17 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/12 11:32:25 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_numbers(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
