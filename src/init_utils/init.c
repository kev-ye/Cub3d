/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:41:33 by kaye              #+#    #+#             */
/*   Updated: 2021/01/18 10:48:42 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_key(t_win *win)
{
    if (!(win->key_code = malloc(sizeof(t_key))))
        return (ERROR);
    ft_bzero(win->key_code, sizeof(t_key));
    win->key_code->key_w = 0;
    win->key_code->key_s = 0;
    win->key_code->key_a = 0;
    win->key_code->key_d = 0;
    win->key_code->key_left = 0;
    win->key_code->key_right = 0;
    return (SUCCESS);    
}

int init_tex(t_win *win)
{
    if (!(win->texture = malloc(sizeof(t_img *) * 4)))
        return (ERROR);
    if (!(win->texture[0] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!(win->texture[1] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!(win->texture[2] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!(win->texture[3] = malloc(sizeof(t_img))))
        return (ERROR);
    ft_bzero(win->texture[0], sizeof(t_img));
    ft_bzero(win->texture[1], sizeof(t_img));
    ft_bzero(win->texture[2], sizeof(t_img));
    ft_bzero(win->texture[3], sizeof(t_img));
    load_texture(win);
    return (SUCCESS);
}