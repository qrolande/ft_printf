#include "../ft_printf.h"

void	parse_precision(char **str, t_printf *t_fl, va_list v_list)
{
	if (t_fl->precision != -1 || **str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		(*str)++;
		t_fl->precision = va_arg(v_list, int);
		if (t_fl->flags == '0' && t_fl->precision >= 0)
			t_fl->flags = '\0';
	}
	else
	{
		t_fl->precision = ft_modif_atoi(*str);
		if (t_fl->flags == '0')
			t_fl->flags = '\0';
		str_move(str);
	}
}
