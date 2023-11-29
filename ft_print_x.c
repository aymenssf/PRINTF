/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:09 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/29 12:20:54 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(unsigned long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_x(unsigned long n, int isupp)
{
	int		size;
	char	*hexarr;
	char	*hex;
	int		hexreturn ;

	hex = "0123456789abcdef";
	if (isupp)
		hex = "0123456789ABCDEF";
	size = len(n);
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	hexarr = (char *)malloc(size + 1);
	if (!hexarr)
		return (-1);
	hexarr[size] = '\0';
	while (size > 0)
	{
		size--;
		hexarr[size] = hex[n % 16];
		n = n / 16;
	}
	hexreturn = ft_putstr_fd(hexarr, 1);
	free(hexarr);
	return (hexreturn);
}
