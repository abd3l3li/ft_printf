/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:36:49 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/03 23:53:04 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr((va_arg(args, int))));
	else if (format == 'X' || format == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_putaddr(va_arg(args, unsigned long int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

static int	ft_format(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	ft_break(const char *format, va_list args, int len)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_format(format[i + 1], "cspdiuxX%"))
		{
			len += ft_check(args, format[i + 1]);
			i++;
		}
		else if (format[i] == '%' && !(ft_format(format[i + 1], "cspdiuxX%")))
		{
			if (format[i + 1] == '\0')
				return (-1);
			len += ft_putchar(format[i]);
			if (format[i + 1] == '\n' || format[i + 1] == '\t')
				len += ft_putchar(format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	len += ft_break(format, args, len);
	va_end(args);
	return (len);
}
