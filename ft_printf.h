/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-baz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 00:37:15 by abel-baz          #+#    #+#             */
/*   Updated: 2023/12/05 17:34:40 by abel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

size_t	ft_putunsigned(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_putaddr(unsigned long int addr);
int		ft_putchar(int c);
int		ft_puthexa(unsigned int nbr, char format);
int		ft_putnbr(int n);
int		ft_putstr(char *str);

#endif
