/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:42 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/22 16:25:27 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert(char x, va_list ap, size_t len)
{
	if (x == '%')
		return ((len += ft_putchar('%')));
	if (x == 'c')
		return ((len += ft_putchar(va_arg(ap, char))));
	if (x == 's')
		return ((len += ft_putstr(va_arg(ap, char *))));
	if (x == 'p')
		return ((len += ft_putstr("0x")
				+ ft_putnbr_base
				(va_arg(ap, unsigned long), "0123456789abcdef")));
	if (x == 'd' || x == 'i')
		return ((len += ft_putnbr(va_arg(ap, int))));
	if (x == 'u')
		return ((len += ft_putnbr_base
				(va_arg(ap, unsigned long long), "0123456789")));
	if (x == 'x')
		return ((len += ft_putnbr_base
				(va_arg(ap, unsigned), "0123456789abcdef")));
	if (x == 'X')
		return ((len += ft_putnbr_base
				(va_arg(ap, unsigned), "0123456789ABCDEF")));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	while (str[i])
	{
		if (str[i] == '%')
			return (ft_convert(str, ap, len));
		else if (str[i] != '%')
		{
			write(1, str[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (len);
}

int main()
{
	char *str = "test";

	printf("Vrai printf : ", printf(str));
	printf("Vrai printf : ", ft_printf(str));
}