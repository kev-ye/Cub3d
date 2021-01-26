/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:22:41 by kaye              #+#    #+#             */
/*   Updated: 2021/01/26 23:23:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_sprite_amount(t_win *win)
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
            if (win->desc_info->map[y][x] == '2')
                ++count;
        }
    }
    return (count);
}

t_sp_cast *sprite_cast_init(t_win *win)
{
    t_sp_cast *sp_cast;
    t_sprite *sprite;
    int count;

    count = get_sprite_amount(win);
    if (!(sprite = malloc(sizeof(t_sprite) * count)))
        return (NULL);
    if (!(sp_cast = malloc(sizeof(t_sp_cast))))
        return (NULL);
    ft_bzero(sprite, sizeof(t_sprite) * count);
    ft_bzero(sp_cast, sizeof(t_sp_cast));
    sp_cast->sp_amount = count;
    sp_cast->sprite = sprite;
    return (sp_cast);
}

t_sp_cast *get_sprite_pos(t_win *win)
{
    t_sp_cast *sp_cast;
    int count;
    int x;
    int y;

    if (!(sp_cast = sprite_cast_init(win)))
        return (NULL);
    count = 0;
    y = -1;
    while (++y < win->desc_info->map_y)
    {
        x = -1;
        while (++x < win->desc_info->map_x)
        {
            if (win->desc_info->map[y][x] == '2')
            {
                sp_cast->sprite[count].x = x;
                sp_cast->sprite[count].y = y;
                ++count;
            }
        }
    }
    return (sp_cast);
}

void    sort_sprite(t_win *win, t_sp_cast *sp_cast)
{
    double sprite_dist[2];
    t_sprite tmp;
    int count;

    count = 0;
    while (count + 1 < sp_cast->sp_amount)
    {
        sprite_dist[0] = ((win->camera->pos_x - sp_cast->sprite[count].x)
                        * (win->camera->pos_x - sp_cast->sprite[count].x)
                        + (win->camera->pos_y - sp_cast->sprite[count].y)
                        * (win->camera->pos_y - sp_cast->sprite[count].y));
        sprite_dist[1] = ((win->camera->pos_x - sp_cast->sprite[count + 1].x)
                        * (win->camera->pos_x - sp_cast->sprite[count + 1].x)
                        + (win->camera->pos_y - sp_cast->sprite[count + 1].y)
                        * (win->camera->pos_y - sp_cast->sprite[count + 1].y));
        if (sprite_dist[0] < sprite_dist[1])
        {
            tmp = sp_cast->sprite[count];
            sp_cast->sprite[count] = sp_cast->sprite[count + 1];
            sp_cast->sprite[count + 1] = tmp;
            count = 0;
        }
        else
            ++count;
    }
}

void    sprite_projection(t_win *win, t_sp_cast *sp_cast, int i)
{
    sp_cast->sprite_x = sp_cast->sprite[i].x - win->camera->pos_x;
    sp_cast->sprite_x = sp_cast->sprite[i].x - win->camera->pos_x;
    sp_cast->inv_det = 1.0 / (win->camera->plane_x * win->camera->dir_y
                       - win->camera->plane_y * win->camera->dir_x);
    sp_cast->transform_x = sp_cast->inv_det * (win->camera->dir_y
                           * sp_cast->sprite_x - win->camera->dir_x
                           * sp_cast->sprite_y);
    sp_cast->transform_y = sp_cast->inv_det * (-win->camera->plane_y
                           * sp_cast->sprite_x + win->camera->plane_x
                           * sp_cast->sprite_y);
    sp_cast->sprite_screen_x = (int)((win->width / 2) * 
                            (1 + sp_cast->transform_x / sp_cast->transform_y));
}

void    sprite_draw(t_win *win, t_sp_cast *sp_cast, t_ray_cast *ray)
{
    sp_cast->sprite_height = abs((int)(win->height / (sp_cast->transform_y)));
    sp_cast->draw_start_y = -sp_cast->sprite_height / 2 + win->height / 2;
    if (sp_cast->draw_start_y < 0)
        sp_cast->draw_start_y = 0;
    sp_cast->draw_end_y = sp_cast->sprite_height / 2 + win->height / 2;
    if (sp_cast->draw_end_y >= win->height)
        sp_cast->draw_end_y = win->height - 1;
    sp_cast->sprite_width = abs((int)(win->height / (sp_cast->transform_y)));
    sp_cast->draw_start_x = -sp_cast->sprite_width / 2 + sp_cast->sprite_screen_x;
    if (sp_cast->draw_start_x < 0)
        sp_cast->draw_start_x = 0;
    sp_cast->draw_end_x = sp_cast->sprite_width / 2 + sp_cast->sprite_screen_x;
    if (sp_cast->draw_end_x >= win->width)
        sp_cast->draw_end_x = win->width - 1;
    sprite_drawing(win, sp_cast, ray);
}

void    sprite_drawing(t_win *win, t_sp_cast *sp_cast, t_ray_cast *ray)
{
    sp_cast->stripe = sp_cast->draw_start_x;
    while (sp_cast->stripe < sp_cast->draw_end_x)
    {
        sp_cast->tex_x = (int)((256 * (sp_cast->stripe - (-sp_cast->sprite_width / 2 + sp_cast->sprite_screen_x)) * 64 / sp_cast->sprite_width) / 256);
        if (sp_cast->transform_y > 0 && sp_cast->stripe > 0 && sp_cast->stripe < win->width && sp_cast->transform_y < ray->zbuffer[sp_cast->stripe])
        {
            sp_cast->y = sp_cast->draw_start_y;
            while (sp_cast->y < sp_cast->draw_end_y)
            {
                pixel_put_sprite(win, sp_cast, ray);
                sp_cast->y++;
            }
        }
        sp_cast->stripe++;
    }
}

void    pixel_put_sprite(t_win *win, t_sp_cast *sp_cast, t_ray_cast *ray)
{
    sp_cast->tex_y = (((sp_cast->y * 256 - win->height * 128 + sp_cast->sprite_height * 128) * win->sprite->height) / sp_cast->sprite_height) / 256;
    ft_memcpy(&sp_cast->color, win->sprite->addr + sp_cast->tex_y * win->sprite->line_len + sp_cast->tex_x * win->sprite->bpp / 8, sizeof(unsigned int));
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
    return (1);
}