/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 18:00:07 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 18:00:47 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_resoltion(char *line, t_desc_info *desc_info)
{
    int count;
    char **s;
    
    count = 0;
    if (!(s = ft_split(line, ' ')))
        return (ERROR);
    while (s[count] != NULL)
        ++count;
    if (count != 3)
    {
        free_split(s);
        return (ERROR);
    }
    if (ft_strcmp(s[0], "R"))
    {
        free_split(s);
        return (ERROR);;
    }
    count = 0;
    while (s[1][count])
        if (!ft_isdigit(s[1][count++]))
        {
            free_split(s);
            return (ERROR);;
        }
    count = 0;
    while (s[2][count])
        if (!ft_isdigit(s[2][count++]))
        {
            free_split(s);
            return (ERROR);;
        }
    desc_info->r_x = ft_atoi(s[1]);
    desc_info->r_y = ft_atoi(s[2]);
    free_split(s);
    if (desc_info->r_x < 1 || desc_info->r_y < 1)
        return (ERROR);
    return (SUCCESS);
}