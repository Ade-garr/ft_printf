/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:45:42 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/31 13:14:27 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printconvsdroite(int width, int precision, char *s)
{
	int	i;
	int	ret;

	i = 0;
	if (precision < 0 || precision > (int)ft_strlen(s))
		precision = ft_strlen(s);
	if (width < precision)
		width = precision;
	ret = width;
	while (width - precision > 0)
	{
		write(1, " ", 1);
		width--;
	}
	while (s[i] != '\0' && width > 0 && precision > 0)
	{
		write(1, s + i, 1);
		i++;
		width--;
		precision--;
	}
	return (ret);
}

void	ft_convert_hex(unsigned long p, char *base)
{
	if (p >= 16)
		ft_convert_hex(p / 16, base);
	write(1, &base[p % 16], 1);
}

int		ft_conversion_p(va_list ap, const char *format, int i)
{
	unsigned long	p;
	int				width;
	int				ret;
	int				indicateur;
	int				long_p;

	width = ft_findwidth(ap, format, i);
	p = va_arg(ap, unsigned long);
	long_p = (ft_findprecision(ap, format, i) == 0 && p == 0) ? 0 :
	ft_findlong_xj(p);
	indicateur = (width < 0) ? 1 : 0;
	width = (width < 0) ? -width : width;
	width = (width < long_p + 2) ? long_p + 2 : width;
	ret = width;
	while (width - (long_p + 2) > 0 && indicateur == 0)
		width = width - write(1, " ", 1);
	write(1, "0x", 2);
	if (ft_findprecision(ap, format, i) != 0 || p != 0)
		ft_convert_hex(p, "0123456789abcdef");
	width = width - (long_p + 2);
	while (width-- > 0)
		write(1, " ", 1);
	return (ret);
}

int		ft_findlong_j(int j)
{
	int				ret;
	unsigned int	i;

	ret = 1;
	i = (j < 0) ? -j : j;
	while (i >= 10)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

int		ft_conversion_di(va_list ap, const char *format, int i)
{
	int	width;
	int	precision;
	int ret;
	int	j;
	int	flag_0;

	flag_0 = (ft_checkflag_0(format, i) == 1) ? 1 : 0;
	width = ft_findwidth(ap, format, i);
	precision = ft_findprecision(ap, format, i);
	j = va_arg(ap, int);
	if (precision == 0 && j == 0)
	{
		width = (width < 0) ? -width : width;
		ret = width;
		while (width-- > 0)
			write(1, " ", 1);
		return (ret);
	}
	flag_0 = (precision >= 0) ? 0 : flag_0;
	ret = (width < 0) ? ft_printconvdileft(width, precision, j) :
	ft_printconvdiright(width, precision, j, flag_0);
	return (ret);
}
