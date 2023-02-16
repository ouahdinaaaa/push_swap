/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:21:46 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 10:23:44 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nb_atoi(const char *str)
{
	int			sign;
	long int	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str + 1 == '+' || *str + 1 == '-')
			sign *= 0;
		sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (*str || sign == 0)
	{
		ft_putstr("ERROR\n");
		exit(0);
	}
	return (num * sign);
}

int	check_doublon(t_pile **pile_a)
{
	t_pile	*tmp;
	t_pile	*tmp_2;

	tmp_2 = *pile_a;
	tmp = (*pile_a)->next;
	while (tmp_2->next)
	{
		while (tmp)
		{
			if (tmp_2->nb == tmp->nb)
				return (ft_putstr("ERROR\nDoublon\n"), 1);
			tmp = tmp->next;
		}
		tmp_2 = tmp_2->next;
		tmp = tmp_2->next;
	}
	return (0);
}

int	check_node(t_pile *pilea)
{
	int		nb_pilea;
	t_pile	*tmp;

	nb_pilea = pilea->nb;
	tmp = pilea->next;
	while (tmp)
	{
		if (nb_pilea > tmp->nb)
			return (1);
		nb_pilea = tmp->nb;
		tmp = tmp->next;
	}
	ft_putstr("ERROR\nPile triee\n");
	return (0);
}

void	tri_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

int	*create_tab(t_pile **pile_a)
{
	t_pile	*tmp;
	int		size;
	int		*tab;
	int		i;

	size = ft_listsize(*pile_a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	tmp = *pile_a;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
	tri_tab(tab, size);
	return (tab);
}
