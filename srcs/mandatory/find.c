/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:11:03 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/12 13:59:44 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_pile *pile, int nb)
{
	t_pile	*first;
	int		index;

	index = 0;
	first = pile;
	while (first)
	{
		if (first->nb == nb)
			return (index);
		first = first->next;
		index++;
	}
	return (index);
}

int	find_min(t_pile *pile)
{
	int		nb;
	t_pile	*tmp;

	tmp = pile;
	nb = pile->nb;
	while (tmp)
	{
		if (tmp->nb < nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	return (nb);
}

int	find_max(t_pile *pile)
{
	int		nb;
	t_pile	*tmp;

	tmp = pile;
	nb = pile->nb;
	while (tmp)
	{
		if (tmp->nb > nb)
			nb = tmp->nb;
		tmp = tmp->next;
	}
	return (nb);
}

int	find_padre(t_pile *pile, int nb)
{
	int		nb_max;
	int		nb_min;
	int		index;
	t_pile	*tmp;
	int		i;

	i = 0;
	index = 0;
	tmp = pile;
	nb_min = find_min(pile);
	nb_max = find_max(pile);
	if (nb > nb_max)
		return (find_index(pile, nb_min));
	while (tmp)
	{
		if (tmp->nb > nb && tmp->nb <= nb_max)
		{
			nb_max = tmp->nb;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (index);
}
