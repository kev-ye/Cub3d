/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:17:38 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 18:18:42 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_path_name(char *path, int *fd)
{
    char *s;

    s = ft_strrchr(path, '.');
    if (ft_strcmp(s, ".xpm") != 0)
        return (ERROR);
    if ((*fd = open(path, O_RDONLY)) == -1)
        return (ERROR);
    else
        close(*fd);
    return (SUCCESS);
}

int check_path(t_desc_info *desc_info)
{
    int fd;
    
    if (!(check_path_name(desc_info->path_no, &fd)))
        return (ERROR);
    if (!(check_path_name(desc_info->path_so, &fd)))
        return (ERROR);
    if (!(check_path_name(desc_info->path_we, &fd)))
        return (ERROR);
    if (!(check_path_name(desc_info->path_ea, &fd)))
        return (ERROR);
    if (!(check_path_name(desc_info->path_s, &fd)))
        return (ERROR);
    return (SUCCESS);
}