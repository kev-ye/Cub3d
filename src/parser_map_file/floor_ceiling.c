/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:02:39 by kaye              #+#    #+#             */
/*   Updated: 2021/01/29 10:11:31 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_floor_color(char *line, t_desc_info *desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return (0);
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return (0);
    }
    if (ft_strcmp(s[0], "F") != 0)
    {
        free_split(s);
        return (0);;
    }
    desc_info->color_f = check_and_get_color(s[1]);
    if (desc_info->color_f == -1)
    {
        free_split(s);
        return (0);;
    }
    free_split(s);
    return (1);
}

int get_ceiling_color(char *line, t_desc_info *desc_info)
{
    int count;
    char **s;

    count = 0;
    if (!(s = ft_split(line, ' ')))
        return (0);;
    while (s[count] != NULL)
        ++count;
    if (count != 2)
    {
        free_split(s);
        return (0);;
    }
    if (ft_strcmp(s[0], "C") != 0)
    {
        free_split(s);
        return (0);;
    }
    desc_info->color_c = check_and_get_color(s[1]);
    if (desc_info->color_c == -1)
    {
        free_split(s);
        return (0);;
    }
    free_split(s);
    return (1);
}