/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:05:31 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/04 00:15:08 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunsigned(unsigned int n)
{
	size_t	count;

	count = 0;
	if (!n)
		return (ft_putchar('0'));
	if (n < 10)
		count += ft_putchar(n + '0');
	else
	{
		count += ft_putunsigned(n / 10);
		count += ft_putunsigned(n % 10);
	}
	return (count);
}
