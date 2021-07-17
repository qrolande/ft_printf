#include "../ft_printf.h"

static int	type(char c)
{
	if ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i') \
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

void	parse_type(char **str, t_printf *t_fl)
{
	t_fl->type = **str;
	if (type(t_fl->type))
		(*str)++;
}
