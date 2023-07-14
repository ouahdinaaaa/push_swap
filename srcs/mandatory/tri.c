/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:29:43 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/07/14 15:08:20 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(t_pile *pile)
{
	int		i;
	t_pile	*tmp;

	i = 0;
	tmp = pile;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	small_number_b(t_pile **pile)
{
	t_pile	*tmp;
	int		index;
	int		nb;

	index = 0;
	tmp = (*pile)->next;
	nb = (*pile)->nb;
	while (tmp)
	{
		if (tmp->nb < nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	index = find_index(*pile, nb);
	return (index);
}

void	small_push(t_pile **pile_a, t_pile **pile_b)
{
	int	index;

	index = small_number_b(pile_a);
	if (index == 1)
		mouv_ra_rb_rr(pile_a, pile_b, 'a');
	else if (index == 2)
	{
		mouv_ra_rb_rr(pile_a, pile_b, 'a');
		mouv_ra_rb_rr(pile_a, pile_b, 'a');
	}
	else if (index == 3)
	{
		mouv_ra_rb_rr(pile_a, pile_b, 'r');
		mouv_ra_rb_rr(pile_a, pile_b, 'r');
		mouv_ra_rb_rr(pile_a, pile_b, 'r');
	}
	else if (index == 4)
		mouv_rra_rrb_rrr(pile_a, pile_b, 'a');
	mouv_pa_pb(pile_a, pile_b, 'b');
}

void	tri_5(t_pile **pile_a, t_pile **pile_b)
{
	small_push(pile_a, pile_b);
	small_push(pile_a, pile_b);
	tri_3(pile_a);
	mouv_pa_pb(pile_a, pile_b, 'a');
	mouv_pa_pb(pile_a, pile_b, 'a');
}

void	tri_3(t_pile **pile)
{
	int	a;
	int	b;
	int	c;

	a = (*pile)->nb;
	b = (*pile)->next->nb;
	c = (*pile)->next->next->nb;
	if (a < b && b < c)
		return ;
	else if (a > b && b < c && a < c)
		mouv_sa_sb_ss(pile, NULL, 'a');
	else if (a < b && b > c && a > c)
		mouv_rra_rrb_rrr(pile, NULL, 'a');
	else if (a > b && b < c && a > c)
		mouv_ra_rb_rr(pile, NULL, 'a');
	else if (a < b && b > c && a < c)
	{
		mouv_rra_rrb_rrr(pile, NULL, 'a');
		mouv_sa_sb_ss(pile, NULL, 'a');
	}
	else
	{
		mouv_ra_rb_rr(pile, NULL, 'a');
		mouv_sa_sb_ss(pile, NULL, 'a');
	}
}
