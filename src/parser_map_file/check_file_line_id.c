/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line_id.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:11:45 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 18:16:24 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int check_file_line_info_done(t_desc desc)
{
    if (desc.r == 0 || desc.no == 0 || desc.so == 0 || desc.we == 0 ||
        desc.ea == 0 || desc.s == 0 || desc.f == 0 || desc.c == 0)
        return (SUCCESS);
    else if (desc.r == 1 && desc.no == 1 && desc.so == 1 && desc.we == 1 &&
        desc.ea == 1 && desc.s == 1 && desc.f == 1 && desc.c == 1)
        return (SUCCESS);
    return (ERROR);
}

static int check_file_line_info(char *line, int i, t_desc *desc, t_desc_info *desc_info)
{
    if (line[i] == 'R' && line[i + 1] == ' ')
    {
        if (!(get_resoltion(line, desc_info)))
            return (ERROR);
        desc->r++;
    }
    else if (line[i] == 'S' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (ERROR);
        desc->s++;
    }
    else if (line[i] == 'F' && line[i + 1] == ' ')
    {
        if (!(get_floor_color(line, desc_info)))
            return (ERROR);
        desc->f++;
    }
    else if (line[i] == 'C' && line[i + 1] == ' ')
    {
        if (!(get_ceiling_color(line, desc_info)))
            return (ERROR);
        desc->c++;
    }
    else if (line[i] == 'N' && !ft_strncmp((line + i), "NO", 2))
    {
        if (!(get_path(line, desc_info)))
            return (ERROR);
        desc->no++;
    }
    else if (line[i] == 'S' && !ft_strncmp((line + i), "SO", 2))
    {
        if (!(get_path(line, desc_info)))
            return (ERROR);
        desc->so++;
    }
    else if (line[i] == 'W' && !ft_strncmp((line + i), "WE", 2))
    {
        if (!(get_path(line, desc_info)))
            return (ERROR);
        desc->we++;
    }
    else if (line[i] == 'E' && !ft_strncmp((line + i), "EA", 2))
    {
        if (!(get_path(line, desc_info)))
            return (ERROR);
        desc->ea++;
    }
    else
        return (ERROR);
    return (SUCCESS);
}

int check_file_line(char *line, t_desc *desc, t_desc_info *desc_info)
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
            if (check_file_line_info(line, i, desc, desc_info) && check_file_line_info_done(*desc))
                return (SUCCESS);
            else
                return (ERROR);
        }
        else
            return (ERROR);
    }
    return (SUCCESS);
}