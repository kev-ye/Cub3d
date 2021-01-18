/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:14:33 by kaye              #+#    #+#             */
/*   Updated: 2020/12/09 21:00:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wchar_byte(wint_t c)
{
	write(1, &c, 1);
	return (1);
}

static int		wchar_twobytes(wint_t c)
{
	unsigned char print_c[2];

	print_c[0] = (c >> 6) + 0xc0;
	print_c[1] = (c >> 0 & 0x3f) + 0x80;
	write(1, print_c, 2);
	return (2);
}

static int		wchar_treebytes(wint_t c)
{
	unsigned char print_c[3];

	print_c[0] = (c >> 12) + 0xe0;
	print_c[1] = (c >> 6 & 0x3f) + 0x80;
	print_c[2] = (c >> 0 & 0x3f) + 0x80;
	write(1, print_c, 3);
	return (3);
}

static int		wchar_fourbytes(wint_t c)
{
	unsigned char print_c[4];

	print_c[0] = (c >> 18) + 0xf0;
	print_c[1] = (c >> 12 & 0x3f) + 0x80;
	print_c[2] = (c >> 6 & 0x3f) + 0x80;
	print_c[3] = (c >> 0 & 0x3f) + 0x80;
	write(1, print_c, 4);
	return (4);
}

int				ft_putwchar_pf(wint_t c)
{
	int count;

	count = 0;
	if (c < 0x80)
		count = wchar_byte(c);
	else if (c < 0x800)
		count = wchar_twobytes(c);
	else if (c < 0x10000)
		count = wchar_treebytes(c);
	else if (c < 0x200000)
		count = wchar_fourbytes(c);
	return (count);
}
