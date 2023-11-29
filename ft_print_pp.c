/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:06 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/29 12:20:29 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pp(void *p)
{
	unsigned long	adr;
	int				size;

	size = 0;
	adr = (unsigned long)p;
	if (!adr)
		return (ft_putstr_fd("0x0", 1));
	size += ft_putstr_fd("0x", 1);
	size += ft_print_x(adr, 0);
	return (size);
}
