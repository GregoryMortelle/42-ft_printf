/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:20:28 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/22 17:59:26 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_putstr(const char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_putnbr(long long nbr)
{	
	size_t	length;

	length = 0;
	if (nbr < 0)
	{
		length += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		length += ft_putnbr(nbr / 10);
		length += ft_putnbr(nbr % 10);
	}
	else
		length += ft_putchar(nbr + 48);
	return (length);
}

size_t	ft_putnbr_base(unsigned long long nbr, char *base)
{
	size_t	length;
	size_t	count;

	if (!base)
		return (0);
	length = ft_strlen(base);
	count = 0;
	if (nbr < length)
	{
		count = count + ft_putchar(base[nbr]);
		return (count);
	}
	else
	{
		count = count + ft_putnbr_base(nbr / length, base);
		count = count + ft_putnbr_base(nbr % length, base);
	}
	return (count);
}
