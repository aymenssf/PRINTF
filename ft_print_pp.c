/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:06 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/28 22:21:04 by aassaf           ###   ########.fr       */
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
	char		*hexarr;
	char		*hex;
	unsigned int	adr;
	int			size;
	adr = (unsigned int)p;
	if (!adr)
		return (ft_putstr_fd("0x0", 1));
	// ft_putstr_fd("0x", 1);
	size = ft_print_x(adr, 0);
	return (0);
}
