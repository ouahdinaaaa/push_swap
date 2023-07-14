/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_sa_sb_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:29:59 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/17 19:06:01 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mouv_swap(t_pile **pile_a, t_pile **pile_b, char name)
{
	if (*pile_a && (*pile_a)->next && (name == 'a' || name == 'c'))
	{
		if (name == 'a')
			ft_putstr("sa\n");
		ft_swap((&(*pile_a)->nb), (&(*pile_a)->next->nb));
	}
	else if (*pile_b && (*pile_b)->next && (name == 'b' || name == 'd'))
	{
		if (name == 'b')
			ft_putstr("sb\n");
		ft_swap((&(*pile_b)->nb), (&(*pile_b)->next->nb));
	}
	else if (((*pile_a && ((*pile_a)->next))
			|| (*pile_b && (*pile_b)->next)) && (name == 's' || name == 'n'))
	{
		if (name == 's')
			ft_putstr("ss\n");
		if (*pile_a && (*pile_a)->next)
			ft_swap((&(*pile_a)->nb), (&(*pile_a)->next->nb));
		if (*pile_b && (*pile_b)->next)
			ft_swap((&(*pile_b)->nb), (&(*pile_b)->next->nb));
	}
}

void	mouv_sa_sb_ss(t_pile **a, t_pile **b, char pile)
{
	if (*a && (*a)->next && pile == 'a')
		mouv_swap(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'b')
		mouv_swap(NULL, b, pile);
	else if (((*a || (*a)->next) || (*b || (*b)->next)) && pile == 's')
		mouv_swap(a, b, pile);
	else if (*a && (*a)->next && pile == 'c')
		mouv_swap(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'd')
		mouv_swap(NULL, b, pile);
	else if (((*a || (*a)->next) || (*b || (*b)->next)) && pile == 'n')
		mouv_swap(a, b, pile);
}
