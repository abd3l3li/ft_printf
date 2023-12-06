/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:23:05 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/03 23:46:44 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nbr, char format)
{
	char	*base;
	int		count;

	count = 0;
	if (!nbr)
		return (ft_putchar('0'));
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < 16)
		count += ft_putchar(base[nbr % 16]);
	else
	{
		count += ft_puthexa(nbr / 16, format);
		count += ft_puthexa(nbr % 16, format);
	}
	return (count);
}
