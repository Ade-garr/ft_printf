/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:06:31 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/27 19:10:19 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_findlong_uj(unsigned int j)
{
	int	ret;

	ret = 1;
	while (j >= 10)
	{
		j = j / 10;
		ret++;
	}
	return (ret);
}

void	ft_putunbr(unsigned int j)
{
	if (j >= 10)
		ft_putnbr(j / 10);
	j = j % 10;
	j = j + 48;
	write(1, &j, 1);
}

int		ft_printconvuleft(int width, int precision, unsigned int j)
{
	int	longueur_j;
	int	ret;

	width = -width;
	longueur_j = ft_findlong_uj(j);
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
	ft_putunbr(j);
	width = width - longueur_j;
	while (width-- > 0)
		write(1, " ", 1);
	return (ret);
}

int		ft_printconvuright(int width, int precision, unsigned int j, int flag_0)
{
	int	longueur_j;
	int ret;

	longueur_j = ft_findlong_uj(j);
	if (flag_0 == 1)
	{
		width = (width < longueur_j) ? longueur_j : width;
		ret = width;
		while (width - longueur_j > 0)
			width = width - write(1, "0", 1);
		ft_putunbr(j);
	}
	else
	{
		width = (width < longueur_j) ? longueur_j : width;
		precision = (precision < longueur_j) ? longueur_j : precision;
		width = (width < precision) ? precision : width;
		ret = width;
		while (width - precision > 0)
			width = width - write(1, " ", 1);
		while (precision - longueur_j > 0)
			precision = precision - write(1, "0", 1);
		ft_putunbr(j);
	}
	return (ret);
}

int		ft_conversion_x(va_list ap, const char *format, int i, int k)
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
	if (width < 0)
		ret = ft_printconvxleft(width, precision, j, k);
	flag_0 = (precision >= 0) ? 0 : flag_0;
	if (width >= 0)
		ret = (flag_0 == 1) ? ft_printconvxright1(width, j, k) :
		ft_printconvxright2(width, precision, j, k);
	return (ret);
}
