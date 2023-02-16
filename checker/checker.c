/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:04 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 14:16:42 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_pilea(t_pile *pile, t_data *data)
{
	int	i;
	int	size;

	if (!pile)
		return ;
	i = 0;
	size = ft_listsize(pile);
	while (pile->next && i < size)
	{
		if (pile->nb > pile->next->nb)
		{
			write(1, "KO\n", 3);
			free_data(data);
			exit(0);
		}
		i++;
		pile = pile->next;
	}
	write (1, "OK\n", 3);
}

int	mouvv(const char *str, t_pile **pile_a, t_pile **pile_b, t_data *data)
{
	if (!ft_strcmp(str, "ra\n"))
		mouv_ra_rb_rr(pile_a, pile_b, 'a');
	else if (!ft_strcmp(str, "rb\n"))
		mouv_ra_rb_rr(pile_a, pile_b, 'b');
	else if (!ft_strcmp(str, "rra\n"))
		mouv_rra_rrb_rrr(pile_a, pile_b, 'a');
	else if (!ft_strcmp(str, "rrb\n"))
		mouv_rra_rrb_rrr(pile_a, pile_b, 'b');
	else if (!ft_strcmp(str, "rr\n"))
		mouv_ra_rb_rr(pile_a, pile_b, 'r');
	else if (!ft_strcmp(str, "rrr\n"))
		mouv_rra_rrb_rrr(pile_a, pile_b, 'r');
	else if (!ft_strcmp(str, "sa\n"))
		mouv_sa_sb_ss(pile_a, pile_b, 'a');
	else if (!ft_strcmp(str, "sb\n"))
		mouv_sa_sb_ss(pile_a, pile_b, 'b');
	else if (!ft_strcmp(str, "ss\n"))
		mouv_sa_sb_ss(pile_a, pile_b, 's');
	else if (!ft_strcmp(str, "pa\n"))
		mouv_pa_pb(pile_a, pile_b, 'a');
	else if (!ft_strcmp(str, "pb\n"))
		mouv_pa_pb(pile_a, pile_b, 'b');
	else
		return (check_pilea(*pile_a, data), exit(0), 1);
	return (0);
}

void	retrieve_arg(int fd, t_pile **a, t_pile **b, t_data *dataa)
{
	char		*str;
	t_dataa		*data;

	data = ft_calloc(1, sizeof(t_dataa));
	str = get_next_line(fd, data, 0);
	while (str != NULL)
	{
		//verif_string(str);
		mouvv(str, a, b, dataa);
		free(str);
		str = get_next_line(fd, data, 0);
	}
	free(data);
}
