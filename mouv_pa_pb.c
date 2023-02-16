/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv_pa_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:28:09 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/09 15:53:51 by ayael-ou         ###   ########.fr       */
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
	if (*pile_b && name == 'a')
	{
		push_pile(pile_b, pile_a);
		ft_putstr("pa\n");
	}
	else if (*pile_a && name == 'b')
	{
		push_pile(pile_a, pile_b);
		ft_putstr("pb\n");
	}
}

void	mouv_pa_pb(t_pile **pile_a, t_pile **pile_b, char pile)
{
	if (*pile_b && pile == 'a')
		pa_pb(pile_a, pile_b, pile);
	else if (*pile_a && pile == 'b')
		pa_pb(pile_a, pile_b, pile);
}
