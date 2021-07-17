#include "../ft_printf.h"

void	parser_start(va_list v_list, t_printf *t_fl, char **str)
{
	parse_flags(str, t_fl);
	parse_width(str, t_fl, v_list);
	parse_precision(str, t_fl, v_list);
	parse_type(str, t_fl);
}
