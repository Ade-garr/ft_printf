/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-garr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:02:48 by ade-garr          #+#    #+#             */
/*   Updated: 2020/01/27 18:23:51 by ade-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conversion_percent(va_list ap, const char *format, int i)
{
	int indicateur;
	int	ret;
	int	width;
	int	flag_0;

	flag_0 = (ft_checkflag_0(format, i) == 1) ? 1 : 0;
	width = ft_findwidth(ap, format, i);
	flag_0 = (width < 0) ? 0 : flag_0;
	indicateur = (width < 0) ? 1 : 0;
	width = (width < 0) ? -width : width;
	width = (width < 1) ? 1 : width;
	ret = width;
	if (indicateur == 0)
	{
		while (width - 1 > 0)
			width = (flag_0 == 1) ? width - write(1, "0", 1) :
			width - write(1, " ", 1);
	}
	width = width - write(1, "%", 1);
	while (width > 0)
		width = width - write(1, " ", 1);
	return (ret);
}
