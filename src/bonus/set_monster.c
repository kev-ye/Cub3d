/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_monster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:18:53 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 14:25:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     set_monster(
    t_win *win,
    const char *path)
{
    if (!(win->monster->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr,
                                    (char *)path, &win->monster->width,
                                    &win->monster->height)))
        return (0);
    win->monster->addr = mlx_get_data_addr(win->monster->img_ptr,
                    &win->monster->bpp, &win->monster->line_len,
                    &win->monster->endian);
    return (1);
}

int     load_monster(t_win *win)
{
    int sprite;
    int monster;

    if (!(monster = set_monster(win, win->desc_info->path_m)))
        return (0);
    return (1);
}

int get_monster_amount(t_win *win)
{
    int count;
    int x;
    int y;

    count = 0;
    y = -1;
    while (++y < win->desc_info->map_y)
    {
        x = -1;
        while (++x < win->desc_info->map_x)
        {
            if (win->desc_info->map[y][x] == '4')
                ++count;
        }
    }
    return (count);
}

t_sp_cast *monster_cast_init(t_win *win)
{
    t_sp_cast *ms_cast;
    t_sprite *monster;
    int count;

    count = get_monster_amount(win);
    if (!(monster = malloc(sizeof(t_sprite) * count)))
        return (NULL);
    ft_bzero(monster, sizeof(t_sprite) * count);
    if (!(ms_cast = malloc(sizeof(t_sp_cast))))
        return (NULL);
    ft_bzero(ms_cast, sizeof(t_sp_cast));
    ms_cast->sp_amount = count;
    ms_cast->sprite = monster;
    return (ms_cast);
}

int init_monster(t_win *win)
{
    if (!(win->monster = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->monster, sizeof(t_img));
    if (!(load_monster(win)))
        return (0);
    return (1);
}