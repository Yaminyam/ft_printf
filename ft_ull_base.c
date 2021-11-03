/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:18:33 by sikang            #+#    #+#             */
/*   Updated: 2021/10/05 13:00:37 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ull_base(unsigned long long nbr, char *base)
{
	int					cnt;
	int					i;
	unsigned long long	nl;
	unsigned long long	n;
	char				*result;

	cnt = 0;
	nl = 1;
	n = nbr;
	i = 0;
	while (n / 16)
	{
		n /= 16;
		nl *= 16;
		cnt++;
	}
	result = (char *)malloc(cnt + 2);
	while (nl)
	{
		result[i++] = base[nbr / nl];
		nbr %= nl;
		nl /= 16;
	}
	result[i] = '\0';
	return (result);
}
