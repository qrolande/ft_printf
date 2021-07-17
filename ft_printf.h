#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_printf
{
	int		status;
	char	type;
	int		precision;
	int		width;
	char	flags;
}			t_printf;

t_printf	struct_init(void);
int			ft_printf(const char *str, ...);
int			read_str(char **str, va_list v_list);
int			write_sym(char **str);
int			write_param(va_list v_list, int *result, char **str);
void		write_type_select(va_list va_list, t_printf *t_fl, int *result);
void		str_move(char **str);

void		print_str(va_list va_list, t_printf *t_fl, int *result);
void		correct_str(char *s, t_printf *t_fl, int len);
void		start_print_str(char *s, t_printf *t_fl, int *result);

void		print_prcntc(va_list va_list, t_printf *t_fl, int *res);
void		correct_prcntc(t_printf *t_fl, int len);
void		start_print_prcntc(t_printf *t_fl, char c, int *res);

void		print_xxpdui(va_list v_list, t_printf *t_fl, int *result);
void		num_set(t_printf *t_fl, va_list va_list, unsigned long *num);
void		set_num_len(t_printf *t_fl, unsigned long num, int *len);
void		correct_xxpdui(t_printf *t_fl, unsigned long *num, int len);
void		start_print_xxpdui(t_printf *t_fl, unsigned long *num, int *result);

int			ft_putchar(char c);
int			ft_isdigit(int c);
int			ft_modif_atoi(const char *str);
int			ft_modif_strlen(char *s);
int			print_num_base(t_printf *t_flags, unsigned long num);

void		parser_start(va_list v_list, t_printf *t_fl, char **str);
void		parse_flags(char **str, t_printf *t_fl);
void		parse_width(char **str, t_printf *t_fl, va_list v_list);
void		parse_precision(char **str, t_printf *t_fl, va_list v_list);
void		parse_type(char **str, t_printf *t_fl);

#endif