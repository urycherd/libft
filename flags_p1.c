/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_p1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:30:33 by urycherd          #+#    #+#             */
/*   Updated: 2022/01/09 20:40:11 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_for_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	ft_for_s(va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_for_p(va_list ap)
{
	unsigned long long	adress_dec;
	char				*adress;
	int					num;
	int					i;

	adress_dec = va_arg(ap, unsigned long long);
	adress = dec_to_hex_inv(adress_dec);
	if (adress == NULL)
		return (0);
	i = ft_strlen(adress) - 1;
	write(1, "0", 1);
	write(1, "x", 1);
	while (i > -1)
		write(1, &adress[i--], 1);
	num = ft_strlen(adress) + 2;
	free(adress);
	return (num);
}

int	ft_for_d(va_list ap)
{
	int		num;
	char	*str;

	num = va_arg(ap, int);
	str = ft_itoa(num);
	if (str == NULL)
		return (0);
	num = 0;
	while (str[num])
		write(1, &str[num++], 1);
	free(str);
	return (num);
}

int	ft_for_u(va_list ap)
{
	unsigned int	num;
	char			*str;

	num = va_arg(ap, unsigned int);
	str = ft_itoa_spec(num);
	if (str == NULL)
		return (0);
	num = 0;
	while (str[num])
		write(1, &str[num++], 1);
	free(str);
	return (num);
}
