#include "../ft_printf.h"

static int	putstring(int len, char *s)
{
	int	res;

	res = 0;
	while (len && *s)
	{
		res += ft_putchar(*s);
		s++;
		len--;
	}
	return (res);
}

static int	printwidth(t_printf *t_fl, int *result)
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
	return (1);
}

static int	printstring(char *s, t_printf *t_fl, int *result)
{
	if (s == NULL)
		*result += putstring(t_fl->precision, "(null)");
	else
		*result += putstring(t_fl->precision, s);
	return (0);
}

void	start_print_str(char *s, t_printf *t_fl, int *result)
{
	if (t_fl->flags == '-')
	{
		printstring(s, t_fl, result);
		printwidth(t_fl, result);
	}
	else
	{
		printwidth(t_fl, result);
		printstring(s, t_fl, result);
	}
}
