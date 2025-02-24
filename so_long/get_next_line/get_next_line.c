/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:05 by nafarid           #+#    #+#             */
/*   Updated: 2024/12/19 13:13:03 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_line(int fd, char *buffer)
{
	char	*line;
	ssize_t	rd_bytes;

	line = malloc((size_t)BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (ft_strchr(buffer, '\n') == -1)
	{
		rd_bytes = read(fd, line, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
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
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*get_new_str(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	str = malloc(ft_strlen(buffer) - i + 1);
	if (!str)
		return (NULL);
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	if (buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = get_line(buffer);
	if (!line)
		return (NULL);
	buffer = get_new_str(buffer);
	return (line);
}

// int main()
// {
//     int fd = open("test.txt",O_RDONLY);
//     char *l;
//     int i = 1;

//     while((l = get_next_line(fd))!=NULL)
//     {
//         printf("next line :%d %s",i,l);
//         free(l);
//         i++;
//     }
//     close(fd);
// }