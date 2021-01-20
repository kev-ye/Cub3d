/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:02:26 by kaye              #+#    #+#             */
/*   Updated: 2021/01/20 17:30:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    msg_error(t_win* win, char *msg)
{
    ft_putstr("Error\n");
    ft_putstr(msg);
    if (win != NULL)
        free_win(win);
    exit(1);
}