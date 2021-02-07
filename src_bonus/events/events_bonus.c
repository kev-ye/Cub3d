/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:01:56 by kaye              #+#    #+#             */
/*   Updated: 2021/02/07 21:17:47 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int    event_loop(t_win *win)
{
    if (!(ray_casting(win)))
        shut_down(win); // need protect
    event_key(win);
    game_sound_loop(win);
    return (1);
}

int event_destroy_win(t_win *win)
{
    shut_down(win);
    return (1);
}