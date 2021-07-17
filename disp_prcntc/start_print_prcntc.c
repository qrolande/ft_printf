#include "../ft_printf.h"

static void	printwidth(t_printf *t_fl, int *result)
{
	char	flag;

	if (t_fl->flags == '0')
		flag = '0';
	else
		flag = ' ';
	while (t_fl->width > 0)
	{
		*result += ft_putchar(flag);
		t_fl->width--;
	}
}

void	start_print_prcntc(t_printf *t_fl, char c, int *result)
{
	if (t_fl->flags == '-')
	{
		*result += ft_putchar(c);
		printwidth(t_fl, result);
	}
	else
	{
		printwidth(t_fl, result);
		*result += ft_putchar(c);
	}
}
