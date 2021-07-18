/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:42:32 by jludt             #+#    #+#             */
/*   Updated: 2021/07/18 18:29:13 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char *get_temp(char *text, int len_line)
{
	char	*temp;
	int		j;
	int		k;
	int		l;

	if (text[len_line] == '\0')
		k = len_line;
	else
		k = len_line + 1;
	j = 0;
	l = k;
	while (text[k++] != '\0')
		j++;
	temp = (char *)malloc(sizeof(char) * j + 1);
	if (temp == NULL)
		return (NULL);
	j = 0;
	while (text[l] != '\0')
		temp[j++] = text[l++];
	temp[j] = '\0';
	return (temp);
}

static char	*get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static	int check_input(int fd, char *text)
{
	if (fd < 0)
	{
		free(text);
		return (0);
	}
	else
		return (1);
}

static char	*output(char *text, int fd)
{
	char		*line;
	static char	*temp[MAX_FD];
	int			error;

	error = check_input(fd, text);
	if (error == 0)
		return (NULL);
	if (temp[fd])
		text = ft_strjoin2(temp[fd], text);
	if (ft_strlen(text) == 0)
	{
		free(text);
		return (NULL);
	}
	line = get_line(text);
	temp[fd] = get_temp(text, ft_strlen(line));
	free(text);
	if (text[ft_strlen(line)] == '\n')
		return (ft_strjoin(line, "\n"));
	else
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*text;
	int			buff_size;

	text = (char *)malloc(sizeof(char) * 1);
	if (text == NULL || BUFFER_SIZE <= 0)
		return (NULL);
	text[0] = '\0';
	buff_size = read(fd, buffer, BUFFER_SIZE);
	while (buff_size > 0)
	{
		buffer[buff_size] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			text = ft_strjoin(text, buffer);
			break ;
		}
		else
		{
			text = ft_strjoin(text, buffer);
			buff_size = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (output(text, fd));
}

// int	main(void)
// {
// 	int	i = open("test.txt", O_RDONLY);
// 	for (int j = 0; j < 5; j++)
// 	{
// 		printf("%s", get_next_line(i));
// 	}
// 	close(i);
// 	return (0);
// }
