/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:42:32 by jludt             #+#    #+#             */
/*   Updated: 2021/07/15 15:34:09 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = (char *)malloc(sizeof(*s1) * (len_s1 + len_s2) + 1);
	if (s_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	free(s1);
	return (s_join);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s_join;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s_join = (char *)malloc(sizeof(*s1) * (len_s1 + len_s2) + 1);
	if (s_join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		s_join[i++] = s2[j++];
	s_join[i] = '\0';
	// free(s1);
	// free(s2);
	return (s_join);
}

static char	*output(char *text, int buff_size, int marker)
{
	char		*line;
	static char	temp[1000];
	int			i;
	int			j;
	int			k;
	static int	end = 0;
	char		nl[2];
		
	
	if (end == 1 || (buff_size <= 0 && marker == 0))
	{
		free(text);
		return (NULL);
	}
	if (ft_strlen(temp))
		text = ft_strjoin2(temp, text);
	nl[0] = '\n';
	nl[1] = '\0';
	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[0] == '\n')
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
	if (text[0] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	//printf("line = %s\n", line);
	j = 0;
	k = i + 1;
	while(text[k] != '\0')
	{
		temp[j] = text[k];
		k++;
		j++;
	}
	temp[j] = '\0';
	//printf("temp = %s\n", temp);
	if (text[i] == '\n')
	{
		free(text);
		return (ft_strjoin(line, nl));
	}
	else
	{
		end = 1;
		free(text);
		return (line);
	}
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*text;
	int			buff_size;
	static int	marker = 0;

	text = (char *)malloc(sizeof(char) * 1);
	if (text == NULL)
		return (NULL);
	text[0] = '\0';
	buff_size = read(fd, buffer, BUFFER_SIZE);
	//printf("buff_size = %i\n", buff_size);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (buff_size > 0)
	{
		buffer[buff_size] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			text = ft_strjoin(text, buffer);
			marker = 1;
			break ;
		}
		else
		{
			text = ft_strjoin(text, buffer);
			buff_size = read(fd, buffer, BUFFER_SIZE);
			marker = 1;
		}
	}
	return (output(text, buff_size, marker));
}

// int	main(void)
// {
// 	int	i = open("test.txt", O_RDONLY);
	
// 	for (int j = 0; j < 2; j++)
// 	{
// 		printf("%s", get_next_line(i));
// 	}
// 	close(i);
// 	return (0);
// }
