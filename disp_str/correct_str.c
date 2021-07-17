#include "../ft_printf.h"

void	correct_str(char *s, t_printf *t_fl, int len)
{
	if (s == NULL)
		len = 6;
	if (t_fl->precision < 0 || t_fl->precision > len)
		t_fl->precision = len;
	if (t_fl->precision < len)
	{
		if (t_fl->precision < t_fl->width)
			t_fl->width = t_fl->width - t_fl->precision;
		else
			t_fl->width = 0;
	}
	else
	{
		if (t_fl->width > len)
			t_fl->width = t_fl->width - len;
		else
			t_fl->width = 0;
	}
}
