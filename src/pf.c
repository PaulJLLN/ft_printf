/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:30:36 by pauljull          #+#    #+#             */
/*   Updated: 2019/04/17 10:30:36 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

unsigned long   print_final(t_plist *list, const char *restrict format)
{
	unsigned long count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
		{
//			ft_putstr(list->tab);
			printf("%s", list->tab);
			while (*format != 'c' && *format != 's' && *format != 'p' && *format != 'd' && *format != 'i' && *format != 'o' && *format != 'u' && *format != 'x' && *format != 'X' && *format != 'f')
				format += 1;
			format += 1;
			count += ft_strlen(list->tab);
			list = list->next;
		}
		else
		{
//			ft_putchar(*format);
			printf("%c", *format);
			count += 1;
			format += 1;
		}
	}
	return (count);
}
