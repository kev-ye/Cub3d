/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:16:18 by kaye              #+#    #+#             */
/*   Updated: 2021/02/07 15:49:55 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void    init_pix_size(t_win *win)
{
    int pix_size_x;
    int pix_size_y;

    pix_size_x = win->width / 3 / win->desc_info->map_x;
    pix_size_y = win->height / 3 / win->desc_info->map_y;
    if (pix_size_x < pix_size_y)
        win->pix_size = pix_size_x;
    else
        win->pix_size = pix_size_y;
    // printf("win / 3 %d\n", win->width /3);
    // printf("minimap %d\n", win->mini_map->width);
    // printf("pix size %d\n", win->pix_size);
}

static int    init_mini_map(t_win *win)
{
    if (!(win->mini_map = new_image(win, win->width / 3, win->height / 3)))
        return (0);
    init_pix_size(win);
    return (1);
}

static void     draw_pix(t_win *win, int map_x, int map_y, unsigned int color)
{
    int x;
    int y;

    x = 0;
    while (x < win->pix_size - 1)
    {
        y = 0;
        while (y < win->pix_size - 1)
        {
            pixel_put_color(win->img, x + (map_x + (win->width - (win->width / 3))), y + map_y, color);
            y++;
        }
        x++;
    }
}

int     creat_mini_map(t_win *win)
{
    unsigned int color;
    int x;
    int y;

    if (!(init_mini_map(win)))
        return (0);
    if (win->pix_size == 0)
        return (0);
    x = 0;
    while (x / win->pix_size < win->desc_info->map_x)
    {
        y = 0;
        while (y / win->pix_size < win->desc_info->map_y)
        {
            if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '1')
                draw_pix(win, x, y, 0x00000000);
            if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '2')
                draw_pix(win, x, y, BLUE);
            if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '3')
                draw_pix(win, x, y, YELLOW);
            if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '4')
                draw_pix(win, x, y, RED);
            if ((y / win->pix_size) == (int)win->camera->pos_y && (x / win->pix_size) == (int)win->camera->pos_x)
                draw_pix(win, x, y, WHITE);
            y += win->pix_size;
        }
        x += win->pix_size;
    }
    //msg_error(win, "test\n");
    return (1);
}