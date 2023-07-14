/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:35:56 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/15 11:58:08 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_mouv_rr_rrr(int total, t_bestmove *bestmove, int i)
{
	if (bestmove[i].ra && bestmove[i].rb)
	{
		if (bestmove[i].ra < bestmove[i].rb)
			total = bestmove[i].rb;
		else if (bestmove[i].ra >= bestmove[i].rb)
			total = bestmove[i].ra;
	}
	if (bestmove[i].rra && bestmove[i].rrb)
	{
		if (bestmove[i].rra < bestmove[i].rrb)
			total = bestmove[i].rrb;
		else if (bestmove[i].rra >= bestmove[i].rrb)
			total = bestmove[i].rra;
	}
	return (total);
}

int	check_condition_struct(int total, t_bestmove *bestmove, int i)
{
	if ((bestmove[i].ra && bestmove[i].rb)
		|| (bestmove[i].rra && bestmove[i].rrb))
		total = check_mouv_rr_rrr(total, bestmove, i);
	else
	{
		if (!bestmove[i].ra && !bestmove[i].rrb)
			total = bestmove[i].rb + bestmove[i].rra;
		if (!bestmove[i].rb && !bestmove[i].rra)
			total = bestmove[i].ra + bestmove[i].rrb;
		if (!bestmove[i].rrb && !bestmove[i].ra)
			total = bestmove[i].rb + bestmove[i].rra;
		if (!bestmove[i].rra && !bestmove[i].rb)
			total = bestmove[i].ra + bestmove[i].rrb;
	}
	return (total);
}

t_bestmove	find_min_from_struct(t_bestmove *bestmove, int size)
{
	int	index;
	int	total;
	int	min;
	int	i;

	i = 0;
	index = 0;
	total = 0;
	total = check_condition_struct(total, bestmove, i);
	min = total;
	while (i < size)
	{
		total = check_condition_struct(total, bestmove, i);
		if (total < min)
		{
			min = total;
			index = i;
		}
		i++;
	}
	return (bestmove[index]);
}
