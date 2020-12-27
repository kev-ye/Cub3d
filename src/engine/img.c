/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:09:17 by kaye              #+#    #+#             */
/*   Updated: 2020/12/27 22:42:04 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    vertical_line(t_line *line, t_win *win, int color)
{
    int y;
    int y_max;
    
    if (line->y0 < line->y1)
    {
        y = line->y0;
        y_max = line->y1;
    }
    else
    {
        y = line->y1;
        y_max = line->y0;
    }
    if (y >= 0)
    {
        while (y < y_max)
        {
            pixel_put(win->img, line->line_x, y, color);
            ++y;
        }
    }
}

void    pixel_put(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_len+ x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

t_img *new_image(t_win *win, int size_width, int size_height)
{
    t_img *new_img;

    if (!(new_img = malloc(sizeof(t_img))))
        return (void *)0;
    ft_bzero(new_img, sizeof(t_img));
    if (!(new_img->img_ptr = mlx_new_image(win->mlx_ptr, size_width, size_height)))
        return (void *)0;
    new_img->addr = mlx_get_data_addr(new_img->img_ptr, &new_img->bpp, &new_img->line_len, &new_img->endian);
    new_img->width = size_width;
    new_img->height = size_height;
    return (new_img);
}