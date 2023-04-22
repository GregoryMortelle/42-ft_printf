/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:20:28 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/22 16:24:36 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	ft_putstr(char *str)
{
	if (!str)
		str = "(NULL)";
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_putnbr(long long nbr)
{	
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr + 48);
	return (nbr);
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
