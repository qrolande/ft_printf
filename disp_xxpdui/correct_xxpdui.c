#include "../ft_printf.h"

static int	null_precision(t_printf *t_fl, int *len, unsigned long *num)
{
	if (*num != 0 || t_fl->precision < 0)
		return (0);
	(*len)--;
	if (t_fl->type == 'p')
		t_fl->status = 0;
	else
		t_fl->status = 1;
	return (1);
}

static void	width_pres_correct(t_printf *t_fl)
{
	if (t_fl->precision >= t_fl->width)
		t_fl->width = 0;
	else if (t_fl->precision > 0)
		t_fl->width = t_fl->width - t_fl->precision;
}

static void	lencorrect(t_printf *t_fl, int len, unsigned long num)
{
	while (len-- > 0 && (t_fl->precision > 0 || t_fl->width > 0))
	{
		if (t_fl->precision > 0 && num != 0)
			t_fl->precision--;
		else if (t_fl->width > 0)
			t_fl->width--;
	}
}

static void	negative(t_printf *t_fl, int len)
{
	if (t_fl->status != -1 || t_fl->precision < len)
		return ;
	t_fl->width--;
	t_fl->precision++;
}

void	correct_xxpdui(t_printf *t_fl, unsigned long *num, int len)
{
	null_precision(t_fl, &len, num);
	width_pres_correct(t_fl);
	negative(t_fl, len);
	lencorrect(t_fl, len, *num);
}
