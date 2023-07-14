/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:30:35 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/19 17:30:05 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile	*pile, char name)
{
	t_pile	*first;

	first = pile;
	if (!first)
	{
		ft_putstr_fd("Pile vide\n", 1);
		return ;
	}
	ft_putstr_fd("PILE :", 1);
	ft_putchar_fd(name, 1);
	ft_putchar_fd('\n', 1);
	while (first)
	{
		ft_putnbr_fd(first->nb, 1);
		ft_putchar_fd('\n', 1);
		first = first->next;
	}
}
