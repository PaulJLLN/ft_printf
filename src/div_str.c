#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"

int		is_number(char *str)
{
	while (*str)
	{
		if (*str > '0' && *str <= '9')
			return (1);
		str += 1;
	}
	return (0);
}

char	*div_str(char *mantissa, __uint128_t div)
{
	char	*result;
	__uint128_t		tmp;

	int i;

	i = 0;
	tmp = 0;
	result = NULL;
	tmp = *mantissa - '0';
	result = ft_strjoinf(result, ft_itoa(tmp / div), 1);
	tmp = tmp % div;
	if (*(mantissa + 1) == '.')
	{
		mantissa += 1;
		result = ft_strjoinf(result, ".", 1);
	}
	mantissa += 1;
	tmp = tmp * 10 + *mantissa - '0';
	while ((tmp || (!tmp && is_number(mantissa))))
	{
		result = ft_strjoinf(result, ft_itoa(tmp / div), 1);
		tmp = tmp % div;
		mantissa += 1;
		tmp = tmp * 10 + *mantissa - '0';
	}
	zero_filling(result + ft_strlen(result), 10000 - ft_strlen(result));
	return (result);
}