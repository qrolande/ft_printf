NAME 		=	libftprintf.a

SRCS  		= 	begin/ft_printf.c \
				begin/read_str.c \
				begin/str_move.c \
				begin/write_param.c \
				begin/write_sym.c \
				begin/write_type_select.c \
				srcs/ft_modif_atoi.c \
				srcs/ft_isdigit.c \
				srcs/ft_modif_strlen.c \
				srcs/ft_putchar.c \
				srcs/print_num_base.c \
				parser/parse_flags.c \
				parser/parse_precision.c \
				parser/parse_type.c \
				parser/parse_width.c \
				parser/parser_start.c \
				parser/struct_init.c \
				disp_prcntc/correct_prcntc.c \
				disp_prcntc/print_prcntc.c \
				disp_prcntc/start_print_prcntc.c \
				disp_str/correct_str.c \
				disp_str/print_str.c \
				disp_str/start_print_str.c \
				disp_xxpdui/correct_xxpdui.c \
				disp_xxpdui/num_set.c \
				disp_xxpdui/print_xxpdui.c \
				disp_xxpdui/set_num_len.c \
				disp_xxpdui/start_print_xxpdui.c

OBJS		=	${SRCS:.c=.o}

CC			= 	gcc

RM			= 	rm -f

CFLAGS		= 	-Wall -Wextra -Werror

INCLUDES	= 	ft_printf.h

%.o : %.c		$(INCLUDES)
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

bonus:			${OBJS}
				ar rcs ${NAME} ${OBJS}

all:			${NAME}

clean:		
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re 
