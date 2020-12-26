/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:09:17 by kaye              #+#    #+#             */
/*   Updated: 2020/12/26 22:26:44 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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