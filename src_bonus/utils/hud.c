/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:26:26 by kaye              #+#    #+#             */
/*   Updated: 2021/02/04 11:12:05 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    put_hud(t_win *win)
{
    char *x;
    char *y;
    char *join;

    x = ft_itoa(win->width);
    y = ft_itoa(win->height);
    if (win->hud == 1)
    {
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 20, WHITE, x);
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 40, WHITE, y);
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 60, WHITE, MSG1);
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 80, WHITE, MSG2);
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 100, WHITE, MSG3);
        mlx_string_put(win->mlx_ptr, win->win_ptr, 10, 120, WHITE, MSG4);
    }
    free(x);
    free(y);
}