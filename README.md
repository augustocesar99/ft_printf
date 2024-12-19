# ft_printf()

Este repositório contém todos os arquivos do projeto **ft_printf** que relizei na formação da 42SP. O projeto consiste em replicar a função printf(), que faz parte da biblioteca `stdio.h`.

## Sobre

Este projeto consiste em replicar o comportamento da função `printf()` em C. Não é necessário implementar a gestão de buffer da função original. Deve-se lidar com os seguintes parâmetros:

- Variáveis do tipo `char`.
- Variáveis do tipo `string`.
- Variáveis do tipo `int`.
- Variáveis do tipo `unsigned int`.
- Variáveis do tipo `int` em hexadecimal (maiúsculo e minúsculo).
- Variáveis do tipo `pointer`.

## Estrutura

Os principais desafios durante a execução do projeto foram: lidar com um número variável de parâmetros e a função `ft_printf()` retornar um `int`.

### va_list

Para lidar com o número variável de parâmetros inseridos, foram utilizadas as macros `va_list`, `va_start`, `va_arg` e `va_end`. A função `ft_printf()` chama a função `check_format()` quando encontra o símbolo `%` entre os parâmetros inseridos e, em seguida, verifica o próximo caractere na string para chamar uma das funções que imprimem os diferentes tipos de variáveis. Para usar essa macro, a biblioteca `<stdarg.h>` é incluída no arquivo `ft_printf.h`.

### Retornando um inteiro

Para lidar com o inteiro retornado por ft_printf(), todas as funções auxiliares retornam o valor de caracteres impressos de acordo com o parâmetro passado. No exemplo abaixo, a função print_str() incrementa o contador i cada vez que um caractere é impresso e, ao final, retorna o valor do contador.

```
int	print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
```

## Formatos

Os diferentes tipos de variáveis são impressos usando uma função para cada formato:

- ft_print_char() = Imprime variáveis do tipo `char`, retorna `1`.
- ft_print_str() = Imprime uma variável do tipo `char *`, chamando `ft_putchar_pf()` em um loop `while`. Se a string for `NULL`, retorna `"(null)"`.
- ft_putptr_pf() = Imprime um ponteiro no formato hexadecimal (minúsculo), precedido pela string "0x".
- ft_putuint_pf() = Imprime uma variável do tipo `unsigned int`.

## Funções Auxiliares

ft_aux_pf.c() Este arquivo contém todas as funções auxiliares, especificamente a função `ft_atoi_base`, Essa função será usada principalmente para mudar a base em funções que lidam com números hexadecimais e variáveis do tipo `unsigned int`.

## Requisitos

As funções são escritas na linguagem **C** e precisam do compilador `gcc`, com as bibliotecas padrão `<stdlib.h>`, `<stdarg.h>` e `<unistd.h>` para serem executadas.
