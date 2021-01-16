/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:06:48 by kaye              #+#    #+#             */
/*   Updated: 2021/01/16 09:07:37 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int main()
// {
//     int len_max_x;
//     int len_max_y;
//     int i = 0;
//     int p_x = -99;
//     int p_y = -99;
//     char **map;
//     int m;
    
//     map = get_map("./src/map.cub", &len_max_y);
//     map = get_player_place(map, &p_x, &p_y);
//     while (map[i] != NULL)
//     {
//         printf("%s\n", map[i++]);
//     }
//     m = check_map(map, p_x, p_y);
//     printf("%d\n", m);
//     return 0;
// }

//////////////////////////////////////////// main

// int main(int ac, char **av)
// {
//     t_desc_info *desc_info = check_file(av[1]);
//     int i = 0;
//     if (desc_info == NULL)
//         printf("ERROR\n");
//     else
//         printf("SUCESS\n");
//     if (desc_info != 0)
//     {
//         printf("Rx : %d\n", desc_info->r_x);
//         printf("Ry : %d\n", desc_info->r_y);
//         printf("F : %x\n", desc_info->color_f);
//         printf("C : %x\n", desc_info->color_c);
//         printf("NO : %s\n", desc_info->path_no);
//         printf("SO : %s\n", desc_info->path_so);
//         printf("WE : %s\n", desc_info->path_we);
//         printf("EA : %s\n", desc_info->path_ea);
//         printf("S : %s\n", desc_info->path_s);
//         printf("p_x : %d\n", desc_info->player_x);
//         printf("p_y : %d\n", desc_info->player_y);
//         while (desc_info->map[i] != NULL)
//             printf("map : %s\n", desc_info->map[i++]);
//     }
//     else
//         printf("ERROR\n");
//     return (0);
// }