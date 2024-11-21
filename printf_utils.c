/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:03:44 by acesar-m          #+#    #+#             */
/*   Updated: 2024/11/21 14:03:53 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return write(1, "(null)", 6);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putbase(long long n, char *base, int div)
{
    int		count;
    char	c;

    count = 0;
    if (n < 0 && div == 10)
    {
        write(1, "-", 1);
        count++;
        n = -n;
    }
    if (n >= div)
        count += ft_putbase(n / div, base, div);
    c = base[n % div];
    count += ft_putchar(c);
    return (count);
}

int	ft_putpoint(unsigned long p)
{
	int		i;
	int		count;
	char	*base;
	char	str[17];

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (!p || p == 0)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	while (p > 0)
	{
		str[i] = base[p % 16];
		p /= 16;
		i++;
	}
	count += i;
	i--;
	while (i >= 0)
		write (1, &str[i--], 1);
	return (count);
}
