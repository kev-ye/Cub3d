/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:09:17 by kaye              #+#    #+#             */
/*   Updated: 2021/01/03 21:05:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    vertical_line_color(t_line *line, t_win *win, int color)
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
            // pixel_put2(win, win->img, line->line_x, y, color);
            pixel_put_color(win->img, line->line_x, y, color);
            ++y;
        }
    }
}

void    pixel_put_color(t_img *img, int x, int y, int color)
{
    char    *dst;
    
    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    // img->line_len = win->width * 4
    // img->bpp / 8 -> becasue bpp = 32 -> 4 * 8 bits -> 32 / 8 = 4 char
    *(unsigned int*)dst = color;
}

void    pixel_put2(t_win *win, t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < win->width && y < win->height)
        ft_memcpy(img->addr + (4 * win->width * y + x * 4), &color, sizeof(unsigned int));
}

// void    pixel_put_tex(t_win *win, t_line *line, t_img *texture, t_cam_ray *ray, int x, int y, int index)
// {
//     if (x < win->width && y < win->height)
//     {
//         line->tex_y = abs((((y * 256 - win->height * 128 + ray->line_height * 128) * 64) / ray->line_height) / 256);
//         ft_memcpy(win->img->addr + 4 * win->width * y + 4, win->texture[index]->addr + line->tex_y % 64 * win->texture[index]->line_len + line->tex_x % 64 * win->texture[index]->bpp / 8, sizeof(int));
//     }
// }


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