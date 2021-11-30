/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 03:45:50 by sikang            #+#    #+#             */
/*   Updated: 2021/11/03 16:48:54 by sion             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_string(char *str)
{
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_treat_pointer(unsigned long long p)
{
	char	*nbr;
	char	*temp;
	int		i;
	int		len;

	i = 0;
	nbr = ft_ull_base(p, "0123456789abcdef");
	temp = nbr;
	nbr = ft_strjoin("0x", nbr);
	free(temp);
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}

int	ft_treat_int(int n)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n);
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}

int	ft_treat_uint(unsigned int n)
{
	char	*nbr;
	int		len;

	nbr = ft_uitoa(n);
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}

int	ft_treat_hexa(unsigned int n, int flag)
{
	char	*nbr;
	int		i;
	int		len;

	i = 0;
	if (flag == 1)
		nbr = ft_ull_base(n, "0123456789ABCDEF");
	else
		nbr = ft_ull_base(n, "0123456789abcdef");
	ft_putstr_fd(nbr, 1);
	len = ft_strlen(nbr);
	free(nbr);
	return (len);
}
