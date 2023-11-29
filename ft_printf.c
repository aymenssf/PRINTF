/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:41:47 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/29 14:30:45 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	checkf(const char *spec, va_list ap)
{
	int	count;

	count = 0;
	if (*spec == 'c')
		count += ft_putchar_fd((va_arg(ap, int)), 1);
	else if (*spec == 's')
		count += ft_putstr_fd((va_arg(ap, char *)), 1);
	else if (*spec == 'd' || *spec == 'i')
		count += ft_putnbr_fd((va_arg(ap, int)), 1);
	else if (*spec == 'p')
		count += ft_print_pp((va_arg(ap, void *)));
	else if (*spec == 'x' || *spec == 'X')
		count += ft_print_x(va_arg(ap, unsigned int), (*spec == 'X'));
	else if (*spec == 'u')
		count += ft_print_u((va_arg(ap, unsigned int)), 1);
	else if (*spec == '%')
		count += ft_putchar_fd('%', 1);
	else if (*spec == '\0')
		count += ft_putchar_fd(*spec, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, s);
	count = 0;
	while (*s != '\0')
	{
		if (*s == '%')
			count += checkf(++s, ap);
		else
			count += write(1, s, 1);
		if (*s == '\0')
			break ;
		++s;
	}
	return (count);
}
// #include <limits.h>
// int main()
// {
// 	// count = ft_printf("%s\n", "%%");
// 	int s = -4114;
// 	int sizee =	ft_printf("%d\n", s);
// 	// printf("%p", s);
// 	int size = printf("%d\n", s);
// 	printf("%d\n", size);
// 	ft_printf("%d", sizee);
// }
// ///////////////return test////////////////

// int	main(void)
// {
// 	int				i;
// 	int				ii;
// 	int				j;
// 	unsigned int	k;
// 	char			c;
// 	char			str[100];

// 	k = 4294967295;
// 	int ft_printf_return ;
// 	int printf_return ;
// 	ft_printf_return (= ft_printf("Character: %c \n", 'A'));
// 	printf_return (= printf("Character: %c \n", 'A'));
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 	printf_return);
// 	ft_printf_return= ft_printf("Integer (decimal): %d \n", 12345);
// 	printf_return= printf("Integer (decimal): %d \n", 12345);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("Negative Integer (decimal): %d \n", -9876);
// 	printf_return= printf("Negative Integer (decimal): %d \n", -9876);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("Integer (hex): %x \n", 255);
// 	printf_return= printf("Integer (hex): %x \n", 255);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("String: %s \n", "Hello, World!");
// 	printf_return= printf("String: %s \n", "Hello, World!");
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("Unsigned Integer: %u \n", k);
// 	printf_return= printf("Unsigned Integer: %u \n", k);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("Pointer: %p\n", (void *)0x12345678);
// 	printf_return= printf("Pointer: %p\n", (void *)0x12345678);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	ft_printf_return= ft_printf("Custom Test: %s %i %d %% Aymen \n", "Assaf",
// 			1337, 42);
// 	printf_return= printf("Custom Test: %s %i %d %% Assaf \n", "Assaf", 1337,
// 			42);
// 	printf("ft_printf return: %d, printf return: %d\n", ft_printf_return,
// 		printf_return);
// 	return (0);
// }

///////////////testes////////////////////

// int main()
// {
//     int i;
//     int ii;
// 	int j;
//     unsigned int k;
//     char c;
//     char str[100];

// 	ft_printf("character :");
//     scanf(" %c", &c);
//     printf("Character: %c \n", c);
//     ft_printf("Character: %c \n", c);

// 	ft_printf("intger(hex)(decimal) :");
//     scanf("%d", &i);
//     printf("Integer (decimal): %d \n", i);
//     ft_printf("Integer (decimal): %d \n", i);

// 	printf("Integer (hex): %x \n", i);
//     ft_printf("Integer (hex): %x \n", i);

// 	ft_printf("-intger(hex)(decimal) :");
//     scanf("%d", &ii);
//     printf("Negative Integer (decimal): %d \n", ii);
//     ft_printf("Negative Integer (decimal): %d \n", ii);

//     printf("-Integer (-hex): %x \n", ii);
//     ft_printf("-Integer (-hex): %x \n", ii);

// 	ft_printf("string (his address) :");
//     scanf("%s", str);
//     printf("String: %s \n", str);
//     ft_printf("String: %s \n", str);

//     printf("Pointer: %p \n", str);
//     ft_printf("Pointer: %p \n", str);

// 	ft_printf("unsigned intger :");
//     scanf("%u", &k);
//     printf("Unsigned Integer: %u \n", k);
//     ft_printf("Unsigned Integer: %u \n", k);

// 	printf("1 name: ");
// 	scanf("%s", str);

// 	char *str1;

// 	printf("2 name: ");
// 	scanf("%s", str1);

// 	printf("age :");
// 	scanf("%d", &i);

// 	printf("random number: ");
// 	scanf("%d", &j);

// 	ft_printf("Hello, %s %s! You are %d years old, and your random number is
		// %d. Cheers! \n", str, str1, i, j);
//  	printf("Hello, %s %s! You are %d years old, and your random number is
		// %d. Cheers! \n", str, str1, i, j);

//     return (0);
// }
