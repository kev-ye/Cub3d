/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:43:00 by kaye              #+#    #+#             */
/*   Updated: 2021/01/16 13:57:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void shut_down(t_win *win)
{
    mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(0);
}

// int init_key(t_win *win)
// {
//     if (!(win->key_code = malloc(sizeof(t_key))))
//         return (ERROR);
//     ft_bzero(win->key_code, sizeof(t_key));
//     win->key_code->key_w = 0;
//     win->key_code->key_s = 0;
//     win->key_code->key_a = 0;
//     win->key_code->key_d = 0;
//     win->key_code->key_left = 0;
//     win->key_code->key_right = 0;
//     return (SUCCESS);    
// }

int init_key(t_win **win)
{
    if (!((*win)->key_code = malloc(sizeof(t_key))))
        return (ERROR);
    ft_bzero((*win)->key_code, sizeof(t_key));
    (*win)->key_code->key_w = 0;
    (*win)->key_code->key_s = 0;
    (*win)->key_code->key_a = 0;
    (*win)->key_code->key_d = 0;
    (*win)->key_code->key_left = 0;
    (*win)->key_code->key_right = 0;
    return (SUCCESS);    
}

int init_tex(t_win **win)
{
    if (!((**win).texture = malloc(sizeof(t_img *) * 4)))
        return (ERROR);
    if (!((*win)->texture[0] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!((*win)->texture[1] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!((*win)->texture[2] = malloc(sizeof(t_img))))
        return (ERROR);
    if (!((*win)->texture[3] = malloc(sizeof(t_img))))
        return (ERROR);
    ft_bzero((*win)->texture[0], sizeof(t_img));
    ft_bzero((*win)->texture[1], sizeof(t_img));
    ft_bzero((*win)->texture[2], sizeof(t_img));
    ft_bzero((*win)->texture[3], sizeof(t_img));
    return (SUCCESS);
}

static t_win *init_mlx_win(char *path)
{
    t_win *new_win;

    if (!(new_win = malloc(sizeof(t_win))))
        exit(1);
    ft_bzero(new_win, sizeof(t_win));
    if (!(new_win->mlx_ptr = mlx_init()))
        return (ERROR);
    if (!(new_win->desc_info = check_file(path)))
        return (ERROR);
    new_win->width = new_win->desc_info->r_x;
    new_win->height = new_win->desc_info->r_y;
    if (!(new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, new_win->width, new_win->height, "Cub3d")))
        return (ERROR);
    if (!(new_win->img = new_image(new_win, new_win->width, new_win->height)))
        return (ERROR);
    // new_win->desc_info->map_width = 0;
    // new_win->desc_info->map_height = 0;
    if (!(init_key(&new_win)))
        exit(1);
    if (!(init_camera(&new_win)))
        exit(1);
    if (!(init_tex(&new_win)))
        exit(0);
    return (new_win);
}


void _f(char *s)
{
    s = malloc(1);
}
int main(int ac, char **av)
{
    t_win *win;
    t_img *img;

    if (!(win = init_mlx_win(av[1])))
        exit(0);
    // if (!(init_window(win)))
    //     exit(0);
    // if (!(init_key(win)))
    //     exit(0);
    // if (!(init_camera(win)))
    //     exit(0);
    // load_texture(&win);
    mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
    mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
    mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
    // mlx_loop_hook(win->mlx_ptr, event_loop, win);
    mlx_loop(win->mlx_ptr);
    return (0);
}
