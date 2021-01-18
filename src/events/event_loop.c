/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:01:56 by kaye              #+#    #+#             */
/*   Updated: 2021/01/18 20:11:18 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void draw(t_win *win)
{
    if (!(ray_casting(win)))
        shut_down(win);
}

int    event_loop(t_win *win)
{
    draw(win);
    event_key(win);
    return (SUCCESS);
}