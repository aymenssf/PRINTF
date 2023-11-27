/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:06 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/27 20:17:45 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_print_pp(void *p)
{
	int			size;
	char		*hexarr;
	char		*hex;
	uintptr_t	adr;
	int			n;

	adr = (uintptr_t)p;
	hex = "0123456789abcedf";
	size = len(adr);
	if (!adr)
		return (ft_putstr_fd("0x0", 1));
	hexarr = (char *)malloc(size + 1);
	if (!hexarr)
		return (-1);
	write(1, "0x", 2);
	hexarr[size] = '\0';
	while (size > 0)
	{
		size--;
		n = adr % 16;
		hexarr[size] = hex[n];
		adr /= 16;
	}
	return (ft_putstr_fd(hexarr, 1));
	free(hexarr);
}
