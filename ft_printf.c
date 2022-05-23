/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:17:11 by urycherd          #+#    #+#             */
/*   Updated: 2022/01/11 16:17:27 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arg(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_for_c(ap);
	else if (c == 's')
		len = ft_for_s(ap);
	else if (c == 'p')
		len = ft_for_p(ap);
	else if (c == 'd' || c == 'i')
		len = ft_for_d(ap);
	else if (c == 'u')
		len = ft_for_u(ap);
	else if (c == 'x')
		len = ft_for_hex(ap, c);
	else if (c == 'X')
		len = ft_for_hex(ap, c);
	else if (c == '%')
		len = ft_for_proc();
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	int		i;
	va_list	ap;

	va_start(ap, fmt);
	len = 0;
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[++i])
			len += ft_arg(ap, fmt[i]);
		else
			len += write(1, &fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
