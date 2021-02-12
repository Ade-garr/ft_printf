/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:54:57 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/31 10:52:25 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int j)
{
	if (j >= 10 || j <= -10)
		ft_putnbr(j / 10);
	j = j % 10;
	if (j < 0)
		j = -j;
	j = j + 48;
	write(1, &j, 1);
}

int		ft_printconvdileft(int width, int precision, int j)
{
	int	longueur_j;
	int	ret;

	width = -width;
	longueur_j = ft_findlong_j(j);
	width = (width < longueur_j) ? longueur_j : width;
	precision = (precision < longueur_j) ? longueur_j : precision;
	width = (width < precision) ? precision : width;
	width = (j < 0 && width == precision) ? width + 1 : width;
	ret = width;
	if (j < 0)
		width = width - write(1, "-", 1);
	while (precision - longueur_j > 0)
	{
		write(1, "0", 1);
		width--;
		precision--;
	}
	ft_putnbr(j);
	width = width - longueur_j;
	while (width-- > 0)
		write(1, " ", 1);
	return (ret);
}

int		ft_printconvdiright2(int width, int precision, int j)
{
	int longueur_j;
	int	ret;

	longueur_j = ft_findlong_j(j);
	width = (width < longueur_j) ? longueur_j : width;
	precision = (precision < longueur_j) ? longueur_j : precision;
	width = (width < precision) ? precision : width;
	width = (j < 0 && width == precision) ? width + 1 : width;
	ret = width;
	while (width - 1 - precision > 0)
		width = width - write(1, " ", 1);
	if (width - precision > 0)
		width = (j < 0) ? width - write(1, "-", 1) : width - write(1, " ", 1);
	while (precision - longueur_j > 0)
		precision = precision - write(1, "0", 1);
	ft_putnbr(j);
	return (ret);
}

int		ft_printconvdiright(int width, int precision, int j, int flag_0)
{
	int	longueur_j;
	int ret;

	if (flag_0 == 1)
	{
		longueur_j = ft_findlong_j(j);
		width = (width < longueur_j) ? longueur_j : width;
		width = (j < 0 && width == longueur_j) ? width + 1 : width;
		ret = width;
		width = (j < 0) ? width - write(1, "-", 1) : width;
		while (width - longueur_j > 0)
			width = width - write(1, "0", 1);
		ft_putnbr(j);
	}
	else
		ret = ft_printconvdiright2(width, precision, j);
	return (ret);
}

int		ft_conversion_u(va_list ap, const char *format, int i)
{
	int				width;
	int				precision;
	int				ret;
	unsigned int	j;
	int				flag_0;

	flag_0 = (ft_checkflag_0(format, i) == 1) ? 1 : 0;
	width = ft_findwidth(ap, format, i);
	precision = ft_findprecision(ap, format, i);
	j = va_arg(ap, unsigned int);
	if (precision == 0 && j == 0)
	{
		width = (width < 0) ? -width : width;
		ret = width;
		while (width-- > 0)
			write(1, " ", 1);
		return (ret);
	}
	flag_0 = (precision >= 0) ? 0 : flag_0;
	ret = (width < 0) ? ft_printconvuleft(width, precision, j) :
	ft_printconvuright(width, precision, j, flag_0);
	return (ret);
}
