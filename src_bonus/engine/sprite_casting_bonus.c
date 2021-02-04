/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:22:41 by kaye              #+#    #+#             */
/*   Updated: 2021/02/03 15:56:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
    sp_cast->sprite_x = sp_cast->sprite[i].x - (win->camera->pos_x - 0.5);
    sp_cast->sprite_y = sp_cast->sprite[i].y - (win->camera->pos_y - 0.5);
    sp_cast->inv_det = 1.0 / (win->camera->plane_x * win->camera->dir_y
                       - win->camera->dir_x * win->camera->plane_y);
    sp_cast->transform_x = sp_cast->inv_det * (win->camera->dir_y
                           * sp_cast->sprite_x - win->camera->dir_x
                           * sp_cast->sprite_y);
    sp_cast->transform_y = sp_cast->inv_det * (-win->camera->plane_y
                           * sp_cast->sprite_x + win->camera->plane_x
                           * sp_cast->sprite_y);
    sp_cast->sprite_screen_x = (int)((win->width / 2) * 
                            (1 + sp_cast->transform_x / sp_cast->transform_y));
}

void    sprite_draw(t_win *win, t_sp_cast *sp_cast, t_ray_cast *ray, int i)
{
    sp_cast->sprite_height = abs((int)(win->height / (sp_cast->transform_y)));
    sp_cast->draw_start_y = -sp_cast->sprite_height / 2 + win->height / 2 * win->camera->cam_height;
    if (sp_cast->draw_start_y < 0)
        sp_cast->draw_start_y = 0;
    sp_cast->draw_end_y = sp_cast->sprite_height / 2 + win->height / 2 * win->camera->cam_height;
    if (sp_cast->draw_end_y >= win->height)
        sp_cast->draw_end_y = win->height - 1;
    sp_cast->sprite_width = abs((int)(win->height / (sp_cast->transform_y)));
    sp_cast->draw_start_x = -sp_cast->sprite_width / 2 + sp_cast->sprite_screen_x;
    if (sp_cast->draw_start_x < 0)
        sp_cast->draw_start_x = 0;
    sp_cast->draw_end_x = sp_cast->sprite_width / 2 + sp_cast->sprite_screen_x;
    if (sp_cast->draw_end_x >= win->width)
        sp_cast->draw_end_x = win->width - 1;
    sp_cast->stripe = sp_cast->draw_start_x;
    sprite_drawing(win, sp_cast, ray, i);
}

void    sprite_drawing(t_win *win, t_sp_cast *sp_cast, t_ray_cast *ray, int i)
{
    while (sp_cast->stripe < sp_cast->draw_end_x)
    {
        if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '2')
        {
            sp_cast->tex_x = (int)((256 * (sp_cast->stripe
                            - (-sp_cast->sprite_width / 2
                            + sp_cast->sprite_screen_x))
                            * win->sprite[0]->width / sp_cast->sprite_width) / 256);
        }
        if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '3')
        {
            sp_cast->tex_x = (int)((256 * (sp_cast->stripe
                            - (-sp_cast->sprite_width / 2
                            + sp_cast->sprite_screen_x))
                            * win->sprite[2]->width / sp_cast->sprite_width) / 256);
        }
        if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '4')
        {
            sp_cast->tex_x = (int)((256 * (sp_cast->stripe
                            - (-sp_cast->sprite_width / 2
                            + sp_cast->sprite_screen_x))
                            * win->sprite[1]->width / sp_cast->sprite_width) / 256);
        }
        if (sp_cast->transform_y > 0 && sp_cast->stripe > 0
            && sp_cast->stripe < win->width
            && sp_cast->transform_y < ray->zbuffer[sp_cast->stripe])
        {
            sp_cast->y = sp_cast->draw_start_y;
            while (sp_cast->y < sp_cast->draw_end_y)
            {
                pixel_put_sprite(win, sp_cast, i);
                if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '2')
                    if ((sp_cast->color & 0x00FFFFFF) != 0)
                        paint_pixel(win, sp_cast, i);
                if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '3')
                {
                    if ((sp_cast->color & 0x00FCFCFC) != 0x00FCFCFC)
                        paint_pixel(win, sp_cast, i);
                }
                if (win->desc_info->map[sp_cast->sprite[i].y][sp_cast->sprite[i].x] == '4')
                    if ((sp_cast->color & 0x000000FF) != 0x000000FF)
                        paint_pixel(win, sp_cast, i);
                sp_cast->y++;
            }
        }
        sp_cast->stripe++;
    }
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
        sprite_draw(win, sp_cast, ray, i);
        i++;
    }
    free(sp_cast);
    free(sp_cast->sprite);
    return (1);
}