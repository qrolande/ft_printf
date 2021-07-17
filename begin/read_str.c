#include "../ft_printf.h"

int	read_str(char **str, va_list v_list)
{
	int	result;

	result = 0;
	while (**str != '\0')
	{
		if (**str != '%')
			result += write_sym(str);
		else
			write_param(v_list, &result, str);
		if (result == -1)
			return (result);
	}
	return (result);
}
