/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_d_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:05 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:46:07 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_d_count(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putnbr_d_count(-1 * 214748364);
		count += ft_putchar_count('8');
		return (11);
	}	
	if (n < 0)
	{
		count += ft_putchar_count('-');
		count += ft_putnbr_d_count(-1 * n);
	}
	else if (n <= 9)
	{
		count += ft_putchar_count(n + '0');
	}
	else
	{
		count += ft_putnbr_d_count(n / 10);
		count += ft_putnbr_d_count(n % 10);
	}
	return (count);
}
