# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayael-ou <ayael-ou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 09:23:49 by ayael-ou          #+#    #+#              #
#    Updated: 2023/02/19 19:04:31 by ayael-ou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

LIBFT			=	libft.a

DIR_SRCS		=	srcs/mandatory

DIR_BONUS		=	srcs/bonus

DIR_OBJS		=	objs

SRCS_NAMES_B	=	checker.c \
					get_next_line.c \
					get_next_line_utils.c \
					main.c \
					mouv_ra_rb_rr.c \
					mouv_rra_rrb_rrr.c \
					mouv_sa_sb_ss.c \
					node.c \
					outils.c \
					print.c \
					free.c \
					find.c \
					tri.c \
					outils2.c \
					mouv_pa_pb.c \

SRCS_NAMES		=	mouv_pa_pb.c \
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

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

OBJS_NAMES_B	=	${SRCS_NAMES_B:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))

SRCS_B			=	$(addprefix $(DIR_BONUS)/,$(SRCS_NAMES_B))

OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

HEAD			=	-Iincludes/ -Ilibft/includes

CC				=	cc

CFLAGS			=	-g3 -Wall -Werror -Wextra

MAKEFLAGS		=	--no-print-directory


all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS) ${LIBFT} -o $(NAME)
	@echo "\033[34;5mpushswap\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)


$(NAME_BONUS): $(SRCS_B)
	make -C libft
	mv libft/libft.a .
	$(CC) $(CFLAGS) $(SRCS_B) ${HEAD} ${LIBFT} -o $(NAME_BONUS)
	@echo "\033[31;5mpushswap BONUS\033[0m"

bonus: $(NAME_BONUS)

clean:
	make clean -C libft
	rm -rf ${DIR_OBJS}
	rm -rf ${OBJS}

fclean:	clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}
	rm -rf ${NAME_BONUS}

re:	fclean all

stop:
	rm ${NAME}


.PHONY:		all clean fclean re bonus
