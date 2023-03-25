/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:47:02 by ktunchar          #+#    #+#             */
/*   Updated: 2022/10/27 18:49:52 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_count(const char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr_count("(null)");
		return (count);
	}
	while (*str)
	{
		count += ft_putchar_count(*str);
		str++;
	}
	return (count);
}
