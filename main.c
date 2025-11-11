/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshinwar <eshinwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:20:50 by eshinwar          #+#    #+#             */
/*   Updated: 2025/11/10 16:44:05 by eshinwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fuctl.h>
#include <stdio.h>

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY);
	char	*line;
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}