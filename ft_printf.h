/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 22:38:06 by sikang            #+#    #+#             */
/*   Updated: 2021/10/05 13:17:30 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_read_format(char *format, va_list ap);
int		ft_treat_format(char c, va_list ap);
int		ft_able_type(char c);

int		ft_treat_string(char *str);
int		ft_treat_pointer(unsigned long long p);
int		ft_treat_int(int n);
int		ft_treat_uint(unsigned int n);
int		ft_treat_hexa(unsigned int n, int flag);

char	*ft_uitoa(unsigned int n);
char	*ft_ull_base(unsigned long long nbr, char *base);

#endif
