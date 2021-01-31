/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:02:26 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 21:17:49 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    msg_error(t_win* win, char *msg)
{
    ft_putstr("Error\n");
    ft_putstr(msg);
    if (win != NULL)
        free_win(win);
    exit(1);
}