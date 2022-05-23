/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_p2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:18:14 by urycherd          #+#    #+#             */
/*   Updated: 2022/01/09 20:34:23 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_for_hex(va_list ap, char c)
{
	unsigned int	num;
	int				i;
	char			*hex;

	num = va_arg(ap, unsigned int);
	hex = dec_to_hex_inv(num);
	if (hex == NULL)
		return (0);
	num = ft_strlen(hex);
	i = num - 1;
	while (i > -1)
	{
		if (c == 'X' && hex[i] > 96 && hex[i] < 122)
			hex[i] -= 32;
		write(1, &hex[i], 1);
		i--;
	}
	free (hex);
	return (num);
}

int	ft_for_proc(void)
{
	write (1, "%", 1);
	return (ft_strlen("%"));
}

char	*dec_to_hex_inv(unsigned long long num)
{
	char	*hex;
	int		rem;
	int		i;

	hex = (char *)malloc(21 * sizeof(char));
	if (hex == 0)
		return (NULL);
	i = 0;
	if (num == 0)
		hex[i++] = 48;
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[i] = 48 + rem;
		else
			hex[i] = 87 + rem;
		i++;
		num /= 16;
	}
	hex[i] = '\0';
	return (hex);
}
