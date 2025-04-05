/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:24:48 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/01 12:08:01 by nafarid          ###   ########.fr       */
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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_end_free(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->map[i])
	{
		free((*map)->map[i]);
		i++;
	}
	free((*map)->map);
	if ((*map)->img.player)
		mlx_destroy_image((*map)->mlx, (*map)->img.player);
	if ((*map)->img.wall)
		mlx_destroy_image((*map)->mlx, (*map)->img.wall);
	if ((*map)->img.floor)
		mlx_destroy_image((*map)->mlx, (*map)->img.floor);
	if ((*map)->img.coin)
		mlx_destroy_image((*map)->mlx, (*map)->img.coin);
	if ((*map)->img.exit)
		mlx_destroy_image((*map)->mlx, (*map)->img.exit);
	mlx_destroy_window((*map)->mlx, (*map)->mlx_win);
	mlx_destroy_display((*map)->mlx);
	free((*map)->mlx);
	print_move(map);
	ft_putstr_fd("You Win!\n", 1);
	exit(0);
}

void	print_move(t_map **map)
{
	char	*num;
	char	*put;

	num = ft_itoa((*map)->movement++);
	put = ft_strjoin("Move : ", num);
	ft_putstr_fd(put, 1);
	ft_putchar_fd('\n', 1);
	free(num);
	free(put);
}
