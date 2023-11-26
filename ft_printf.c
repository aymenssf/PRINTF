/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:41:47 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/26 15:50:04 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int checkf(const char *spec, va_list ap)
{
	int count;

	count = 0;
	if(*spec == 'c')
		count += ft_putchar_fd((va_arg(ap, int)), 1);
	else if(*spec == 's')
		count += ft_putstr_fd((va_arg(ap, char *)), 1);
	else if(*spec == 'd' || *spec == 'i')
		count += ft_putnbr_fd((va_arg(ap, int)), 1);
	// else if(*spec == 'p')
	// 	count += ft_print_p((va_arg(ap, char *)));
	// else if(*spec == 'x'|| *spec == 'x')
	// 	count += ft_printf_x((va_arg(ap, unsigned int)), 1);
	// else if(*spec == 'u')
	// 	count += ft_printf_u((va_arg(ap, unsigned int)), 1);
	else if(*spec == '%')
		count += ft_putchar_fd('%', 1);
	else if(*spec == '\0')
		count += ft_putchar_fd(*spec, 1);
	return (count);
}
int ft_printf(const char *s, ...)
{
	va_list ap;
	int	count;

	va_start(ap, s);
	count = 0;
	while(*s != '\0')
	{
		if(*s == '%')
			count += checkf(++s, ap);
		else
			count += write(1, s, 1);
		++s;
	}
	return (count);
}

int main()
{
	int count = 0;
	count = ft_printf("%s\n", "%%");
	ft_printf("%d", count);
}
