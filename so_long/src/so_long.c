/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:09:31 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/25 20:25:39 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_map map;
    if(ac != 2)
        ft_error("Error\n");
    check_file_is_valide(av[1]);
    map.map = get_map(av[1]);
    if(map.map != NULL)
    {
        check_map_is_valid(&map);
    }
}