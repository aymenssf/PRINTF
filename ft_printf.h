/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aassaf <aassaf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:42:07 by aassaf            #+#    #+#             */
/*   Updated: 2023/11/27 20:16:31 by aassaf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
// size_t				ft_strlen(const char *s);
int ft_printf(const char *s, ...);
int	ft_print_x(unsigned int n, int isupp);
int	ft_print_u(unsigned int n, int fd);
int	ft_print_pp(void *p);
#endif
