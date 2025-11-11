/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshinwar <eshinwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:30:00 by ElyassShinw       #+#    #+#             */
/*   Updated: 2025/11/10 21:05:37 by eshinwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_return_null(char *ptr1, char *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (NULL);
}

static char	*get_new_leftover(char *leftover)
{
	char	*new_leftover;
	char	*nl_pos;
	size_t	len;

	nl_pos = ft_strchr(leftover, '\n');
	if (!nl_pos)
		return (free_and_return_null(leftover, NULL));
	len = ft_strlen(nl_pos + 1);
	if (len == 0)
		return (free_and_return_null(leftover, NULL));
	new_leftover = ft_substr(nl_pos + 1, 0, len);
	free(leftover);
	return (new_leftover);
}

static char	*extract_line_from(char *leftover)
{
	char	*line;
	char	*nl_pos;
	size_t	len;

	if (!*leftover)
		return (NULL);
	nl_pos = ft_strchr(leftover, '\n');
	if (!nl_pos)
		len = ft_strlen(leftover);
	else
		len = (nl_pos - leftover) + 1;
	line = ft_substr(leftover, 0, len);
	return (line);
}

static char	*read_from_file(int fd, char *leftover)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_and_return_null(leftover, NULL));
	bytes_read = 1;
	while (ft_strchr(leftover, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_and_return_null(leftover, buffer));
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(leftover, buffer);
		if (!temp)
			return (free_and_return_null(leftover, buffer));
		free(leftover);
		leftover = temp;
	}
	free(buffer);
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover)
		leftover = ft_strdup("");
	leftover = read_from_file(fd, leftover);
	if (!leftover)
		return (NULL);
	line = extract_line_from(leftover);
	if (!line)
	{
		leftover = free_and_return_null(leftover, NULL);
		return (NULL);
	}
	leftover = get_new_leftover(leftover);
	return (line);
}
