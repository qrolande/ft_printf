#include "../ft_printf.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int	ft_modif_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;

	sign = 1;
	res = 0;
	while (ft_is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
	{
		res = (res * 10) + (*str - '0');
		if (res >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (res > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(res * sign));
}
