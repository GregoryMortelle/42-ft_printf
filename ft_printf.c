/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:21:42 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/22 17:58:45 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert(char x, va_list ap)
{
	size_t	len;
	
	len = 0;	
	if (x == '%')
		len += ft_putchar('%');
	if (x == 'c')
		len += ft_putchar(va_arg(ap, int));
	if (x == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (x == 'p')
		len += ft_putstr("0x") + ft_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
	if (x == 'd' || x == 'i')
		len += ft_putnbr(va_arg(ap, int));
	if (x == 'u')
		len += ft_putnbr_base(va_arg(ap, unsigned), "0123456789");
	if (x == 'x')
		len += ft_putnbr_base(va_arg(ap, unsigned), "0123456789abcdef");
	if (x == 'X')
		len += ft_putnbr_base(va_arg(ap, unsigned), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_convert(((char)str + 1), ap);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/*#include <stdio.h>

int main()
{
	char *str;

	str = NULL;
	ft_printf("%s\n", str);
	//printf("%s\n", str);
}*/