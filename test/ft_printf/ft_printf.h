/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouhlal <ibouhlal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:15:35 by ibouhlal          #+#    #+#             */
/*   Updated: 2021/12/09 21:44:49 by ibouhlal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FT_PRINTF_H
# define    FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_put(va_list ptr, char c);
size_t	ft_hex(unsigned int nbr);
size_t	ft_hexmin(unsigned int nbr);
int		ft_pointer(unsigned long s);
int		ft_unsigned_int(unsigned int n);

#endif
