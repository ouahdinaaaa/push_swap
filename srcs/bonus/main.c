/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:33:29 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/18 20:31:12 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (argc < 2)
		return (free_data(data), ft_putstr("ERROR\n"), 1);
	create_pile(data, argc, argv);
	if (check_doublon(&data->pile_a) == 1)
		return (free_data(data), 1);
	retrieve_arg(0, data);
	check_pilea(data->pile_a, data->pile_b, data);
	return (0);
}
