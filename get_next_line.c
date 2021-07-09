/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:42:32 by jludt             #+#    #+#             */
/*   Updated: 2021/07/09 15:14:38 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	count = 0;;
	char		*line;
	static int	memory = 0;
	int			memory2;
	int			i;

	if (count == 0)
	{
		if ((count = (read(fd, buffer, BUFFER_SIZE))) > 0)
		{
			buffer[count] = '\0';
			while (buffer[memory] != '\n' && buffer[memory] != '\0')
				memory++;
			line = (char *)malloc(sizeof(char) * ++memory);
			if (line == NULL)
				return (NULL);
			i = 0;
			while (buffer[i] != '\n' && buffer[i] != '\0')
			{
				line[i] = buffer[i];
				i++;
			}
			if (buffer[i] == '\n')
				line[i] = '\n';
			else
				line[i] = '\0';	
		}
		else
			line = (char *)malloc(sizeof(char));
	}
	else if (count > 0 && memory <= count)
		{
			memory2 = 0;
			while (buffer[memory + memory2] != '\n' && buffer[memory + memory2] != '\0')
				memory2++;
			line = (char *)malloc(sizeof(char) * ++memory2);
			if (line == NULL)
				return (NULL);
			i = 0;
			while (buffer[memory + i] != '\n' && buffer[memory + i] != '\0')
			{
				line[i] = buffer[memory + i];
				i++;
			}
			if (buffer[i] == '\n')
				line[i] = '\n';
			else
				line[i] = '\0';
			memory += memory2;
		}
	else
		line = (char *)malloc(sizeof(char));
	return (line);
}

int main(void)
{
	int i = open("test.txt", O_RDONLY);
	
	for (int j = 0; j < 8; j++)
	{
		printf("%s", get_next_line(i));
	}
	close(i);
	return (0);
}