#include "../ft_printf.h"

void	write_type_select(va_list v_list, t_printf *t_fl, int *result)
{
	if (t_fl->type == 's')
		print_str(v_list, t_fl, result);
	if (t_fl->type == '%' || t_fl->type == 'c')
		print_prcntc(v_list, t_fl, result);
	if (t_fl->type == 'X' || t_fl->type == 'x' || t_fl->type == 'p' || \
			t_fl->type == 'd' || t_fl->type == 'u' || t_fl->type == 'i')
		print_xxpdui(v_list, t_fl, result);
}
