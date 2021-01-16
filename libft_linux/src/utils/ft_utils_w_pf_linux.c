/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_w_pf_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:20:30 by kaye              #+#    #+#             */
/*   Updated: 2021/01/16 19:23:06 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wchar_len(int16_t c)
{
	int count;

	count = 0;
	if (c < 0x80)
		count = 1;
	else if (c < 0x800)
		count = 2;
	else if (c < 0x10000)
		count = 3;
	else if (c < 0x200000)
		count = 4;
	return (count);
}

int				ft_strwlen(wchar_t *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count += ft_wchar_len(*(int16_t *)s);
		++s;
	}
	return (count);
}

int				ft_putwstr_pf(wchar_t *s)
{
	int count;
	int i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		count += ft_putwchar_pf(s[i++]);
	return (count);
}

int				ft_putwstr_prec_pf(wchar_t *s, int prec)
{
	int count;

	count = 0;
	while (s[count] && count < prec)
		(void)ft_putwchar_pf(s[count++]);
	return (count);
}
