#include "../ft_printf.h"

static void	negative(t_printf *t_fl, int *result)
{
	if (t_fl->status != -1)
		return ;
	*result += ft_putchar('-');
	t_fl->status = 0;
}

static void	print_num(t_printf *t_fl, unsigned long *num, int *result)
{
	if (t_fl->status == 1 || (t_fl->precision == 0 && *num == 0 \
			&& t_fl->type != 'p'))
		return ;
	negative(t_fl, result);
	*result += print_num_base(t_fl, *num);
	t_fl->status = 1;
}

static void	printwidth(t_printf *t_fl, int *result)
{
	char	flag;

	if (t_fl->width <= 0)
		return ;
	if (t_fl->flags == '0')
		flag = '0';
	else
		flag = ' ';
	if (flag == '0')
		negative(t_fl, result);
	while (t_fl->width-- > 0)
		*result += ft_putchar(flag);
}

static void	print_precision(t_printf *t_fl, int *result)
{
	if (t_fl->precision <= 0)
		return ;
	negative(t_fl, result);
	while (t_fl->precision-- > 0)
		*result += ft_putchar('0');
}

void	start_print_xxpdui(t_printf *t_fl, unsigned long *num, int *resultult)
{
	if (t_fl->flags == '-')
	{
		print_precision(t_fl, resultult);
		print_num(t_fl, num, resultult);
		printwidth(t_fl, resultult);
	}
	else
	{
		printwidth(t_fl, resultult);
		print_precision(t_fl, resultult);
		print_num(t_fl, num, resultult);
	}
}
