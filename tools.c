/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauljull <pauljull@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:19:36 by pauljull          #+#    #+#             */
/*   Updated: 2019/04/03 22:39:46 by pauljull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int len;

	len = 0;
	while (s[len])
		len += 1;
	return (len);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 0)
	{
		ft_putchar('-');
		if (n > -10)
			ft_putnbr(-n);
		else
		{
			ft_putnbr(-(n / 10));
			ft_putchar(-(n % 10) + '0');
		}
	}
}

void	print_flag_c(int option)
{
	if (option == 1)
		ft_putstr("c ");
	if (option == (1 << 1))
		ft_putstr("s ");
	if (option == (1 << 2))
		ft_putstr("p ");
	if (option == (1 << 3))
		ft_putstr("d ");
	if (option == (1 << 4))
		ft_putstr("i ");
	if (option == (1 << 5))
		ft_putstr("o ");
	if (option == (1 << 6))
		ft_putstr("u ");
	if (option == (1 << 7))
		ft_putstr("x ");
	if (option == (1 << 8))
		ft_putstr("X ");
	if (option == (1 << 9))
		ft_putstr("f ");
	if (option == (1 << 10))
		ft_putstr("l ");
	if (option == (1 << 11))
		ft_putstr("ll ");
	if (option == (1 << 12))
		ft_putstr("L ");
	if (option == (1 << 13))
		ft_putstr("h ");
	if (option == (1 << 14))
		ft_putstr("hh ");
	if (option == (1 << 15))
		ft_putstr("# ");
	if (option == (1 << 16))
		ft_putstr("0 ");
	if (option == (1 << 17))
		ft_putstr("+ ");
	if (option == (1 << 18))
		ft_putstr("- ");
	if (option == (1 << 19))
		ft_putstr("ESP ");
}

void	print_flag(int flag)
{
	unsigned int mask;

	mask = 1 << 31;
	while (mask)
	{
		if (mask & flag)
			print_flag_c(mask & flag);
		mask >>= 1;
	}
	ft_putstr("\n\n");
}

void	print_list(t_list *list)
{
	int args;

	args = 1;
	while (list)
	{
		printf("ARGUMENT No %d\n\n", args++);
		printf("LMC : %d\n", list->width);
		printf("precision : %d\n", list->precision);
		printf("binary flag : %d\n\n", list->flag);
		print_flag(list->flag);
		list = list->next;
	}
}
