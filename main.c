/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julian <julian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 12:58:13 by julian            #+#    #+#             */
/*   Updated: 2021/12/30 13:07:49 by julian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	i;
	char *str;

	i = open("dracula.txt", O_RDONLY);
	while ((str = get_next_line(i)))
	{
		printf("%s",str);
		free(str);
		str = NULL;
	}
	close(i);
	return (0);
}
