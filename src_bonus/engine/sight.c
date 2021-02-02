/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:34:03 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 15:43:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int    set_sight_img(t_win *win, const char *path)
{
    if (!(win->sight = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->sight, sizeof(t_img));
    if (!(win->sight->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, (char *)path, &win->sight->width, &win->sight->height)))
        return (0);
    win->sight->addr = mlx_get_data_addr(win->sight->img_ptr, &win->sight->bpp, &win->sight->line_len, &win->sight->endian);
    return (1);
}

int    sight(t_win *win)
{
    unsigned int    color;
    int x;
    int y;

    x = 0;
    while (x < win->sight->width)
    {
        y = 0;
        while (y < win->sight->height)
        {
            color = *(unsigned int *)(win->sight->addr +
                    (y * win->sight->line_len) + (x * (win->sight->bpp / 8)));
            if (color != 0x00FFFFFF)
                pixel_put_win(win, (win->width - win->sight->width) / 2 + x, (win->height - win->sight->height) / 2 + y, color);
            ++y;
        }
        ++x;
    }
    return (1);
}