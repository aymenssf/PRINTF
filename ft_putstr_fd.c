/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 02:28:56 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/28 10:58:31 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (fd < 0)
		return (-1);
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		if (ft_putchar_fd(*s++, fd) == -1)
			return (-1);
		count++;
	}
	return (count);
}
