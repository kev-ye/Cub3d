/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_desc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:57:11 by kaye              #+#    #+#             */
/*   Updated: 2021/01/13 21:20:56 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_desc    init_desc()
{
    t_desc desc;
    
    ft_bzero(&desc, sizeof(desc));
    return (desc);
}

t_desc_info *init_desc_info()
{
    t_desc_info *new_info;

    if (!(new_info = malloc(sizeof(t_desc_info))))
        return (void *)0;
    new_info->r_x = -1;
    new_info->r_y = -1;
    new_info->path_no = NULL;
    new_info->path_so = NULL;
    new_info->path_we = NULL;
    new_info->path_ea = NULL;
    new_info->path_s = NULL;
    new_info->color_f = -1;
    new_info->color_c = -1;
    new_info->player_x = -99;
    new_info->player_y = -99;
    new_info->map = NULL;
    return (new_info);
}