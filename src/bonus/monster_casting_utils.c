/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_casting_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:51:29 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 12:31:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sp_cast *get_monster_pos(t_win *win)
{
    t_sp_cast *ms_cast;
    int count;
    int x;
    int y;

    if (!(ms_cast = sprite_cast_init(win)))
        return (NULL);
    count = 0;
    y = -1;
    while (++y < win->desc_info->map_y)
    {
        x = -1;
        while (++x < win->desc_info->map_x)
        {
            if (win->desc_info->map[y][x] == '4')
            {
                ms_cast->sprite[count].x = x;
                ms_cast->sprite[count].y = y;
                ++count;
            }
        }
    }
    return (ms_cast);
}

void    sort_monster(t_win *win, t_sp_cast *ms_cast)
{
    double monster_dist[2];
    t_sprite tmp;
    int count;

    count = 0;
    while (count + 1 < ms_cast->sp_amount)
    {
        monster_dist[0] = ((win->camera->pos_x - ms_cast->sprite[count].x)
                        * (win->camera->pos_x - ms_cast->sprite[count].x)
                        + (win->camera->pos_y - ms_cast->sprite[count].y)
                        * (win->camera->pos_y - ms_cast->sprite[count].y));
        monster_dist[1] = ((win->camera->pos_x - ms_cast->sprite[count + 1].x)
                        * (win->camera->pos_x - ms_cast->sprite[count + 1].x)
                        + (win->camera->pos_y - ms_cast->sprite[count + 1].y)
                        * (win->camera->pos_y - ms_cast->sprite[count + 1].y));
        if (monster_dist[0] < monster_dist[1])
        {
            tmp = ms_cast->sprite[count];
            ms_cast->sprite[count] = ms_cast->sprite[count + 1];
            ms_cast->sprite[count + 1] = tmp;
            count = 0;
        }
        else
            ++count;
    }
}

void    monster_projection(t_win *win, t_sp_cast *ms_cast, int i)
{
    ms_cast->sprite_x = ms_cast->sprite[i].x - (win->camera->pos_x - 0.5);
    ms_cast->sprite_y = ms_cast->sprite[i].y - (win->camera->pos_y - 0.5);
    ms_cast->inv_det = 1.0 / (win->camera->plane_x * win->camera->dir_y
                       - win->camera->dir_x * win->camera->plane_y);
    ms_cast->transform_x = ms_cast->inv_det * (win->camera->dir_y
                           * ms_cast->sprite_x - win->camera->dir_x
                           * ms_cast->sprite_y);
    ms_cast->transform_y = ms_cast->inv_det * (-win->camera->plane_y
                           * ms_cast->sprite_x + win->camera->plane_x
                           * ms_cast->sprite_y);
    ms_cast->sprite_screen_x = (int)((win->width / 2) * 
                            (1 + ms_cast->transform_x / ms_cast->transform_y));
}

void    monster_draw(t_win *win, t_sp_cast *ms_cast, t_ray_cast *ray)
{
    ms_cast->sprite_height = abs((int)(win->height / (ms_cast->transform_y)));
    ms_cast->draw_start_y = -ms_cast->sprite_height / 2 + win->height / 2 * win->camera->cam_height;
    if (ms_cast->draw_start_y < 0)
        ms_cast->draw_start_y = 0;
    ms_cast->draw_end_y = ms_cast->sprite_height / 2 + win->height / 2 * win->camera->cam_height;
    if (ms_cast->draw_end_y >= win->height)
        ms_cast->draw_end_y = win->height - 1;
    ms_cast->sprite_width = abs((int)(win->height / (ms_cast->transform_y)));
    ms_cast->draw_start_x = -ms_cast->sprite_width / 2 + ms_cast->sprite_screen_x;
    if (ms_cast->draw_start_x < 0)
        ms_cast->draw_start_x = 0;
    ms_cast->draw_end_x = ms_cast->sprite_width / 2 + ms_cast->sprite_screen_x;
    if (ms_cast->draw_end_x >= win->width)
        ms_cast->draw_end_x = win->width - 1;
    ms_cast->stripe = ms_cast->draw_start_x;
    monster_drawing(win, ms_cast, ray);
}

void    monster_drawing(t_win *win, t_sp_cast *ms_cast, t_ray_cast *ray)
{
    while (ms_cast->stripe < ms_cast->draw_end_x)
    {
        ms_cast->tex_x = (int)((256 * (ms_cast->stripe
                        - (-ms_cast->sprite_width / 2
                        + ms_cast->sprite_screen_x))
                        * win->sprite->width / ms_cast->sprite_width) / 256);
        if (ms_cast->transform_y > 0 && ms_cast->stripe > 0
            && ms_cast->stripe < win->width
            && ms_cast->transform_y < ray->zbuffer[ms_cast->stripe])
        {
            ms_cast->y = ms_cast->draw_start_y;
            while (ms_cast->y < ms_cast->draw_end_y)
            {
                pixel_put_monster(win, ms_cast);
                if ((ms_cast->color & 0x00FFFFFF) != 0)
                    paint_pixel_m(win, ms_cast);
                ms_cast->y++;
            }
        }
        ms_cast->stripe++;
    }
}