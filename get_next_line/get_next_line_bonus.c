/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:20:06 by nafarid           #+#    #+#             */
/*   Updated: 2024/12/12 10:32:07 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read_line(int fd, char *buffer)
{
	char	*line;
	int		rd_bytes;

	line = malloc((ssize_t)BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (ft_strchr(buffer, '\n') == -1)
	{
		rd_bytes = read(fd, line, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0)
			break ;
		line[rd_bytes] = '\0';
		buffer = ft_strjoin(buffer, line);
	}
	free(line);
	return (buffer);
}

static char	*get_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_new_str(char *buffer)
{
	int		i;
	char	*new_str;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	new_str = malloc(ft_strlen(buffer) - i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (buffer[i])
		new_str[j++] = buffer[i++];
	new_str[j] = '\0';
	free(buffer);
	return (new_str);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd] || buffer[fd][0] == '\0')
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd] = get_new_str(buffer[fd]);
	return (line);
}

// int main()
// {
//     int fd1 = open("test.txt", O_RDONLY);
//     int fd2 = open("test1.txt", O_RDONLY);
//     char *line1, *line2;

//     while ((line1 = get_next_line(fd1)) != NULL
// 	|| (line2 = get_next_line(fd2)) != NULL)
//     {
//         if (line1 != NULL)
//         {
//             printf("File 1: %s", line1);
//             free(line1);
//         }
//         if (line2 != NULL)
//         {
//             printf("File 2: %s", line2);
//             free(line2);
//         }
//     }

//     close(fd1);
//     close(fd2);

//     return (0);
// }