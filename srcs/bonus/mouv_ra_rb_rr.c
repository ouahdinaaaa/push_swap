/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_ra_rb_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:27:08 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:49:26 by ayael-ou         ###   ########.fr       */
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
	if (a && (name == 'a' || name == 'c'))
	{
		if (name == 'a')
			ft_putstr("ra\n");
		mouv_pile(a, last(*a));
	}
	else if (b && (name == 'b' || name == 'd'))
	{
		if (name == 'b')
			ft_putstr("rb\n");
		mouv_pile(b, last(*b));
	}
	else if ((a || b) && (name == 'r' || name == 'u'))
	{
		if (name == 'r')
			ft_putstr("rr\n");
		mouv_pile(a, last(*a));
		mouv_pile(b, last(*b));
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
	else if (*a && (*a)->next && pile == 'c')
		mouv(a, NULL, pile);
	else if (*b && (*b)->next && pile == 'd')
		mouv(NULL, b, pile);
	else if (((*a && (*a)->next) || (*b && (*b)->next)) && pile == 'u')
		mouv(a, b, pile);
}
