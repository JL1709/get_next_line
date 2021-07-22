/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jludt <jludt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 15:42:32 by jludt             #+#    #+#             */
/*   Updated: 2021/07/22 08:59:19 by jludt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_temp(char *temp_old, int len_line)
{
	char	*temp_new;
	int		j;
	int		k;
	int		l;

	if (temp_old[len_line] == '\0')
		k = len_line;
	else
		k = len_line + 1;
	j = 0;
	l = k;
	while (temp_old[k++] != '\0')
		j++;
	temp_new = (char *)malloc(sizeof(char) * j + 1);
	if (temp_new == NULL)
		return (NULL);
	j = 0;
	while (temp_old[l] != '\0')
		temp_new[j++] = temp_old[l++];
	temp_new[j] = '\0';
	free(temp_old);
	return (temp_new);
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

static char	*free_temp(char **temp)
{
	free(*temp);
	*temp = NULL;
	return (NULL);
}

static char	*output(char *text)
{
	char		*line;
	static char	*temp;

	if (temp == NULL)
		temp = ft_calloc(1, 1);
	if (temp == NULL)
		return (NULL);
	if (ft_strlen(text) > 0)
		temp = ft_strjoin(temp, text);
	free(text);
	if (ft_strlen(temp) == 0)
		return (free_temp(&temp));
	line = get_line(temp);
	if (temp[ft_strlen(line)] == '\n')
	{
		temp = get_temp(temp, ft_strlen(line));
		return (ft_strjoin(line, "\n"));
	}
	else
	{
		free(temp);
		temp = NULL;
		return (line);
	}
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*text;
	int			buff_size;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	text = ft_calloc(1, 1);
	if (text == NULL || buffer == NULL || BUFFER_SIZE <= 0)
		return (NULL);
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
	free(buffer);
	return (output(text));
}

// int	main(void)
// {
// 	int	i;
// 	char *str;

// 	i = open("dracula.txt", O_RDONLY);
// 	while ((str = get_next_line(i)))
// 	{
// 		printf("%s",str);
// 		free(str);
// 		str = NULL;
// 	}
// 	close(i);

	// printf("empty\n");
	// i = open("tests/empty", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);	
	// printf("\n");
	
	// printf("nl\n");
	// i = open("tests/nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);

	// printf("41_no_nl\n");
	// i = open("tests/41_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("41_with_nl\n");
	// i = open("tests/41_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("42_no_nl\n");
	// i = open("tests/42_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("42_with_nl\n");
	// i = open("tests/42_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("43_no_nl\n");
	// i = open("tests/43_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("43_with_nl\n");
	// i = open("tests/43_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("multiple_nlx5\n");
	// i = open("tests/multiple_nlx5", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("multiple_line_no_nl\n");
	// i = open("tests/multiple_line_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("multiple_line_with_nl\n");
	// i = open("tests/multiple_line_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");
	
	// printf("alternate_line_nl_no_nl\n");
	// i = open("tests/alternate_line_nl_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");

	// printf("alternate_line_nl_with_nl\n");
	// i = open("tests/alternate_line_nl_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	
	// printf("\n");
	
	// printf("big_line_no_nl\n");
	// i = open("tests/big_line_no_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
	// close(i);
	// printf("\n");

	// printf("big_line_with_nl\n");
	// i = open("tests/big_line_with_nl", O_RDONLY);
	// while ((str = get_next_line(i)))
	// {
	// 	printf("%s",str);
	// 	free(str);
	// 	str = NULL;
	// }
// 	// close(i);
	
// 	return (0);
// }
