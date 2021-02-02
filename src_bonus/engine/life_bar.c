/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 10:17:59 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 10:58:45 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int    set_life_img(t_win *win, const char *path)
{
    if (!(win->life = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->life, sizeof(t_img));
    if (!(win->life->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, (char *)path, &win->life->width, &win->life->height)))
        return (0);
    win->life->addr = mlx_get_data_addr(win->life->img_ptr, &win->life->bpp, &win->life->line_len, &win->life->endian);
    return (1);
}

void    ft_pixel_put(
    t_win *win,
    int x,
    int y,
    unsigned int color)
{
    char    *dst;

    dst = win->img->addr + (y * win->img->line_len + x * (win->img->bpp / 8));
    *(unsigned int *)dst = color;
}


int    life_bar(t_win *win)
{
    unsigned int    color;
    int x;
    int y;

    x = 0;
    while (x < win->life->width)
    {
        y = 0;
        while (y < win->life->height)
        {
            color = *(unsigned int *)(win->life->addr +
                    (y * win->life->line_len) + (x * (win->life->bpp / 8)));
            if (x < win->player_life * win->life->width && color != 0x000000FF)
                ft_pixel_put(win, x, win->height - win->life->height + y, color);
            ++y;
        }
        ++x;
    }
    return (1);
}