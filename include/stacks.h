/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:42 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/18 13:22:45 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		n;
	int		n_a;
	int		n_b;
}			t_stacks;

#endif
