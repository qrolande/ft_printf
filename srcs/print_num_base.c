#include "../ft_printf.h"

static int	ft_putnbr_base(unsigned long num, unsigned long base, char c)
{
	int	res;

	res = 0;
	if (num > (base - 1))
	{
		res += ft_putnbr_base(num / base, base, c);
		res += ft_putnbr_base(num % base, base, c);
	}
	else if (num < 10)
		res += ft_putchar(num + '0');
	else if (c == 'x')
		res += ft_putchar((num % 10) + 97);
	else if (c == 'X')
		res += ft_putchar((num % 10) + 65);
	return (res);
}

int	print_num_base(t_printf *t_fl, unsigned long num)
{
	int	res;

	res = 0;
	if (t_fl->type == 'X')
		res += ft_putnbr_base(num, 16, 'X');
	else if (t_fl->type == 'x')
		res += ft_putnbr_base(num, 16, 'x');
	else if (t_fl->type == 'p')
	{
		res += ft_putchar('0');
		res += ft_putchar('x');
		if (num == 0 && t_fl->precision >= 0)
			res += 0;
		else
			res += ft_putnbr_base(num, 16, 'x');
	}
	else
		res += ft_putnbr_base(num, 10, 'd');
	return (res);
}
