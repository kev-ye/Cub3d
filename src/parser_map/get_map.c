/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:45:45 by kaye              #+#    #+#             */
/*   Updated: 2021/01/21 12:56:35 by kaye             ###   ########.fr       */
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

static int get_map_x_max(const char *path, int *fd)
{
    char *line;
    int x_max;
    int r;
    int i;

    if ((*fd = open(path, O_RDONLY)) == -1)
        return (ERROR);
    x_max = 0;
    r = 1;
    while (r)
    {
        i = 0;
        r = get_next_line(*fd, &line);
        while (line[i])
            i++;
        if (x_max < i)
            x_max = i;
        free(line);
    }
    close(*fd);
    return (x_max);
}

static char **get_map2(const char *path, int *fd, int y_max, int x_max)
{
    char *line;
    char **map;
    int r;
    int i;
    int j;
    int len;

    if (!(map = malloc(sizeof(char *) * (y_max))))
        return (NULL);
    if ((*fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    r = 1;
    i = 0;
    while (r)
    {
        j = 0;
        r = get_next_line(*fd, &line);
        if (map_line(line))
        {
            map[i] = ft_strdup(line);
            len = ft_strlen(map[i]);
            while (len + j < x_max)
            {
                map[i] = ft_strjoin_gnl(map[i], " ");
                j++;
            }
            i++;
        }
        free(line);
    }
    close(*fd);
    return (map);
}

char **get_map(const char *path, int *len_max_y, int *len_max_x)
{
    int fd;
    char **map;
    
    if (!(*len_max_y = get_map_y_max(path, &fd)))
        return (NULL);
    if (!(*len_max_x = get_map_x_max(path, &fd)))
        return (NULL);
    if (!(map = get_map2(path, &fd, *len_max_y, *len_max_x)))
        return (NULL);
    return (map);
}