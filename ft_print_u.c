/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:12 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/28 09:47:34 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int n, int fd)
{
	int	count;

	if (fd < 0)
		return (-1);
	count = 0;
	if (n >= 0 && n < 10)
		count += ft_putchar_fd((n + '0'), fd);
	else
	{
		count += ft_print_u((n / 10), fd);
		count += ft_print_u((n % 10), fd);
	}
	return (count);
}
