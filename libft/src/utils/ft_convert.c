/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:58:04 by kaye              #+#    #+#             */
/*   Updated: 2020/12/09 21:01:43 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_lltoa_base_pf(t_ll n, int base)
{
	size_t			len;
	char			*str;
	t_ull			n_tmp;

	n_tmp = (n < 0) ? -(t_ull)n : n;
	len = (n < 0) ? ft_ulllen_base_pf(n_tmp, base) + 1 :
					ft_ulllen_base_pf(n_tmp, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh_pf(n_tmp % base, N_LOW);
		n_tmp /= base;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char			*ft_ulltoa_base_pf(t_ull un, int base, int low_up)
{
	size_t			len;
	char			*str;

	len = ft_ulllen_base_pf(un, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = ft_conv_dh_pf((un % base), low_up);
		un /= base;
	}
	return (str);
}
