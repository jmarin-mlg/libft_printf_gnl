/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:50:05 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/21 06:12:47 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Reads and appends data from the file descriptor to the storage buffer.
static char	*read_fd_add_buffer(int fd, char *storage)
{
	ssize_t	bytes;
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_memory(&storage));
	buffer[0] = '\0';
	bytes = 1;
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			storage = ft_strjoin(storage, buffer);
			if (!storage)
				return (ft_free_memory(&buffer));
		}
	}
	ft_free_memory(&buffer);
	if (bytes == -1)
		return (ft_free_memory(&storage));
	return (storage);
}

// Extracts the current line from the storage buffer.
char	*extract_line(char *storage)
{
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	return (ft_substr(storage, 0, len));
}

// Cleans the storage buffer and returns the remaining part of the buffer.
static char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free_memory(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free_memory(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free_memory(&storage);
	return (new_storage);
}

// Main function for reading lines from a file descriptor.
char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	char		*line;

	if (fd == -1)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = read_fd_add_buffer(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	if (!line)
		return (ft_free_memory(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
