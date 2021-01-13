/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:56:10 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 17:59:33 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    free_split(char **s)
{
    int count;

    count = 0;
    while (s[count] != NULL)
        free(s[count++]);
    free(s[count]);
    free(s);
}

void    free_desc_info(t_desc_info *desc_info)
{
    if (desc_info->path_no)
        free(desc_info->path_no);
    if (desc_info->path_so)
        free(desc_info->path_so);
    if (desc_info->path_we)
        free(desc_info->path_we);
    if (desc_info->path_ea)
        free(desc_info->path_ea);
    if (desc_info->path_s)
        free(desc_info->path_s);
    free(desc_info);
}