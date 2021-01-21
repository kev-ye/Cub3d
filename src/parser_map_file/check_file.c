/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:19:17 by kaye              #+#    #+#             */
/*   Updated: 2021/01/21 17:17:29 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int parser_map(const char *path, t_desc_info *desc_info, t_desc desc, t_win *win)
{
    char **map;
    int len_max_y;
    int len_max_x;

    if (!(map = get_map(path, &len_max_y, &len_max_x)))
        return (ERROR);
    (*desc_info).map_y = len_max_y;
    (*desc_info).map_x = len_max_x;
    (*desc_info).map = get_player_place(map, &(*desc_info).player_x, &(*desc_info).player_y, desc_info, desc);
    if ((*desc_info).map == NULL)
    {
        free_desc_info(desc_info);
        msg_error(win, "File -> Player error\n");
    }
    if (!check_map(map, len_max_y))
        return (ERROR);
    return (SUCCESS);
}

t_desc_info *check_file(t_win *win, const char *path)
{
    char *line;
    int r;
    int fd;
    t_desc desc;
    t_desc_info *desc_info;

    if (!(check_file_name(path)))
        msg_error(win, "File -> File name error\n");
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
            msg_error(win, "File -> ID error\n");
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
            msg_error(win, "File -> ID error\n");
        }
        free(line);
        if (desc.map)
            break;
    }
    while (r)
    {
        r = get_next_line(fd, &line);
        if (!check_map_norm(line))
        {
            free(line);
            free_desc_info(desc_info);
            msg_error(win, "File -> Map error\n");
        }
        free(line);
    }
    close(fd);
    if (!check_path(desc_info))
    {
        free_desc_info(desc_info);
        msg_error(win, "Path -> Path no exist\n");
    }
    if (!parser_map(path, desc_info, desc, win))
        msg_error(win, "Map -> Map error\n");
    return (desc_info);
}