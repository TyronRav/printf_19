/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:28:22 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/01 19:38:17 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

int ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int ft_print_str(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("null");
		return (4);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return(i);
}

int ft_print_nbr(int nb)
{
	int len;
	char *num;

	len = 0;
	num = ft_itoa(nb);
	len = ft_print_str(num);
	free(num);
	return (len);
}
