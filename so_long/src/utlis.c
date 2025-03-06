/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:24:48 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/05 16:41:00 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_linelen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void ft_free(char **str)
{
    int i = 0;
    if (!str)
        return;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}

