/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:57:55 by kaye              #+#    #+#             */
/*   Updated: 2021/02/01 12:37:53 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d_bonus.h"

int    set_life(t_win *win, const char *path)
{
    if (!(win->life = malloc(sizeof(t_img))))
        return (0);
    ft_bzero(win->life, sizeof(t_img));
    if (!(win->life->img_ptr = mlx_xpm_file_to_image(win->mlx_ptr, (char *)path, &win->life->width, &win->life->height)))
        return (0);
    win->life->addr = mlx_get_data_addr(win->img->img_ptr, &win->img->bpp, &win->img->line_len, &win->img->endian);
    return (1);
}

int    life_bar(t_win *win)
{
    mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->life->img_ptr, 0, win->height - win->life->height);
    return (1);
}