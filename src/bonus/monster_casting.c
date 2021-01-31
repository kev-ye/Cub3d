/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:22:41 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 12:34:01 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    pixel_put_monster(t_win *win, t_sp_cast *ms_cast)
{
    ms_cast->tex_y = (((ms_cast->y * 256 - win->height * win->camera->cam_height * 128
                        + ms_cast->sprite_height * 128)
                        * win->sprite->height) / ms_cast->sprite_height) / 256;
    ft_memcpy(&ms_cast->color, win->monster->addr + ms_cast->tex_y
                * win->monster->line_len + ms_cast->tex_x * win->monster->bpp / 8,
                sizeof(unsigned int));
}

void    paint_pixel_m(t_win *win, t_sp_cast *ms_cast)
{
    ft_memcpy(win->img->addr + ms_cast->y * win->img->line_len
                + ms_cast->stripe * win->img->bpp / 8, win->monster->addr
                + ms_cast->tex_y * win->monster->line_len + ms_cast->tex_x
                * win->monster->bpp / 8, sizeof(unsigned int));
}

int    monster_casting(t_win *win, t_ray_cast *ray)
{
    t_sp_cast *ms_cast;
    int i;
    
    if (!(ms_cast = get_sprite_pos(win)))
        return (0);
    sort_monster(win, ms_cast);
    i = 0;
    while (i < ms_cast->sp_amount)
    {
        monster_projection(win, ms_cast, i);
        monster_draw(win, ms_cast, ray);
        i++;
    }
    free(ms_cast);
    free(ms_cast->sprite);
    return (1);
}