/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:30:35 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/01/28 08:32:33 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_pile(t_pile	*pile, char name)
{
	t_pile	*first;

	first = pile;
	if (!first)
	{
		printf("Pile vide\n");
		return ;
	}
	printf("PILE : %c\n", name);
	while (first)
	{
		printf("%d \n", first->nb);
		first = first->next;
	}
}
