/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:45:26 by sikang            #+#    #+#             */
/*   Updated: 2021/11/03 13:58:39 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		cnt;
	va_list	ap;
	char	*tmp;

	tmp = (char *)format;
	va_start(ap, format);
	cnt = ft_read_format(tmp, ap);
	va_end(ap);
	return (cnt);
}

int	ft_read_format(char *format, va_list ap)
{
	int	cnt;

	cnt = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_able_type(*format))
				cnt += ft_treat_format(*format, ap);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			cnt++;
		}
		format++;
	}
	return (cnt);
}

int	ft_treat_format(char c, va_list ap)
{
	int	cnt;

	if (c == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (c == 's')
		cnt = ft_treat_string(va_arg(ap, char *));
	else if (c == 'p')
		cnt = ft_treat_pointer(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		cnt = ft_treat_int(va_arg(ap, int));
	else if (c == 'u')
		cnt = ft_treat_uint(va_arg(ap, unsigned int));
	else if (c == 'x')
		cnt = ft_treat_hexa(va_arg(ap, unsigned int), 0);
	else if (c == 'X')
		cnt = ft_treat_hexa(va_arg(ap, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	if (c == 'c' || c == '%')
		cnt = 1;
	return (cnt);
}

int	ft_able_type(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}
