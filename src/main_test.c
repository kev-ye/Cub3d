/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:06:48 by kaye              #+#    #+#             */
/*   Updated: 2021/01/11 21:50:08 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"   

// // void shut_down(t_win *win)
// // {
// //     mlx_destroy_window(win->mlx_ptr, win->win_ptr);
// //     exit(0);
// // }

// // static t_win *init_mlx_win(void)
// // {
// //     t_win *new_win;

// //     if (!(new_win = malloc(sizeof(t_win))))
// //         exit(1);
// //     ft_bzero(new_win, sizeof(t_win));
// //     if (!(new_win->mlx_ptr = mlx_init()))
// //         return (ERROR);
// //     new_win->win_ptr = mlx_new_window(new_win->mlx_ptr, 800, 600, "Cub3d");
// //     return (new_win);
// // }

// // int init_key(t_win *win)
// // {
// //     if (!(win->key_code = malloc(sizeof(t_key))))
// //         return (ERROR);
// //     ft_bzero(win->key_code, sizeof(t_key));
// //     win->key_code->key_w = 0;
// //     win->key_code->key_s = 0;
// //     win->key_code->key_a = 0;
// //     win->key_code->key_d = 0;
// //     win->key_code->key_left = 0;
// //     win->key_code->key_right = 0;
// //     return (SUCCESS);    
// // }

// // int init_camera(t_win *win)
// // {
// //     if (!(win->camera = malloc(sizeof(t_camera))))
// //         return (ERROR);
// //     ft_bzero(win->camera, sizeof(t_camera));
// //     win->camera->pos_x = 400;
// //     win->camera->pos_y = 300;
// //     return (SUCCESS);
// // }

// // // test main for draw and key control
// // int main()
// // {
// //     t_win *win;
// //     t_img *img;
// //     int width;
// //     int height;

// //     if (!(win = init_mlx_win()) ||
// //         !(init_key(win)) ||
// //         !(init_camera(win)))
// //         exit(0);
// //     if (!(img = new_image(win, 800, 600)))
// //         exit(0);
// //     // vertical_line();
// //     // mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, win->camera->pos_x, win->camera->pos_y);
// //     img = mlx_xpm_file_to_image(win->mlx_ptr, "./textures/east.xpm", &width, &height);
// //     printf("%d\n", img);
// //     mlx_hook(win->win_ptr, 2, 1L << 0, event_key_press, win);
// //     mlx_hook(win->win_ptr, 3, 1L << 1, event_key_release, win);
// //     mlx_hook(win->win_ptr, 17, 1L << 17, event_destroy_win, win);
// //     // mlx_loop_hook(win->mlx_ptr, test_draw_move, win);
// //     mlx_loop(win->mlx_ptr);
// //     return (0);
// // }

// int check_map(char **map, int px, int py);
// int check_map_1(char **map, int px, int py);
// int check_map_2(char **map, int px, int py);
// int check_map_3(char **map, int px, int py);
// int check_map_4(char **map, int px, int py);
// int check_map_x(char **map, int y, int x);
// int check_map_x2(char **map, int y, int x, int get_wall);
// int check_map_y(char **map, int y, int x);
// int check_map_y2(char **map, int y, int x, int get_wall);

// // int main()
// // {
// // //////////////////////////////////////////// get map len
// //     int fd;
// //     char*line;
// //     int len_max_x;
// //     int len_max_y;
// //     int i;
// //     int r1;
    
// //     fd = open("./src/map", O_RDONLY);
// //     if (fd == -1)
// //         return (0);
// //     len_max_x = 0;
// //     len_max_y = 0;
// //     r1 = 1;
// //     while (r1)
// //     {
// //         r1 = get_next_line(fd, &line);
// //         i = 0;
// //         while (line[i] != '\0')
// //         {
// //             ++i;
// //             if (len_max_x < i)
// //                 len_max_x = i;
// //         }
// //         ++len_max_y;
// //         free(line);
// //     }
// //     // printf("%d %d\n", len_max_x, len_max_y);    
// //     close(fd);
    
// // //////////////////////////////////////////// malloc map with size max
// //     char **map;
    
// //     int i_malloc;
    
// //     i_malloc = 0;
// //     map = malloc(sizeof(char *) * len_max_y + 1);
// //     if (!map)
// //         return (0);
// //     map[len_max_y] = NULL;
// //     while (i_malloc < len_max_y)
// //         if (!(map[i_malloc++] = malloc(sizeof(char) * len_max_x + 1)))
// //             return (0);

// // //////////////////////////////////////////// init map -> give valu 0
// //     int map_i;
// //     int map_j;

// //     map_i = 0;
// //     while (map[map_i] != NULL)
// //     {
// //         map_j = 0;
// //         while (map_j < len_max_x)
// //             map[map_i][map_j++] = 0;
// //         map[map_i++][map_j] = '\0';
// //     }
// // //////////////////////////////////////////// get and fill map

// //     int map_fd;
// //     int fill_i;
// //     int r2;
// //     char *map_line;

// //     map_fd = open("./src/map.cub", O_RDONLY);
// //     if (map_fd == -1)
// //         return (0);
// //     fill_i = 0;
// //     r2 = 1;
// //     while (r2)
// //     {
// //         r2 = get_next_line(map_fd, &map_line);
// //         strcpy(map[fill_i++], map_line);
// //         free(map_line);
// //     }
// //     close(map_fd);

// //     // fill_i = 0;
// //     // while (map[fill_i] != NULL)
// //     // {
// //     //     printf("%s\n", map[fill_i]);
// //     //     fill_i++;
// //     // }

// // //////////////////////////////////////////// get player point

// //     int p_x;
// //     int p_y;
// //     int m_x;
// //     int m_y;

// //     p_x = -99;
// //     p_y = -99;
// //     m_y = 0;
// //     while (map[m_y] != NULL)
// //     {
// //         m_x = 0;
// //         while (map[m_y][m_x])
// //         {
// //             if (map[m_y][m_x] == 'N')
// //             {
// //                 p_x = m_x;
// //                 p_y = m_y;
// //                 map[m_y][m_x] = '0';
// //             }
// //             ++m_x;
// //         }
// //         ++m_y;
// //     }

// //     // printf("%d %d\n", p_x, p_y);

// // //////////////////////////////////////////// check map
// //     int m = check_map(map, p_x, p_y);
// //     printf("%d\n", m);

// //     return 0;
// // }

// // int check_map_x(char **map, int y, int x)
// // {
// //     int tmp_x;
// //     int get_wall;

// //     tmp_x = x;
// //     get_wall = 0;
// //     while (map[y][x])
// //     {
// //         if (map[y][x] == '1')
// //         {
// //             get_wall++;
// //             break;
// //         }
// //         ++x;
// //     }
// //     x = tmp_x;
// //     get_wall = check_map_x2(map, y, x, get_wall);
// //     if (get_wall == 2)
// //         return (1);
// //     else
// //         return (0);    
// // }

// // int check_map_x2(char **map, int y, int x, int get_wall)
// // {
// //     while (x >= 0)
// //     {
// //         if (map[y][x] == '1')
// //         {
// //             get_wall++;
// //             break;
// //         }
// //         --x;
// //     }
// //     return (get_wall);
// // }

// // int check_map_y(char **map, int y, int x)
// // {
// //     int tmp_y;
// //     int get_wall;

// //     tmp_y = y;
// //     get_wall = 0;
// //     while (map[y] != NULL)
// //     {
// //         if (map[y][x] == '1')
// //         {
// //             get_wall++;
// //             break;
// //         }
// //         ++y;
// //     }
// //     y = tmp_y;
// //     get_wall = check_map_y2(map, y, x, get_wall);
// //     if (get_wall == 2)
// //         return (1);
// //     else
// //         return (0);    
// // }

// // int check_map_y2(char **map, int y, int x, int get_wall)
// // {
// //     while (y >= 0)
// //     {
// //         if (map[y][x] == '1')
// //         {
// //             get_wall++;
// //             break;
// //         }
// //         --y;
// //     }
// //     return (get_wall);
// // }

// // int check_map_1(char **map, int px, int py)
// // {
// //     int check_x;
// //     int check_y;
// //     int resu_x;
// //     int resu_y;

// //     check_y = py;
// //     resu_x = 0;
// //     resu_y = 0;
// //     while (check_y >= 0)
// //     {
// //         check_x = px;
// //         while (check_x >= 0)
// //         {
// //             if (map[check_y][check_x] == '0')
// //             {
// //                 resu_x = check_map_x(map, check_y, check_x);
// //                 resu_y = check_map_y(map, check_y, check_x);
// //             }
// //             if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
// //                 return (0);
// //             --check_x;
// //         }
// //         --check_y;
// //     }
// //     return (1);
// // }

// // int check_map_2(char **map, int px, int py)
// // {
// //     int check_x;
// //     int check_y;
// //     int resu_x;
// //     int resu_y;

// //     check_y = py;
// //     resu_x = 0;
// //     resu_y = 0;
// //     while (check_y >= 0)
// //     {
// //         check_x = px;
// //         while (map[check_y][check_x] != '\0')
// //         {
// //             if (map[check_y][check_x] == '0')
// //             {
// //                 resu_x = check_map_x(map, check_y, check_x);
// //                 resu_y = check_map_y(map, check_y, check_x);
// //             }
// //             if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
// //                 return (0);
// //             ++check_x;
// //         }
// //         --check_y;
// //     }
// //     return (1);
// // }

// // int check_map_3(char **map, int px, int py)
// // {
// //     int check_x;
// //     int check_y;
// //     int resu_x;
// //     int resu_y;

// //     check_y = py;
// //     resu_x = 0;
// //     resu_y = 0;
// //     while (map[check_y] != NULL)
// //     {
// //         check_x = px;
// //         while (check_x >= 0)
// //         {
// //             if (map[check_y][check_x] == '0')
// //             {
// //                 resu_x = check_map_x(map, check_y, check_x);
// //                 resu_y = check_map_y(map, check_y, check_x);
// //             }
// //             if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
// //                 return (0);
// //             --check_x;
// //         }
// //         ++check_y;
// //     }
// //     return (1);
// // }

// // int check_map_4(char **map, int px, int py)
// // {
// //     int check_x;
// //     int check_y;
// //     int resu_x;
// //     int resu_y;

// //     check_y = py;
// //     resu_x = 0;
// //     resu_y = 0;
// //     while (map[check_y] != NULL)
// //     {
// //         check_x = px;
// //         while (map[check_y][check_x] != '\0')
// //         {
// //             if (map[check_y][check_x] == '0')
// //             {
// //                 resu_x = check_map_x(map, check_y, check_x);
// //                 resu_y = check_map_y(map, check_y, check_x);
// //             }
// //             if (map[check_y][check_x] == '0' && (!resu_x || !resu_y))
// //                 return (0);
// //             ++check_x;
// //         }
// //         ++check_y;
// //     }
// //     return (1);
// // }

// // int check_map(char **map, int px, int py)
// // {
// //     if (px == -99 || py == -99)
// //         return (0);
// //     if (check_map_1(map, px, py) && check_map_2(map, px, py) && check_map_3(map, px, py) && check_map_4(map, px, py))
// //         return (1);
// //     else
// //         return (0);
// // }

//////////////////////////////////////////// parser file

//////////////////////////////////////////// init description value

t_desc    init_desc()
{
    t_desc desc;
    
    ft_bzero(&desc, sizeof(desc));
    return (desc);
}

//////////////////////////////////////////// color function

int		create_rgb(int r, int g, int b)
{
	return(r << 16 | g << 8 | b);
}

//////////////////////////////////////////// get element info

void    free_split(char **s)
{
    int count;

    count = 0;
    while (s[count] != NULL)
        free(s[count++]);
    free(s[count]);
    free(s);
}

t_desc_info *init_desc_info()
{
    t_desc_info *new_info;

    if (!(new_info = malloc(sizeof(t_desc_info))))
        return (void *)0;
    new_info->r_x = -1;
    new_info->r_y = -1;
    new_info->path_no = NULL;
    new_info->path_so = NULL;
    new_info->path_we = NULL;
    new_info->path_ea = NULL;
    new_info->path_s = NULL;
    new_info->color_f = -1;
    new_info->color_c = -1;
    return (new_info);
}

void get_resoltion(char *line, t_desc_info **desc_info)
{
    int count;
    char **s;
    
    count = 0;
    if (!(s = ft_split(line, ' ')))
        return ;
    while (s[count] != NULL)
        ++count;
    if (count != 3)
    {
        free_split(s);
        return ;
    }
    if (ft_strcmp(s[0], "R"))
    {
        free_split(s);
        return ;
    }
    count = 0;
    while (s[1][count])
        if (!ft_isdigit(s[1][count++]))
        {
            free_split(s);
            return ;
        }
    count = 0;
    while (s[2][count])
        if (!ft_isdigit(s[2][count++]))
        {
            free_split(s);
            return ;
        }
    (*desc_info)->r_x = ft_atoi(s[1]);
    (*desc_info)->r_y = ft_atoi(s[2]);
    free_split(s);
}

int get_color(char **s)
{
    int r;
    int g;
    int b;
    int color;

    r = ft_atoi(s[0]);
    g = ft_atoi(s[1]);
    b = ft_atoi(s[2]);
    color = create_rgb(r, g, b);
    return (color);
}

int check_and_get_color(char *s)
{
    char **color;
    int count;
    int c;

    count = 0;
    if (!(color = ft_split(s, ',')))
        return (-1);
    while (color[count] != NULL)
        ++count;
    if (count != 3)
    {
        free_split(color);
        return (-1);
    }
    count = 0;
    while (color[0][count] || color[1][count] || color[2][count])
    {
        if ((color[0][count] && !ft_isdigit(color[0][count])) ||
            (color[1][count] && !ft_isdigit(color[1][count])) ||
            (color[2][count] && !ft_isdigit(color[2][count])))
        {
            free_split(color);
            return (-1);
        }
        ++count;
    }
    c = get_color(color);
    free_split(color);
    return (c);
}

void get_floor_color(char *line, t_desc_info **desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return ;
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return ;
    }
    if (ft_strcmp(s[0], "F"))
    {
        free_split(s);
        return ;
    }
    (*desc_info)->color_f = check_and_get_color(s[1]);
    if ((*desc_info)->color_f == -1)
    {
        free_split(s);
        return ;
    }
    free_split(s);
}

void get_ceiling_color(char *line, t_desc_info **desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return ;
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return ;
    }
    if (ft_strcmp(s[0], "C"))
    {
        free_split(s);
        return ;
    }
    (*desc_info)->color_c = check_and_get_color(s[1]);
    if ((*desc_info)->color_c == -1)
    {
        free_split(s);
        return ;
    }
    free_split(s);
}

int get_path_2(char **s, t_desc_info **desc_info)
{
    char *tmp;
    if (!ft_strncmp(s[0], "NO", 2))
    {
        (*desc_info)->path_no = ft_strdup(s[1]);
        return (1);
    }
    else if (!ft_strncmp(s[0], "SO", 2))
    {
        (*desc_info)->path_so = ft_strdup(s[1]);
        return (1);
    }
    else if (!ft_strncmp(s[0], "WE", 2))
    {
        (*desc_info)->path_we = ft_strdup(s[1]);
        return (1);
    }
    else if (!ft_strncmp(s[0], "EA", 2))
    {
        (*desc_info)->path_ea = ft_strdup(s[1]);
        return (1);
    }
    else if (!ft_strcmp(s[0], "S"))
    {
        (*desc_info)->path_s = ft_strdup(s[1]);
        return (1);
    }
    return (0);
}

void get_path(char *line, t_desc_info **desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return ;
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return ;
    }
    if (!get_path_2(s, &*desc_info))
    {
        free_split(s);
        return ;
    }
    free_split(s);
}

t_desc_info *get_desc_info(char *line)
{
    t_desc_info *desc_info;

    if (!(desc_info = init_desc_info()))
        return (void *)0;
    get_resoltion(line, &desc_info);
    get_floor_color(line, &desc_info);
    get_ceiling_color(line, &desc_info);
    get_path(line, &desc_info);
    return (desc_info);
}

//////////////////////////////////////////// function check file name

int check_file_name(const char *path)
{
    const char *tmp_path;

    tmp_path = path;
    while (*path && *path != '.')
        ++path;
    if (*path && !ft_strcmp(path, ".cub"))
    {
        path = tmp_path;
        return (1);
    }
    msg_error("Map file name no valid\n");
    return (0);   
}

//////////////////////////////////////////// function check file info line

int check_file_line_info_done(t_desc desc)
{
    if (desc.r == 0 || desc.no == 0 || desc.so == 0 || desc.we == 0 ||
        desc.ea == 0 || desc.s == 0 || desc.f == 0 || desc.c == 0)
        return (SUCCESS);
    else if (desc.r == 1 && desc.no == 1 && desc.so == 1 && desc.we == 1 &&
        desc.ea == 1 && desc.s == 1 && desc.f == 1 && desc.c == 1)
        return (SUCCESS);
    return (ERROR);
}

int check_file_line_info(char *line, int i, t_desc *desc)
{
    if (line[i] == 'R' && line[i + 1] == ' ')
        desc->r++;
    else if (line[i] == 'S' && line[i + 1] == ' ')
        desc->s++;
    else if (line[i] == 'F' && line[i + 1] == ' ')
        desc->f++;
    else if (line[i] == 'C' && line[i + 1] == ' ')
        desc->c++;
    else if (line[i] == 'N' && !ft_strncmp((line + i), "NO", 2))
        desc->no++;
    else if (line[i] == 'S' && !ft_strncmp((line + i), "SO", 2))
        desc->so++;
    else if (line[i] == 'W' && !ft_strncmp((line + i), "WE", 2))
        desc->we++;
    else if (line[i] == 'E' && !ft_strncmp((line + i), "EA", 2))
        desc->ea++;
    else
        return (ERROR);
    return (SUCCESS);
}

int check_file_line(char *line, t_desc *desc)
{
    int i;

    if (!*line)
        return (SUCCESS);
    i = 0;
    while (line[i])
    {
        if (line[i] == ' ')
            ++i;
        else if (line[i] == 'R' || line[i] == 'S' || line[i] == 'F' ||
                line[i] == 'N' || line[i] == 'W' || line[i] == 'E' ||
                line[i] == 'C')
        {
            if (check_file_line_info(line, i, desc) && check_file_line_info_done(*desc))
                return (SUCCESS);
            else
                return (ERROR);
        }
        else
            return (ERROR);
    }
    return (SUCCESS);
}

//////////////////////////////////////////// function check map norme

int check_map_ready(t_desc desc)
{
    if (desc.r == 1 && desc.no == 1 && desc.so == 1 && desc.we == 1 &&
        desc.ea == 1 && desc.s == 1 && desc.f == 1 && desc.c == 1)
        return (SUCCESS);
    return (ERROR);
}

int check_no_map(char *line, t_desc *desc)
{
    int i;

    i = 0;
    if (!line[0])
    {
        desc->map = 0;
        return (SUCCESS);
    }
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == '2'
            || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
        {
            desc->map = 1;
            return (SUCCESS);
        }
        ++i;
    }
    return (ERROR);
}

int check_map_norm(char *line, t_desc *desc)
{
    int i;

    i = 0;
    if (!line[0])
        return (ERROR);
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == '2'
            || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            i++;
        else
            return (ERROR);
    }
    return (SUCCESS);
}

//////////////////////////////////////////// function check file norme global

int check_file(const char *path)
{
    char *line;
    int r;
    int fd;
    int check;
    t_desc desc;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (ERROR);
    r = 1;
    check = 0;
    desc = init_desc();
    while (r)
    {
        r = get_next_line(fd, &line);
        if (!check_file_line(line, &desc))
        {
            free(line);
            return (ERROR);
        }
        free(line);
        if (check_map_ready(desc))
            break;
    }
    while (r)
    {
        r = get_next_line(fd, &line);
        if (!check_no_map(line, &desc))
        {
            free(line);
            return (ERROR);
        }
        free(line);
        if (desc.map)
            break;
    }
    while (r)
    {
        r = get_next_line(fd, &line);
        if (!check_map_norm(line, &desc))
        {
            free(line);
            return (ERROR);
        }
        free(line);
    }
    return (SUCCESS);
}

int main(int ac, char **av)
{
    // int i = check_file(av[1]);
    // if (!i)
    //     printf("ERROR");
    // else
    //     printf("SUCESS");
    t_desc_info *desc_info;
    char *s = "NO ./path_to_the_north_texture";
    desc_info = get_desc_info(s);
    if (desc_info != 0)
    {
        printf("Rx : %d\n", desc_info->r_x);
        printf("Ry : %d\n", desc_info->r_y);
        printf("F : %d\n", desc_info->color_f);
        printf("C : %d\n", desc_info->color_c);
        printf("NO : %s\n", desc_info->path_no);
        printf("SO : %s\n", desc_info->path_so);
        printf("WE : %s\n", desc_info->path_we);
        printf("EA : %s\n", desc_info->path_ea);
        printf("S : %s\n", desc_info->path_s);
    }
    else
        printf("ERROR\n");
    return (0);
}