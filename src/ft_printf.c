/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: traviaer <traviaer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:50:44 by traviaer          #+#    #+#             */
/*   Updated: 2022/09/01 11:22:41 by traviaer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "ft_printf.h" */
#include <unistd.h>
#include <stdarg.h>

int ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_formats(va_list list, const char format)
{
	int len;

	len = 0;
	if (format == 'd' || format == 'i')
		len += ft_print_nbr(va_arg(list, int));
	else if (format == 'c')
		len += ft_print_char(va_arg(list, int));
	else if (format == 's')
		len += ft_print_str(va_arg(list, char *));
	else if (format == 'u')
		len += ft_print_unsigned(va_arg(list, unsigned int));
	else if (format == 'p')
		len += ft_print_ptr(va_arg(list, unsigned long long));
	else if (format == 'x' || format == 'X')
		len += ft_print_hex(va_arg(list, unsigned int), format);
	else if (format == '%')
		len += ft_print_percent();
	return(len);
}


int ft_printf(const char *str, ...)
{
	int i;
	int len;
	va_list list;

	i = 0;
	len = 0;
	va_start(list, str);

	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += ft_formats(list, str[i + 1]);
			i++;
		}
		else
		{
			len += ft_print_char(str[i]);
			i++;
		}
	}

	va_end(list);
	return (len);
}