/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:27:48 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/31 13:14:09 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findwidth(va_list ap, const char *format, int i)
{
	int	width;
	int	flag_minus;

	flag_minus = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			flag_minus = 1;
		i++;
	}
	if (format[i] == '*')
	{
		width = va_arg(ap, int);
		if (flag_minus == 1 && width >= 0)
			width = -width;
		return (width);
	}
	else
	{
		width = ft_atoi(format + i);
		width = (flag_minus == 1) ? -width : width;
		return (width);
	}
}

int	ft_printconvc(va_list ap, int width)
{
	int	ret;
	int c;

	ret = 0;
	if (width >= 0)
	{
		while (--width > 0)
		{
			write(1, " ", 1);
			ret++;
		}
		c = va_arg(ap, int);
		write(1, &c, 1);
	}
	else
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		while (++width < 0)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_conversion_c(va_list ap, const char *format, int i)
{
	int	c;
	int	width;
	int	ret;

	ret = 0;
	if (format[i] == 'c' || (format[i] == '-' && format[i + 1] == 'c'))
	{
		c = va_arg(ap, int);
		return (write(1, &c, 1));
	}
	else
	{
		width = ft_findwidth(ap, format, i);
		ret = ft_printconvc(ap, width);
	}
	return (ret + 1);
}

int	ft_conversion(va_list ap, const char *format, int i)
{
	int	j;

	j = i;
	while (format[j] == '-' || format[j] == '.' || format[j] == '*' ||
		(format[j] >= 48 && format[j] <= 57))
		j++;
	if (format[j] == 'c')
		return (ft_conversion_c(ap, format, i));
	if (format[j] == 's')
		return (ft_conversion_s(ap, format, i));
	if (format[j] == 'p')
		return (ft_conversion_p(ap, format, i));
	if (format[j] == 'd' || format[j] == 'i')
		return (ft_conversion_di(ap, format, i));
	if (format[j] == 'u')
		return (ft_conversion_u(ap, format, i));
	if (format[j] == 'x')
		return (ft_conversion_x(ap, format, i, 1));
	if (format[j] == 'X')
		return (ft_conversion_x(ap, format, i, 2));
	if (format[j] == '%')
		return (ft_conversion_percent(ap, format, i));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	int		retdef;

	i = -1;
	retdef = 0;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			if ((ret = ft_conversion(ap, format, ++i)) == -1)
				return (-1);
			retdef = retdef + ret;
			while (ft_checkconv(format[i]) == 0)
				i++;
		}
		else
			retdef = retdef + write(1, &format[i], 1);
	}
	va_end(ap);
	return (retdef);
}
