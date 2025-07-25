/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:57:07 by ybenzidi          #+#    #+#             */
/*   Updated: 2024/12/19 21:58:27 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BASE_DECI "0123456789abcdef"
# define BASE_HEXA "0123456789ABCDEF"

int	ft_putstr(const char *str);
int	putnbrbase(long number, const char *base, int base_length);
int	putpointer(void *ptr_address);
int	datatype_check(char c, va_list args);
int	ft_printf(const char *datatype, ...);
int	checkchar(int c);
int	checkputnbr(long *number);
int	process_format(const char *str, va_list args);

#endif
