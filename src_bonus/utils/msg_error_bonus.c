/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:02:26 by kaye              #+#    #+#             */
/*   Updated: 2021/02/07 15:21:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    msg_error(t_win* win, char *msg)
{
    ft_putstr("Error\n");
    ft_putstr(msg);
    system(KILL_SOUND); // remove after
    if (win != NULL)
        free_win(win);
    exit(1);
}