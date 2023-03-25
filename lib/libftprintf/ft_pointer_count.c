/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:24:36 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:25:35 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer_count(unsigned long long n)
{
	int	count;

	count = 0;
	count += ft_putstr_count("0x");
	count += ft_putnbr_x_count(n);
	return (count);
}
