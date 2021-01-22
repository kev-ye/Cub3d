/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:23:38 by kaye              #+#    #+#             */
/*   Updated: 2021/01/22 11:28:39 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     set_sprites(
    t_win *win,
    const char *path)
{
    if (!(win->sprite->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
                                    (char *)path, &win->sprite->width,
                                    &win->sprite->height)))
        return (0);
    win->sprite->addr = mlx_get_data_addr(win->sprite->img_ptr,
                    &win->sprite->bpp, &win->sprite->line_len,
                    &win->sprite->endian);
    return (1);
}

int     load_sprites(t_win *win)
{

    int sprite;

    sprite = set_sprites(win, win->desc_info->path_s);
    if (!sprite)
        return (0);
    return (1);
}