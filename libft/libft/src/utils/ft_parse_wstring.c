/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:19:42 by kaye              #+#    #+#             */
/*   Updated: 2020/12/09 21:00:56 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	with_prec(wchar_t *s, int prec)
{
	int		count;
	size_t	len;

	count = 0;
	len = ft_strwlen(s);
	if (prec >= 0)
		count += ft_putwstr_prec_pf(s, prec);
	else
		count += ft_putwstr_pf(s);
	return (count);
}

int			ft_parse_wstring(wchar_t *s, t_flag flag)
{
	int		count;
	int		len;

	if (!s)
		s = L"(null)";
	count = 0;
	len = ft_strwlen(s);
	if (flag.prec >= 0 && flag.prec > len)
		flag.prec = len;
	if (flag.minus)
		count += with_prec(s, flag.prec);
	if (flag.prec >= 0)
		count += ft_parse_width(flag.width, flag.prec, flag.zero);
	else
		count += ft_parse_width(flag.width, len, flag.zero);
	if (!flag.minus)
		count += with_prec(s, flag.prec);
	return (count);
}
