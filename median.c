/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:08:07 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 12:18:34 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_median(t_pile **pile_a, t_data *data)
{
	int		*tab;
	int		mediane;
	int		size;

	tab = create_tab(pile_a);
	size = ft_listsize(*pile_a);
	mediane = tab[(size / 7) * 5];
	while (ft_listsize(*pile_a) > 3)
	{
		if (data->pile_a->nb >= mediane)
		{
			mouv_pa_pb(pile_a, &data->pile_b, 'b');
			free(tab);
			tab = create_tab(pile_a);
			size = ft_listsize(*pile_a);
			mediane = tab[((size / 7) * 5)];
		}
		else
			mouv_ra_rb_rr(pile_a, NULL, 'a');
	}
	free(tab);
	tri_3(&data->pile_a);
}
