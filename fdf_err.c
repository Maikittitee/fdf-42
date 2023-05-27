/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_err.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:47:00 by ktunchar          #+#    #+#             */
/*   Updated: 2023/05/28 04:26:48 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_all_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int	is_hex(char *str)
{
	int	i;

	i = 0;
	ft_str_tolower(str);
	if (str[i] == '0')
		i++;
	if (str[i] == 'x')
		i++;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '\n')
			return (0);
		if (!ft_isdigit(str[i]) && (str[i] > 'f' || str[i] < 'a') \
			&& str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	is_format_error(char **value)
{
	if (value)
	{
		if (value[0] && !is_all_digit(value[0]))
		{
			dprintf(1,"%s not digit", value[0]);
			ft_double_free(value);
			exit(1);
		}
		if (value[1] && !is_hex(value[1]))
		{	
			dprintf(1,"not hex");
			ft_double_free(value);
			exit(1);
		}
	}
	else
		exit(1);
}

void	check_arg(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (ft_strnstr(filename, ".fdf", len) == NULL)
	{
		ft_putendl_fd("only .fdf file", 1);
		exit(1);
	}
	if (filename[len - 1] != 'f' || filename[len - 2] != 'd' || \
		filename[len - 3] != 'f' || filename[len - 4] != '.')
	{	
		ft_putendl_fd("only .fdf file", 1);
		exit(1);
	}
}
