/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:33:03 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/06 09:17:18 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	printnbr_base(int nbr, char *base);
int	printhex_base(unsigned int nbr, char *base);
int	print_unsigned(unsigned int nbr);
int	printchar(int c);
int	print_address(unsigned long addr, char *base, int first);
int	printstr(char *str);
int	ft_strlen(const char *s);
#endif
