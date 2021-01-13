/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:19:17 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 21:21:28 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int parser_map(const char *path)
// {
//     char **map;
//     int len_max_y;
//     int p_x;
//     int p_y;

//     p_x = -99;
//     p_y = -99;
//     if (!(map = get_map(path, &len_max_y)))
//         return (ERROR);
//     map = get_player_place(map, &p_x, &p_y);
//     if (!check_map(map, p_x, p_y))
//         return (ERROR);
//     return (SUCCESS);
// }

static int parser_map(const char *path, t_desc_info *desc_info)
{
    char **map;
    int len_max_x;
    int len_max_y;
    int i;
    
    i = 0;
    if (!(map = get_map(path, &len_max_y)))
        return (ERROR);
    (*desc_info).map = get_player_place(map, &(*desc_info).player_x, &(*desc_info).player_y);
    if (!check_map(map, (*desc_info).player_x, (*desc_info).player_y))
        return (ERROR);
    return (SUCCESS);
}

t_desc_info *check_file(const char *path)
{
    char *line;
    int r;
    int fd;
    t_desc desc;
    t_desc_info *desc_info;

    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    r = 1;
    desc = init_desc();
    if (!(desc_info = init_desc_info()))
        return (NULL);
    while (r)
    {
        r = get_next_line(fd, &line);
        if (!check_file_line(line, &desc, desc_info))
        {
            free(line);
            free_desc_info(desc_info);
            return (NULL);
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
            free_desc_info(desc_info);
            return (NULL);
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
            free_desc_info(desc_info);
            return (NULL);
        }
        if (desc.player > 1)
        {
            free(line);
            free_desc_info(desc_info);
            return (NULL);
        }
        free(line);
    }
    close(fd);
    if (!check_path(desc_info))
    {
        free_desc_info(desc_info);
        return (NULL);
    }
    if (!parser_map(path, desc_info))
        return (NULL);
    return (desc_info);
}