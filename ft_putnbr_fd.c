/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:21:10 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/28 14:42:40 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	ft_putnbr_fd(int n, int fd)
// {
// 	int	count;

// 	if (fd < 0)
// 		return (-1);
// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		count += ft_putchar_fd('-', fd);
// 		count += ft_putchar_fd('2', fd);
// 		count += ft_putnbr_fd(147483648, fd);
// 	}
// 	else if (n >= 0 && n < 10)
// 		count += ft_putchar_fd((n + '0'), fd);
// 	else if (n < 0)
// 	{
// 		count += ft_putchar_fd('-', fd);
// 		count += ft_putnbr_fd((n * -1), fd);
// 	}
// 	else
// 	{
// 		count += ft_putnbr_fd((n / 10), fd);
// 		count += ft_putnbr_fd((n % 10), fd);
// 	}
// 	return (count);
// }
int ft_putnbr_fd(int n, int fd)
{
	long ln;
	ln = n;
	int count;

	count = 0;
    if (fd < 0)
        return (-1);
    if (ln < 0)
    {
        count += ft_putchar_fd('-', fd);
        ln = -ln;
    }
    long div = 1;

    while (ln / div >= 10)
        div *= 10;
    while (div)
    {
        int digit = ln / div;
        count += ft_putchar_fd(digit + '0', fd);
        ln %= div;
        div /= 10;
    }
	return (count);
}
