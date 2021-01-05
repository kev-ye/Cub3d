/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 21:43:00 by kaye              #+#    #+#             */
/*   Updated: 2021/01/05 19:10:24 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void shut_down(t_win *win)
{
    mlx_destroy_window(win->mlx_ptr, win->win_ptr);
    exit(0);
}

static t_win *init_mlx_win(void)
{
    t_win *new_win;

    if (!(new_win = malloc(sizeof(t_win))))
        exit(1);
    ft_bzero(new_win, sizeof(t_win));
    if (!(new_win->mlx_ptr = mlx_init()))
        return (ERROR);
    new_win->width = 640;
    new_win->height = 480;
    return (new_win);
}

static char **test_map(void)
{
    char **t_map;
    int i;

    i = 0;
    if (!(t_map = malloc(sizeof(char *) * 24)))
        return (void *)0;
    while (i < 10)
    {
        if (!(t_map[i] = malloc(sizeof(char) * 25)))
            return (void *)0;
        i++;
    }
    t_map[0] = "111111111111111111111111";
    t_map[1] = "100000000000000000000001";
    t_map[2] = "100000000000000000000001";
    t_map[3] = "100000000000000000000001";
    t_map[4] = "100000111110000101010001";
    t_map[5] = "100000100010000000000001";
    t_map[6] = "100000100010000100010001";
    t_map[7] = "100000100010000000000001";
    t_map[8] = "100000110110000101010001";
    t_map[9] = "100000000000000000000001";
    t_map[10] = "100000000000000000000001";
    t_map[11] = "100000000000000000000001";
    t_map[12] = "100000000000000000000001";
    t_map[13] = "100000000000000000000001";
    t_map[14] = "100000000000000000000001";
    t_map[15] = "100000000000000000000001";
    t_map[16] = "100000000000000000000001";
    t_map[17] = "100000000000000000000001";
    t_map[18] = "100000000000000000000001";
    t_map[19] = "100000000000000000000001";
    t_map[20] = "100000000000000000000001";
    t_map[21] = "100000000000000000000001";
    t_map[22] = "100000000000000000000001";
    t_map[23] = "111111111111111111111111";
    return (t_map);
}

static int  init_window(t_win *win)
{
    if (!(win->win_ptr = mlx_new_window(win->mlx_ptr, 640, 480, "Cub3d")))
        return (ERROR);
    if (!(win->img = new_image(win, win->width, win->height)))
        return (ERROR);
    if (!(win->map = malloc(sizeof(t_map))))
        return (ERROR);
    ft_bzero(win->map, sizeof(t_map));
    if (!(win->map->map = test_map()))
        return (ERROR);
    win->map->map_height = 0;
    win->map->map_width = 0;
    return (SUCCESS);
}

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

int init_camera(t_win *win)
{
    if (!(win->camera = malloc(sizeof(t_camera))))
        return (ERROR);
    ft_bzero(win->camera, sizeof(t_camera));
    win->camera->pos_x = 22.0;
    win->camera->pos_y = 12.0;
    win->camera->dir_x = -1.0;
    win->camera->dir_y = 0.0;
    win->camera->plane_x = 0.0;
    win->camera->plane_y = -0.66;
    win->camera->rot_speed = 0.10;
    win->camera->speed = 0.10;
    win->camera->cam_height = 1.0;
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
    return (SUCCESS);
}

// int main()
// {
//     t_win *win;
//     t_img *img;

//     if (!(win = init_mlx_win()))
//         exit(0);
//     if (!(init_window(win)))
//         exit(0);
//     if (!(init_key(win)))
//         exit(0);
//     if (!(init_camera(win)))
//         exit(0);
//     if (!(init_tex(win)))
//         exit(0);
//     load_texture(win);
//     mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
//     mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
//     mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
//     mlx_loop_hook(win->mlx_ptr, event_loop, win);
//     mlx_loop(win->mlx_ptr);
//     return (0);
// }
