#include "../ft_printf.h"

static long	negativ(long num, t_printf *t_fl)
{
	if (num >= 0)
		return (num);
	t_fl->status = -1;
	return (num * -1);
}

void	num_set(t_printf *t_fl, va_list v_list, unsigned long *num)
{
	if (t_fl->type == 'i' || t_fl->type == 'd')
		*num = (unsigned long)negativ(va_arg(v_list, int), t_fl);
	else if (t_fl->type == 'p')
		*num = va_arg(v_list, unsigned long);
	else
		*num = (unsigned long)va_arg(v_list, unsigned int);
}
