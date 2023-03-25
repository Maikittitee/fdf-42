/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:39:29 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:36:03 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_percent(char s, va_list *args)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar_count(va_arg(*args, int));
	if (s == 's')
		count += ft_putstr_count(va_arg(*args, char *));
	if (s == 'p')
		count += ft_pointer_count(va_arg(*args, unsigned long long));
	if (s == 'd' || s == 'i')
		count += ft_putnbr_d_count(va_arg(*args, int));
	if (s == 'x')
		count += ft_putnbr_x_count(va_arg(*args, unsigned int));
	if (s == 'X')
		count += ft_putnbr_ux_count(va_arg(*args, unsigned int));
	if (s == 'u')
		count += ft_putnbr_u_count(va_arg(*args, unsigned int));
	if (s == '%')
		count += ft_putchar_count('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_percent(str[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_count(str[i]);
				count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*
int main()
{
    ft_printf("My name is %s, %d \n","Mai",18);
    return (0);
	
} */
