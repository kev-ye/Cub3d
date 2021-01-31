/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:17:38 by kaye              #+#    #+#             */
/*   Updated: 2021/01/31 12:38:07 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_path_name(char *path, int *fd)
{
    char *s;

    s = ft_strrchr(path, '.');
    if (ft_strcmp(s, ".xpm") != 0)
        return (0);
    if ((*fd = open(path, O_RDONLY)) == -1)
        return (0);
    close(*fd);
    return (1);
}

int check_path(t_desc_info *desc_info)
{
    int fd;
    
    if (!(check_path_name(desc_info->path_no, &fd)))
        return (0);
    if (!(check_path_name(desc_info->path_so, &fd)))
        return (0);
    if (!(check_path_name(desc_info->path_we, &fd)))
        return (0);
    if (!(check_path_name(desc_info->path_ea, &fd)))
        return (0);
    if (!(check_path_name(desc_info->path_s, &fd)))
        return (0);
    if (!(check_path_name(desc_info->path_m, &fd))) // add monster
        return (0);
    return (1);
}