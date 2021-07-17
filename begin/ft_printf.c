#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	v_list;

	if (!str)
		return (-1);
	result = 0;
	va_start(v_list, str);
	result = read_str((char **)&str, v_list);
	va_end(v_list);
	return (result);
}
