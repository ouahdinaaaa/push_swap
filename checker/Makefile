SRCS		=	../mouv_pa_pb.c \
				../mouv_ra_rb_rr.c \
				../mouv_rra_rrb_rrr.c \
				../mouv_sa_sb_ss.c \
				../node.c \
				../outils.c \
				../print.c \
				../free.c \
				../tri.c \
				../median.c \
				../find.c \
				../calculator.c \
				../outils2.c \
				../check_struct.c\
				./checker.c\
				./get_next_line.c\
				./get_next_line_utils.c\
				./main.c\



OBJS		= 	$(SRCS:.c=.o)

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SWAP		=	checker

.c.o :
			$(CC) -g3 $(CFLAGS) $(INCLUDES) -c $< -o $@


$(SWAP):	${OBJS}
			make -C../libft
			cp ../libft/libft.a .
			$(CC) $(CFLAGS) ${OBJS} -g3 -L . -lft -o $(SWAP)

all:		$(SWAP)

clean:
			rm -rf *.o

fclean:		clean
			rm -rf $(SWAP) *.a

re:			fclean all


.PHONY:		all clean fclean re bonus
