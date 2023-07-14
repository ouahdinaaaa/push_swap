/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:16:25 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:54:43 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	create_pile(data, argc, argv);
	if (check_doublon(&data->pile_a) == 1 || check_node(data->pile_a) == 0)
		return (free_data(data), 1);
	if (argc == 3)
		return (mouv_sa_sb_ss(&data->pile_a, NULL, 'a'), free_data(data), 0);
	if (argc == 6 || argc == 4)
	{
		if (argc == 6)
			tri_5(&data->pile_a, &data->pile_b);
		tri_3(&data->pile_a);
		return (free_data(data), 0);
	}
	do_median(&data->pile_a, data);
	counter_calc(data->pile_a, data->pile_b);
	while (ft_listsize(data->pile_b) > 0)
		algo(&data->pile_a, &data->pile_b);
	return (mouv_arrange(&data->pile_a), free_data(data), 1);
}
