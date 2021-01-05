/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:06:48 by kaye              #+#    #+#             */
/*   Updated: 2021/01/05 23:32:18 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void shut_down(t_win *win)
// {
//     mlx_destroy_window(win->mlx_ptr, win->win_ptr);
//     exit(0);
// }

// static t_win *init_mlx_win(void)
// {
//     t_win *new_win;

//     if (!(new_win = malloc(sizeof(t_win))))
//         exit(1);
//     ft_bzero(new_win, sizeof(t_win));
//     if (!(new_win->mlx_ptr = mlx_init()))
//         return (ERROR);
//     new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, 800, 600, "Cub3d");
//     return (new_win);
// }

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

// int init_camera(t_win *win)
// {
//     if (!(win->camera = malloc(sizeof(t_camera))))
//         return (ERROR);
//     ft_bzero(win->camera, sizeof(t_camera));
//     win->camera->pos_x = 400;
//     win->camera->pos_y = 300;
//     return (SUCCESS);
// }

// // test main for draw and key control
// int main()
// {
//     t_win *win;
//     t_img *img;
//     int width;
//     int height;

//     if (!(win = init_mlx_win()) ||
//         !(init_key(win)) ||
//         !(init_camera(win)))
//         exit(0);
//     if (!(img = new_image(win, 800, 600)))
//         exit(0);
//     // vertical_line();
//     // mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
//     img = mlx_xpm_file_to_image(win->mlx_ptr, "./textures/east.xpm", &width, &height);
//     printf("%d\n", img);
//     mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
//     mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
//     mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
//     // mlx_loop_hook(win->mlx_ptr, test_draw_move, win);
//     mlx_loop(win->mlx_ptr);
//     return (0);
// }

// int map_check_x(char **map, int x, int y)
// {
//     while (map[y][x])
//     {
//         if (map[y][x] == '1')
//             return (1);
//         ++x;
//     }
//     return (0);
// }

// int map_check(char **map)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;
//     while (1)
//     {
//         if (map[y][x] && map[y][x] == '1')
//             x++;
//         if (map[y][x] == '\0')
//             y++;
//         if (map[y][x] == '0')
//         {
            
//         }
//     }
// }

int check_map(char **map);
int check_map_x(char **map, int y, int x);
int check_map_x2(char **map, int y, int x, int get_wall);
int check_map_y(char **map, int y, int x);
int check_map_y2(char **map, int y, int x, int get_wall);

int main()
{
//////////////////////////////////////////// get map len
    int fd;
    char*line;
    int len_max_x;
    int len_max_y;
    int i;
    int r1;
    
    fd = open("./src/map", O_RDONLY);
    if (fd == -1)
        return (0);
    len_max_x = 0;
    len_max_y = 0;
    r1 = 1;
    while (r1)
    {
        r1 = get_next_line(fd, &line);
        i = 0;
        while (line[i] != '\0' && line[i] != '\n')
        {
            ++i;
            if (len_max_x < i)
                len_max_x = i;
        }
        ++len_max_y;
        free(line);
    }
    // printf("%d %d\n", len_max_x, len_max_y);    
    close(fd);
    
//////////////////////////////////////////// malloc map with size max
    char **map;
    
    int i_malloc;
    
    i_malloc = 0;
    map = malloc(sizeof(char *) * len_max_y + 1);
    if (!map)
        return (0);
    map[len_max_y] = NULL;
    while (i_malloc < len_max_y)
        if (!(map[i_malloc++] = malloc(sizeof(char) * len_max_x + 1)))
            return (0);

//////////////////////////////////////////// init map -> give valu 0
    int map_i;
    int map_j;

    map_i = 0;
    while (map[map_i] != NULL)
    {
        map_j = 0;
        while (map_j < len_max_x)
            map[map_i][map_j++] = 0;
        map[map_i++][map_j] = '\0';
    }
//////////////////////////////////////////// get and fill map

    int map_fd;
    int fill_i;
    int r2;
    char *map_line;

    map_fd = open("./src/map", O_RDONLY);
    if (map_fd == -1)
        return (0);
    fill_i = 0;
    r2 = 1;
    while (r2)
    {
        r2 = get_next_line(map_fd, &map_line);
        ft_strcpy(map[fill_i++], map_line);
        free(map_line);
    }
    close(map_fd);

    // fill_i = 0;
    // while (map[fill_i] != NULL)
    // {
    //     printf("%s\n", map[fill_i]);
    //     fill_i++;
    // }

//////////////////////////////////////////// check map
    int m = check_map(map);
    printf("%d\n", m);

    return 0;
}

int check_map_x(char **map, int y, int x)
{
    int tmp_x;
    int get_wall;

    tmp_x = x;
    get_wall = 0;
    while (map[y][x])
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        ++x;
    }
    x = tmp_x;
    get_wall = check_map_x2(map, y, x, get_wall);
    if (get_wall == 2)
        return (1);
    else
        return (0);    
}

int check_map_x2(char **map, int y, int x, int get_wall)
{
    while (map[y][x])
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        --x;
    }
    return (get_wall);
}

int check_map_y(char **map, int y, int x)
{
    int tmp_y;
    int get_wall;

    tmp_y = y;
    get_wall = 0;
    while (map[y] != NULL)
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        ++y;
    }
    y = tmp_y;
    get_wall = check_map_y2(map, y, x, get_wall);
    if (get_wall == 2)
        return (1);
    else
        return (0);    
}

int check_map_y2(char **map, int y, int x, int get_wall)
{
    while (y >= 0)
    {
        if (map[y][x] == '1')
        {
            get_wall++;
            break;
        }
        --y;
    }
    return (get_wall);
}

int check_map(char **map)
{
    int check_x;
    int check_y;
    int resu_check_x;
    int resu_check_y;

    check_y = 0;
    resu_check_x = 0;
    resu_check_y = 0;
    while (map[check_y] != NULL)
    {
        check_x = 0;
        while (map[check_y][check_x] != '\0')
        {
            if (map[check_y][check_x] == '0')
            {
                resu_check_x = check_map_x(map, check_y, check_x);
                resu_check_y = check_map_y(map, check_y, check_x);
            }
            if (map[check_y][check_x] == '0' && (!resu_check_x || !resu_check_y))
                return (0);
            ++check_x;
        }
        ++check_y;
    }
    return (1);
}