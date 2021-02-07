/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:16:18 by kaye              #+#    #+#             */
/*   Updated: 2021/02/07 21:22:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int    init_pix_size(t_win *win)
{
    int pix_size_x;
    int pix_size_y;

    pix_size_x = win->width / 3 / win->desc_info->map_x;
    pix_size_y = win->height / 3 / win->desc_info->map_y;
    if (pix_size_x < pix_size_y)
        win->pix_size = pix_size_x;
    else
        win->pix_size = pix_size_y;
    if (win->pix_size == 0)
        return (0);
    return (1);
}

static int    init_mini_map(t_win *win)
{
    int size_x;
    int size_y;
    
    if (!(init_pix_size(win)))
        return (0);
    size_x = win->pix_size * win->desc_info->map_x;
    size_y = win->pix_size * win->desc_info->map_y;
    if (size_x > win->width || size_y > win->height)
        return (0);
    if (!(win->mini_map = new_image(win, size_x, size_y)))
        return (0);
    return (1);
}

static void     draw_pix(t_win *win, int map_x, int map_y, unsigned int color)
{
    int x;
    int y;

    x = 0;
    while (x < win->pix_size)
    {
        y = 0;
        while (y < win->pix_size)
        {
            pixel_put_color(win->mini_map, x + map_x, y + map_y, color);
            y++;
        }
        x++;
    }
}

int     mini_map(t_win *win) // try with bash and makefile speed is different
{
    int x;
    int y;

    if (!(init_mini_map(win)))
        return (0);
    if (win->show_mini_map == 0)
        return (0);
    x = 0;
    while (x / win->pix_size < win->desc_info->map_x)
    {
        y = 0;
        while (y / win->pix_size < win->desc_info->map_y)
        {
            if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '1')
                draw_pix(win, x, y, WHITE);
            else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '2')
                draw_pix(win, x, y, BLUE);
            else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '3')
                draw_pix(win, x, y, YELLOW);
            else if (win->desc_info->map[y / win->pix_size][x / win->pix_size] == '4')
                draw_pix(win, x, y, RED);
            else if ((y / win->pix_size) == (int)win->camera->pos_y && (x / win->pix_size) == (int)win->camera->pos_x)
                draw_pix(win, x, y, WHITE);
            else
                draw_pix(win, x, y, 0xF0000000);
            y += win->pix_size;
        }
        x += win->pix_size;
    }
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->mini_map->img_ptr, win->width - (win->pix_size * win->desc_info->map_x), 0);
    return (1);
}