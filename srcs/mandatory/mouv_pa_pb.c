/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_pa_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:28:09 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/17 19:02:57 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_pile(t_pile **pile_push, t_pile **pile)
{
	t_pile	*var;

	if (!*pile_push)
		return ;
	var = (*pile_push);
	*pile_push = (*pile_push)->next;
	if (!*pile)
	{
		var->next = NULL;
		*pile = var;
		return ;
	}
	var->next = *pile;
	*pile = var;
}

void	pa_pb(t_pile **pile_a, t_pile **pile_b, char name)
{
	if (*pile_b && (name == 'a' || name == 'c'))
	{
		if (name == 'a')
			ft_putstr("pa\n");
		push_pile(pile_b, pile_a);
	}
	else if (*pile_a && (name == 'b' || name == 'd'))
	{
		if (name == 'b')
			ft_putstr("pb\n");
		push_pile(pile_a, pile_b);
	}
}

void	mouv_pa_pb(t_pile **pile_a, t_pile **pile_b, char pile)
{
	if (*pile_b && pile == 'a')
		pa_pb(pile_a, pile_b, pile);
	else if (*pile_a && pile == 'b')
		pa_pb(pile_a, pile_b, pile);
	else if (*pile_b && pile == 'c')
		pa_pb(pile_a, pile_b, pile);
	else if (*pile_a && pile == 'd')
		pa_pb(pile_a, pile_b, pile);
}
