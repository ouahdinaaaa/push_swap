/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:07:45 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 14:22:28 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_pile *pile)
{
	t_pile	*first;

	while (pile)
	{
		first = pile -> next;
		free(pile);
		pile = first;
	}
}

void	free_data(t_data *data)
{
	if (data->pile_b)
		free_pile(data->pile_b);
	free_pile(data->pile_a);
	free(data);
}
