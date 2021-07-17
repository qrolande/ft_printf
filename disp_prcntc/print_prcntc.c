#include "../ft_printf.h"

void	print_prcntc(va_list va_list, t_printf *t_fl, int *res)
{
	char	c;

	if (t_fl->type == 'c')
		c = (char)va_arg(va_list, int);
	else
		c = '%';
	correct_prcntc(t_fl, 1);
	start_print_prcntc(t_fl, c, res);
}
