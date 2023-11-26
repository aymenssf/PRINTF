/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:14:09 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/27 00:43:38 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int len(unsigned int n)
{
        int len;

        len = 0;
        while(n != 0)
        {
                n /= 16;
                len++;
        }
        return(len);
}


int	ft_print_x(unsigned int n)
{
        char *hex = "0123456789abcedf";
        int i;

        i = 0;

        
}
