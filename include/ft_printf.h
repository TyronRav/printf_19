/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:24:06 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/01 19:27:27 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
#define LIBFT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
int ft_print_char(int c);
int ft_formats(va_list list, const char format);
int ft_print_percent(void);
void ft_putstr(char *str);
int ft_print_str(char *str);
int ft_print_nbr(int nb);
int ft_num_len(unsigned int nb);
char *ft_uitoa(unsigned int nb);
int ft_print_unsigned(unsigned int nb);
int ft_hex_len(unsigned int num);
void ft_put_hex(unsigned int num, const char format);
int ft_print_hex(unsigned int num, const char format);
int ft_ptr_len(uintptr_t num);
void ft_put_ptr(uintptr_t num);
int ft_print_ptr(unsigned long long ptr);

#endif