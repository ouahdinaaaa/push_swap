/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:17:59 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 09:51:29 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mouv_arrange(t_pile **pileA)
{
	int	size;
	int	nb_min;
	int	index_min;

	size = ft_listsize(*pileA);
	nb_min = find_min(*pileA);
	index_min = find_index(*pileA, nb_min);
	if (index_min > (size / 2))
	{
		index_min = size - index_min;
		while (index_min-- > 0)
			mouv_rra_rrb_rrr(pileA, NULL, 'a');
	}
	else
	{
		while (index_min-- > 0)
			mouv_ra_rb_rr(pileA, NULL, 'a');
	}
}

int	find_nb(t_pile *pile, int index)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (pile)
	{
		if (i == index)
			nb = pile->nb;
		pile = pile->next;
		i++;
	}
	return (nb);
}
