/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:23:35 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/16 12:21:53 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"
# define BUFFER_SIZE 1

typedef struct s_data
{
	int		ret;
	char	*res;
}				t_dataa;

char	*ft_gnl_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd, t_dataa *data, int boolean);
int		mouvv(const char *str, t_pile **pile_a, t_pile **pile_b, t_data *data);
void	retrieve_arg(int fd, t_pile **a, t_pile **b, t_data *dataa);
void	check_pilea(t_pile *pile, t_data *data);

#endif
