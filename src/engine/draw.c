/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:21:27 by kaye              #+#    #+#             */
/*   Updated: 2021/01/03 17:21:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_text(t_cam_ray *ray, t_win *win)
{
    t_img *img;
    t_line *line;
    int color;

    if (!(line = malloc(sizeof(t_line))))
    {
        ft_putstr("ERROR LINE");
        exit(0);
    }
    ft_bzero(line, sizeof(t_line));
    line->line_x = ray->pix;
    if (win->map->map[ray->map_y][ray->map_x] == '1')
        color = BLUE;
    else if (win->map->map[ray->map_y][ray->map_x] == '2')
        color = YELLOW;
    else if (win->map->map[ray->map_y][ray->map_x] == '3')
        color = WHITE;
    if (ray->side == 1)
        color = color / 2;
    line->y0 = ray->draw_start;
    line->y1 = ray->draw_end;
    vertical_line(line, win, color);
    line->y0 = 0;
	line->y1 = ray->draw_start;
	vertical_line(line, win, RED);
	line->y0 = win->height;
	line->y1 = ray->draw_end;
	vertical_line(line, win, GREEN);
}