/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:23:38 by kaye              #+#    #+#             */
/*   Updated: 2021/01/26 12:29:16 by kaye             ###   ########.fr       */
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

int init_sprite(t_win *win)
{
    if (!(win->sprite = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->sprite, sizeof(t_img));
    return (1);
}

t_list  *get_sprite_info(t_win *win)
{
    t_list *new;
    t_sprite info;
    int x;
    int y;
    
    y = -1;
    new = ft_lstnew(&info);
    if (!new)
        return (NULL);
    while (++y < win->desc_info->map_y)
    {
        x = -1;
        while (++x < win->desc_info->map_x)
        {
            if (win->desc_info->map[y][x] == '2')
            {
                info.x = x;
                info.y = y;
                new->content.x = x;
                new->content.y = y;
            }
        }
    }
    return (new);
}