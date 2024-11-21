/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:06:30 by acesar-m          #+#    #+#             */
/*   Updated: 2024/11/21 14:10:21 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_verify(char spec, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putbase(long long n, char *base, int div);
int	ft_putpoint(unsigned long p);

#endif
