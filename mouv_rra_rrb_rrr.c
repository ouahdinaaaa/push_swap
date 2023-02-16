/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_rra_rrb_rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:27:48 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/09 10:39:58 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb_rrr(t_pile **pile)
{
	t_pile	*vari;
	t_pile	*tmp;

	if (!pile || ((*pile) && !(*pile)->next))
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
	if (pile_a && name == 'a')
	{
		rra_rrb_rrr(pile_a);
		ft_putstr("rra\n");
	}
	else if (pile_b && name == 'b')
	{
		rra_rrb_rrr(pile_b);
		ft_putstr("rrb\n");
	}
	else if ((pile_a || pile_b) && name == 'r')
	{
		rra_rrb_rrr(pile_a);
		rra_rrb_rrr(pile_b);
		ft_putstr("rrr\n");
	}
}

void	mouv_rra_rrb_rrr(t_pile **a, t_pile **b, char pile)
{
	if (*a && (*a)->next && pile == 'a')
		mouv_add(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'b')
		mouv_add(NULL, b, pile);
	else if (((*a && (*a)->next) || (*b && (*b)->next)) && pile == 'r')
		mouv_add(a, b, pile);
}
