#include "../ft_printf.h"

static int	type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' \
			|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void 	str_move(char **str)
{
	while (ft_isdigit(**str) && !type(**str))
		(*str)++;
}
