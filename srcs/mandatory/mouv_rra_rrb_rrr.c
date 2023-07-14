/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rra_rrb_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:27:48 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/19 17:32:16 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb_rrr(t_pile **pile)
{
	t_pile	*vari;
	t_pile	*tmp;

	if (*pile && !(*pile)->next)
		return ;
	tmp = *pile;
	vari = last(*pile);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	vari->next = *pile;
	*pile = vari;
}

void	mouv_add(t_pile **pile_a, t_pile **pile_b, char name)
{
	if (pile_a && (name == 'a' || name == 'c'))
	{
		if (name == 'a')
			ft_putstr("rra\n");
		rra_rrb_rrr(pile_a);
	}
	else if (pile_b && (name == 'b' || name == 'd'))
	{
		if (name == 'b')
			ft_putstr("rrb\n");
		rra_rrb_rrr(pile_b);
	}
	else if (pile_a && *pile_b && (name == 'r' || name == 'u'))
	{
		if (name == 'r')
			ft_putstr("rrr\n");
		rra_rrb_rrr(pile_a);
		rra_rrb_rrr(pile_b);
	}
}

void	mouv_rra_rrb_rrr(t_pile **a, t_pile **b, char pile)
{
	if (*a && (*a)->next && pile == 'a')
		mouv_add(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'b')
		mouv_add(NULL, b, pile);
	else if ((*a && (*a)->next) || ((*b && ((*b)->next)) && pile == 'r'))
		mouv_add(a, b, pile);
	else if (*a && (*a)->next && pile == 'c')
		mouv_add(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'd')
		mouv_add(NULL, b, pile);
	else if ((*a && (*a)->next) || ((*b && (*b)->next) && pile == 'u'))
		mouv_add(a, b, pile);
}
