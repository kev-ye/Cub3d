/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_line_id_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:11:45 by kaye              #+#    #+#             */
/*   Updated: 2021/02/02 15:38:51 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int check_file_line_info_done(t_desc desc)
{
    if (desc.r == 0 || desc.no == 0 || desc.so == 0 || desc.we == 0 ||
        desc.ea == 0 || desc.s == 0 || desc.f == 0 || desc.c == 0 || desc.b == 0 || desc.l == 0 || desc.m == 0 || desc.g == 0 || desc.v == 0)
        return (1);
    else if (desc.r == 1 && desc.no == 1 && desc.so == 1 && desc.we == 1 &&
        desc.ea == 1 && desc.s == 1 && desc.f == 1 && desc.c == 1 && desc.b == 1 && desc.l == 1 && desc.m == 1 && desc.g == 1 && desc.v == 1)
        return (1);
    return (0);
}

static int check_file_line_info(char *line, int i, t_desc *desc, t_desc_info *desc_info)
{
    if (line[i] == 'R' && line[i + 1] == ' ')
    {
        if (!(get_resoltion(line, desc_info)))
            return (0);
        desc->r++;
    }
    else if (line[i] == 'S' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->s++;
    }
    else if (line[i] == 'F' && line[i + 1] == ' ')
    {
        if (!(get_floor_color(line, desc_info)))
            return (0);
        desc->f++;
    }
    else if (line[i] == 'C' && line[i + 1] == ' ')
    {
        if (!(get_ceiling_color(line, desc_info)))
            return (0);
        desc->c++;
    }
    else if (line[i] == 'N' && !ft_strncmp((line + i), "NO", 2))
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->no++;
    }
    else if (line[i] == 'S' && !ft_strncmp((line + i), "SO", 2))
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->so++;
    }
    else if (line[i] == 'W' && !ft_strncmp((line + i), "WE", 2))
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->we++;
    }
    else if (line[i] == 'E' && !ft_strncmp((line + i), "EA", 2))
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->ea++;
    }
    else if (line[i] == 'B' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->b++;
    }
    else if (line[i] == 'L' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->l++;
    }
    else if (line[i] == 'M' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->m++;
    }
    else if (line[i] == 'G' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->g++;
    }
    else if (line[i] == 'V' && line[i + 1] == ' ')
    {
        if (!(get_path(line, desc_info)))
            return (0);
        desc->v++;
    }
    else
        return (0);
    return (1);
}

int check_file_line(char *line, t_desc *desc, t_desc_info *desc_info)
{
    int i;

    if (!*line)
        return (1);
    i = 0;
    while (line[i])
    {
        if (line[i] == 'R' || line[i] == 'S' || line[i] == 'F' ||
                line[i] == 'N' || line[i] == 'W' || line[i] == 'E' ||
                line[i] == 'C' || line[i] == 'B' || line[i] == 'L' || line[i] == 'M' || line[i] == 'G' || line[i] == 'V')
        {
            if (check_file_line_info(line, i, desc, desc_info)
                && check_file_line_info_done(*desc))
                return (1);
            else
                return (0);
        }
        else
            return (0);
    }
    return (1);
}