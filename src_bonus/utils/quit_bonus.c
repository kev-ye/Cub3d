/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:42:20 by kaye              #+#    #+#             */
/*   Updated: 2021/02/04 10:05:57 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void shut_down(t_win *win)
{
    mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    if (win != NULL)
        free_win(win);
    system("killall afplay");
    if (win->player_life < 0)
    {
        ft_putstr(S_RED"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        ft_putstr("!          GAME OVER          !\n");
        ft_putstr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"S_NONE);
    }
    exit(0);
}