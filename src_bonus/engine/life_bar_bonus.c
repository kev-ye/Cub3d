/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:57:55 by kaye              #+#    #+#             */
/*   Updated: 2021/02/01 16:01:29 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d_bonus.h"

int    set_life(t_win *win, const char *path)
{
    if (!(win->life = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->life, sizeof(t_img));
    if (!(win->life->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, (char *)path, &win->life->width, &win->life->height)))
        return (0);
    win->life->addr = mlx_get_data_addr(win->life->img_ptr, &win->life->bpp, &win->life->line_len, &win->life->endian);
    // printf("len %d\n", win->life->line_len);
    // printf("w %d\n", win->life->width);
    // printf("h %d\n", win->life->height);
    return (1);
}

// static void    pixel_put_color1(
//     t_img *img,
//     int x,
//     int y,
//     unsigned int color)
// {
//     char    *dst;

//     dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
//     *(unsigned int*)dst = color;
// }

// static void    vertical_line_color1(
//     t_line *line,
//     t_win *win,
//     unsigned int color)
// {
//     int draw_start;
//     int draw_end;
    
//     draw_start = line->draw_start;
//     draw_end = line->draw_end;
//     if (draw_start >= 0)
//     {
//         while (draw_start < draw_end)
//         {
//             pixel_put_color(win->img, line->line_x, draw_start, color);
//             ++draw_start;
//         }
//     }
// }

// void    draw_life(t_win *win)
// {
//     int start;
//     int end;

//     start = 0;
//     end = win->img->height;
//     while (start < end)
//     {
//         ++start;
//     }
// }

int    life_bar(t_win *win)
{
    uint32_t    color;
    int x;
    int y;

    x = 0;
    while (x < win->life->width)
    {
        y = 0;
        while (y < win->life->height)
        {
            color = *(uint32_t *)(win->life->addr + (y * win->life->line_len) + (x * (win->life->bpp / 8)));
            if (color == 0x000000FF)
                pixel_put_color(win->life, x, y, 0xFF000000);
            if (x >= 0.9 * win->life->width)
                pixel_put_color(win->life, x, y, 0xFF000000);
            ++y;
        }
        ++x;
    }
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->life->img_ptr, 0, win->height - win->life->height);
    return (1);
}