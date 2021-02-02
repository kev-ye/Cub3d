/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:09:17 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 15:36:10 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    pixel_put_color(
    t_img *img,
    int x,
    int y,
    unsigned int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}


void    vertical_line_color(
    t_line *line,
    t_win *win,
    unsigned int color)
{
    int draw_start;
    int draw_end;
    
    draw_start = line->draw_start;
    draw_end = line->draw_end;
    if (draw_start >= 0)
    {
        while (draw_start < draw_end)
        {
            pixel_put_color(win->img, line->line_x, draw_start, color);
            ++draw_start;
        }
    }
}

/*
**  Note : 256 -> the size of line texure image, 64 (width of one line of pixel is 64) * 4 (coded on 4 chars) = 256.
*/
void    pixel_put_tex(
    t_line *line,
    t_img *texture,
    t_win *win,
    t_ray_cast *ray)
{

    line->tex_y = (((line->line_y * 256 - win->height * win->camera->cam_height * 128 + ray->line_height * 128) * texture->height) / ray->line_height) / 256;
    ft_memcpy(win->img->addr + line->line_y * win->img->line_len
                            + line->line_x * win->img->bpp / 8,
                            texture->addr + line->tex_y * texture->line_len
                            + line->tex_x * (texture->bpp / 8), sizeof(unsigned int));
}

void    vertical_line_tex(
    t_line *line,
    t_win *win,
    t_img *texture,
    t_ray_cast *ray)
{
    int draw_end;

    line->line_y = line->draw_start;
    draw_end = line->draw_end;
    if (line->line_y >= 0)
    {
        while (line->line_y < draw_end)
        {
            pixel_put_tex(line, texture, win, ray);
            ++line->line_y;
        }
    }
}

t_img *new_image(t_win *win, int size_width, int size_height)
{
    t_img *new_img;

    if (!(new_img = malloc(sizeof(t_img))))
        return (NULL);
    ft_bzero(new_img, sizeof(t_img));
    if (!(new_img->img_ptr = mlx_new_image(win->mlx_ptr, size_width,
                                                        size_height)))
        return (NULL);
    new_img->addr = mlx_get_data_addr(new_img->img_ptr, &new_img->bpp,
                                &new_img->line_len, &new_img->endian);
    new_img->width = size_width;
    new_img->height = size_height;
    return (new_img);
}