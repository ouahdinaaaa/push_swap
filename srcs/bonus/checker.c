/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:25:04 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/19 12:48:51 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_pilea(t_pile *pile, t_pile *pile_b, t_data *data)
{
	int	i;
	int	size;

	if (!pile || pile_b)
		return (free_data(data), write(1, "KO\n", 3), exit(0));
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
		pile = pile->next;
		i++;
	}
	write (1, "OK\n", 3);
	free_data(data);
}

void	mouv2(const char *str, t_data *data, t_dataa *dataa)
{
	if (!str)
		return (ft_freee(dataa, 0), free_data(data),
			write(1, "KO\n", 3), exit(0));
	if (!ft_strcmp(str, "ra\n"))
		mouv_ra_rb_rr(&data->pile_a, &data->pile_b, 'c');
	else if (!ft_strcmp(str, "print_pileB\n"))
		print_pile(data->pile_b, 'b');
	else if (!ft_strcmp(str, "print_pileA\n"))
		print_pile(data->pile_a, 'a');
	else if (!ft_strcmp(str, "rb\n"))
		mouv_ra_rb_rr(&data->pile_a, &data->pile_b, 'd');
	else if (!ft_strcmp(str, "rra\n"))
		mouv_rra_rrb_rrr(&data->pile_a, &data->pile_b, 'c');
	else if (!ft_strcmp(str, "rrb\n"))
		mouv_rra_rrb_rrr(&data->pile_a, &data->pile_b, 'd');
}

int	mouvv(const char *str, t_data *data, t_dataa *dataa)
{
	if (!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "print_pileB\n")
		|| !ft_strcmp(str, "print_pileA\n") || !ft_strcmp(str, "rb\n")
		|| !ft_strcmp(str, "rra\n") || !ft_strcmp(str, "rrb\n"))
		mouv2(str, data, dataa);
	else if (!ft_strcmp(str, "rr\n"))
		mouv_ra_rb_rr(&data->pile_a, &data->pile_b, 'u');
	else if (!ft_strcmp(str, "rrr\n"))
		mouv_rra_rrb_rrr(&data->pile_a, &data->pile_b, 'u');
	else if (!ft_strcmp(str, "sa\n"))
		mouv_sa_sb_ss(&data->pile_a, &data->pile_b, 'c');
	else if (!ft_strcmp(str, "sb\n"))
		mouv_sa_sb_ss(&data->pile_a, &data->pile_b, 'd');
	else if (!ft_strcmp(str, "ss\n"))
		mouv_sa_sb_ss(&data->pile_a, &data->pile_b, 'n');
	else if (!ft_strcmp(str, "pa\n"))
		mouv_pa_pb(&data->pile_a, &data->pile_b, 'c');
	else if (!ft_strcmp(str, "pb\n"))
		mouv_pa_pb(&data->pile_a, &data->pile_b, 'd');
	else
		return (ft_freee(dataa, 0), free_data(data),
			write(1, "KO\n", 3), exit(0), 1);
	return (0);
}

int	ft_freee(t_dataa *data, int fd)
{
	get_next_line(0, data, 1);
	if (fd >= 0)
		close(fd);
	if (data->res)
		free(data->res);
	if (data)
	{
		free(data);
		data = NULL;
	}
	return (0);
}

void	retrieve_arg(int fd, t_data *dataa)
{
	char		*str;
	t_dataa		*data;

	data = ft_calloc(1, sizeof(t_dataa));
	str = get_next_line(fd, data, 0);
	while (str != NULL)
	{
		mouvv(str, dataa, data);
		if (str)
			free(str);
		str = get_next_line(fd, data, 0);
	}
	if (data)
		free(data);
}
