/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:30 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/27 16:52:53 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findlong_xj(unsigned long j)
{
	int	ret;

	ret = 1;
	while (j >= 16)
	{
		j = j / 16;
		ret++;
	}
	return (ret);
}

int	ft_checkflag_0(const char *format, int i)
{
	int	flag_0;

	flag_0 = 0;
	while (format[i] == '-')
		i++;
	if (format[i] == '0')
		flag_0 = 1;
	return (flag_0);
}

int	ft_printconvxleft(int width, int precision, unsigned int j, int k)
{
	int	longueur_j;
	int	ret;

	width = -width;
	longueur_j = ft_findlong_xj(j);
	width = (width < longueur_j) ? longueur_j : width;
	precision = (precision < longueur_j) ? longueur_j : precision;
	width = (width < precision) ? precision : width;
	ret = width;
	while (precision - longueur_j > 0)
	{
		write(1, "0", 1);
		width--;
		precision--;
	}
	(k == 1) ? ft_convert_hex(j, "0123456789abcdef") :
	ft_convert_hex(j, "0123456789ABCDEF");
	width = width - longueur_j;
	while (width-- > 0)
		write(1, " ", 1);
	return (ret);
}

int	ft_printconvxright1(int width, unsigned int j, int k)
{
	int	longueur_j;
	int ret;

	longueur_j = ft_findlong_xj(j);
	width = (width < longueur_j) ? longueur_j : width;
	ret = width;
	while (width - longueur_j > 0)
		width = width - write(1, "0", 1);
	(k == 1) ? ft_convert_hex(j, "0123456789abcdef") :
	ft_convert_hex(j, "0123456789ABCDEF");
	return (ret);
}

int	ft_printconvxright2(int width, int precision, unsigned int j, int k)
{
	int	longueur_j;
	int	ret;

	longueur_j = ft_findlong_xj(j);
	width = (width < longueur_j) ? longueur_j : width;
	precision = (precision < longueur_j) ? longueur_j : precision;
	width = (width < precision) ? precision : width;
	ret = width;
	while (width - precision > 0)
		width = width - write(1, " ", 1);
	while (precision - longueur_j > 0)
		precision = precision - write(1, "0", 1);
	(k == 1) ? ft_convert_hex(j, "0123456789abcdef") :
	ft_convert_hex(j, "0123456789ABCDEF");
	return (ret);
}
