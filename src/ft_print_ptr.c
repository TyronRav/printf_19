/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:42:07 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/01 19:30:16 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int ft_ptr_len(uintptr_t num)
{
	int len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int ft_print_ptr(unsigned long long ptr)
{
	int len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}