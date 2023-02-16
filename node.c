/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:16:27 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 09:51:54 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*new(int nb)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_add(t_pile **lst, t_pile *new)
{
	new->next = *lst;
	*lst = new;
}

t_pile	*last(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next != NULL)
		pile = pile->next;
	return (pile);
}

void	create_pile(t_data *data, int argc, char **argv)
{
	int		i;
	int		nb;
	t_pile	*node;

	i = argc - 1 ;
	while (i >= 1)
	{
		nb = ft_nb_atoi(argv[i]);
		node = new(nb);
		if ((nb > 2147483647 || nb < -2147483648) || node == NULL)
		{
			free(data);
			ft_putstr("ERROR\n");
			exit(0);
		}
		ft_add(&data->pile_a, node);
		i--;
	}
}
