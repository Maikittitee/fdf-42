/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:48:28 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:48:30 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x_count(unsigned long long n)
{
	int	count;

	count = 0;
	if (n < 16)
		count += ft_putchar_count("0123456789abcdef"[n]);
	else
	{
		count += ft_putnbr_x_count(n / 16);
		count += ft_putnbr_x_count(n % 16);
	}
	return (count);
}
