/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:45:45 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 21:18:37 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int map_line(char *line)
{
    int i;

    i = 0;
    if (!line[0])
        return (ERROR);
    while (line[i])
    {
        if (line[i] == ' ' || line[i] == '0' || line[i] == '1' || line[i] == '2'
            || line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
            ++i;
        else
            return (ERROR);
    }
    return (SUCCESS);
}

static int get_map_y_max(const char *path, int *fd)
{
    char *line;
    int y_max;
    int r;

    if ((*fd = open(path, O_RDONLY)) == -1)
        return (ERROR);
    y_max = 0;
    r = 1;
    while (r)
    {
        r = get_next_line(*fd, &line);
        if (map_line(line))
            ++y_max;
        free(line);
    }
    close(*fd);
    return (y_max);
}

static char **get_map2(const char *path, int *fd, int y_max)
{
    char *line;
    char **map;
    int r;
    int i;

    if (!(map = malloc(sizeof(char *) * (y_max + 1))))
        return (NULL);
    if ((*fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    map[y_max] = NULL;
    r = 1;
    i = 0;
    while (r)
    {
        r = get_next_line(*fd, &line);
        if (map_line(line))
            map[i++] = ft_strdup(line);
        free(line);
    }
    close(*fd);
    return (map);
}

char **get_map(const char *path, int *len_max_y)
{
    int fd;
    char **map;
    int y;
    int x;
    
    if (!(*len_max_y = get_map_y_max(path, &fd)))
        return (NULL);
    if (!(map = get_map2(path, &fd, *len_max_y)))
        return (NULL);
    // *len_max_x = 0;
    // x = 0;
    // y = 0;
    // while (map[y] != NULL)
    // {
    //     while (map[y][x] != '\0')
    //     {
    //         ++x;
    //         if (*len_max_x < x)
    //             *len_max_x = x;
    //     }
    //     ++y;
    // }
    return (map);
}