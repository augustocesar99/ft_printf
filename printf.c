/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:13 by acesar-m          #+#    #+#             */
/*   Updated: 2024/11/22 10:16:33 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verify(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (spec == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		count = ft_putbase(va_arg(args, int), "0123456789", 10);
	else if ( spec == 'u')
		count = ft_putbase(va_arg(args, unsigned int), "0123456789", 10);
	else if (spec == 'x')
		count = ft_putbase(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if (spec == 'X')
		count = ft_putbase(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if (spec == 'p')
		count = ft_putpoint(va_arg(args, unsigned long));
	else if (spec == '%')
		count = ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += ft_verify(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return(count);
}
