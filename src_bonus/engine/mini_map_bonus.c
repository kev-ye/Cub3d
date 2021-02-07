/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:16:18 by kaye              #+#    #+#             */
/*   Updated: 2021/02/07 13:01:13 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void    int_pix_size()
{
    int pix_size_x;
    int pix_size_y;

    pix_size_x = win->width / 3 / win->desc_info->map_x;
    pix_size_y = win->height / 3 /win->desc_info->map_y;
    if (pix_size_x < pix_size_y)
        win->pix_size = pix_size_x;
    else
        win->pix_size = pix_size_y;
}

static int    init_mini_map(t_win *win)
{
    if (!(win->mini_map = new_image(win, win->width / 3, win->height / 3)))
        return (0);
    init_pix_size();
    return (1);
}

int     creat_mini_map(t_win *win)
{
    unsigned int color;
    int x;
    int y;

    if (!(init_mini_map(win)))
        return (0);
    x = 0;
    while (x < win->desc_info->map_x)
    {
        y = 0;
        while (y < win->desc_info->map_y)
        {
            if (win->desc_info->map[y][x] == "1")
                // draw
            else if (win->desc_info->map[y][x] == "2")
                // draw
        }
        x++;
    }
    return (1);
}