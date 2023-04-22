/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grmortel <grmortel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:03:45 by grmortel          #+#    #+#             */
/*   Updated: 2023/04/22 16:21:27 by grmortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

char	ft_putchar(char c);
size_t	ft_strlen(char *str);
char	ft_putstr(char *str);
size_t	ft_putnbr(long long nbr);
size_t	ft_putnbr_base(unsigned long long nbr, char *base);
size_t	ft_convert(char x, va_list ap);
int		ft_printf(const char *str, ...);

#endif