#include "../ft_printf.h"

int	write_param(va_list v_list, int *result, char **str)
{
	t_printf	t_fl;

	(*str)++;
	t_fl = struct_init();
	parser_start(v_list, &t_fl, str);
	write_type_select(v_list, &t_fl, result);
	return (*result);
}
