/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:22:41 by kaye              #+#    #+#             */
/*   Updated: 2021/01/29 09:54:57 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    pixel_put_sprite(t_win *win, t_sp_cast *sp_cast)
{
    sp_cast->tex_y = (((sp_cast->y * 256 - win->height * 128
                        + sp_cast->sprite_height * 128)
                        * win->sprite->height) / sp_cast->sprite_height) / 256;
    ft_memcpy(&sp_cast->color, win->sprite->addr + sp_cast->tex_y
                * win->sprite->line_len + sp_cast->tex_x * win->sprite->bpp / 8,
                sizeof(unsigned int));
}

void    paint_pixel(t_win *win, t_sp_cast *sp_cast)
{
    ft_memcpy(win->img->addr + sp_cast->y * win->img->line_len
                + sp_cast->stripe * win->img->bpp / 8, win->sprite->addr
                + sp_cast->tex_y * win->sprite->line_len + sp_cast->tex_x
                * win->sprite->bpp / 8, sizeof(unsigned int));
}

int    sprite_casting(t_win *win, t_ray_cast *ray)
{
    t_sp_cast *sp_cast;
    int i;
    
    if (!(sp_cast = get_sprite_pos(win)))
        return (0);
    sort_sprite(win, sp_cast);
    i = 0;
    while (i < sp_cast->sp_amount)
    {
        sprite_projection(win, sp_cast, i);
        sprite_draw(win, sp_cast, ray);
        i++;
    }
    free(sp_cast);
    free(sp_cast->sprite);
    return (1);
}