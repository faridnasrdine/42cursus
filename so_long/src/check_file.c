/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:10:15 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/05 17:18:46 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_is_valide(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4)
		ft_error("Error\nFile name too short");
	if (file[len - 1] != 'r' || file[len - 2] != 'e' || file[len - 3] != 'b' || file[len - 4] != '.')
		ft_error("Error\nFile extension must be .ber");
}
