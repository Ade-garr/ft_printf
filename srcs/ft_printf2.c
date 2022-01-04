/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:16:59 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/27 20:00:39 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkconv(char c)
{
	int	ret;

	ret = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		ret = 1;
	return (ret);
}

int	ft_findprecision(va_list ap, const char *format, int i)
{
	int	precision;

	while (ft_checkconv(format[i]) == 0)
	{
		if (format[i] == '.')
		{
			i++;
			if (format[i] == '*')
			{
				precision = va_arg(ap, int);
				return (precision);
			}
			else
			{
				precision = ft_atoi(format + i);
				return (precision);
			}
		}
		i++;
	}
	return (-1);
}

int	ft_printconvsgauche(int width, int precision, char *s)
{
	int	i;
	int ret;

	i = 0;
	width = -width;
	if (precision < 0 || precision > (int)ft_strlen(s))
		precision = ft_strlen(s);
	if (width < precision)
		width = precision;
	ret = width;
	while (s[i] != '\0' && width > 0 && precision > 0)
	{
		write(1, &s[i], 1);
		i++;
		width--;
		precision--;
	}
	while (width > 0)
	{
		write(1, " ", 1);
		width--;
	}
	return (ret);
}

int	ft_conversion_s(va_list ap, const char *format, int i)
{
	char	*s;
	int		width;
	int		precision;
	int		ret;

	ret = 0;
	width = ft_findwidth(ap, format, i);
	precision = ft_findprecision(ap, format, i);
	s = va_arg(ap, char *);
	if (width < 0)
		ret = (s == NULL) ? ft_printconvsgauche(width, precision, "(null)") :
		ft_printconvsgauche(width, precision, s);
	else
		ret = (s == NULL) ? ft_printconvsdroite(width, precision, "(null)") :
		ft_printconvsdroite(width, precision, s);
	return (ret);
}
