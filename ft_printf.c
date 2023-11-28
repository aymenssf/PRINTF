/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:41:47 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/28 19:10:31 by aassaf           ###   ########.fr       */
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
		++s;
	}
	return (count);
}
#include <limits.h>
int main()
{
	// count = ft_printf("%s\n", "%%");
	char *s = "ddddss";
	ft_printf("%p\n", s);
	printf("%p", s);
	printf("yhe real number %p", s);
}
