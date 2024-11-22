/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acesar-m <acesar-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:04:30 by acesar-m          #+#    #+#             */
/*   Updated: 2024/11/21 18:36:47 by acesar-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int		ft_ret, orig_ret;
	char	c = 'A';
	char	*str = "Hello, world!";
	int		decimal = -42;
	unsigned int uint = 42;
	void	*ptr = &decimal;
	void	*num = &decimal;

	// Teste para caractere (%c)
	printf("\n--- Teste de %%c ---\n");
	ft_ret = ft_printf("ft_printf: [%c]\n", c);
	orig_ret = printf("printf   : [%c]\n", c);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para string (%s)
	printf("\n--- Teste de %%s ---\n");
	ft_ret = ft_printf("ft_printf: [%s]\n", str);
	orig_ret = printf("printf   : [%s]\n", str);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para decimal/sinalizado (%d e %i)
	printf("\n--- Teste de %%d / %%i ---\n");
	ft_ret = ft_printf("ft_printf: [%d] [%i]\n", decimal, decimal);
	orig_ret = printf("printf   : [%d] [%i]\n", decimal, decimal);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para unsigned decimal (%u)
	printf("\n--- Teste de %%u ---\n");
	ft_ret = ft_printf("ft_printf: [%u]\n", uint);
	orig_ret = printf("printf   : [%u]\n", uint);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para hexadecimal minúsculo (%x)
	printf("\n--- Teste de %%x ---\n");
	ft_ret = ft_printf("ft_printf: [%x]\n", uint);
	orig_ret = printf("printf   : [%x]\n", uint);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para hexadecimal maiúsculo (%X)
	printf("\n--- Teste de %%X ---\n");
	ft_ret = ft_printf("ft_printf: [%X]\n", uint);
	orig_ret = printf("printf   : [%X]\n", uint);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para ponteiro (%p)
	printf("\n--- Teste de %%p ---\n");
	ft_ret = ft_printf("ft_printf: [%p]\n", ptr);
	orig_ret = printf("printf   : [%p]\n", ptr);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para literal de porcentagem (%%)
	printf("\n--- Teste de %%%% ---\n");
	ft_ret = ft_printf("ft_printf: [%%%%]\n");
	orig_ret = printf("printf   : [%%%%]\n");
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	// Teste para string NULL (%s com NULL)
	printf("\n--- Teste de %%s com NULL ---\n");
	ft_ret = ft_printf("ft_printf: [%s]\n", NULL);
	orig_ret = printf("printf   : [%s]\n", (char *)NULL);
	printf("Retorno -> ft_printf: %d, printf: %d\n\n", ft_ret, orig_ret);

	return (0);
}
