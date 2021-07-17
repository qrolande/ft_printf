#include "../ft_printf.h"

int	write_sym(char **str)
{
	ft_putchar(**str);
	(*str)++;
	return (1);
}
