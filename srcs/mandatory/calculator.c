/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:10:13 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/07/14 15:08:57 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	counter_pilea(t_pile *pile, int index, t_bestmove *best)
{
	int	size;

	size = ft_listsize(pile);
	if (index > size / 2)
		best -> rra = size - index;
	else
		best -> ra = index;
}

void	counter_pileb(t_pile *pile, int index, t_bestmove *best)
{
	int	size;

	size = ft_listsize(pile);
	if (index > size / 2)
		best -> rrb = size - index;
	else
		best -> rb = index;
}

t_bestmove	counter_calc(t_pile *ptr, t_pile *ptrb)
{
	t_pile		*pileb;
	t_bestmove	*bestmove;
	t_bestmove	test;
	int			i;

	bestmove = ft_calloc(1, (sizeof(t_bestmove) * ft_listsize(ptrb)));
	pileb = ptrb;
	i = 0;
	while (pileb)
	{
		counter_pileb(ptrb, i, &bestmove[i]);
		counter_pilea(ptr, find_padre(ptr, pileb->nb), &bestmove[i]);
		i++;
		pileb = pileb->next;
	}
	test = find_min_from_struct(bestmove, i);
	free(bestmove);
	return (test);
}

void	mouv_algo(t_pile **pile_a, t_pile **pile_b, t_bestmove bestmove)
{
	if (bestmove.ra)
	{
		while (bestmove.ra-- > 0)
			mouv_ra_rb_rr(pile_a, pile_b, 'a');
	}
	if (bestmove.rb)
	{
		while (bestmove.rb-- > 0)
			mouv_ra_rb_rr(pile_a, pile_b, 'b');
	}
	if (bestmove.rra)
	{
		while (bestmove.rra-- > 0)
			mouv_rra_rrb_rrr(pile_a, pile_b, 'a');
	}
	if (bestmove.rrb)
	{
		while (bestmove.rrb-- > 0)
			mouv_rra_rrb_rrr(pile_a, pile_b, 'b');
	}
}

void	algo(t_pile **ptr, t_pile **ptrb)
{
	t_pile		**pile_a;
	t_pile		**pile_b;
	t_bestmove	bestmove;

	pile_a = ptr;
	pile_b = ptrb;
	bestmove = counter_calc(*pile_a, *pile_b);
	while (bestmove.ra > 0 && bestmove.rb > 0)
	{
		mouv_ra_rb_rr(ptr, ptrb, 'r');
		bestmove.ra--;
		bestmove.rb--;
	}
	while (bestmove.rra > 0 && bestmove.rrb > 0)
	{
		mouv_rra_rrb_rrr(ptr, ptrb, 'r');
		bestmove.rra--;
		bestmove.rrb--;
	}
	mouv_algo(ptr, ptrb, bestmove);
	mouv_pa_pb(pile_a, pile_b, 'a');
}
