/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_ra_rb_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:27:08 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/13 19:34:10 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mouv_pile(t_pile **pile, t_pile *end)
{
	if (*pile == NULL)
		return ;
	if (end && end != (*pile))
	{
		end->next = *pile;
		*pile = (*pile)->next;
		end->next->next = NULL;
	}
}

void	mouv(t_pile **a, t_pile **b, char name)
{
	if (a && name == 'a')
	{
		mouv_pile(a, last(*a));
		ft_putstr("ra\n");
	}
	else if (b && name == 'b')
	{
		mouv_pile(b, last(*b));
		ft_putstr("rb\n");
	}
	else if ((a || b) && name == 'r')
	{
		mouv_pile(a, last(*a));
		mouv_pile(b, last(*b));
		ft_putstr("rr\n");
	}
}

void	mouv_ra_rb_rr(t_pile **a, t_pile **b, char pile)
{
	if (*a && (*a)->next && pile == 'a')
		mouv(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'b')
		mouv(NULL, b, pile);
	else if (((*a && (*a)->next) || (*b && (*b)->next)) && pile == 'r')
		mouv(a, b, pile);
}
