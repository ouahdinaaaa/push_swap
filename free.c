/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:07:45 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 17:43:11 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_pile *pile)
{
    t_pile    *temp;
    t_pile    *tmp2;

    temp = pile;
    while (temp)
    {
        tmp2 = temp->next;
        free(temp);
        temp = tmp2;
    }
}

void	free_data(t_data *data)
{
	if (data->pile_b)
		free_pile(data->pile_b);
	if (data->pile_a)
		free_pile(data->pile_a);
	if (data)
		free(data);
}
