#include "../ft_printf.h"

void	parse_width(char **str, t_printf *t_fl, va_list v_list)
{
	if (t_fl->width != 0)
		return ;
	if (**str == '*')
	{
		(*str)++;
		t_fl->width = va_arg(v_list, int);
		if (t_fl->width < 0)
		{
			t_fl->flags = '-';
			t_fl->width *= -1;
		}
	}
	else
	{
		t_fl->width = ft_modif_atoi(*str);
		str_move(str);
	}
}
