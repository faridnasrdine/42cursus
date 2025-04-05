/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:10:15 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/28 16:06:08 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_is_valide(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || file[len - 5] == '/')
		ft_error("Error\nFile name too short\n");
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
	{
		ft_error("Error\nFile extension must be .ber\n");
	}
}
