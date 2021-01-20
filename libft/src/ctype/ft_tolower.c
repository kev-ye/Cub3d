/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:56:32 by kaye              #+#    #+#             */
/*   Updated: 2020/11/04 17:41:22 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts uppercase letters to lowercase letters.
*/

int		ft_tolower(int c)
{
	return ((c >= 65 && c <= 90) ? c + 32 : c);
}