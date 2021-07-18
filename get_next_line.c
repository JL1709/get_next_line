/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:42:32 by jludt             #+#    #+#             */
/*   Updated: 2021/07/18 15:01:56 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*prepare_output(char *text)
{
	char		*line;
	static char	*temp;
	int			i;
	int			j;
	int			k;
	int			l;
	char		nl[2];

	if (temp)
		text = ft_strjoin2(temp, text);
	if (ft_strlen(text) == 0)
	{
		free(text);
		return (NULL);
	}
	nl[0] = '\n';
	nl[1] = '\0';
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
	if (text[i] == '\0')
		k = i;
	else
		k = i + 1;
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
	free(text);
	if (text[i] == '\n')
		return (ft_strjoin(line, nl));
	else
	{
		free(temp);
		temp = NULL;
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
	return (prepare_output(text));
}

int	main(void)
{
	int	i = open("test.txt", O_RDONLY);
	for (int j = 0; j < 5; j++)
	{
		printf("%s", get_next_line(i));
	}
	close(i);
	return (0);
}
