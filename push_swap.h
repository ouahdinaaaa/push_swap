/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:56:38 by ayael-ou          #+#    #+#             */
/*   Updated: 2023/02/15 11:54:22 by ayael-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_pile
{
	int				nb;
	int				index;
	struct s_pile	*next;
}					t_pile;

typedef struct s_bestmove
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}			t_bestmove;

typedef struct s_data_push
{
	t_pile		*pile_a;
	t_pile		*pile_b;
}				t_data;

int				ft_nb_atoi(const char *str);
int				check_doublon(t_pile **pile_a);
int				check_node(t_pile *pilea);

void			create_pile(t_data *data, int argc, char **argv);
int				*create_tab(t_pile **pile_a);

void			tri_tab(int *tab, int size);
void			tri_3(t_pile **pile);
void			tri_5(t_pile **pile_a, t_pile **pile_b);

int				ft_listsize(t_pile *pile);

void			free_data(t_data *data);
void			print_pile(t_pile *pile, char name);

int				find_padre(t_pile *pile, int nb);
int				find_max(t_pile *pile);
int				find_min(t_pile *pile);
int				find_index(t_pile *pile, int nb);
int				find_nb(t_pile *pile, int index);
t_bestmove		find_min_from_struct(t_bestmove *bestmove, int size);

int				counter_pile(t_pile *pile, int index);
t_bestmove		counter_calc(t_pile *ptr, t_pile *ptrb);
void			mouv_algo(t_pile **pile_a, t_pile **pile_b,
					t_bestmove bestmove);

void			do_median(t_pile **pile_a, t_data *data);
void			algo(t_pile **ptr, t_pile **ptrb);

void			mouv_sa_sb_ss(t_pile **a, t_pile **b, char pile);
void			mouv_ra_rb_rr(t_pile **a, t_pile **b, char pile);
void			mouv_rra_rrb_rrr(t_pile **a, t_pile **b, char pile);
void			mouv_pa_pb(t_pile **pile_a, t_pile **pile_b, char pile);
void			mouv_arrange(t_pile **pileA);

t_pile			*last(t_pile *pile);

#endif
