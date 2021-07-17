#include "../ft_printf.h"

static int	type(char c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i') \
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

static int	find_flags(char str)
{
	if (!(type(str)) && (str == '-' || str == '0'))
		return (1);
	return (0);
}

void	parse_flags(char **str, t_printf *t_fl)
{
	while (find_flags(**str))
	{
		if (**str == '0' && t_fl->flags != '-')
			t_fl->flags = '0';
		else
			t_fl->flags = '-';
		(*str)++;
	}
}
