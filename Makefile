# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 09:23:49 by ayael-ou          #+#    #+#              #
#    Updated: 2023/02/13 17:41:39 by ayael-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	mouv_pa_pb.c \
				mouv_ra_rb_rr.c \
				mouv_rra_rrb_rrr.c \
				mouv_sa_sb_ss.c \
				node.c \
				outils.c \
				push_swap.c \
				print.c \
				free.c \
				tri.c \
				median.c \
				find.c \
				calculator.c \
				outils2.c \
				check_struct.c\


OBJS		= 	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SWAP		=	push_swap

.c.o :
			$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@


$(SWAP):	${OBJS}
			make -C ./libft
			cp ./libft/libft.a .
			$(CC) $(CFLAGS) ${OBJS} -g3 -L . -lft -o $(SWAP)

all:		$(SWAP)

clean:
			rm -rf *.o

fclean:		clean
			rm -rf $(SWAP) *.a

re:			fclean all


.PHONY:		all clean fclean re bonus
