/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:49:20 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:49:22 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_count(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar_count(n + '0');
	else
	{
		count += ft_putnbr_u_count(n / 10);
		count += ft_putnbr_u_count(n % 10);
	}
	return (count);
}
