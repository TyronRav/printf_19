/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:52:04 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/01 19:30:47 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

int ft_num_len(unsigned int nb)
{
	int len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char *ft_uitoa(unsigned int nb)
{
	int len;
	char *num;

	len = ft_num_len(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (num);
}

int ft_print_unsigned(unsigned int nb)
{
	int len;
	char *num;

	len = 0;
	if (nb == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(nb);
		len += ft_print_str(num);
		free(num);
	}
	return (len);
}
