/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:53:22 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/04 00:30:11 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex(unsigned long int nbr)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (nbr < 16)
		count += ft_putchar(base[nbr % 16]);
	else
	{
		count += ft_hex(nbr / 16);
		count += ft_hex(nbr % 16);
	}
	return (count);
}

int	ft_putaddr(unsigned long int ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_hex(ptr);
	return (count);
}
